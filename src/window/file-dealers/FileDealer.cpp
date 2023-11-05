//
// Created by cc on 05.11.23.
//

#include <QFileDialog>

#include "FileDealer.h"
#include "FilterCreator.h"

FileDealer::FileDealer(IEditorWindow &main) :
  window{main},
  dfactory{main} {
}

bool FileDealer::openFile(const QString &path) {
  clear();

  define_dealer(path);

  if (cdealer == nullptr || define_dealer(path) == nullptr) {
    window.showStatusMessage(window.t("Failure to create a reader object: ") + path);
    return false;
  }

  if (!cdealer->openFile(path)) {
    window.showStatusMessage(window.t("Failure to the file: ") + path);
    return false;
  }

  window.showStatusMessage(path);

  return true;
}

bool FileDealer::newFile() {
  return clear();
}

bool FileDealer::openFile() {
  QString folder{default_save_folder};

  auto filename = QFileDialog::getOpenFileName(
    &window.widget(),
    window.t("Open a text file"),
    folder,
    FilterCreator::defaultTxtFilter()
  );

  if (filename.isEmpty()) {
    window.showStatusMessage(window.t("No file path given"));
    return false;
  }

  return openFile(filename);
}

bool FileDealer::saveFile() {
  if (cdealer == nullptr || ! cdealer->isOpen()) { return saveFileAs(); }

  if (!cdealer->saveFile())
  {
    window.showStatusMessage(window.t("Failure to the file: ") + filename());
    return false;
  }

  window.showStatusMessage(filename());

  return true ;
}

bool FileDealer::saveFileAs() {
  QString folder{default_save_folder};

  QString filename = QFileDialog::getSaveFileName(
    &window.widget(),
    window.t("Save File As"),
    folder,
    FilterCreator::defaultTxtFilter()
  );

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

bool FileDealer::saveFileAs(const QString &path) {
  if (cdealer == nullptr || define_dealer(path) == nullptr) {
    window.showStatusMessage(window.t("Failure to create reader object for: ") + path);
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
  window.getTextEdit().clear();

  if (cdealer != nullptr) {
    // as the user about file close
    // if (cdealer->isOpen ())
    // {}

    cdealer->clear();
  }

  // also check if text is filled
  // to ask if user want to close it
  //QString data = window.getTextEdit().toPlainText () ;

  window.showStatusMessage(defaultStatus);

  return true;
}

bool FileDealer::isOpen() {
  return cdealer != nullptr && cdealer->isOpen();
}

std::shared_ptr<IDealer> FileDealer::define_dealer(const QString &path) {
  cdealer = dfactory.dealer_by_ext(path);

  if (cdealer == nullptr) {
    window.showStatusMessage(
      window.t("Error while creating reader for a file: ") + path
    );
    return {};
  }

  return cdealer;
}

QString FileDealer :: filename ()
{
  return cdealer != nullptr ? cdealer->filename () : QString{} ;
}
