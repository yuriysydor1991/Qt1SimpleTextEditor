# Qt5SimpleTextEditorDemo project

Just a demonstration project for the educational purposes.

Currently in development.

# Project goal

Project goal is to create simple text editor with some basic features:
+ open/edit/save text file;
+ dealing with unsaved altered data;
+ copy/cut/paste into text document;
+ undo/redo features;
+ find text in the document;
+ go to line feature;
+ cross-platform application with Qt5, etc.

There are implemented additional functionality for the HTML files. This text editor allows to wrap selected text with chosen HTML tags to increase text formatting speed. It is available in Edit menu during *.html file opening or saving.

# Home page

Visit [http://www.kytok.org.ua/](http://www.kytok.org.ua/) for more.

# Building

To build this project run next command
```
mkdir -vp build && cd build && cmake ../ && cmake --build . -j$(nproc)
```
And **voilà!** You have executable under the build directory.

# Running the executable

To find and run the executable run next commands:

```
# to find the executable under the source/build tree
find . -name 'Qt1SimpleTextEditorDemo'

# example of the text editor executable dislocation
./build/src/Qt1SimpleTextEditorDemo
```

Don't forget to build it as in previous section shown.

# Generating documentation

Ensure that there are required Doxygen and Graphviz packages in your system:

```
sudo apt-get install -y doxygen graphviz
```

To generate Doxygen documentation execute the following commands:

```
mkdir -vp build && cd build && cmake ../ && cmake --build . --target Doxygen-doc
```

Under the build directory there will be created among others the "html" directory with index.html.

# Running cppcheck

## Installing cppcheck 

Ensure that cppcheck tools is installed in your system. If not, install it with help of a command (for Debian and descendants):

```
sudo apt-get install -y cppcheck
```

## Running all available checks

To run project wide checks with help of cppcheck, execute next command:

```
mkdir -vp build && cd build && cmake ../ && cmake --build . --target unstable-cppcheck
```

All the warnings and errors if any will be printed for the stdout.
