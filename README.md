<h1 align="center">corganizer</h1>
<h3 align="center">A blazing fast, memory-safe CLI tool to automatically organize your cluttered files</h3>

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
> **Always Preview First:** `corganizer` moves files directly on your filesystem. While it is built to be extremely safe,
> it is highly recommended to always run the `scan` command first to preview the changes before executing the `run` command.

## 💖 Support Us

[![Patreon](https://img.shields.io/badge/Patreon-F96854?style=for-the-badge&logo=patreon&logoColor=white)](https://patreon.com/zedxihan)

> [!TIP]
> ⭐ **Star This Repository To Support The Developer And Encourage Future Updates!**

## Description

`corganizer` is a deeply optimized, POSIX-compliant command-line utility written in strict C99. It scans messy directories and automatically categorizes your files into 
 organized folders (Documents, Images, Code, Media, Archives) based on their file extensions. Built with a robust two-phase architecture, it ensures memory safety and provides
 a dry-run preview before touching your filesystem.

## Features

- **Blazing Fast:** Written in pure C with zero external dependencies, optimized with `-O2`.
- **Two-Phase Safety:** Uses a linked-list architecture to build a task queue (`scan`) before performing any disk operations (`run`).
- **Dry-Run Previews:** Safely see exactly where your files will go without actually moving them.
- **Smart Categorization:** Case-insensitive extension matching (e.g., `.JPG` and `.jpg` both go to Images).
- **Memory Safe:** Thoroughly tested with AddressSanitizer (`-fsanitize=address`) to help ensure stability.

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
## Usage

### 1. Preview Mode (Dry-Run)

Safely preview how your messy directory will be organized (no files will be moved during this phase):

```bash
corganizer scan ~/Downloads
```

### 2. Run Mode (Execute)

Execute the operations to permanently move the files into their respective category folders:

```bash
corganizer run ~/Downloads
```

## 🗺 Roadmap

- Support for customized `.corganizerrc` configuration settings.
- Implement recursive descending directory scanning.
- Native undo history to easily revert past operations.
- Built-in collision handling with automated file renaming.

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
