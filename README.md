# line_editor
# Simple Line Editor in C

A simple command-line text editor developed in **C** as part of the **Portfolio Building — Studio Course 3rd Semester Coding Competition**.

The editor works entirely through the terminal and allows users to create, view, and modify a small text document using line-based commands.

## Team Members

* CHARAN M - R25EJ023
* Kiran Raj C N - R25EJ055
* Karibasavaraja - R25EJ050

## Features Implemented

### Core Features

1. **Insert a Line**

   * Adds a new line of text at a specified line number.
   * Existing lines are shifted down.

2. **Delete a Line**

   * Deletes a line at the specified line number.
   * Remaining lines are shifted up.

3. **Display the Document**

   * Displays all current lines along with their line numbers.

4. **Save / Load a File**

   * Saves the document to a `.txt` file.
   * Loads a previously saved text file into the editor.

### Bonus Features

5. **Search**

   * Searches for a word or phrase in the document.
   * Displays the line number where the text is found.

6. **Find and Replace**

   * Replaces a word or phrase in a selected line or throughout the document.

7. **Line Count / Word Count**

   * Displays the total number of lines and words in the document.

## Data Structure

The editor stores document lines using an **array of strings**.

### Why an Array of Strings?

An array of strings is simple to implement and provides easy access to individual lines using their line numbers. It is suitable for this competition because the editor is designed to handle a small text document.

## Commands

| Command   | Description                 |
| --------- | --------------------------- |
| `insert`  | Insert a new line           |
| `delete`  | Delete a line               |
| `display` | Display the document        |
| `save`    | Save the document to a file |
| `load`    | Load a document from a file |
| `search`  | Search for a word or phrase |
| `replace` | Find and replace text       |
| `count`   | Display line and word count |
| `help`    | Display available commands  |
| `exit`    | Exit the editor             |

## How to Compile

Make sure **GCC** is installed.

Open the terminal in the project directory and run:

```bash
gcc line_editor.c -o line_editor
```

## How to Run

After successful compilation, run:

```bash
./line_editor
```

## Example

```text
Simple Line Editor

> insert
Enter line number: 1
Enter text: Hello World

> insert
Enter line number: 2
Enter text: This is my first document.

> display

1. Hello World
2. This is my first document.

> delete
Enter line number: 1

> display

1. This is my first document.

> exit
```

## Error Handling

The editor handles basic invalid inputs such as:

* Invalid line numbers
* Deleting from an empty document
* Inserting outside the valid range
* File opening errors
* Empty documents

## Project Structure

```text
line_editor/
│
├── line_editor.c
├── README.md
├── HELP.md
└── document.txt
```

## Requirements

* C Compiler (GCC)
* Terminal / Command Line
* VS Code or any C-compatible editor

## Competition Requirements

This project was created according to the **Build a Simple Line Editor in C** problem statement.

The project includes:

* Paper design
* Working C project
* Help file
* README
* GitHub repository

The editor is designed to compile cleanly using GCC and run entirely from the terminal.

## Conclusion

The Simple Line Editor demonstrates basic C programming concepts including arrays, strings, functions, file handling, loops, conditional statements, and command-line input processing.
