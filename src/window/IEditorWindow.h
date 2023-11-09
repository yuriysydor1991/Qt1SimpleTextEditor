//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_IEDITORWINDOW_H
#define QT1SIMPLETEXTEDITORDEMO_IEDITORWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QString>
#include <QTextEdit>

class IEditorWindow {
 public:
  IEditorWindow() = default;

  virtual ~IEditorWindow() = default;

  virtual void showStatusMessage(const char* status) = 0;

  virtual void showStatusMessage(const QString& status) = 0;

  virtual bool openFile(const char* path) = 0;

  virtual bool openFile(const QString& path) = 0;

  virtual bool clear() = 0;

  virtual void setMainMenu(QMenuBar& menu) = 0;

  virtual QTextEdit& getTextEdit() = 0;

  virtual QString t(const char* txt) = 0;

  virtual QMainWindow& widget() = 0;

  virtual bool isTextChanged() = 0;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_IEDITORWINDOW_H
