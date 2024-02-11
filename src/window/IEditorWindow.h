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

#ifndef QT1SIMPLETEXTEDITORDEMO_IEDITORWINDOW_H
#define QT1SIMPLETEXTEDITORDEMO_IEDITORWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QString>
#include <QTextEdit>

namespace qt5simpleted22 {
/**
 * An abstract class to implement by the editor window
 * class. Perform well known window related operations
 * on main application window or delegate it's execution
 * to other classes.
 */
class IEditorWindow {
 public:
  IEditorWindow() = default;

  virtual ~IEditorWindow() = default;

  /**
   * Instantiates a QString object from
   * a given pointer of character string and
   * forwards it to it's overloaded version
   * with the QString parameter.
   * @param status
   */
  virtual void showStatusMessage(const char *status) = 0;

  /**
   * Show some status or error message in the status bar
   * of the application's main window. Most often
   * will show just a path to currently opened file
   * or <No file opened> at the start of application.
   * @param status Status string which should be shown
   * in the status bar of the main window.
   */
  virtual void showStatusMessage(const QString &status) = 0;

  /**
   * Instantiates the QString object from a given
   * string of characters and forwards it to the
   * QString overloaded version.
   * @param path Pointer to the string of characters
   * which are representing path to the file of
   * interest.
   * @return Returns what it's QString overloaded version
   * returns.
   */
  virtual bool openFile(const char *path) = 0;

  /**
   * Makes window open and read the file by a given filepath
   * @param path Path to the file to open.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool openFile(const QString &path) = 0;

  /**
   * Try to clear current contents of the QEditorWidget
   * and close file if any. May be interrupted if
   * user choose to leave unsaved data as is.
   * @return
   */
  virtual bool clear() = 0;

  /**
   * Sets given QMenuBar object as main menu bar
   * for the application's main window.
   * @param menu built and filled menu with
   * appropriate items-actions.
   */
  virtual void setMainMenu(QMenuBar &menu) = 0;

  /**
   * Returns the application's main window QTextEdit widget
   * @return Returns the application's main window
   * QTextEdit widget.
   */
  virtual QTextEdit &getTextEdit() = 0;

  /**
   * Method helps classes objects to translate
   * text which should be shown to the user.
   *
   * All such calls will be processed by the the Linguist's lupdate tool.
   * @param txt Text which should be translated.
   * @param ctx Context of a translation. Represents a class name in which this
   * funcrtion is called
   * @return Returns a QString object with translation if any or with original
   * text if no translation available for a given text.
   */
  virtual QString t(const char *txt, const char *ctx) = 0;

  /**
   * Returns a reference to the application's main window in
   * a form of the QMainWindow reference.
   * @return A casted reference to the QMainWindow
   */
  virtual QMainWindow &widget() = 0;

  /**
   * Checks if window data was changed and unsaved.
   * @return Returns true if data is changed and unsaved.
   */
  virtual bool isTextChanged() = 0;

  /**
   * Adds fiven QMenu object to the main window's
   * Editor top menu to display additional
   * available features for a given opened file.
   * @param newMenu Build and packed menu to display
   * under the Edit menu.
   */
  virtual void addToEdit(QMenu &newMenu) = 0;

  /**
   * Erases menu object given to the addTiEdit method
   * from the main window's Edit top level menu.
   *
   * Happens if opened file type differs from the previous
   * opened one.
   * @param newMenu A reference to the menu object
   * which should be deleted from the Edit top
   * level menu.
   */
  virtual void removeFromEdit(QMenu &newMenu) = 0;
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_IEDITORWINDOW_H
