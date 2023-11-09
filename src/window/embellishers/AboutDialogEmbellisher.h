//
// Created by cc on 07.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H

#include <QBoxLayout>
#include <QDialog>
#include <QLabel>

#include "IEditorWindow.h"

class AboutDialogEmbellisher {
 public:
  explicit AboutDialogEmbellisher(IEditorWindow& main);

  void show();
  void show_aboutQt();

 private:
  IEditorWindow& window;
  QDialog dialog;

  QBoxLayout box;
  QLabel gitlabel;
  QLabel mainLabel;
  QLabel homepageLabel;
  QLabel buildLabel;

  void build_dialog();
  void set_labels();

  static inline QString make_creator_name();
  static inline QString make_creator_email_link();
  static inline QString make_homepage_link();
  static inline QString make_git_link();
  static inline QString make_link(const QString& url, const QString& text);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
