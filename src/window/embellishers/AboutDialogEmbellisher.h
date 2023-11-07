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
  AboutDialogEmbellisher(IEditorWindow& main);

  void show();

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

  inline QString make_creator_name();
  inline QString make_creator_email_link();
  inline QString make_homepage_link();
  inline QString make_git_link();
  inline QString make_link(const QString& url, const QString& text);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
