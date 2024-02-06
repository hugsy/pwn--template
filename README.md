# MyProject

Start with

```compile
git clone -q https://github.com/hugsy/template-pwn MyProject
```

Edit source files in `src/` and add their paths to `CMakeLists.txt`.

Build

```console
cd MyProject
cmake -S ./ -B build/ -T host=x64 -A x64
cmake --build build/
```

Make sure to change all the `CHANGE` values, and edit the root `CMakeLists.txt` to enable/disable the wanted features to build along side your tool.

_Note_: To easily cross-compile, simply change cmake options `-A` and `-T`. `pwn++` currently supports 
 - `win32`
```bash
cmake .. -T host=x64 -A win32
```
 - `x64`
```bash
cmake .. -T host=x64 -A x64
```
 - `arm64`
```bash
cmake .. -T host=x64 -A arm64
```
 - `arm`
```bash
cmake .. -T host=x86 -A arm
```


Enjoy 🍻!
