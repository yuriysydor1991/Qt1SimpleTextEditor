//
// Created by cc on 05.11.23.
//

#include "TxtDealer.h"

#include <iostream>

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