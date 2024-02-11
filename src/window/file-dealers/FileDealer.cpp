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

#include "FileDealer.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

#include "FilterCreator.h"

namespace qt5simpleted22 {

FileDealer::FileDealer(IEditorWindow &main) : window{main}, dfactory{main} {}

bool FileDealer::openFile(const QString &path) {
  clear();

  define_dealer(path);

  if (cdealer == nullptr || define_dealer(path) == nullptr) {
    window.showStatusMessage(
        window.t("Error while creating reader for a file: ", classname) + path);
    return false;
  }

  if (!cdealer->openFile(path)) {
    window.showStatusMessage(window.t("Failure to read the file: ", classname) +
                             path);
    return false;
  }

  window.showStatusMessage(path);

  return true;
}

bool FileDealer::newFile() { return clear(); }

QString FileDealer::get_home_folder() {
  auto path = QStandardPaths::displayName(QStandardPaths::HomeLocation);

  if (path.isEmpty()) {
    path = default_save_folder;
  }

  return path;
}

bool FileDealer::openFile() {
  auto filename = QFileDialog::getOpenFileName(
      &window.widget(), window.t("Open a text file", classname),
      get_home_folder(), FilterCreator::defaultTxtFilter());

  if (filename.isEmpty()) {
    window.showStatusMessage(window.t("No file path given", classname));
    return false;
  }

  return openFile(filename);
}

bool FileDealer::saveFile() {
  if (cdealer == nullptr || !cdealer->isOpen()) {
    return saveFileAs();
  }

  if (!cdealer->saveFile()) {
    window.showStatusMessage(window.t("Failure to save the file: ", classname) +
                             filename());
    return false;
  }

  window.showStatusMessage(filename());

  return true;
}

bool FileDealer::saveFileAs() {
  QString filename = QFileDialog::getSaveFileName(
      &window.widget(), window.t("Save File As", classname), get_home_folder(),
      FilterCreator::defaultTxtFilter());

  if (filename.isEmpty()) {
    window.showStatusMessage(window.t("No file path given", classname));
    return false;
  }

  if (!saveFileAs(filename)) {
    window.showStatusMessage(window.t("Failure to open file: ", classname) +
                             filename);
    return false;
  }

  window.showStatusMessage(filename);

  return true;
}

bool FileDealer::saveFileAs(const QString &path) {
  if (cdealer == nullptr && define_dealer(path) == nullptr) {
    window.showStatusMessage(
        window.t("Error while creating reader for a file: ", classname) + path);
    return false;
  }

  if (!cdealer->saveFileAs(path)) {
    window.showStatusMessage(window.t("Failure to save file as: ", classname) +
                             path);
    return false;
  }

  window.showStatusMessage(path);

  return true;
}

bool FileDealer::clear() {
  // ask the user about file close
  if (window.isTextChanged() && !ensure_user_close()) {
    return false;
  }

  if (cdealer != nullptr) {
    cdealer->clear();
    cdealer.reset();
  }

  window.getTextEdit().clear();

  window.showStatusMessage(window.t("<No file opened>", classname));

  return true;
}

bool FileDealer::isOpen() { return cdealer != nullptr && cdealer->isOpen(); }

std::shared_ptr<IDealer> FileDealer::define_dealer(const QString &path) {
  cdealer = dfactory.dealer_by_ext(path);

  if (cdealer == nullptr) {
    window.showStatusMessage(
        window.t("Error while creating reader for a file: ", classname) + path);
    return {};
  }

  return cdealer;
}

QString FileDealer::filename() {
  return cdealer != nullptr ? cdealer->filename() : QString{};
}

bool FileDealer::ensure_user_close() {
  auto button = askUserAboutUnsaveds();

  if (button == QMessageBox::No) {
    return false;
  } else if (button == QMessageBox::Save) {
    saveFile();
  }

  return true;
}

const QString FileDealer::makeCloseDialogText() {
  return window.t(
      "Close and dismiss unsaved data? - Press \"Yes\" button.\n"
      "Cancel operation? - Press \"No\" button.\n"
      "Save data into current file? - Press \"Save\" button.\n",
      classname);
}

QMessageBox::StandardButtons FileDealer::makeCloseDialogButtons() {
  return QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No |
                                      QMessageBox::Save);
}

QMessageBox::StandardButton FileDealer::askUserAboutUnsaveds() {
  return QMessageBox::question(
      &window.widget(),
      window.t("What to do with the unsaved data?", classname),
      makeCloseDialogText(), makeCloseDialogButtons(),
      QMessageBox::StandardButton::No);
}

}  // namespace qt5simpleted22