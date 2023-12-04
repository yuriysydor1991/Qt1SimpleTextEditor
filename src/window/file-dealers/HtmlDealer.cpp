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

#include "HtmlDealer.h"

#include <QAction>

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
  subHtml.setTitle(window.t("HTML", classname));
  subHeaders.setTitle(window.t("Headers <hN>", classname));

  subHtml.addMenu(&subHeaders);

  QAction* bWrap = subHtml.addAction(window.t("Wrap <b>bold</b>", classname));
  QAction* iWrap = subHtml.addAction(window.t("Wrap <i>italic</i>", classname));
  QAction* uWrap =
      subHtml.addAction(window.t("Wrap <u>underline</u>", classname));

  subHtml.addSeparator();

  QAction* aWrap =
      subHtml.addAction(window.t("Wrap <a href=\"\"...>", classname));

  subHtml.addSeparator();

  QAction* pWrap = subHtml.addAction(window.t("Wrap <p></p>", classname));

  subHtml.addSeparator();

  QAction* preWrap = subHtml.addAction(window.t("Wrap <pre></pre>", classname));

  QAction* h1Wrap = subHeaders.addAction(window.t("Wrap <h1>", classname));
  QAction* h2Wrap = subHeaders.addAction(window.t("Wrap <h2>", classname));
  QAction* h3Wrap = subHeaders.addAction(window.t("Wrap <h3>", classname));
  QAction* h4Wrap = subHeaders.addAction(window.t("Wrap <h4>", classname));
  QAction* h5Wrap = subHeaders.addAction(window.t("Wrap <h5>", classname));
  QAction* h6Wrap = subHeaders.addAction(window.t("Wrap <h6>", classname));

  bWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_B));
  iWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_I));
  uWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_U));

  aWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_A));

  pWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_P));

  h1Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_1));
  h2Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_2));
  h3Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_3));
  h4Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_4));
  h5Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_5));
  h6Wrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_6));

  preWrap->setShortcut(QKeySequence(Qt::ALT + Qt::Key_C));

  connect(bWrap, SIGNAL(triggered()), this, SLOT(wrapB()));
  connect(iWrap, SIGNAL(triggered()), this, SLOT(wrapI()));
  connect(uWrap, SIGNAL(triggered()), this, SLOT(wrapU()));
  connect(aWrap, SIGNAL(triggered()), this, SLOT(wrapA()));
  connect(pWrap, SIGNAL(triggered()), this, SLOT(wrapP()));
  connect(h1Wrap, SIGNAL(triggered()), this, SLOT(wrapH1()));
  connect(h2Wrap, SIGNAL(triggered()), this, SLOT(wrapH2()));
  connect(h3Wrap, SIGNAL(triggered()), this, SLOT(wrapH3()));
  connect(h4Wrap, SIGNAL(triggered()), this, SLOT(wrapH4()));
  connect(h5Wrap, SIGNAL(triggered()), this, SLOT(wrapH5()));
  connect(h6Wrap, SIGNAL(triggered()), this, SLOT(wrapH6()));
  connect(preWrap, SIGNAL(triggered()), this, SLOT(wrapPre()));
}

void HtmlDealer::wrapB() { wrapSelectionWith("<b>", "</b>"); }
void HtmlDealer::wrapI() { wrapSelectionWith("<i>", "</i>"); }
void HtmlDealer::wrapU() { wrapSelectionWith("<u>", "</u>"); }
void HtmlDealer::wrapA() {
  wrapSelectionWith("<a href=\"\" target=\"_blank\">", "</a>");
}
void HtmlDealer::wrapP() { wrapSelectionWith("<p>\n", "\n</p>"); }
void HtmlDealer::wrapH1() { wrapSelectionWith("<h1>", "</h1>"); }
void HtmlDealer::wrapH2() { wrapSelectionWith("<h2>", "</h2>"); }
void HtmlDealer::wrapH3() { wrapSelectionWith("<h3>", "</h3>"); }
void HtmlDealer::wrapH4() { wrapSelectionWith("<h4>", "</h4>"); }
void HtmlDealer::wrapH5() { wrapSelectionWith("<h5>", "</h5>"); }
void HtmlDealer::wrapH6() { wrapSelectionWith("<h6>", "</h6>"); }
void HtmlDealer::wrapPre() {
  wrapSelectionWith("<pre class=\"\">\n", "\n</pre>");
}

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
