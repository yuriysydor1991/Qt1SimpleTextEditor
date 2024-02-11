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

#include "DealersFactory.h"

#include <QFileInfo>
#include <algorithm>
#include <memory>

#include "HtmlDealer.h"
#include "IEditorWindow.h"
#include "TxtDealer.h"

namespace qt5simpleted22 {

DealersFactory::DealersFactory(IEditorWindow &main) : window{main} {}

std::shared_ptr<IDealer> DealersFactory::dealer_by_ext(
    const QString &filepath) {
  QFileInfo finfo(filepath);
  // returns txt
  QString ext = finfo.completeSuffix();

  if (HtmlDealer::isHtml(ext)) {
    return htmlDealer();
  }

  return defaultDealer();
}

std::shared_ptr<IDealer> DealersFactory::defaultDealer() {
  return std::make_shared<TxtDealer>(window);
}

std::shared_ptr<IDealer> DealersFactory::htmlDealer() {
  return std::make_shared<HtmlDealer>(window);
}

}  // namespace qt5simpleted22
