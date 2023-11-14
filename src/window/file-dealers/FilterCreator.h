//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_FILTERCREATOR_H
#define QT1SIMPLETEXTEDITORDEMO_FILTERCREATOR_H

/**
 * Factory class which encapsulates code for a
 * open Qt dialog file filter subsystem.
 */
class FilterCreator {
 public:
  FilterCreator() = default;

  /**
   * Creates and returns pointer to a string which contains
   * filters for a file filter facility of an open dialog.
   * @return Created file filter pointer to a char string.
   */
  static const char* defaultTxtFilter();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_FILTERCREATOR_H
