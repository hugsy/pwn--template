# ChangeMe

Start with
```bash
git clone https://github.com/hugsy/template-pwn pwn
```

Edit source files in `src/` and add their paths to `CMakeLists.txt`.

Build

```bash
mkdir build && cd build
cmake .. -T host=x64 -A x64
cmake --build .
```

_Note_: To cross-compile, change `-A` (pwn++ currently supports `win32`, `x64` and `arm64`). Example

```bash
cmake .. -T host=x64 -A arm64
```


Enjoy 🍻!
