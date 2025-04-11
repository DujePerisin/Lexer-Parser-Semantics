# **Language Processing Projects**

This repository contains various projects related to **lexical analysis, parsing, and semantic evaluation**. The goal is to build a deeper understanding of how programming languages are interpreted and executed, with future plans to develop a **custom lexer, parser, and compiler** from scratch.

## **Overview**

### **Lexers (Lexical Analysis)**
Lexers are responsible for **breaking down raw text into meaningful tokens**. Tokens are the smallest units of meaning in a language, such as keywords, numbers, operators, and identifiers.

In my projects, I've worked with:
- **Flex (Lex)** to define token patterns using **regular expressions**.
- **Token classification** for handling keywords, operators, identifiers, and literals.
- **Error handling** for unexpected inputs.

🛠 **Future Project:** Building my own **lexer** from scratch, without relying on tools like Flex.

---

### **Parsers (Syntax Analysis)**
Parsers take the tokens from the lexer and **analyze their structure** according to a grammar. They ensure that the code follows syntactic rules.

In my projects, I've worked with:
- **Bison (Yacc)** to define grammars using **context-free rules**.
- **Operator precedence and associativity** for arithmetic and logical expressions.
- **Control structures** like loops (`while`, `for`) and branching (`if-else`, `switch-case`).
- **AST (Abstract Syntax Tree) construction** for representing the parsed code.

🛠 **Future Project:** Building my own **parser** without relying on Bison/Yacc, implementing a **recursive descent** or **LR parser** manually.

---

### **Semantic Analysis & Execution**
After parsing, the program needs to be evaluated. Semantic analysis ensures that the parsed code **makes sense** beyond just following syntax. This includes:
- **Symbol table management** for variable storage.
- **Expression evaluation** using an **AST-based interpreter**.
- **Custom error handling** for undefined variables, type mismatches, and division by zero.

🛠 **Future Project:** Building a **full compiler** that translates parsed code into a lower-level representation (possibly **bytecode** or **assembly**).

---

## **Future Roadmap**
✅ **Phase 1:** Develop a **custom lexer** (manual tokenization).  
✅ **Phase 2:** Implement a **custom parser** (manual AST construction).  
✅ **Phase 3:** Build a **complete compiler** (generating low-level code).  

---
## **Building the Projects**
Each project will be built using a variation of these commands (most often the gcc is the one with the most variations). Example usage:

```sh
bison -d kalk.y  
flex kalk.lex 
gcc -w kalk.c kalk_sym.c lex.yy.c kalk.tab.c -lm -o kalk
 ```
---

## **Running the Projects**
Each project comes with a `Makefile` for easy compilation. Example usage:

```sh
./kalk test.txt
 ```
---

## **Some Information about VM**
- Linux Virtual Machine at/ Oracle VirtualBox
- Ubuntu 22
- VM uses 1GB RAM-a & 10GB disc space

## **COOL Lexer (located in lexer folder)**

This project implements a **lexer** for the [COOL programming language](https://theory.stanford.edu/people/aiken/cool/), using **Flex** (Fast Lexical Analyzer Generator). The lexer is designed to recognize all standard COOL tokens, handle nested comments, string constants, and edge cases such as invalid or unterminated strings.

## 📄 Overview

The lexer processes input from a file and tokenizes it according to COOL's lexical structure. It supports:

- Keywords and identifiers
- Type and object IDs
- Integer and boolean constants
- Complex string constants
- Multi-line and nested comments
- Error handling for malformed input

## 🗂️ Files Overview

 **cool.flex =>**
Flex source file containing the lexical specification for the COOL programming language. This is the core file where you define patterns for tokens and their corresponding actions.

**test.cl =>**
A test source file written in COOL. This file is used to test the functionality of your lexer. You can modify this file to include custom test cases and edge conditions.

**cool-parse.h =>**
A header file that contains shared definitions used throughout the compiler. Provides essential constants and types for integration between different stages of the compiler.

**stringtab.cc, stringtab.h, stringtab_functions.h =>**
Source and header files for managing string tables in the compiler. These modules provide utility functions for handling string constants.

**utilities.cc, utilities.h =>**
A collection of utility functions, including helper methods like strdup() which are used within the lexer infrastructure.

**lextest.cc =>**
Main entry point for running the lexer. It initializes the lexer, processes input, and prints out the tokens generated.

**cool-lex.cc =>**
Auto-generated file created by Flex from cool.flex. It contains the compiled C++ code implementing the lexer logic.

Testing script that verifies the correctness of your lexer. It compares actual output against expected results and assigns a score based on performance. Check out all the test files located in test_files directory

## 🚀 Features

- **Token recognition** for all COOL constructs (`CLASS`, `IF`, `FI`, `LET`, etc.)
- **Case-insensitive matching** for keywords
- **Multiline and nested comments** handling
- **String constant parsing** with support for:
  - Valid escape sequences: `\n`, `\t`, `\\`, `\"`, etc.
  - Line continuation using `\` at the end of a line
  - Error detection for:
    - Unterminated strings
    - Null characters in strings
    - Strings exceeding 1024 characters
- **Graceful error reporting** with detailed messages
