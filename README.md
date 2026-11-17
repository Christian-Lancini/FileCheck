
# FileCheck 

FileCheck is a project that allowed me to improve with C++ and to practice with cryptography.

## About

With FileCheck, you can calculate and view a file's 256-bit hash. You can also store it in a local database (db/database.txt) and check if the file has been modified.

I created this project to improve my C++ skills, practice working with header files, and apply the theoretical knowledge I had acquired to a real project.

## Technologies

This project was developed using the following technologies:

- **Language:** C++
- **Database:** A simple file .txt
- **Tools:** OpenSSL 

## Getting Started

Follow these instructions to start using FileCheck.

### Prerequisites

Make sure you have installed:

- **C++ Compiler**
- **C++11 or later**
- **OpenSSL**

### How to install OpenSSL

Ubuntu / Debian:
```bash
sudo apt update
sudo apt install build-essential libssl-dev
```

macOS (Homebrew):
```bash
brew install openssl
```

Windows:

Install OpenSSL using a package manager like [vcpkg](https://github.com/microsoft/vcpkg) or install a compatible OpenSSL distribution.
 

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Christian-Lancini/FileCheck
   ```

2. Navigate to the project directory.


3. Create the executable file (e.g. Windows)

   ```bash
   g++ src/main.cpp src/hash.cpp src/integrity.cpp -o fileCheck.exe -lcrypto
   ```

4. Run it.



## Project Structure

```text
FileCheck/
│
├── src/         
│    │─ main.cpp        # Menu
│    │─ integrity.cpp   # Record, show, comparison
│    │─ hash.cpp        # SHA-256 hashing using OpenSSL
├── db/
│    │─ database.txt    # Local database
├── include/
│    │─ hash.h          # Header
│    │─ integrity.h     # Header
├── test/
│    │─ test.txt        # Test file
├── README.md
```

## Example of use

```bash
      _____   _       ____ _               _     
     |  ___(_) | ___ / ___| |__   ___  ___| | __ 
     | |_  | | |/ _ | |   | '_ | / _ |/ __| |/ / 
     |  _| | | |  __/ |___| | | |  __/ (__|   <  
     |_|   |_|_||___||____|_| |_||___||___|_||_| 
                                            
		
      1. Calculate the hash of a file.
      2. Record a new file.
      3. Verify file integrity.
      4. View recorded files.
      5. Exit.

      Option: 1
      Enter file name: test/test.txt

      Hash: 64c66cef9bcef5f2423f51fec623d76bb1d2538ed71d5fba5111276aada148c9

```

## Future improvements

I will add an error-checking system and, if necessary, optimize/improve the project.

## Contact

**Author:** [Christian Lancini]

- GitHub: [@Christian-Lancini](https://github.com/Christian-Lancini/)
- Email: chrilanci00@gmail.com
