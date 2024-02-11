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

#include "EditorWindow.h"

#include <QApplication>
#include <QCloseEvent>

#include "Qt1SimpleTextEditor-conf.h"

namespace qt5simpleted22 {

EditorWindow::EditorWindow()
    : menus{*this},
      about{*this},
      finder{*this},
      gotoLine{*this},
      dealer{*this} {
  textEdit.setUndoRedoEnabled(true);
  setCentralWidget(&textEdit);
  setStatusBar(&statusBar);
  statusBar.addPermanentWidget(&permanentStatus, 1);

  connectSignals();

  clearNoVirtual();

  updateWindowTitle("[*]");
}

void EditorWindow::setMainMenu(QMenuBar &menu) { setMenuBar(&menu); }

QTextEdit &EditorWindow::getTextEdit() { return textEdit; }

void EditorWindow::showStatusMessage(const char *status) {
  showStatusMessage(QString(status));
}

void EditorWindow::showStatusMessage(const QString &status) {
  permanentStatus.setText(status);
}

bool EditorWindow::openFile(const char *path) {
  return openFile(QString(path));
}

bool EditorWindow::openFile(const QString &path) {
  return clear() && dealer.openFile(path) && setUnchanged();
}

bool EditorWindow::clear() { return clearNoVirtual(); }

bool EditorWindow::clearNoVirtual() { return dealer.clear() && setUnchanged(); }

void EditorWindow::connectSignals() {
  connect(&menus.getFileNew(), SIGNAL(triggered()), this, SLOT(newFile()));
  connect(&menus.getFileClose(), SIGNAL(triggered()), this, SLOT(newFile()));
  connect(&menus.getFileOpen(), SIGNAL(triggered()), this, SLOT(openFile()));
  connect(&menus.getFileSave(), SIGNAL(triggered()), this, SLOT(saveFile()));
  connect(&menus.getFileSaveAs(), SIGNAL(triggered()), this,
          SLOT(saveFileAs()));

  connect(&menus.getEditCopy(), SIGNAL(triggered()), this, SLOT(copy()));
  connect(&menus.getEditCut(), SIGNAL(triggered()), this, SLOT(cut()));
  connect(&menus.getEditPaste(), SIGNAL(triggered()), this, SLOT(paste()));
  connect(&menus.getEditUndo(), SIGNAL(triggered()), this, SLOT(undo()));
  connect(&menus.getEditRedo(), SIGNAL(triggered()), this, SLOT(redo()));
  connect(&menus.getEditFind(), SIGNAL(triggered()), this, SLOT(show_find()));
  connect(&menus.getEditFindBack(), SIGNAL(triggered()), this,
          SLOT(show_find_back()));
  connect(&menus.getEditGoTo(), SIGNAL(triggered()), this, SLOT(show_goto()));

  connect(&menus.getHelpAbout(), SIGNAL(triggered()), this, SLOT(show_about()));
  connect(&menus.getHelpAboutQt(), SIGNAL(triggered()), this,
          SLOT(show_about_qt()));

  connect(&textEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));
}

void EditorWindow::newFile() { clear(); }

bool EditorWindow::openFile() {
  return clear() && dealer.openFile() && setUnchanged();
}

bool EditorWindow::saveFile() { return dealer.saveFile() && setUnchanged(); }

bool EditorWindow::saveFileAs() {
  return dealer.saveFileAs() && setUnchanged();
}

QString EditorWindow::t(const char *txt, const char *ctx) {
  return QApplication::translate(ctx, txt);
}

QMainWindow &EditorWindow::widget() { return *this; }

void EditorWindow::paste() { textEdit.paste(); }

void EditorWindow::cut() { textEdit.cut(); }

void EditorWindow::copy() { textEdit.copy(); }

void EditorWindow::undo() { textEdit.undo(); }

void EditorWindow::redo() { textEdit.redo(); }

void EditorWindow::show_about() { about.show(); }

void EditorWindow::show_find() { finder.show(); }

void EditorWindow::show_find_back() { finder.show(true); }

void EditorWindow::show_goto() { gotoLine.show_goto(); }

void EditorWindow::textChanged() { setWindowModified(true); }

bool EditorWindow::setUnchanged() {
  setWindowModified(false);
  return !isTextChanged();
}

bool EditorWindow::isTextChanged() { return isWindowModified(); }

void EditorWindow::updateWindowTitle(const QString &appender) {
  static const QString projectName{qt5simpleted22::constants::PROJECT_NAME};
  static const QString projectVersion{
      qt5simpleted22::constants::EDITOR_VERSION};

  setWindowTitle(projectName + " " + projectVersion +
                 (appender.isEmpty() ? appender : " " + appender));
}

void EditorWindow::show_about_qt() { about.show_aboutQt(); }

void EditorWindow::addToEdit(QMenu &newMenu) { menus.addToEdit(newMenu); }

void EditorWindow::removeFromEdit(QMenu &newMenu) {
  menus.removeFromEdit(newMenu);
}

void EditorWindow::closeEvent(QCloseEvent *event) {
  // just in case
  if (event == nullptr) {
    return;
  }

  if (!clear()) {
    event->ignore();
  }
}

}  // namespace qt5simpleted22