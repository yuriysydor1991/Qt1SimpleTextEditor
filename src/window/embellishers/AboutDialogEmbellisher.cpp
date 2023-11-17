//
// Created by cc on 07.11.23.
//

#include "AboutDialogEmbellisher.h"

#include <QLayout>
#include <QMessageBox>

#include "Qt1SimpleTextEditor-conf.h"
#include "kytok.org.ua-logo.h"

AboutDialogEmbellisher ::AboutDialogEmbellisher(IEditorWindow& main)
    : window{main},
      dialog{&main.widget()},
      vbox{QBoxLayout::Direction::LeftToRight, &dialog},
      box{QBoxLayout::Direction::TopToBottom} {
  build_dialog();
}

void AboutDialogEmbellisher ::show() { dialog.show(); }

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
                     QString{qt1simpleted::constants::PROJECT_BUILD_DATE} +
                     window.t(" and git commit: ", classname) +
                     QString{qt1simpleted::constants::PROJECT_GIT_COMMIT});

  bool imageLoaded =
      logo.loadFromData(qt1simpleted::images::kytok_logo_data,
                        qt1simpleted::images::kytok_logo_data_size);

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
  return QString{qt1simpleted::constants::EDITOR_CREATOR_NAME};
}

QString AboutDialogEmbellisher::make_creator_email_link() {
  return make_link(qt1simpleted::constants::EDITOR_CREATOR_EMAIL,
                   qt1simpleted::constants::EDITOR_CREATOR_EMAIL);
}

QString AboutDialogEmbellisher::make_homepage_link() {
  return make_link(qt1simpleted::constants::EDITOR_HOMEPAGE_URL,
                   qt1simpleted::constants::EDITOR_HOMEPAGE_URL);
}

QString AboutDialogEmbellisher ::make_git_link() {
  return make_link(qt1simpleted::constants::PROJECT_GIT_URL,
                   qt1simpleted::constants::PROJECT_GIT_URL);
}

QString AboutDialogEmbellisher ::make_link(const QString& url,
                                           const QString& text) {
  return QString{"<a href=\""} + (url.contains("@") ? "mailto:" + url : url) +
         "\">" + text + "</a>";
}

void AboutDialogEmbellisher ::show_aboutQt() {
  QMessageBox::aboutQt(&window.widget(),
                       window.t("About used Qt5 framework", classname));
}
