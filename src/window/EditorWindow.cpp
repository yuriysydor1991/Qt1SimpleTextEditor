//
// Created by cc on 03.09.23.
//

#include <QFileDialog>

#include "EditorWindow.moc.h"
#include "Qt1SimpleTextEditor-conf.h"

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

void EditorWindow::setMainMenu(QMenuBar& menu) { setMenuBar(&menu); }

QTextEdit& EditorWindow::getTextEdit() { return textEdit; }

void EditorWindow::showStatusMessage(const char* status) {
  showStatusMessage(QString(status));
}

void EditorWindow::showStatusMessage(const QString& status) {
  permanentStatus.setText(status);
}

bool EditorWindow::openFile(const char* path) {
  return openFile(QString(path));
}

bool EditorWindow::openFile(const QString& path) {
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

QString EditorWindow::t(const char* txt) { return tr(txt); }

QMainWindow& EditorWindow::widget() { return *this; }

void EditorWindow::paste() { textEdit.paste(); }

void EditorWindow::cut() { textEdit.cut(); }

void EditorWindow::copy() { textEdit.copy(); }

void EditorWindow::undo() { textEdit.undo(); }

void EditorWindow::redo() { textEdit.redo(); }

void EditorWindow::show_about() { about.show(); }

void EditorWindow::show_find() { finder.show(); }

void EditorWindow ::show_find_back() { finder.show(true); }

void EditorWindow ::show_goto() { gotoLine.show_goto(); }

void EditorWindow ::textChanged() { setWindowModified(true); }

bool EditorWindow ::setUnchanged() {
  setWindowModified(false);
  return !isTextChanged();
}

bool EditorWindow::isTextChanged() { return isWindowModified(); }

void EditorWindow::updateWindowTitle(const QString& appender) {
  static const QString projectName{qt1simpleted::constants::PROJECT_NAME};
  static const QString projectVersion{qt1simpleted::constants::EDITOR_VERSION};

  setWindowTitle(projectName + " " + projectVersion +
                 (appender.isEmpty() ? appender : " " + appender));
}
