#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LEN (165)

class Book {
public:
    Book(const string &title,
         const string &author) {
        mTitle  = title;
        mAuthor = author;
    }

    ~Book() {
    }

    string title() const {
        return mTitle;
    }

    friend class Compare;
    
private:

    string mTitle;
    string mAuthor;
};

class Compare {
public:
    bool operator() (const Book &a, const Book &b) {
        if (a.mAuthor != b.mAuthor)
            return a.mAuthor < b.mAuthor;
        
        return a.mTitle < b.mTitle;
    }
};

int main(int argc, char **argv) {
    char line[MAX_LEN];

    set<Book, Compare> books;
    unordered_map<string, set<Book>::iterator> locate;
    while(gets(line)) {
        if (!strcmp(line, "END")) {
            break;
        } else {
            string title;
            string author;

            int pos = 1;
            while(line[pos] != '\"') {
                title += line[pos++];
            }
            
            pos += 5;
            while(line[pos] != '\0') {
                author += line[pos++];
            }
            
            Book book(title, author);
            auto itor = books.insert(book);
            locate[title] = itor.first;
        }
    }

    set<Book, Compare> borrow;
    unordered_map<string, set<Book>::iterator> pend;
    vector<Book> shelf;
    while(gets(line)) {
        if (!strncmp(line, "END", 3)) {
            break;
        } else if(!strncmp(line, "BORROW", 6)) {
            int pos = 8;
            string title;
            while(line[pos] != '\"') {
                title += line[pos++];
            }
            if (locate.find(title) != locate.end()) {
                auto itor = borrow.insert(*(locate[title]));
                pend[title] = itor.first;
                books.erase(locate[title]);
                locate.erase(title);
            }
        } else if (!strncmp(line, "RETURN", 6)) {
            int pos = 8;
            string title;
            while(line[pos] != '\"') {
                title += line[pos++];
            }
            if (pend.find(title) != pend.end()) {
                shelf.push_back(*(pend[title]));
                borrow.erase(pend[title]);
                pend.erase(title);
            }
        } else {
            sort(shelf.begin(), shelf.end(), Compare());
            for (int i = 0; i < shelf.size(); i++) {
                Book book = shelf[i];
                auto curr = books.insert(book).first;
                locate[book.title()] = curr;
                if (curr == books.begin()) {
                    cout << "Put \"" << curr->title() << "\" first" << endl;
                } else {
                    cout << "Put \"" << curr->title() << "\" after \"" << prev(curr)->title() << "\"" << endl;
                }
            }
            shelf.clear();
            cout << "END" << endl;
        }
    }

    return 0;
}