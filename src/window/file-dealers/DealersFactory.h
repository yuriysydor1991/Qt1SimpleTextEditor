//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H
#define QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H

#include <memory>

#include "IDealer.h"
#include "IEditorWindow.h"

class DealersFactory {
 public:
  explicit DealersFactory(IEditorWindow& main);

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
  virtual std::shared_ptr<IDealer> dealer_by_ext(const QString& filepath);

 protected:
  IEditorWindow& window;

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

#endif  // QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H
