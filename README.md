# This is Jam's Escape!

A little jumping game build for the Hive's March Gamejam.
Made in C++ and SFML (version 2.6)

## How to build?

1. Clone the repo
2. From the root:


   ```bash
   mkdir build
   cd build
   cmake ..
   make

   ./JamsEscape
   ```

3. After building, if you get an error like Library not loaded: libsfml-graphics.2.6.dylib, try this:

```
cp SFML/lib/libsfml-*.dylib .
./JamsEscape

```

   # to remove

   ``` rm -rf build/ ```
