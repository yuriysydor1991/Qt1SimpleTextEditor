/*
 * Copyright (c) 2023, 2024 Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "GoToLineEmbellisher.h"

#include <QInputDialog>
#include <limits>

namespace qt5simpleted22 {

GoToLineEmbellisher::GoToLineEmbellisher(IEditorWindow &main) : window{main} {}

void GoToLineEmbellisher::show_goto() {
  auto &edit = window.getTextEdit();
  const auto &text = edit.toPlainText();
  const qsizetype lines = text.count(NLINE);

  bool ok;
  const qsizetype cline =
      QInputDialog::getInt(&window.widget(), window.t("Go to line", classname),
                           window.t("Line ", classname) +
                               QString("(max %1):").arg(lines == 0 ? 1 : lines),
                           1, 1, lines, 1, &ok);
  if (ok) {
    searchAndSet(edit, text, cline);
  }
}

void GoToLineEmbellisher::searchAndSet(QTextEdit &edit, const QString &text,
                                       const qsizetype cline) {
  qsizetype lineIter{1};
  qsizetype foundPos{0};

  if (cline == 1) {
    setCursor(edit, 0);
    return;
  }

  while (lineIter < cline) {
    foundPos = text.indexOf(NLINE, foundPos == 0 ? foundPos : foundPos + 1);

    if (foundPos < 0) {
      return;
    }

    ++lineIter;
  }

  setCursor(edit, ++foundPos);
}

void GoToLineEmbellisher::setCursor(QTextEdit &edit, const qsizetype pos) {
  if (pos < 0) {
    return;
  }

  auto cursor = edit.textCursor();
  cursor.setPosition(pos);
  edit.setTextCursor(cursor);

  edit.ensureCursorVisible();
}

}  // namespace qt5simpleted22