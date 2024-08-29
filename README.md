# ChangeMe

Start:

 - with [`gh`](https://github.com/github/cli) (preferred)
```compile
gh repo create ChangeMe --template hugsy/template-pwn --clone # --private
```


 - with `git`
```compile
git clone --depth 1 -q https://github.com/hugsy/template-pwn ChangeMe
```

Edit source files in `src/` and add their paths to `CMakeLists.txt`.

Build

```console
cd ChangeMe
cmake -S ./ -B build/ -T host=x64 -A x64
cmake --build build
```

Make sure to change all the `ChangeMe` values, and edit the root `CMakeLists.txt` to enable/disable the wanted features to build along side your tool.

_Note_: To easily cross-compile, simply change cmake options `-A` and `-T`. `pwn++` currently supports 

| Architecture | Command |
|:-------------|:---------|
| `win32` | `cmake --build .. -T host=x64 -A win32` |
| `x64` | `cmake --build .. -T host=x64 -A x64` |
| `arm64` | `cmake --build .. -T host=x64 -A arm64` |
| `arm` | `cmake --build .. -T host=x86 -A arm` |

Enjoy 🍻!
