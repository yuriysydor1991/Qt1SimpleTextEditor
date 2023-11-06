# Qt5SimpleTextEditorDemo project

Just a demonstration project.
Currently in development.

# Home page

Visint [http://www.kytok.org.ua/](http://www.kytok.org.ua/) for more.

# Building

To build this project run next command
```
mkdir -vp build && cd build && cmake ../ && cmake --build . -j$(nproc)
```
And **voila!** You have executable under the build directory.

# Running the executable

To find and run the executable run next commands:

```
# to find the executable under the source/build tree
find . -name 'Qt1SimpleTextEditorDemo'

# example of the text editor executable dislocation
./build/src/Qt1SimpleTextEditorDemo
```

Don't forget to build it as in previous section shown.