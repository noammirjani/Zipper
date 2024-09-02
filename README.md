# Archiver 📦


## Introduction

Archiver is a versatile file compression and decompression tool designed to simplify the process of managing compressed files. Whether you need to compress a single file or an entire directory, Archiver provides a seamless experience across different platforms.

## Run Locally
1. Clone the project:

```bash
   git clone https://github.com/noammirjani/Zipper.git
```
2. Go to the project directory

```bash
cd Zipper
````

3. Install dependencies using the provided script:

```bash
  ./Zipper/scripts/conan-install.sh
```

## Usage

Archiver offers a simple command-line interface (CLI) for compressing and decompressing files. Use the following syntax:
` <project-name> <-c/-d flag> <-t type> <files/directories>`

Flags:
- `-c` or `--compress`: Compress files
- `-d` or `--decompress`: Decompress files

Types (for now):
- `zip`: Zip format
- `7zip`: 7-Zip format

### example:

Compress files/directories to a zip archive

```bash
compress zip <zip_name.zip> <files/directory>
```

Specify flags explicitly:

```bash
compress -c zip <zip_name.zip> <files/directory>
```

Decompress a zip archive:

```bash
compress -d zip <zip_name.zip>
```

You don't need to provide the type for decompression if the folder name contains the type in the file name extension:

```bash
compress -d <zip_name.zip>
```

## Features

- Cross-platform compatibility
- Easy-to-use command-line interface

## Project Status

Archiver is actively maintained and developed. Stay tuned for updates and new features!
