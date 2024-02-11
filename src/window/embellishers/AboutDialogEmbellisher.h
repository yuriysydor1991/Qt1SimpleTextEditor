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

#ifndef QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H

#include <QBoxLayout>
#include <QDialog>
#include <QImage>
#include <QLabel>

#include "IEditorWindow.h"

namespace qt5simpleted22 {

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
  explicit AboutDialogEmbellisher(IEditorWindow &main);

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
  constexpr static const char *const classname = "AboutDialogEmbellisher";

  constexpr static const int LOGO_SCALE_WIDTH = 100;
  constexpr static const int LOGO_SCALE_HEIGHT = LOGO_SCALE_WIDTH;

  /**
   * The editor application main window instance
   * reference.
   */
  IEditorWindow &window;

  /**
   * Dialog instance to show with about this
   * program content.
   */
  QDialog dialog;

  QBoxLayout vbox;
  QBoxLayout box;
  QLabel gitlabel;
  QLabel mainLabel;
  QLabel homepageLabel;
  QLabel buildLabel;
  QImage logo;
  QLabel logoLabel;

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
  static inline QString make_link(const QString &url, const QString &text);
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_ABOUTDIALOGEMBELLISHER_H
