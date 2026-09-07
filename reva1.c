#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 10
#define MAX_INPUT 1000

typedef struct
{
    char **lines;
    int count;
    int capacity;
} Document;


/* Initialize document */
void initializeDocument(Document *doc)
{
    doc->count = 0;
    doc->capacity = INITIAL_CAPACITY;

    doc->lines = malloc(doc->capacity * sizeof(char *));

    if (doc->lines == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}


/* Increase array size */
void resizeDocument(Document *doc)
{
    doc->capacity *= 2;

    char **temp = realloc(
        doc->lines,
        doc->capacity * sizeof(char *)
    );

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    doc->lines = temp;
}


/* Insert a line */
void insertLine(Document *doc, int lineNumber, char *text)
{
    if (lineNumber < 1 || lineNumber > doc->count + 1)
    {
        printf("Invalid line number.\n");
        printf("Valid range: 1 to %d\n", doc->count + 1);
        return;
    }

    /* Resize if array is full */
    if (doc->count == doc->capacity)
    {
        resizeDocument(doc);
    }

    /* Shift lines downward */
    for (int i = doc->count; i >= lineNumber; i--)
    {
        doc->lines[i] = doc->lines[i - 1];
    }

    /* Allocate memory for new line */
    doc->lines[lineNumber - 1] =
        malloc(strlen(text) + 1);

    if (doc->lines[lineNumber - 1] == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(doc->lines[lineNumber - 1], text);

    doc->count++;

    printf("Line inserted successfully.\n");
}


/* Delete a line */
void deleteLine(Document *doc, int lineNumber)
{
    if (doc->count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > doc->count)
    {
        printf("Invalid line number.\n");
        printf("Valid range: 1 to %d\n", doc->count);
        return;
    }

    /* Free deleted line */
    free(doc->lines[lineNumber - 1]);

    /* Shift lines upward */
    for (int i = lineNumber - 1;
         i < doc->count - 1;
         i++)
    {
        doc->lines[i] = doc->lines[i + 1];
    }

    doc->count--;

    printf("Line deleted successfully.\n");
}


/* Display document */
void displayDocument(Document *doc)
{
    if (doc->count == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n========== DOCUMENT ==========\n");

    for (int i = 0; i < doc->count; i++)
    {
        printf("%d  %s\n",
               i + 1,
               doc->lines[i]);
    }

    printf("==============================\n");
}


/* Save document */
void saveFile(Document *doc, char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    for (int i = 0; i < doc->count; i++)
    {
        fprintf(file, "%s\n", doc->lines[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}


/* Load document */
void loadFile(Document *doc, char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    /* Delete current document */
    for (int i = 0; i < doc->count; i++)
    {
        free(doc->lines[i]);
    }

    doc->count = 0;

    char buffer[MAX_INPUT];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        /* Remove newline */
        buffer[strcspn(buffer, "\n")] = '\0';

        if (doc->count == doc->capacity)
        {
            resizeDocument(doc);
        }

        doc->lines[doc->count] =
            malloc(strlen(buffer) + 1);

        if (doc->lines[doc->count] == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        strcpy(doc->lines[doc->count], buffer);

        doc->count++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}


/* Search text */
void searchText(Document *doc, char *text)
{
    int found = 0;

    for (int i = 0; i < doc->count; i++)
    {
        if (strstr(doc->lines[i], text) != NULL)
        {
            printf("Found in line %d: %s\n",
                   i + 1,
                   doc->lines[i]);

            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}


/* Replace text */
void replaceText(Document *doc,
                 char *oldText,
                 char *newText)
{
    int replacements = 0;

    for (int i = 0; i < doc->count; i++)
    {
        char *position;

        while ((position =
                strstr(doc->lines[i], oldText)) != NULL)
        {
            int oldLength = strlen(oldText);
            int newLength = strlen(newText);
            int currentLength = strlen(doc->lines[i]);

            int newSize =
                currentLength -
                oldLength +
                newLength +
                1;

            char *newLine = malloc(newSize);

            if (newLine == NULL)
            {
                printf("Memory allocation failed.\n");
                return;
            }

            int prefixLength =
                position - doc->lines[i];

            strncpy(
                newLine,
                doc->lines[i],
                prefixLength
            );

            newLine[prefixLength] = '\0';

            strcat(newLine, newText);

            strcat(
                newLine,
                position + oldLength
            );

            free(doc->lines[i]);

            doc->lines[i] = newLine;

            replacements++;
        }
    }

    printf("%d replacement(s) made.\n",
           replacements);
}


/* Display statistics */
void showStats(Document *doc)
{
    int words = 0;
    int characters = 0;

    for (int i = 0; i < doc->count; i++)
    {
        characters += strlen(doc->lines[i]);

        int insideWord = 0;

        for (int j = 0;
             doc->lines[i][j] != '\0';
             j++)
        {
            if (!isspace(
                    (unsigned char)doc->lines[i][j]))
            {
                if (!insideWord)
                {
                    words++;
                    insideWord = 1;
                }
            }
            else
            {
                insideWord = 0;
            }
        }
    }

    printf("\n========== STATISTICS ==========\n");
    printf("Lines      : %d\n", doc->count);
    printf("Words      : %d\n", words);
    printf("Characters : %d\n", characters);
    printf("================================\n");
}


/* Display help */
void showHelp(void)
{
    printf("\n========== HELP ==========\n");

    printf("insert <line> <text>\n");
    printf("  Example: insert 1 Hello World\n\n");

    printf("delete <line>\n");
    printf("  Example: delete 2\n\n");

    printf("display\n");
    printf("  Display all lines\n\n");

    printf("save <filename>\n");
    printf("  Example: save document.txt\n\n");

    printf("load <filename>\n");
    printf("  Example: load document.txt\n\n");

    printf("search <text>\n");
    printf("  Example: search Hello\n\n");

    printf("replace|old|new\n");
    printf("  Example: replace|Hello|Hi\n\n");

    printf("stats\n");
    printf("  Show document statistics\n\n");

    printf("help\n");
    printf("  Show commands\n\n");

    printf("quit\n");
    printf("  Exit editor\n");

    printf("==========================\n");
}


/* Free all memory */
void freeDocument(Document *doc)
{
    for (int i = 0; i < doc->count; i++)
    {
        free(doc->lines[i]);
    }

    free(doc->lines);
}


/* Main function */
int main()
{
    Document doc;

    initializeDocument(&doc);

    printf("====================================\n");
    printf("         SIMPLE LINE EDITOR\n");
    printf("====================================\n");

    printf("Type 'help' to see commands.\n");

    char input[MAX_INPUT];

    while (1)
    {
        printf("\n> ");

        if (fgets(input,
                  sizeof(input),
                  stdin) == NULL)
        {
            break;
        }

        /* Remove newline */
        input[strcspn(input, "\n")] = '\0';


        /* QUIT */
        if (strcmp(input, "quit") == 0 ||
            strcmp(input, "exit") == 0)
        {
            break;
        }


        /* HELP */
        else if (strcmp(input, "help") == 0)
        {
            showHelp();
        }


        /* DISPLAY */
        else if (strcmp(input, "display") == 0)
        {
            displayDocument(&doc);
        }


        /* STATS */
        else if (strcmp(input, "stats") == 0)
        {
            showStats(&doc);
        }


        /* INSERT */
        else if (strncmp(input, "insert ", 7) == 0)
        {
            int lineNumber;
            char text[MAX_INPUT];

            if (sscanf(
                    input + 7,
                    "%d %[^\n]",
                    &lineNumber,
                    text) == 2)
            {
                insertLine(
                    &doc,
                    lineNumber,
                    text
                );
            }
            else
            {
                printf(
                    "Usage: insert <line> <text>\n"
                );
            }
        }


        /* DELETE */
        else if (strncmp(input, "delete ", 7) == 0)
        {
            int lineNumber;

            if (sscanf(
                    input + 7,
                    "%d",
                    &lineNumber) == 1)
            {
                deleteLine(
                    &doc,
                    lineNumber
                );
            }
            else
            {
                printf(
                    "Usage: delete <line>\n"
                );
            }
        }


        /* SAVE */
        else if (strncmp(input, "save ", 5) == 0)
        {
            char filename[100];

            if (sscanf(
                    input + 5,
                    "%99s",
                    filename) == 1)
            {
                saveFile(
                    &doc,
                    filename
                );
            }
            else
            {
                printf(
                    "Usage: save <filename>\n"
                );
            }
        }


        /* LOAD */
        else if (strncmp(input, "load ", 5) == 0)
        {
            char filename[100];

            if (sscanf(
                    input + 5,
                    "%99s",
                    filename) == 1)
            {
                loadFile(
                    &doc,
                    filename
                );
            }
            else
            {
                printf(
                    "Usage: load <filename>\n"
                );
            }
        }


        /* SEARCH */
        else if (strncmp(input, "search ", 7) == 0)
        {
            char text[MAX_INPUT];

            if (sscanf(
                    input + 7,
                    "%[^\n]",
                    text) == 1)
            {
                searchText(
                    &doc,
                    text
                );
            }
            else
            {
                printf(
                    "Usage: search <text>\n"
                );
            }
        }


        /* REPLACE */
        else if (strncmp(input, "replace|", 8) == 0)
        {
            char *oldText;
            char *newText;
            char *separator;

            oldText = input + 8;

            separator = strchr(oldText, '|');

            if (separator == NULL)
            {
                printf(
                    "Usage: replace|old|new\n"
                );
                continue;
            }

            *separator = '\0';

            newText = separator + 1;

            if (strlen(oldText) == 0)
            {
                printf(
                    "Old text cannot be empty.\n"
                );
                continue;
            }

            replaceText(
                &doc,
                oldText,
                newText
            );
        }


        /* UNKNOWN COMMAND */
        else
        {
            printf("Unknown command.\n");
            printf("Type 'help' for available commands.\n");
        }
    }

    freeDocument(&doc);

    printf("Editor closed.\n");

    return 0;
}