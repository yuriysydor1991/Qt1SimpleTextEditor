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

#include "FileDealer.h"
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

 private slots:

  void newFile();

  void openFile();

  void saveFile();

  void saveFileAs();

 private:
  QTextEdit textEdit;
  QStatusBar statusBar;
  QLabel permanentStatus;
  MenuEmbellisher menus;
  FileDealer dealer;

  void connectMenus();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
