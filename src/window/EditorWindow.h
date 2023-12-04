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

#ifndef QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
#define QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>
#include <QString>
#include <QTextEdit>

#include "AboutDialogEmbellisher.h"
#include "FileDealer.h"
#include "FindEmbellisher.h"
#include "GoToLineEmbellisher.h"
#include "IEditorWindow.h"
#include "MenuEmbellisher.h"
#include "TextEdit.h"

/**
 * The main text editor application window.
 *
 * A QMainWindow Qt5 widget descendant.
 *
 * Also implements IEditorWindow abstract class interface
 * to help decompose the application code and provide
 * required applications to all interested classes-users.
 *
 * Holds all delegate class instances that are containing
 * implementation of the text editor application basic
 * operations.
 */
class EditorWindow : public QMainWindow, public IEditorWindow {
  Q_OBJECT

 public:
  EditorWindow();
  ~EditorWindow() = default;

  /*
   * Next methods are described in the IEditorWindow
   * abstract class declaration.
   */

  virtual void showStatusMessage(const char* status) override;

  virtual void showStatusMessage(const QString& status) override;

  virtual bool openFile(const char* path) override;

  virtual bool openFile(const QString& path) override;

  virtual bool clear() override;

  virtual void setMainMenu(QMenuBar& menu) override;

  virtual QTextEdit& getTextEdit() override;

  virtual QString t(const char* txt, const char* ctx) override;

  virtual QMainWindow& widget() override;

  virtual bool isTextChanged() override;

  virtual void addToEdit(QMenu& newMenu) override;
  virtual void removeFromEdit(QMenu& newMenu) override;

 private slots:

  /**
   * Triggers new file creation. If there were some unsaved data
   * present in the editor widget an appropriate dialog will
   * emerge to ask the user to deal with it.
   *
   * Main window partly delegates execution of this operation
   * to the FileDealer instance.
   */
  void newFile();

  /**
   * Triggers open file dialog to emerge on the user's screen
   * to allow to chose some file to load into editor widget.
   *
   * If there were some unsaved data in the editor widget,
   * an appropriate dialog will emerge to allow user to deal
   * with it.
   * @return Returns true on success. Anything else
   * in case of a failure.
   *
   * Main window delegates execution of this operation
   * to the FileDealer instance.
   */
  bool openFile();

  /**
   * Triggers a file save if editor have one opened.
   * If there is no file opened this method will call
   * saveFileAs() method to allow the user to specify
   * a file where data will be stored.S
   * @return Returns true on success. Anything else
   * in case of a failure.
   *
   * Main window delegates execution of this operation
   * to the FileDealer instance.
   */
  bool saveFile();

  /**
   * Shows appropriate save dialog on the users screem
   * to allow to save current available data from the
   * widget to a chosen file if any.
   * @return Returns true on success. Anything else
   * in case of a failure.
   *
   * Main window delegates execution of this operation
   * to the FileDealer instance.
   */
  bool saveFileAs();

  /**
   * Triggers paste from the system copy buffer if any.
   *
   * Implementation is kindly provided by the
   * QTextEdit widget.
   */
  void paste();

  /**
   * Triggers cut operation on selected widget
   * data if any.
   *
   * Implementation is kindly provided by the
   * QTextEdit widget.
   */
  void cut();

  /**
   * Triggers copy operation on selected widget
   * data if any.
   *
   * Implementation is kindly provided by the
   * QTextEdit widget.
   */
  void copy();

  /**
   * Triggers reverse of the previous executed
   * widget data modify command to restore
   * previous state.
   *
   * Implementation is kindly provided by the
   * QTextEdit widget.
   */
  void undo();

  /**
   * Triggers redo operation on the editor window
   * which restores effects of a previous reversed
   * operation.
   *
   * Implementation is kindly provided by the
   * QTextEdit widget.
   */
  void redo();

  /**
   * Shows about dialog which contains various information
   * about current application. It may include the build data,
   * git commit hash info, creator name and contacts and some
   * pages where additional info can be obtained.
   *
   * Implemented bu the AboutDialogEmbellisher class.
   */
  void show_about();

  /**
   * Shows find text in the available editor data.
   * The text search is performed only in forward direction
   * from the current cursor position.
   *
   * Implemented by the FindEmbellisher class.
   */
  void show_find();

  /**
   * Shows find text in the available editor data.
   * The text search is performed only in backward direction
   * from the current cursor position.
   *
   * Implemented by the FindEmbellisher class.
   */
  void show_find_back();

  /**
   * Shows a dialog to input line number to
   * scroll and place a cursor at the begining of it.
   *
   * Implemented by the GoToLineEmBellisher.
   */
  void show_goto();

  /**
   * Method which is called by the Qt system
   * to notify editor during text editor main
   * widget data alters.
   */
  void textChanged();

  /**
   * Shows the standard Qt5 framework
   * about dialog.
   *
   * Implemented by the Qt5 framework itself.
   */
  void show_about_qt();

 private:
  /**
   * Main text editor QTextEdit window
   * which is returned by the getTextEdit()
   * method for all objects of interest.
   */
  TextEdit textEdit;

  /**
   * Main status bar of the editor window.
   */
  QStatusBar statusBar;

  /**
   * Label that will be packed into
   * statusBar object to display
   * messages to the user about current
   * application state.
   */
  QLabel permanentStatus;

  /**
   * The editor window main menu builder.
   *
   * Creates all the standard editor window menus,
   * inserts all standard actions (QActions are representing
   * particular menu items), binds appropriate
   * shortcuts and uses setMainMenu() window interface
   * method to show build menu to the user.
   */
  MenuEmbellisher menus;

  /**
   * Encapsulates Help menu about program dialogs
   * show code.
   */
  AboutDialogEmbellisher about;

  /**
   * Encapsulates editor application search facility
   * from the Search menu.
   */
  FindEmbellisher finder;

  /**
   * Encapsulates go to line facility of the
   * editor window from the Search menu.
   */
  GoToLineEmbellisher gotoLine;

  /**
   * Implements file dealing operations and
   * accepts requests from the EditorWindow
   * instance to perform appropriate actions
   * on the file opened.
   */
  FileDealer dealer;

  /**
   * Routine that connects main window signals
   * to appropriate available slots implemented
   * by the current class.
   */
  void connectSignals();

  /**
   * Reset all related data changed track facility.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  bool setUnchanged();

  /**
   * Sets or updates main window title to a text given.
   *
   * Additional interpretation may occur by the Qt5
   * framework of the data provided.
   * @param appender Text that will be appended after
   * standard text editor name and version.
   */
  void updateWindowTitle(const QString& appender = QString{});

  /**
   * A clear method by itself that was encapsulated on the
   * separated nonvirtual method to prevent call of
   * a virtual clear() method in the class constructor.
   * @return
   */
  bool clearNoVirtual();

  /**
   * Close event dealer.
   *
   * In case when user forgets to save the data. So the
   * text editor will show an appropriate dialog
   * to ask the user on what to do with available
   * altered data (which effectively can be discarded
   * by the user by pressing appropriate dialog button).
   */
  virtual void closeEvent(QCloseEvent* event) override;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
