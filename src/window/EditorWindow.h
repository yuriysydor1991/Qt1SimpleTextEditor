//
// Created by cc on 03.09.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
#define QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H

#include <QFile>
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

class EditorWindow : public QMainWindow, public IEditorWindow {
  Q_OBJECT

 public:
  EditorWindow();

  virtual void showStatusMessage(const char* status) override;

  virtual void showStatusMessage(const QString& status) override;

  virtual bool openFile(const char* path) override;

  virtual bool openFile(const QString& path) override;

  virtual bool clear() override;

  virtual void setMainMenu(QMenuBar& menu) override;

  virtual QTextEdit& getTextEdit() override;

  virtual QString t(const char* txt) override;

  virtual QMainWindow& widget() override;

  virtual bool isTextChanged() override;

  virtual void addToEdit(QMenu& newMenu) override;
  virtual void removeFromEdit(QMenu& newMenu) override;

 private slots:

  void newFile();

  bool openFile();

  bool saveFile();

  bool saveFileAs();

  void paste();

  void cut();

  void copy();

  void undo();

  void redo();

  void show_about();

  void show_find();

  void show_find_back();

  void show_goto();

  void textChanged();

  void show_about_qt();

 private:
  QTextEdit textEdit;
  QStatusBar statusBar;
  QLabel permanentStatus;
  MenuEmbellisher menus;
  AboutDialogEmbellisher about;
  FindEmbellisher finder;
  GoToLineEmbellisher gotoLine;
  FileDealer dealer;

  void connectSignals();

  bool setUnchanged();

  void updateWindowTitle(const QString& appender = QString{});

  bool clearNoVirtual();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
