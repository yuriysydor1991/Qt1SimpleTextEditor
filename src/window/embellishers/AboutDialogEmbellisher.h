//
// Created by cc on 07.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H

#include <QBoxLayout>
#include <QDialog>
#include <QLabel>

#include "IEditorWindow.h"

/**
 * Class that encapsulates the main window
 * about dialog dealing code.
 *
 * The EditorWindow uses instances of the
 * AboutDialogEmbellisher class to show about dialogs
 * during user About and AboutQt QAction triggers
 * (mouse clicks).
 */
class AboutDialogEmbellisher {
 public:
  explicit AboutDialogEmbellisher(IEditorWindow& main);

  /**
   * Shows regular about this program dialog with
   * usefull information that may include:
   * - git commit hash;
   * - binary build date;
   * - GiHub home page;
   * - Author name, email and blog link.
   */
  void show();

  /**
   * Trigger show of a standart Qt5 about dialog.
   */
  void show_aboutQt();

 private:
  constexpr static const char* const classname = "AboutDialogEmbellisher";

  /**
   * The editor application main window instance
   * reference.
   */
  IEditorWindow& window;

  /**
   * Dialog instance to show with about this
   * program content.
   */
  QDialog dialog;

  QBoxLayout box;
  QLabel gitlabel;
  QLabel mainLabel;
  QLabel homepageLabel;
  QLabel buildLabel;

  /**
   * Build the about this program dialog.
   */
  void build_dialog();

  /**
   * Sets text to the about this
   * program dialog all labels.
   */
  void set_labels();

  /**
   * Creates current source code creator name string.
   * @return Returns computed creator text string.
   */
  static inline QString make_creator_name();
  /**
   * Creates creators email link.
   * @return Returns HTML link to a creator email.
   */
  static inline QString make_creator_email_link();
  /**
   * Creates a home page link string.
   * @return Returns homepage HTML link string text.
   */
  static inline QString make_homepage_link();

  /**
   * Makes a github project link.
   * @return Returns the HTML link to a github
   * repository location.
   */
  static inline QString make_git_link();

  /**
   * Method that encapsulates the HTML link creation.
   * @param url URL on which HTML link will point to.
   * @param text Text of the link to display on the
   * about dialog.
   * @return Returns build HTML link.
   */
  static inline QString make_link(const QString& url, const QString& text);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
