# ChangeMe

### Start

 - with [`gh`](https://github.com/github/cli) (preferred)

```console
gh repo create ChangeMe --template hugsy/template-pwn --clone # --private
```

 - with `git`
```console
git clone --depth 1 -q https://github.com/hugsy/template-pwn ChangeMe
```

Edit source files in `src/` and add their paths to `CMakeLists.txt`.

### Configure

```console
cd ChangeMe
cmake -S ./ -B build/ -T host=x64 -A x64
cmake --build build
```

Make sure to change all the `ChangeMe` values, and edit the root `CMakeLists.txt` to enable/disable the wanted features to build along side your tool.

### Build

To use the default architecture (i.e. the one cmake runs on), simply go with:

```console
cmake --build ./build
```

Or you can be more specific and cross-compile to one of the architecture supported by `pwn++`:

| Architecture | Command |
|:-------------|:---------|
| `win32` | `cmake --build ./build -T host=x64 -A win32` |
| `x64` | `cmake --build ./build -T host=x64 -A x64` |
| `arm64` | `cmake --build ./build -T host=x64 -A arm64` |
| `arm` | `cmake --build ./build -T host=x86 -A arm` |


Enjoy 🍻!
