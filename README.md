# **Language Processing Projects**

This repository contains various projects related to **lexical analysis, parsing, and semantic evaluation**. The goal is to build a deeper understanding of how programming languages are interpreted and executed, with future plans to develop a **custom lexer, parser, and compiler** from scratch.

## **Overview**

### **Lexers (Lexical Analysis)**
Lexers are responsible for **breaking down raw text into meaningful tokens**. Tokens are the smallest units of meaning in a language, such as keywords, numbers, operators, and identifiers.

In my projects, I've worked with:
- **Flex (Lex)** to define token patterns using **regular expressions**.
- **Token classification** for handling keywords, operators, identifiers, and literals.
- **Error handling** for unexpected inputs.

✅ **Completed Project:** Building my own **lexer** from scratch.

---

### **Parsers (Syntax Analysis)**
Parsers take the tokens from the lexer and **analyze their structure** according to a grammar. They ensure that the code follows syntactic rules.

In my projects, I've worked with:
- **Bison (Yacc)** to define grammars using **context-free rules**.
- **Operator precedence and associativity** for arithmetic and logical expressions.
- **Control structures** like loops (`while`, `for`) and branching (`if-else`, `switch-case`).
- **AST (Abstract Syntax Tree) construction** for representing the parsed code.

✅ **Completed Project:** Building my own **parser** from scratch.

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
❌ **Phase 3:** Develop a **custom semanter**  (analyse semantic and syntax values).  
❌ **Phase 4:** Develop a **custom code generator**  (balance between corectness and speed of execution).  

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

Testing script that verifies the correctness of your lexer. It compares actual output against expected results and assigns a score based on performance. Check out [all the test files](https://drive.google.com/drive/folders/1V2Bg05z747DW2gsZLgBb7v-oxeIpjzhl?usp=sharing/) located on my google drive (ask for permission).

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


## **COOL Parser (located in the parser folder)**

This project implements a parser for the [COOL programming language](https://theory.stanford.edu/people/aiken/cool/), using **Bison** (GNU parser generator). The parser analyzes COOL syntax and builds an abstract syntax tree (AST), enabling further semantic analysis and code generation phases in the compiler pipeline.

## 📄 Overview

The parser consumes a stream of tokens generated by the COOL lexer and organizes them according to COOL’s grammar. It produces an AST that reflects the hierarchical structure of valid COOL programs. The parser also incorporates error handling mechanisms and line tracking for precise diagnostics.

It supports:

   - Full COOL grammar:
        - Class declarations with optional inheritance
        - Features (methods and attributes)
        - Let, case, loop, and dispatch expressions
        - Conditional branching (if-then-else-fi)
        - Operator precedence (arithmetic, comparison, etc.
   - AST node construction for every language construct
   - Line number propagation for accurate error messages
   - Integration with semantic and codegen phases

## 🗂️ Files Overview

**cool.y =>**
Bison grammar file that defines the structure of the COOL parser. It includes initial productions for program and class which can be used as templates for writing the remaining grammar rules. The file compiles and runs in its initial form but does not implement full parsing behavior yet.

**good.cl/bad.cl =>**
Test source files written in COOL. good.cl contains examples of syntactically correct programs, while bad.cl includes programs with grammar errors. Use these files to verify and debug your parser.

**cool-tree.aps =>**
Source file describing the structure of the AST (Abstract Syntax Tree) in a custom DSL. This file is used to generate the cool-tree.h and cool-tree.cc files. It is provided for reference only — do not modify this file.

**cool-tree.h / cool-tree.cc =>**
Auto-generated files that define the core classes for AST nodes. Each COOL construct corresponds to a C++ class. These files should not be edited manually.

**cool-tree.handcode.h =>**
The only AST-related file that you are allowed to modify. Use it to extend class declarations and define additional methods, using hooks and extensions declared in cool-tree.h and cool-tree.cc.

**tree.h / tree.cc =>**
Support files for tree manipulation and common base functionality for AST classes. These are shared across all compiler stages. Do not modify.

**tokens-lex.cc =>**
Helper lexer that reads tokens from standard input in a format produced by the lexer stage. Used to simulate lexer output during parser testing. Do not modify.

**parser-phase.cc =>**
Driver program for testing the parser. It reads input files, invokes the parser, and handles AST construction. Do not modify.

**dumptype.cc =>**
Provides pretty-print functionality for AST nodes. Ensures that the AST is in the correct form for semantic analysis. Do not modify.

**handle_flags.cc =>**
Handles command-line flags and argument parsing for all compiler stages. Do not modify.

**cool-parse.cc =>**
Auto-generated C++ file created by Bison from cool.y. Contains the implementation of the parser. This file is regenerated on every compilation and should not be edited manually.

Other files are a by-product of Bison, like cool-parse.cc which contain C++ code of the parser generated by Bison. I have not listed description of all the files here, especially of the ones mentioned in the previous phase.

## 🚀 Features

- **AST Construction**: Builds typed nodes (class_, assign, method, cond, loop, etc.) representing the structure of COOL programs.
- **Error Recovery**: Gracefully reports syntax errors with line numbers and problematic tokens.
- **Line Tracking**: Integrates with the lexer’s curr_lineno to associate AST nodes with source locations.
- **Expression Evaluation Support**:
        - Operator precedence and associativity defined explicitly
        - Handles nested expressions and parentheses
  - **Conditional Expressions**:
        - Full support for if-then-else-fi
        - Optional else branches using no_expr() for if without else
- **Extensibility**: The grammar is modular and easy to extend with additional constructs or operators.

Testing script that verifies the correctness of your parser. It compares actual output against expected results and assigns a score based on performance. Check out [all the test files](https://drive.google.com/drive/folders/1EgAbIHfEtZwU02KttBEeTaIW-rsmjHzw) located on my google drive (ask for permission). Parser is not yet full optmized so feel free to suggest further improvments.

   
## **COOL Semantic analyzer **
   🛠 *Loading...*


