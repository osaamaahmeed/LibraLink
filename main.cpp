#include<bits/stdc++.h>
using namespace std;

class Book {
public:
  string title;
  string author;
  int publishYear;
  Book *next;
  Book *prev;

Book () {
    title  = "";
    author = "";
    publishYear = -1;
    next   = NULL;
    prev   = NULL;
}

Book (string t, string a, int year) {
    title = t;
    author = a;
    publishYear = year;
    next = NULL;
    prev = NULL;
}

};

class Library {

Book *head;

public:
Library() {
  head = NULL;
}

// Add Functions
void addBookToHead(string title, string author, int publishYear) {
    Book* b = new Book(title, author, publishYear);
    if(head == NULL) {
      head = b;
    } else {
      head->prev = b;
      b->next = head;
      head = head->prev;
    }
}

void addBookToHead (Book *b) {
  if (head == NULL) {
    head = b;
  } else {
    head->prev = b;
    b->next = head;
    head = b;
  }
}

void addBookToTail (string title, string author, int publishYear) {
  Book *b = new Book(title, author, publishYear);
  if (head == NULL) {
    head = b;
  } else {
    Book *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    b->prev = temp;
    temp->next = b;
  }
}

void addBookToTail (Book *b) {
  if (head == NULL) {
    head = b;
  } else {
    Book *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    b->prev = temp;
    temp->next = b;
  }
}

void addBookToPos (Book *b, int index) {
  if (index != 1 && countBook() < index) {
    cout << "Invalid Index !\n";
    return;
  }
  
  if (countBook() == index) {
    addBookToTail(b);
  } else if (index == 1) {
    addBookToHead(b);
  } else {
    Book *temp = head;
    int i = 1;
    while (temp != NULL && i < index) {
      temp = temp->next;
      i++;
    }
      b->next = temp;
      b->prev = temp->prev;
      temp->prev->next = b;
      temp->prev = b;
    }
}

void addBookToPos (string title, string author, int publishYear, int index) {
    if (index != 1 && countBook() < index) {
    cout << "Invalid Index !\n";
    return;
  }
  Book *b = new Book(title,author,publishYear);
  if (countBook() == index) {
    addBookToTail(b);
  } else if (index == 1) {
    addBookToHead(b);
  } else {
    Book *temp = head;
    int i = 1;
    while (temp != NULL && i < index) {
      temp = temp->next;
      i++;
    }
      b->next = temp;
      b->prev = temp->prev;
      temp->prev->next = b;
      temp->prev = b;
    }
}

// Remove Functions
void removeFromHead () {
  if (head == NULL) {cout << "Library is already empty !\n";}
  else {
    Book *temp = head;
    if (head->next == NULL) {
      head = NULL;
    } else {
      head = head->next;
      head->prev = NULL;
    }
    cout << "Deleted Book: \nTitle: " << temp->title << ", Author: " << temp->author; 
    delete temp;
  }
}

void removeFromTail () {
  if (head == NULL) {cout << "Library is already empty !\n";}
  else {
    Book *temp = head;
    if (head->next == NULL) {
      delete head;
      head = NULL;
    } else {
      while (temp->next != NULL) {
        temp = temp->next;
      }
      // Book *temp2 = temp->prev;
      // temp2->next = NULL;
      temp->prev->next = NULL;
    }
    cout << "Deleted Book: \nTitle: " << temp->title << ", Author: " << temp->author << ", Publish Year: " << temp->publishYear; 
    delete temp;
  }
}

void removeBookByIndex (int index) {
  if (head == NULL) {
    cout << "Library is already empty !\n";
  } else {
    if (countBook() < index) {
      cout << "Index out of range !\n";
    } else {
      if (index == 1) {
        head = NULL;
      } else if (countBook() == index) {
        removeFromTail();
      } else {
        int i = 1;
        Book *temp = head;
        while (i < index-1 && temp != NULL) {
          temp = temp->next;
          i++;
        }
        Book *deleteptr = temp->next;
        temp->next = deleteptr->next;
        deleteptr->next->prev = temp;
        delete deleteptr;
      }
    }
  //   if (i < index) cout << "Invalid Index Number\n";
  //   else {
  //   if (temp->next == NULL) {
  //     temp->prev->next = NULL;
  //   } else if (temp == head) {
  //     head->next->prev = NULL;
  //     head = head->next;
  //   } else {
  //     temp->next->prev = temp->prev;
  //     temp->prev->next = temp->next;
  //   }
  //   delete temp;
  // }
  }
}

void removeBook (Book *b) {
  if (head == NULL) cout << "Library is already Empty !\n";
  else {
    Book *temp = head;
    while (temp != NULL && !isEqual(temp, b)) {
      temp = temp->next;
    }
    
    if (temp == NULL) {
      cout << "Book not Found\n";
      return;
    }

    if (temp == head) {
      removeFromHead();
    } else if (temp->next == NULL) {
      removeFromTail();
    } else {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
    delete temp;
  }
}

void clear () {
  while(head != NULL){
    removeFromHead();
  }
  head = NULL;
}

// Search Functions
void searchByPublishYear (int year) {
  Book *temp = head;
  cout << "Books with Publish Year: " << year << "\n";
  while (temp != NULL) {
    if (temp->publishYear == year) {
      cout << temp->title << ", " << temp->author << "\n";
    }
    temp = temp->next;
  }
}

void searchByAuthor (string author) {
  Book *temp = head;
  cout << "Books with Author Name: " << author << "\n";
  while (temp != NULL) {
    if (temp->author == author) {
      cout << temp->title << ", " <<  temp->publishYear << "\n";
    }
    temp = temp->next;
  }
}

void searchByTitle (string title) {
  Book *temp = head;
  cout << "Books with Title: " << title << "\n";
  while (temp != NULL) {
    if (temp->title == title) {
      cout << temp->author << ", " << temp->publishYear << "\n";
    }
    temp = temp->next;
  }
}

// Sort Functions
void sortByPublishYear () {
  Book *b = head;
  while (b -> next != NULL) {
    Book *minB = b->next;
    while (minB != NULL) {
      if (minB->publishYear < b->publishYear) {
        swapBooks(*minB, *b);
      }
      minB = minB->next;
    }
    b = b->next;
  }
}

void reverseSortByPublishYear () {
  Book *b = head;
  while (b -> next != NULL) {
    Book *minB = b->next; 
    while (minB != NULL) {
      if (minB->publishYear > b->publishYear) {
        swapBooks(*minB, *b);
      }
      minB = minB->next;
    }
    b = b->next;
  }
}


void sortByAuthor () {
  Book *b = head;
  while (b != NULL) {
    Book *temp = b->next;
    while (temp != NULL) {
      /*
      if (b->author.size() > temp->author.size()) {
        swapBooks(*temp, *b);
      } else if (b->author.size() == temp->author.size()) {
        // int i = 0;
        // for (; i < min(b->author.size(),temp->author.size()); i++) {
        //   char c1 = b->author[i] < 97 ? b->author[i]+32 : b->author[i];
        //   char c2 = temp->author[i] < 97 ? temp->author[i]+32 : temp->author[i];
        //   cout << c1 << " " << c2 << "\n";
        //   if (c1 > c2) {
        //     swapBooks(*temp, *b);
        //     break;
        //   } if (c1 < c2) {
        //     break;
        //   }
        // }
        // if (b->author.size() > i) {
        //     swapBooks(*b,*temp);
        // }
        
        // string s1 = tolower();
        // string s2 = ;
        */
        if (temp->author < b->author) {
          swapBooks(*temp, *b);
        }
        temp = temp->next;
      }
      b = b->next;
    }
}

void reverseSortByAuthor () {
  Book *b = head;
  while (b != NULL) {
    Book *temp = b->next;
    while (temp != NULL) {
      /*
      if (b->author.size() > temp->author.size()) {
        swapBooks(*temp, *b);
      } else if (b->author.size() == temp->author.size()) {
        // int i = 0;
        // for (; i < min(b->author.size(),temp->author.size()); i++) {
        //   char c1 = b->author[i] < 97 ? b->author[i]+32 : b->author[i];
        //   char c2 = temp->author[i] < 97 ? temp->author[i]+32 : temp->author[i];
        //   cout << c1 << " " << c2 << "\n";
        //   if (c1 > c2) {
        //     swapBooks(*temp, *b);
        //     break;
        //   } if (c1 < c2) {
        //     break;
        //   }
        // }
        // if (b->author.size() > i) {
        //     swapBooks(*b,*temp);
        // }
        
        // string s1 = tolower();
        // string s2 = ;
        */
        if (temp->author > b->author) {
          swapBooks(*temp, *b);
        }
        temp = temp->next;
      }
      b = b->next;
    }
}


void sortByTitle () {
  Book *b = head;
  while (b != NULL) {
    Book *temp = b->next;
    while (temp != NULL) {
      /*
      if (b->author.size() > temp->author.size()) {
        swapBooks(*temp, *b);
      } else if (b->author.size() == temp->author.size()) {
        // int i = 0;
        // for (; i < min(b->author.size(),temp->author.size()); i++) {
        //   char c1 = b->author[i] < 97 ? b->author[i]+32 : b->author[i];
        //   char c2 = temp->author[i] < 97 ? temp->author[i]+32 : temp->author[i];
        //   cout << c1 << " " << c2 << "\n";
        //   if (c1 > c2) {
        //     swapBooks(*temp, *b);
        //     break;
        //   } if (c1 < c2) {
        //     break;
        //   }
        // }
        // if (b->author.size() > i) {
        //     swapBooks(*b,*temp);
        // }
        
        // string s1 = tolower();
        // string s2 = ;
        */
        if (temp->title > b->title) {
          swapBooks(*temp, *b);
        }
        temp = temp->next;
      }
      b = b->next;
    }
}

void reversesortByTitle () {
    Book *b = head;
  while (b != NULL) {
    Book *temp = b->next;
    while (temp != NULL) {
      /*
      if (b->author.size() > temp->author.size()) {
        swapBooks(*temp, *b);
      } else if (b->author.size() == temp->author.size()) {
        // int i = 0;
        // for (; i < min(b->author.size(),temp->author.size()); i++) {
        //   char c1 = b->author[i] < 97 ? b->author[i]+32 : b->author[i];
        //   char c2 = temp->author[i] < 97 ? temp->author[i]+32 : temp->author[i];
        //   cout << c1 << " " << c2 << "\n";
        //   if (c1 > c2) {
        //     swapBooks(*temp, *b);
        //     break;
        //   } if (c1 < c2) {
        //     break;
        //   }
        // }
        // if (b->author.size() > i) {
        //     swapBooks(*b,*temp);
        // }
        
        // string s1 = tolower();
        // string s2 = ;
        */
        if (temp->title < b->title) {
          swapBooks(*temp, *b);
        }
        temp = temp->next;
      }
      b = b->next;
    }
}

// Other Functions:
bool isEqual (Book *b1, Book *b2) {
  return b1->author == b2->author && b1->publishYear == b2->publishYear && b1->title == b2->title;
}

void swapBooks (Book &old, Book &n) {
  if (head == NULL || head->next == NULL) {
    cout << "Can't run this function !\n";
  } else {
      Book temp(old.title, old.author, old.publishYear);
      
      old.author = n.author;
      old.title = n.title;
      old.publishYear = n.publishYear;

      n.title = temp.title;
      n.author = temp.author;
      n.publishYear = temp.publishYear;
  }
}

void displayBooks () {
  Book *b = head;
  cout << "Books in Library: \n";
  while (b != NULL) {
    cout << b->title << ", " << b->author << ", " << b->publishYear << "\n";
    b = b->next;
  }
}

void reverseDisplay () {
  Book *b = head;
  cout << "Books in Library: \n";
  while (b->next != NULL) {
    b = b->next;
  }
  while (b != NULL) {
    cout << b->title << ", " << b->author << ", " << b->publishYear << "\n";
    b = b->prev;
  }
}

int countBook () {
  Book *temp = head;
  int size = 0;
  while (temp != NULL) {
    size++;
    temp = temp->next;
  }
  return size;
}

~Library () {
  // Book *temp = head;
  // while (temp != NULL) {
  //   
  //   delete temp;
  // }

    while(head != NULL){
      removeFromHead();
    }
    head = NULL;

    // head = head->next;
    // while (head != NULL) {
    //   delete head->prev;
    //   head = head->next;
    // }
    // head = NULL;
}

};

// 26/7=

int main() {
  Book *b1 = new Book("Atomic", "Osama", 123);
  Book *b2 = new Book("Habits", "Ahmed", 321);
  Book *b3 = new Book("Power", "Shahd", 456);
  Book *b4 = new Book("Amareta", "Sama", 114);
  Book *b5 = new Book("Amareta", "Ritsu", 114);
  Book *b6 = new Book("Amareta", "Sherry", 114);
  Book *b7 = new Book("Amareta", "Mariam", 114);
  // Book *b5 = new Book("AAAA", "EE", 114);
  Library lb;
  lb.addBookToTail(b1);
  lb.addBookToTail(b2);
  lb.addBookToTail(b3);
  lb.addBookToTail(b4);
  lb.addBookToTail(b5);
  lb.addBookToTail(b6);
  lb.addBookToTail(b7);
  lb.sortByAuthor();
  lb.displayBooks();
  cout << "=======================\n";
  lb.reverseSortByAuthor();
  lb.displayBooks();
  
}