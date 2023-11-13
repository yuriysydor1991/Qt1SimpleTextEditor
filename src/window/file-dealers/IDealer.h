//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_IDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_IDEALER_H

#include <QString>

/** Interface for the file dealers.
 * Subclass and implement it's virtual functions
 * to substitute default TxtDealer for the
 * appropriate file extension.
 *
 * Put newly created class instantiation code
 * into a DealersFactory class implementation.
 * */
class IDealer {
 public:
  IDealer() = default;

  virtual ~IDealer() = default;

  // true on success,
  // on a failure - everything else

  /** Open a file by the filepath given.
   *
   * @param path
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool openFile(const QString& path) = 0;

  /**
   * Triggers creation of a new file.
   *
   * Particular IDealer implementor for the previous file
   * extension will be destroyed.
   *
   * In case of a FileDealer class, dialog window may emerge on
   * the screen to asc the user about unsaved data.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool newFile() = 0;

  /**
   * Triggers file opening in case of a FileDealer class.
   * May trigger current file close as in case of TxtDealer
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool openFile() = 0;

  /**
   * Triggers save of the data available on the screen
   * into opened file if any. If no file opened, may show
   * SaveAs (by calling the saveFileAs method)  window, so the user
   * can instruct application where to save the data.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool saveFile() = 0;

  /**
   * Triggers opening of a SaveAs window, so user can
   * instruct the application where to save the
   * available window data.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool saveFileAs() = 0;

  /**
   * Saves current data available in editor window into
   * file by given path.
   * @param path Path to the file where to save the data.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool saveFileAs(const QString& path) = 0;

  /**
   * Clears current data contents of implementor.
   *
   * It may clear window text view widget and destroy
   * particular extension dealer in case of the FileDealer
   * class. The FileDealer object will ask the user
   * on what to do with the unsaved data by showing
   * an appropriate dialog.
   *
   * Or it may just close current opened file in case
   * of a TxtDealer, for example.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  virtual bool clear() = 0;

  /**
   * Returns a true value if there is any file opened.
   * @return Returns true on any opened file.
   */
  virtual bool isOpen() = 0;

  /**
   * Returns filepath of a currently opened file if any.
   * @return Opened filepath
   */
  virtual QString filename() = 0;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_IDEALER_H
