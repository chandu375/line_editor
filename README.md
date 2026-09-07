📝 Simple Line Editor in C

A Simple Line Editor is a command-line text editor developed in C programming language as part of the Portfolio Building — Studio Course, 3rd Semester Coding Competition.

The editor works entirely through the terminal and allows users to create, view, modify, search, and save a small text document using simple line-based commands.

👥 Team Members
Name	USN / ID
CHARAN M	R25EJ023
Kiran Raj C N	R25EJ055
Karibasavaraja	R25EJ050
🎯 Project Objective

The main objective of this project is to develop a simple and efficient text editor using C that demonstrates fundamental programming concepts such as:

Arrays and strings
Functions
Loops and conditional statements
File handling
Dynamic text manipulation
Searching and replacing text
Command-line input processing
Error handling

The project provides practical experience in designing and implementing a real-world command-line application.

✨ Features
Core Features
1. Insert a Line
Adds a new line at a specified line number.
Existing lines are automatically shifted down.
Supports insertion at the beginning, middle, or end of the document.
2. Delete a Line
Deletes a line using its line number.
Remaining lines are shifted upward.
Prevents deletion when the document is empty.
3. Display Document
Displays all lines currently stored in the document.
Each line is displayed with its corresponding line number.
4. Save File
Saves the current document into a .txt file.
Handles file-opening errors.
5. Load File
Loads an existing text file into the editor.
Replaces the current document with the contents of the selected file.
🚀 Bonus Features
6. Search

Searches for a particular word or phrase throughout the document.

Example:

> search
Enter text to search: World

Found "World" in line 1.

7. Find and Replace

Finds a word or phrase and replaces it with new text.

The replacement can be performed:

In a selected line
Throughout the entire document

Example:

> replace
Enter text to find: Hello
Enter replacement text: Hi

Replacement completed successfully.

8. Line Count / Word Count

Displays useful statistics about the document.

Example:

Total Lines: 5
Total Words: 27

💻 Available Commands
Command	Description
insert	Insert a new line
delete	Delete a line
display	Display the document
save	Save the document to a file
load	Load a document from a file
search	Search for a word or phrase
replace	Find and replace text
count	Display line and word count
help	Display available commands
exit	Exit the editor
🏗️ Data Structure

The editor stores document lines using an array of strings.

Conceptually, the document is represented as:

document[0] → First line
document[1] → Second line
document[2] → Third line
...

Why an Array of Strings?

An array of strings was selected because:

It is simple to understand and implement.
Individual lines can be accessed easily using an index.
Insertion and deletion operations can be implemented using shifting.
It is suitable for handling small text documents.
It demonstrates fundamental C array and string concepts.

For a small educational project, this approach provides a good balance between simplicity and functionality.

⚙️ How the Editor Works

The editor follows a command-based approach.

Basic Workflow
Start Program
     │
     ▼
Display Command Prompt
     │
     ▼
Read User Command
     │
     ├── insert ──► Insert Line
     │
     ├── delete ──► Delete Line
     │
     ├── display ─► Display Document
     │
     ├── save ────► Save File
     │
     ├── load ────► Load File
     │
     ├── search ──► Search Text
     │
     ├── replace ─► Replace Text
     │
     ├── count ───► Count Lines/Words
     │
     ├── help ────► Show Commands
     │
     └── exit ────► Terminate Program


The program continues accepting commands until the user selects exit.

🧩 Algorithm
Insert Operation
Read the required line number.
Validate the line number.
Shift existing lines downward.
Read the new line of text.
Store the text at the selected position.
Increase the total line count.
Delete Operation
Check whether the document is empty.
Read the line number.
Validate the line number.
Shift all lines after the selected line upward.
Decrease the total line count.
Search Operation
Read the search text.
Check every line in the document.
Compare the search text with each line.
Display the line number whenever a match is found.
Replace Operation
Read the text to find.
Read the replacement text.
Search the document for matching text.
Replace the matching text.
Display the number of replacements made.
Save Operation
Open the specified file in write mode.
Write every document line to the file.
Close the file.
Display a success or error message.
Load Operation
Open the specified file in read mode.
Clear the current document.
Read the file line by line.
Store each line in the document array.
Close the file.
🖥️ Example Usage
Starting the Editor
Simple Line Editor
Type 'help' to see available commands.

> help

Available Commands:
insert
delete
display
save
load
search
replace
count
help
exit

Inserting Lines
> insert

Enter line number: 1
Enter text: Hello World

Line inserted successfully.

> insert

Enter line number: 2
Enter text: This is my first document.

Line inserted successfully.

Displaying the Document
> display

1. Hello World
2. This is my first document.

Searching
> search

Enter text to search: World

Found "World" in line 1.

Counting
> count

Total Lines: 2
Total Words: 6

Deleting a Line
> delete

Enter line number: 1

Line deleted successfully.

Final Document
> display

1. This is my first document.

Exiting
> exit

Thank you for using Simple Line Editor!

🛡️ Error Handling

The application handles common invalid inputs and file-related errors.

Examples include:

Invalid line numbers
Inserting outside the valid range
Deleting from an empty document
Searching an empty document
Loading a file that does not exist
File-opening errors
Empty documents
Invalid commands
Exceeding the maximum document capacity

Example:

> delete

Error: Cannot delete a line because the document is empty.


Another example:

> insert

Enter line number: 10

Error: Invalid line number.

🛠️ Technologies Used
Technology	Purpose
C Programming	Main programming language
GCC	Compilation
File Handling	Saving and loading documents
Arrays	Storing document lines
Strings	Managing text
Terminal / Command Line	User interface
VS Code	Development environment
📁 Project Structure
line_editor/
│
├── line_editor.c       # Main C source code
├── README.md           # Project documentation
├── HELP.md             # Detailed command help
└── document.txt        # Sample text document

📋 Requirements

Before running the project, make sure you have:

A C compiler such as GCC
Terminal / Command Prompt
VS Code or another C-compatible IDE
Basic knowledge of C programming
🔧 Compilation

Open a terminal inside the project directory and run:

gcc line_editor.c -o line_editor


If compilation is successful, an executable named line_editor will be created.

For stricter compilation and warnings, you can also use:

gcc -Wall -Wextra -o line_editor line_editor.c

▶️ Running the Program
Linux / macOS
./line_editor

Windows
line_editor.exe

📄 File Handling

The editor supports .txt files for storing documents.

For example:

document.txt


A saved document may contain:

Hello World
This is my first document.
C programming is interesting.


The save command writes the current document to a file, while the load command reads an existing file into the editor.

🧪 Testing

The following test cases can be used to verify the functionality of the editor:

Test Case	Expected Result
Insert into empty document	Line is added successfully
Insert at beginning	Existing lines shift down
Insert in middle	Existing lines shift down
Insert at end	New line is added
Delete existing line	Selected line is removed
Delete from empty document	Error message displayed
Display empty document	Appropriate empty-document message
Search existing text	Matching line numbers displayed
Search unavailable text	No-match message displayed
Replace existing text	Text replaced successfully
Save document	File created/updated
Load existing file	File contents displayed
Load unavailable file	File error displayed
Count lines and words	Correct counts displayed
Invalid command	Help/error message displayed
📸 Screenshots

Screenshots of the running application can be added here.

Recommended screenshots:

Main editor screen
Insert operation
Display operation
Search operation
Find and replace operation
Save/load operation
Count operation

Example:

screenshots/
├── main-menu.png
├── insert.png
├── display.png
├── search.png
├── replace.png
└── save-load.png

🎓 Learning Outcomes

Through this project, the team gained practical experience in:

Writing modular C programs
Working with arrays and strings
Implementing functions
Performing file input/output
Handling user input
Implementing search algorithms
Manipulating text
Designing command-line applications
Debugging and testing C programs
Using Git/GitHub for project management
🔮 Future Enhancements

The project can be extended with several additional features:

Undo and redo operations
Multiple document support
Dynamic memory allocation
Line editing instead of only insertion/deletion
Syntax highlighting
Case-insensitive search
Regular-expression search
Automatic backup
More advanced text formatting
Keyboard shortcuts
Improved command-line interface
Linked-list-based document storage for larger files
🏆 Competition Requirements

This project was developed according to the "Build a Simple Line Editor in C" problem statement.

The project includes:

✅ Paper design
✅ Working C implementation
✅ Help file
✅ README documentation
✅ GitHub repository
✅ Core editor operations
✅ File handling
✅ Search functionality
✅ Find and replace
✅ Line and word counting
✅ Error handling
📌 Project Highlights

The Simple Line Editor demonstrates how fundamental C programming concepts can be combined to build a practical command-line application.

Instead of using an existing text-editing library, the project implements the core functionality manually using arrays, strings, loops, functions, and file handling.

This makes the project useful for understanding how basic text editors work internally while strengthening fundamental programming skills.

👨‍💻 Team

CHARAN M — R25EJ023
Kiran Raj C N — R25EJ055
Karibasavaraja — R25EJ050

Portfolio Building — Studio Course
3rd Semester Coding Competition

📜 Conclusion

The Simple Line Editor in C is an educational command-line text editor that demonstrates fundamental concepts of C programming and file management.

The project successfully implements essential text-editing operations such as inserting, deleting, displaying, searching, replacing, saving, and loading text.

It provides a strong foundation for understanding data structures, string manipulation, file handling, and modular programming, while also serving as a practical portfolio project.

⭐ Acknowledgement

We would like to express our gratitude to our faculty and mentors for providing us with the opportunity to work on this project as part of the Portfolio Building — Studio Course.

This project helped us improve our programming, problem-solving, teamwork, and software development skills.

Made with C 💻 | Built for Learning 🚀
