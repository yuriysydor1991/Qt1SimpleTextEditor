//
// Created by cc on 08.11.23.
//

#include "GoToLineEmbellisher.h"

#include <QInputDialog>
#include <limits>

GoToLineEmbellisher ::GoToLineEmbellisher(IEditorWindow& main) : window{main} {}

void GoToLineEmbellisher ::show_goto() {
  auto& edit = window.getTextEdit();
  const auto& text = edit.toPlainText();
  const qsizetype lines = text.count(NLINE);

  bool ok;
  const qsizetype cline = QInputDialog::getInt(
      &window.widget(), window.t("Go to line"),
      window.t("Line ") + QString("(max %1):").arg(lines == 0 ? 1 : lines), 1,
      1, lines, 1, &ok);
  if (ok) {
    searchAndSet(edit, text, cline);
  }
}

void GoToLineEmbellisher ::searchAndSet(QTextEdit& edit, const QString& text,
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

void GoToLineEmbellisher ::setCursor(QTextEdit& edit, const qsizetype pos) {
  if (pos < 0) {
    return;
  }

  auto cursor = edit.textCursor();
  cursor.setPosition(pos);
  edit.setTextCursor(cursor);

  edit.ensureCursorVisible();
}
