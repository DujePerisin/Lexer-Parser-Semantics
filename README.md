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
make
bison -d kalk.y  
flex kalk.lex 
gcc -w kalk.c kalk_sym.c lex.yy.c kalk.tab.c -lm -o kalk
 ```
---

## **Running the Projects**
Each project comes with a `Makefile` for easy compilation. Example usage:

```sh
make
./kalk test.txt
 ```
