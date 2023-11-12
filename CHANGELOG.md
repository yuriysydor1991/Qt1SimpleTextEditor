# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.0.0] - 2023-11-12

+ 67116bf translations: added de_DE locale and reduced script-vars
+ 43b2aee translations: added initial pl_PL machine locale
+ a8a47cb translations: integration through TS and QM-files with Qt Linguist
+ fa967a7 README.md: additional info
+ 7a66269 README.md: add a note about HTML tag wrapping features
+ 619410c README.md: add a note about HTML tag wrapping features
+ b8a8805 HtmlDealer: implemented tag wrap functionality
+ a5fd6e2 CMakeLists.txt: moved FindEmbellisher to appropriate script
+ 3855d84 dealers: add HtmlDealer
+ 9ab9770 menus: add about Qt5 help action
+ 861df06 menus: reordered edit menu
+ f38381f menus: add Find top menu and move commands inside
+ b433816 README.md: refined project goal section
+ 8e905f1 bugfix: error during inserted data Save As command
+ 09f15a2 FileDealer: erased redundant condition from if-statement
+ 09fbcf1 FileDealer: add unsaved dealing data logic
+ b437080 EditorWindow: refine virtual call in the constructor
+ 04158be EditorWindow: add doc changed indication logic with title
+ f373518 GoToLineEmbellisher: implemented go to line feature
+ becc833 Finder: empty default flags (removed case sensitivity)
+ 2ea7fdb minor: removed redundant statush change from finder
+ bc7a267 EditorWindow: implemented text find feature
+ d84e95f README.md: refined cppcheck target on doc command
+ 87d3a17 cppcheck: renaming target to unstable since unpredictable results
+ 3ffe9b1 moc: generating moc-processed file into build root
+ 6f0ca81 cppcheck: reducing minor code issues
+ 8a87e2f cppcheck: single missing include repair
+ bf8c69c README.md: adding section about cppcheck target
+ 3353138 cppcheck: refined code for reduced warnings
+ e5bef55 cppcheck: integration into project
+ 45a8f30 README.md: slight refinement
+ 8df8916 About: add project help info window
+ 3c09c08 CMakeLists.txt: add project info configure file
+ b743326 menus: adding shortcuts for edit submenus
+ 932724c EditorWindow: adding slots for edit submenus
+ 682c216 menu: adding edit submenu getters
+ f6ddf20 menus: adding shortcuts to a file menu
+ 1ba722f menu: add separators between menus groups
+ 606bb4e menu: add actions for redo/undo
+ 58617ab QTextEdit: enable built-in undo/redo feature
+ 391f46b TxtDealer: insert OR beteween file.flush() calls
+ e5ff5f4 Doxygen: edited README.md
+ f56403c Doxygen: adding doc generation system
+ 74d2243 CMakeLists.txt: refined to lower required version
+ cde4fe9 clang-format: formatted code
+ a9fe970 CMakeLists.txt: changing execute_process to find_program
+ c9e9863 clang-format: CMakeLists.txt refinement
+ f252dfc clang-format: adding appropriate Google code styling target
+ e2633c5 errors: unified some errors
+ b1aa15c save paths: giving home folder as default
+ 48a2818 README.md: moved
+ 7c21537 README.md: adding simple doc file
+ a6b495f file: dealing decomposing
+ 001722d filefilterslist: add a little more
+ e150528 test filters: add some new and decomposed
+ d37cfd3 embalishers: repaired directory name
+ 5bea2ef CMakeLists.txt: add require version to embalisher
+ 488f1e5 QTextEdit: using insertPlainText instead of append
+ 8dd0bae menu: decomposed into separate class
+ e799072 EditorWindow: add some basic file functions
