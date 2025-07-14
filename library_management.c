#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define FILENAME "library.txt"

typedef struct
{
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
} Book;

void add_book();
void view_books();
void delete_book();
void modify_book();
void search_book();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Delete Book\n");
        printf("4. Modify Book\n");
        printf("5. Search Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice)
        {
        case 1:
            add_book();
            break;
        case 2:
            view_books();
            break;
        case 3:
            delete_book();
            break;
        case 4:
            modify_book();
            break;
        case 5:
            search_book();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}

void add_book()
{
    FILE *fp = fopen(FILENAME, "a");
    Book book;

    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    getchar();
    printf("Enter Title: ");
    fgets(book.title, MAX_TITLE, stdin);
    book.title[strcspn(book.title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(book.author, MAX_AUTHOR, stdin);
    book.author[strcspn(book.author, "\n")] = 0;

    fwrite(&book, sizeof(Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

void view_books()
{
    FILE *fp = fopen(FILENAME, "r");
    Book book;

    printf("\n--- Book List ---\n");
    while (fread(&book, sizeof(Book), 1, fp))
    {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n---\n", book.id, book.title, book.author);
    }
    fclose(fp);
}

void delete_book()
{
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    Book book;
    int id, found = 0;

    printf("Enter ID of the book to delete: ");
    scanf("%d", &id);

    while (fread(&book, sizeof(Book), 1, fp))
    {
        if (book.id != id)
        {
            fwrite(&book, sizeof(Book), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
        printf("Book deleted successfully!\n");
    else
        printf("Book not found.\n");
}

void modify_book()
{
    FILE *fp = fopen(FILENAME, "r+");
    Book book;
    int id, found = 0;

    printf("Enter ID of the book to modify: ");
    scanf("%d", &id);
    getchar();

    while (fread(&book, sizeof(Book), 1, fp))
    {
        if (book.id == id)
        {
            found = 1;
            printf("Enter new Title: ");
            fgets(book.title, MAX_TITLE, stdin);
            book.title[strcspn(book.title, "\n")] = 0;
            printf("Enter new Author: ");
            fgets(book.author, MAX_AUTHOR, stdin);
            book.author[strcspn(book.author, "\n")] = 0;

            fseek(fp, -sizeof(Book), SEEK_CUR);
            fwrite(&book, sizeof(Book), 1, fp);
            printf("Book modified successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(fp);
}

void search_book()
{
    FILE *fp = fopen(FILENAME, "r");
    Book book;
    char keyword[MAX_TITLE];
    int found = 0;

    printf("Enter title or author to search: ");
    getchar();
    fgets(keyword, MAX_TITLE, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    while (fread(&book, sizeof(Book), 1, fp))
    {
        if (strstr(book.title, keyword) || strstr(book.author, keyword))
        {
            printf("\nID: %d\nTitle: %s\nAuthor: %s\n---\n", book.id, book.title, book.author);
            found = 1;
        }
    }

    if (!found)
        printf("No matching books found.\n");

    fclose(fp);
}
