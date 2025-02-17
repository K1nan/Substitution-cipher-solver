# Substitution Cipher Decryption

This is a part of the **DD2520 Applied Cryptography** course. It is a simple **Substitution Cipher Decryption** program written in C++. The program takes an encrypted text from a file (`ct.txt`), applies a predefined substitution mapping, and outputs the decrypted text to another file (`dt.txt`).

## How It Works

1. The program reads an encrypted text from `ct.txt`.
2. It uses a predefined character mapping to replace characters with their corresponding plaintext equivalents.
3. Special cases:
   - `_` (underscore) is replaced with a space.
   - `#` (hash) is replaced with a newline.
   - Characters not in the mapping remain unchanged.
4. The decrypted text is then saved into `dt.txt`.

