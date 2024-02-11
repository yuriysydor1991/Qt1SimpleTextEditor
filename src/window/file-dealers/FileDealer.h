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

#ifndef QT1SIMPLETEXTEDITORDEMO_FILEDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_FILEDEALER_H

#include <QMessageBox>
#include <memory>

#include "DealersFactory.h"
#include "IDealer.h"
#include "IEditorWindow.h"

namespace qt5simpleted22 {

/**
 * Top level dealer class for the QMainWindow descendant
 * EditorWindow instance  to decompose and encapsulate all
 * the code related to operations with files and unsaved data.
 *
 * Descendant of the IDealer abstract class.
 */
class FileDealer : public IDealer {
 public:
  explicit FileDealer(IEditorWindow &main);

  ~FileDealer() override = default;

  /**
   * Default fallback directory path for all open and save dialogs.
   */
  constexpr static const char *const default_save_folder = "/home/";

  virtual bool openFile(const QString &path) override;

  virtual bool newFile() override;

  virtual bool openFile() override;

  virtual bool saveFile() override;

  virtual bool saveFileAs() override;

  virtual bool saveFileAs(const QString &path) override;

  virtual bool clear() override;

  virtual bool isOpen() override;

  virtual QString filename() override;

 private:
  /**
   * Class name for the text translation purposes.
   */
  constexpr static const char *const classname = "FileDealer";

  /**
   * A reference to the main editor window instance
   * to work with.
   */
  IEditorWindow &window;

  /**
   * Instance of a DealersFactory to instantiate
   * particular file dealer based on filepath
   * information available.
   */
  DealersFactory dfactory;

  /**
   * Current opened file dealer which performs open/save and
   * possibly other operations of interest.
   */
  std::shared_ptr<IDealer> cdealer;

  /**
   * Designed to encapsulate particular dealer
   * creation code.
   * @param path Path to the file which about to be opened.
   * @return Returns smart pointer to a newly created
   * file dealer of available extension or nullptr in case
   * of a failure.
   */
  std::shared_ptr<IDealer> define_dealer(const QString &path);

  /**
   * Returns a home folder path if available or a default_save_folder
   * fallback constant value in case of empty folder computed.
   * @return Returns string to computed folder.
   */
  static QString get_home_folder();

  /**
   * Method that encapsulate code for an asking dialog
   * in case of unsaved data. Dialog makes user to
   * perform some actions to save new data or discard it.
   * @return True if data was saved or false in case
   * that close or any other operation should be
   * interupted.
   */
  bool ensure_user_close();

  /**
   * Generates text that explains to the user
   * actions performed on each button pressed
   * in case of the unsaved data dealing dialog.
   * @return Generated and possibly translated
   * explanatory text for the asking dialog.
   */
  const QString makeCloseDialogText();

  /**
   * Creates a Qt array of button type enum values
   * which would be included in the asking dialog.
   * @return Returns Qt array of enum values
   * of the button types.
   */
  QMessageBox::StandardButtons makeCloseDialogButtons();

  /**
   * Encapsulates dialog calling and value retrieving
   * from the asking dialog.
   * @return Returns particular button pressed
   * type enum value.
   */
  QMessageBox::StandardButton askUserAboutUnsaveds();
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_FILEDEALER_H
