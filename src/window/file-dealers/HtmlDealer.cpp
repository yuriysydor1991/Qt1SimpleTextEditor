//
// Created by cc on 10.11.23.
//

#include <QAction>

#include "HtmlDealer.moc.h"

HtmlDealer ::HtmlDealer(IEditorWindow& main)
    : TxtDealer(main), textEdit{window.getTextEdit()} {
  buildHtmlMenu();
  window.addToEdit(subHtml);
}

HtmlDealer::~HtmlDealer() { window.removeFromEdit(subHtml); }

bool HtmlDealer ::isHtml(const QString& ext) {
  return std::any_of(HTML_EXTs.begin(), HTML_EXTs.end(),
                     [ext](const QString& e) { return e == ext; });
}

void HtmlDealer::buildHtmlMenu() {
  subHtml.setTitle("HTML");

  QAction* bWrap = subHtml.addAction(window.t("Wrap <b>bold</b>"));
  QAction* iWrap = subHtml.addAction(window.t("Wrap <i>italic</i>"));
  QAction* uWrap = subHtml.addAction(window.t("Wrap <u>underline</u>"));

  subHtml.addSeparator();

  QAction* aWrap = subHtml.addAction(window.t("Wrap <a href=\"\"...>"));

  subHtml.addSeparator();

  QAction* h1Wrap = subHtml.addAction(window.t("Wrap <h1>"));
  QAction* h2Wrap = subHtml.addAction(window.t("Wrap <h2>"));
  QAction* h3Wrap = subHtml.addAction(window.t("Wrap <h3>"));
  QAction* h4Wrap = subHtml.addAction(window.t("Wrap <h4>"));
  QAction* h5Wrap = subHtml.addAction(window.t("Wrap <h5>"));
  QAction* h6Wrap = subHtml.addAction(window.t("Wrap <h6>"));

  bWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_B));
  iWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_I));
  uWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_U));

  aWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_A));

  h1Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_1));
  h2Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_2));
  h3Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_3));
  h4Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_4));
  h5Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_5));
  h6Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_6));

  connect(bWrap, SIGNAL(triggered()), this, SLOT(wrapB()));
  connect(iWrap, SIGNAL(triggered()), this, SLOT(wrapI()));
  connect(uWrap, SIGNAL(triggered()), this, SLOT(wrapU()));
  connect(aWrap, SIGNAL(triggered()), this, SLOT(wrapA()));
  connect(h1Wrap, SIGNAL(triggered()), this, SLOT(wrapH1()));
  connect(h2Wrap, SIGNAL(triggered()), this, SLOT(wrapH2()));
  connect(h3Wrap, SIGNAL(triggered()), this, SLOT(wrapH3()));
  connect(h4Wrap, SIGNAL(triggered()), this, SLOT(wrapH4()));
  connect(h5Wrap, SIGNAL(triggered()), this, SLOT(wrapH5()));
  connect(h6Wrap, SIGNAL(triggered()), this, SLOT(wrapH6()));
}

void HtmlDealer::wrapB() { wrapSelectionWith("<b>", "</b>"); }
void HtmlDealer::wrapI() { wrapSelectionWith("<i>", "</i>"); }
void HtmlDealer::wrapU() { wrapSelectionWith("<u>", "</u>"); }
void HtmlDealer::wrapA() {
  wrapSelectionWith("<a href=\"\" target=\"_blank\">", "</a>");
}
void HtmlDealer::wrapH1() { wrapSelectionWith("<h1>", "</h1>"); }
void HtmlDealer::wrapH2() { wrapSelectionWith("<h2>", "</h2>"); }
void HtmlDealer::wrapH3() { wrapSelectionWith("<h3>", "</h3>"); }
void HtmlDealer::wrapH4() { wrapSelectionWith("<h4>", "</h4>"); }
void HtmlDealer::wrapH5() { wrapSelectionWith("<h5>", "</h5>"); }
void HtmlDealer::wrapH6() { wrapSelectionWith("<h6>", "</h6>"); }

bool HtmlDealer ::wrapSelectionWith(const QString& beforeWrap,
                                    const QString& afterWrap) {
  auto cursor = textEdit.textCursor();

  auto initCursorPos = cursor.position();

  if (!cursor.hasSelection()) {
    return false;
  }

  auto endInsert = cursor.selectionEnd();
  auto startInsert = cursor.selectionStart();

  cursor.setPosition(endInsert);
  textEdit.setTextCursor(cursor);
  textEdit.insertPlainText(afterWrap);

  cursor.setPosition(startInsert);
  textEdit.setTextCursor(cursor);
  textEdit.insertPlainText(beforeWrap);

  cursor.setPosition(initCursorPos + beforeWrap.size());
  textEdit.setTextCursor(cursor);

  return true;
}
