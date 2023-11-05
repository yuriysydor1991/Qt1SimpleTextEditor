//
// Created by cc on 03.09.23.
//

#include <QFileDialog>

#include "EditorWindow.moc.h"

EditorWindow::EditorWindow() :
  menus{*this},
  dealer{*this} {
  setCentralWidget(&textEdit);
  setStatusBar(&statusBar);
  statusBar.addPermanentWidget(&permanentStatus, 1);

  connectMenus();

  dealer.clear();
}

void EditorWindow::setMainMenu(QMenuBar &menu) {
  setMenuBar(&menu);
}

QTextEdit &EditorWindow::getTextEdit() {
  return textEdit;
}

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
  if (! clear()) { return false; }

  return dealer.openFile(path);
}

bool EditorWindow::clear() {
  return dealer.clear();
}

void EditorWindow::connectMenus() {
  connect(&menus.getFileNew(), SIGNAL(triggered()), this, SLOT(newFile()));
  connect(&menus.getFileClose(), SIGNAL(triggered()), this, SLOT(newFile()));
  connect(&menus.getFileOpen(), SIGNAL(triggered()), this, SLOT(openFile()));
  connect(&menus.getFileSave(), SIGNAL(triggered()), this, SLOT(saveFile()));
  connect(&menus.getFileSaveAs(), SIGNAL(triggered()), this, SLOT(saveFileAs()));
}

void EditorWindow::newFile() {
  clear();
}

void EditorWindow::openFile() {
  if (! clear()) { return; }

  dealer.openFile();
}

void EditorWindow::saveFile() {
  dealer.saveFile();
}

void EditorWindow::saveFileAs() {
  dealer.saveFileAs();
}

QString EditorWindow::t(const char *txt) {
  return tr(txt);
}

QMainWindow &EditorWindow::widget() {
  return *this;
}
