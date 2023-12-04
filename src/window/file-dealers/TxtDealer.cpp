/*
 * Copyright (c) 2023, Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
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

#include "TxtDealer.h"

TxtDealer::TxtDealer(IEditorWindow& main) : window(main) {}

bool TxtDealer::openFile(const QString& path) {
  if (isOpen()) {
    clear();
  }

  if (!hideOpen(path)) {
    return false;
  }

  auto& edit = window.getTextEdit();

  while (!file.atEnd()) {
    QString line = file.readLine();
    edit.insertPlainText(line);
  }

  return true;
}

bool TxtDealer::openFile() { return clear(); }

bool TxtDealer::newFile() { return clear(); }

bool TxtDealer::saveFile() {
  if (!file.isOpen()) {
    return false;
  }

  auto data = window.getTextEdit().toPlainText().toLocal8Bit();

  return file.reset() && file.resize(data.size()) && file.write(data) >= 0 &&
         (file.flush() || file.flush());
}

bool TxtDealer::saveFileAs() { return false; }

bool TxtDealer::saveFileAs(const QString& path) {
  return hideOpen(path) && saveFile();
}

bool TxtDealer::clear() {
  file.close();
  file.setFileName("");

  return !file.isOpen();
}

bool TxtDealer::isOpen() { return file.isOpen(); }

bool TxtDealer::hideOpen(const QString& path) {
  file.setFileName(path);

  if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
    window.showStatusMessage(
        window.t("Error while opening the file: ", classname) + path);
    return false;
  }

  return file.isOpen();
}

QString TxtDealer ::filename() { return file.fileName(); }