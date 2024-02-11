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

#ifndef QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H
#define QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H

#include <memory>

#include "IDealer.h"
#include "IEditorWindow.h"

namespace qt5simpleted22 {

class DealersFactory {
 public:
  explicit DealersFactory(IEditorWindow &main);

  virtual ~DealersFactory() = default;

  /**
   * Examines given filepath and instantiates and returns
   * the appropriate file dealer object for one of the
   * available IDealers descendants.
   * @param filepath The path to the file for which
   * IDealer descendant should be created.
   * @return Returns a smaprt pointer to the newly created
   * most appropriate file dealer.
   */
  virtual std::shared_ptr<IDealer> dealer_by_ext(const QString &filepath);

 protected:
  IEditorWindow &window;

  /**
   * Instantiates default file dealer which try to open and read
   * file selected by the user.
   * @return Returns a smart pointer pointing to the instantiated
   * default file dealer (TxtDealer).
   */
  virtual std::shared_ptr<IDealer> defaultDealer();

  /**
   * Instantiates the HtmlDealer class object and returns it's
   * smart pointer.
   * @return Smart pointer to a newly created HtmlDealer's smart pointer.
   */
  virtual std::shared_ptr<IDealer> htmlDealer();
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H
