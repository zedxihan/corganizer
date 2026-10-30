<h1 align="center">corganizer</h1>
<h3 align="center">A blazing fast CLI tool to automatically organize your cluttered files</h3>

<h1 align="center">
<a href="https://github.com/zedxihan/corganizer">
<img src="https://img.shields.io/github/stars/zedxihan/corganizer?style=for-the-badge&logo=github&labelColor=11140F&color=BBE9AA">
</a>
<a href="https://github.com/zedxihan/corganizer/blob/main/LICENSE">
<img src="https://img.shields.io/github/license/zedxihan/corganizer?style=for-the-badge&logo=gnu&labelColor=11140F&color=BBE9AA">
</a>
<a href="https://github.com/zedxihan/corganizer/commits">
<img src="https://img.shields.io/github/last-commit/zedxihan/corganizer?style=for-the-badge&logo=git&labelColor=11140F&color=BBE9AA">
</a>
<br>
<img src="https://skillicons.dev/icons?i=c,linux,bash">
</h1>

> [!WARNING]  
> **Preview Is The Default:** `corganizer` moves files directly on your filesystem. By default it only
> shows what it would do and moves nothing. Always check the preview first, then add `-r` / `--run`
> to actually move the files.

## 💖 Support Us

[![Patreon](https://img.shields.io/badge/Patreon-F96854?style=for-the-badge&logo=patreon&logoColor=white)](https://patreon.com/zedxihan)

> [!TIP]
> ⭐ **Star This Repository To Support The Developer And Encourage Future Updates!**

## Description

`corganizer` is a fast command-line utility for Linux, written in C99. It scans a messy directory
and automatically sorts your files into category folders (Documents, Images, Code, Media, Archives,
Others) based on their file extensions. It works in two phases: it first scans the folder into a
compact in-memory list, then either prints a preview or moves the files.

## Features

- **Blazing Fast:** Written in pure C with zero external dependencies, optimized with `-O2`. The
  whole file list lives in two memory blocks (an arena for paths and a flat array of entries)
  instead of one allocation per file.
- **Preview By Default:** See exactly where your files will go without moving anything. Files are
  only moved when you pass `-r`.
- **Never Overwrites:** If a file with the same name already exists in the destination, it is
  skipped and reported instead of being replaced.
- **Smart Categorization:** Case-insensitive extension matching (e.g., `.JPG` and `.jpg` both go to
  Images).
- **Clean Table UI:** Color-coded, aligned table output with a clear status for every file and a
  summary line at the end.
- **Tested With AddressSanitizer:** Built and tested with `-fsanitize=address` (`make debug`).

## Installation

### Arch Linux (AUR)

Latest stable version using `yay` (or any other AUR helper)

```bash
yay -S corganizer
```

### Manual Build

Clone the project and compile it locally using `make`.

```bash
git clone https://github.com/zedxihan/corganizer.git
cd corganizer
make
sudo make install
```

Requires Linux (kernel 3.15+ and glibc 2.28+) and a C99 compiler.

## Usage

### 1. Preview Mode (Default)

Safely preview how your messy directory will be organized (no files are moved):

```bash
corganizer ~/Downloads
```

### 2. Run Mode (Execute)

Move the files into their respective category folders:

```bash
corganizer -r ~/Downloads
```

### Options

| Option          | Description                                  |
| --------------- | -------------------------------------------- |
| `-r`, `--run`   | Move the files (default: preview only)       |
| `-h`, `--help`  | Show the help message                        |

## 🗺 Roadmap

- Support for customized `.corganizerrc` configuration settings.
- Implement recursive descending directory scanning.
- Native undo history to easily revert past operations.
- Automatic renaming on name collisions (currently such files are skipped).

## Hacking

Contributions are welcome. Improve extension rules, performance, or architecture with a pull request.

To build a debug version tailored for development with AddressSanitizer enabled:

```bash
make debug
```

## License

This repository is licensed under the MIT License.

---

Made with ❤️ by zedxihan
