# Password Generator & Text Encrypter

A robust and versatile password generator and text encryption tool implemented in both C and a web-based stack (HTML, CSS, JavaScript). This project demonstrates cryptographically-inspired random number generation and classic encryption algorithms, offering both command-line and browser-friendly interfaces for security enthusiasts and developers.

## Features

- **Password Generator**
  - Generates strong, secure passwords.
  - Supports multiple random number generation algorithms:
    - **Blum Blum Shub (BBS)**
    - **Linear Congruential Generation (LCG)**

- **Text Encryption & Decryption**
  - Supports classic cryptography algorithms:
    - **Vigenère Cipher**
    - **Caesar Cipher**
  - Both encryption and decryption modes are available.

- **Cross-Platform**
  - **C Version:** Fast, lightweight CLI application for desktops.
  - **Web Version:** Convenient, intuitive, and responsive UI using HTML, CSS, and JavaScript.

## Technologies Used

- **C**: For fast command-line binaries.
- **HTML/CSS/JavaScript**: For easy access and a visual (UI) approach.

## Algorithms Implemented

| Algorithm                      | Purpose                                     |
|-------------------------------|---------------------------------------------|
| Blum Blum Shub (BBS)          | Cryptographically strong random generation  |
| Linear Congruential Generator | Basic pseudo-random number generation       |
| Vigenère Cipher               | Classical polyalphabetic text encryption    |
| Caesar Cipher                 | Simple monoalphabetic text encryption       |

## Usage

- **Compile and run the C version:**
  - Generate passwords using BBS or LCG.
  - Encrypt/decrypt text using Vigenère or Caesar ciphers.

- **Or use the Web version:**
  - Open in any modern browser.
  - User-friendly forms for password generation and secure text encryption/decryption.

## Motivation

This project was created to:

- Learn and demonstrate core concepts of PRNG and classical encryption.
- Compare implementation differences between system-level (C) and web (JS) coding.
- Provide a practical tool for generating passwords and securing text.

Contributions, feature suggestions, and feedback are always welcome!
