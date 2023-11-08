//
// Created by cc on 03.09.23.
//

#include <QFileDialog>

#include "EditorWindow.moc.h"

EditorWindow::EditorWindow() : menus{*this}, about{*this}, finder{*this}, dealer{*this} {
  textEdit.setUndoRedoEnabled(true);
  setCentralWidget(&textEdit);
  layout()->addWidget(&finder.widget());
  setStatusBar(&statusBar);
  statusBar.addPermanentWidget(&permanentStatus, 1);

  connectMenus();

  dealer.clear();
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
  if (!clear()) {
    return false;
  }

  return dealer.openFile(path);
}

bool EditorWindow::clear() { return dealer.clear(); }

void EditorWindow::connectMenus() {
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

  connect(&menus.getHelpAbout(), SIGNAL(triggered()), this, SLOT(show_about()));
}

void EditorWindow::newFile() { clear(); }

void EditorWindow::openFile() {
  if (!clear()) {
    return;
  }

  dealer.openFile();
}

void EditorWindow::saveFile() { dealer.saveFile(); }

void EditorWindow::saveFileAs() { dealer.saveFileAs(); }

QString EditorWindow::t(const char* txt) { return tr(txt); }

QMainWindow& EditorWindow::widget() { return *this; }

void EditorWindow::paste() { textEdit.paste(); }

void EditorWindow::cut() { textEdit.cut(); }

void EditorWindow::copy() { textEdit.copy(); }

void EditorWindow::undo() { textEdit.undo(); }

void EditorWindow::redo() { textEdit.redo(); }

void EditorWindow::show_about() { about.show(); }
