//
// Created by cc on 07.11.23.
//

#include "AboutDialogEmbellisher.h"

#include <QLayout>

#include "Qt1SimpleTextEditor-conf.h"

AboutDialogEmbellisher ::AboutDialogEmbellisher(IEditorWindow& main)
    : window{main},
      dialog{&main.widget()},
      box{QBoxLayout::Direction::TopToBottom, &dialog} {
  build_dialog();
}

void AboutDialogEmbellisher ::show() { dialog.show(); }

void AboutDialogEmbellisher::build_dialog() {
  dialog.setModal(true);

  set_labels();

  auto& layout = *dialog.layout();

  gitlabel.setOpenExternalLinks(true);
  mainLabel.setOpenExternalLinks(true);
  homepageLabel.setOpenExternalLinks(true);

  buildLabel.setTextInteractionFlags(Qt::TextSelectableByMouse);

  layout.addWidget(&gitlabel);
  layout.addWidget(&mainLabel);
  layout.addWidget(&homepageLabel);
  layout.addWidget(&buildLabel);
}

void AboutDialogEmbellisher::set_labels() {
  dialog.setWindowTitle(window.t("About window"));

  gitlabel.setText(window.t("Visit project github repository ") +
                   make_git_link() +
                   window.t(" for updates and additional info"));

  mainLabel.setText(window.t("Created by ") + QString{make_creator_name()} +
                    " " + make_creator_email_link());

  homepageLabel.setText(window.t("Visit home page for more ") +
                        make_homepage_link());

  buildLabel.setText(window.t("Build date: ") +
                     QString{qt1simpleted::constants::PROJECT_BUILD_DATE} +
                     window.t(" and git commit: ") +
                     QString{qt1simpleted::constants::PROJECT_GIT_COMMIT});
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
