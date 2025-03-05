#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Book {
	int id;
	char title[50];
	char author[50];
};

struct Book books[MAX];
int bookCount = 0;

void addBook() {
	if(bookCount >= MAX) {
		printf("\nLibrary is full! Cannot add more books.\n");
		return;
	}
	printf("\nEnter Book ID: ");
	scanf("%d", &books[bookCount].id);
	getchar();
	printf("Enter Book Title: ");
	fgets(books[bookCount].title, sizeof(books[bookCount].title), stdin);
	strtok(books[bookCount].title, "\n");
	printf("Enter Author Name: ");
	fgets(books[bookCount].author, sizeof(books[bookCount].author), stdin);
	strtok(books[bookCount].author, "\n");
	bookCount++;
	printf("Book Added Successfully!\n");
}

void displayBooks() {
	if(bookCount == 0) {
		printf("\nNo books found\n");
		return;
	}
	printf("\nBooks in Library:\n");
	for(int i = 0; i < bookCount; i++) {
		printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
	}
}

void updateBook() {
	int id, found = 0;
	printf("\nEnter Book ID to Update: ");
	scanf("%d", &id);
	getchar();
	for(int i = 0; i < bookCount; i++) {
		if(books[i].id == id) {
			found = 1;
			printf("Enter Title Name: ");
			fgets(books[i].title, sizeof(books[i].title), stdin);
			strtok(books[i].title, "\n"); 
			printf("Enter Author Name: ");
			fgets(books[i].author, sizeof(books[i].author), stdin);
			strtok(books[i].author, "\n");
			printf("Book Updated\n");
			break;
		}
	}
	if(!found) {
		printf("Book Not Found!\n");
	}
}

void deleteBook() {
	int id, found = 0;
	printf("\nEnter Book ID to Delete: ");
	scanf("%d", &id);
	for(int i = 0; i < bookCount; i++) {
		if(books[i].id == id) {
			found = 1;
			for(int j = i; j < bookCount - 1; j++) {
				books[j] = books[j + 1];
			}
			bookCount--;
			printf("Book Deleted\n");
			break;
		}
	}
	if(!found) {
		printf("Book Not Found!\n");
	}
}

int main() {
	int choice;
	while(1) {
		printf("\nLibrary Management System\n");
		printf("1. Add Book\n");
		printf("2. Display Books\n");
		printf("3. Update Book\n");
		printf("4. Delete Book\n");
		printf("5. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		getchar();

		switch(choice) {
		case 1:
			addBook();
			break;
		case 2:
			displayBooks();
			break;
		case 3:
			updateBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			exit(0);
		default:
			printf("Invalid Choice! Try Again.\n");
		}
	}
	return 0;
}
