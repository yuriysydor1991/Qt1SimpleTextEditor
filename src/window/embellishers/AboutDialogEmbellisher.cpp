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

#include "AboutDialogEmbellisher.h"

#include <QLayout>
#include <QMessageBox>

#include "Qt1SimpleTextEditor-conf.h"
#include "kytok.org.ua-logo.h"

namespace qt5simpleted22 {

AboutDialogEmbellisher::AboutDialogEmbellisher(IEditorWindow &main)
    : window{main},
      dialog{&main.widget()},
      vbox{QBoxLayout::Direction::LeftToRight, &dialog},
      box{QBoxLayout::Direction::TopToBottom} {
  build_dialog();
}

void AboutDialogEmbellisher::show() { dialog.show(); }

void AboutDialogEmbellisher::build_dialog() {
  dialog.setModal(true);

  set_labels();

  gitlabel.setOpenExternalLinks(true);
  mainLabel.setOpenExternalLinks(true);
  homepageLabel.setOpenExternalLinks(true);

  buildLabel.setTextInteractionFlags(Qt::TextSelectableByMouse);

  box.addWidget(&gitlabel);
  box.addWidget(&mainLabel);
  box.addWidget(&homepageLabel);
  box.addWidget(&buildLabel);

  vbox.addWidget(&logoLabel);
  vbox.addLayout(&box);
}

void AboutDialogEmbellisher::set_labels() {
  dialog.setWindowTitle(window.t("About window", classname));

  gitlabel.setText(window.t("Visit project github repository ", classname) +
                   make_git_link() +
                   window.t(" for updates and additional info", classname));

  mainLabel.setText(window.t("Created by ", classname) +
                    QString{make_creator_name()} + " " +
                    make_creator_email_link());

  homepageLabel.setText(window.t("Visit home page for more ", classname) +
                        make_homepage_link());

  buildLabel.setText(window.t("Build date: ", classname) +
                     QString{qt5simpleted22::constants::PROJECT_BUILD_DATE} +
                     window.t(" and git commit: ", classname) +
                     QString{qt5simpleted22::constants::PROJECT_GIT_COMMIT});

  bool imageLoaded =
      logo.loadFromData(qt5simpleted22::images::kytok_logo_data,
                        qt5simpleted22::images::kytok_logo_data_size);

  if (imageLoaded) {
    logo = logo.scaled(LOGO_SCALE_WIDTH, LOGO_SCALE_HEIGHT);

    /*
     * Do not blame me, it's from
     * an official tutorial
     * https://doc.qt.io/qt-5/qtwidgets-widgets-imageviewer-example.html
     */
    logoLabel.setPixmap(QPixmap::fromImage(logo));
  }
}

QString AboutDialogEmbellisher::make_creator_name() {
  return QString{qt5simpleted22::constants::EDITOR_CREATOR_NAME};
}

QString AboutDialogEmbellisher::make_creator_email_link() {
  return make_link(qt5simpleted22::constants::EDITOR_CREATOR_EMAIL,
                   qt5simpleted22::constants::EDITOR_CREATOR_EMAIL);
}

QString AboutDialogEmbellisher::make_homepage_link() {
  return make_link(qt5simpleted22::constants::EDITOR_HOMEPAGE_URL,
                   qt5simpleted22::constants::EDITOR_HOMEPAGE_URL);
}

QString AboutDialogEmbellisher::make_git_link() {
  return make_link(qt5simpleted22::constants::PROJECT_GIT_URL,
                   qt5simpleted22::constants::PROJECT_GIT_URL);
}

QString AboutDialogEmbellisher::make_link(const QString &url,
                                          const QString &text) {
  return QString{"<a href=\""} + (url.contains("@") ? "mailto:" + url : url) +
         "\">" + text + "</a>";
}

void AboutDialogEmbellisher::show_aboutQt() {
  QMessageBox::aboutQt(&window.widget(),
                       window.t("About used Qt5 framework", classname));
}

}  // namespace qt5simpleted22
