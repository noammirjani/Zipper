#!/bin/bash

# Install Homebrew if not already installed
if ! command -v brew &> /dev/null
then
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

# Install pre-commit
brew install pre-commit

# Install clang-format
brew install clang-format

# Install llvm (includes clang-tidy)
brew install llvm

# Install oclint
brew install oclint

# Install uncrustify
brew install uncrustify

# Install cppcheck
brew install cppcheck

# Install cpplint
pip install --user cpplint

# Install include-what-you-use
brew install include-what-you-use

echo "All tools installed successfully"
