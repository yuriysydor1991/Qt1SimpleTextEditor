//
// Created by cc on 05.11.23.
//

#include "FileDealer.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

#include "FilterCreator.h"

FileDealer::FileDealer(IEditorWindow& main) : window{main}, dfactory{main} {}

bool FileDealer::openFile(const QString& path) {
  clear();

  define_dealer(path);

  if (cdealer == nullptr || define_dealer(path) == nullptr) {
    window.showStatusMessage(
        window.t("Error while creating reader for a file: ") + path);
    return false;
  }

  if (!cdealer->openFile(path)) {
    window.showStatusMessage(window.t("Failure to the file: ") + path);
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
      &window.widget(), window.t("Open a text file"), get_home_folder(),
      FilterCreator::defaultTxtFilter());

  if (filename.isEmpty()) {
    window.showStatusMessage(window.t("No file path given"));
    return false;
  }

  return openFile(filename);
}

bool FileDealer::saveFile() {
  if (cdealer == nullptr || !cdealer->isOpen()) {
    return saveFileAs();
  }

  if (!cdealer->saveFile()) {
    window.showStatusMessage(window.t("Failure to save the file: ") +
                             filename());
    return false;
  }

  window.showStatusMessage(filename());

  return true;
}

bool FileDealer::saveFileAs() {
  QString filename = QFileDialog::getSaveFileName(
      &window.widget(), window.t("Save File As"), get_home_folder(),
      FilterCreator::defaultTxtFilter());

  if (filename.isEmpty()) {
    window.showStatusMessage(window.t("No file path given"));
    return false;
  }

  if (!saveFileAs(filename)) {
    window.showStatusMessage(window.t("Failure to open file: ") + filename);
    return false;
  }

  window.showStatusMessage(filename);

  return true;
}

bool FileDealer::saveFileAs(const QString& path) {
  if (cdealer == nullptr && define_dealer(path) == nullptr) {
    window.showStatusMessage(
        window.t("Error while creating reader for a file: ") + path);
    return false;
  }

  if (!cdealer->saveFileAs(path)) {
    window.showStatusMessage(window.t("Failure to save file as: ") + path);
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

  window.showStatusMessage(defaultStatus);

  return true;
}

bool FileDealer::isOpen() { return cdealer != nullptr && cdealer->isOpen(); }

std::shared_ptr<IDealer> FileDealer::define_dealer(const QString& path) {
  cdealer = dfactory.dealer_by_ext(path);

  if (cdealer == nullptr) {
    window.showStatusMessage(
        window.t("Error while creating reader for a file: ") + path);
    return {};
  }

  return cdealer;
}

QString FileDealer ::filename() {
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
      "Save data into current file? - Press \"Save\" button.\n");
}

QMessageBox::StandardButtons FileDealer::makeCloseDialogButtons() {
  return QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No |
                                      QMessageBox::Save);
}

QMessageBox::StandardButton FileDealer::askUserAboutUnsaveds() {
  return QMessageBox::question(&window.widget(),
                               window.t("What to do with the unsaved data?"),
                               makeCloseDialogText(), makeCloseDialogButtons(),
                               QMessageBox::StandardButton::No);
}
