#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

/*
* book 클래스의 변수에 직접 접근할 수 있다. OCP가 위배될 가능성이 높다.
* 가지고 있는 데이터가 다른 book이 생길 수도 있기 때문에 book interface를 선언하고 현재 Book을 BasicBook으로 선언하는 것이 확장성이 좋다
*/
class Book {
public:
   string title;
   string author;

   Book(const string& title, const string& author) 
      : title(title), author(author) {
   }
};

class BorrowManager //구현을 공유할 class가 따로 없으므로 인터페이스는 필요없다. Manager마다 구현 기능이 다를 것 같기 때문에
{
   unordered_map<string, int> stock; //만약 book의 title이 변경된다면 수정이 필요해진다. unordered_map<Book, int>가 더 나을듯
public:
   void initializeStock(const string& title, int quantity = 3) {
      stock.insert(make_pair(title, quantity));
   }
   void borrowBook(const string& title) {
      if (stock.find(title) != stock.end() && stock[title] <= 0)
         cout << "대여 불가능\n";
      else
      {
         stock[title]--;
         cout << "대여했습니다\n";
      }
   }
   void returnBook(const string& title) {
      if (stock.find(title) == stock.end())
         cout << "등록되지 않은 책 입니다.\n";
      stock[title]++;
   }
   int displayStock(const string& title) const {
      if (stock.find(title) != stock.end()) {
         cout << "- 대여가능 수: " << stock.find(title)->second << "\n";
         return stock.find(title)->second;
      }
   }
};

class BookManager { //구현을 공유할 class가 따로 없으므로 인터페이스는 필요없다. Manager마다 구현 기능이 다를 것 같기 때문에
private:
   vector<Book> books; // 책 목록 저장

public:
   // 책 추가 메서드
   void addBook(const string& title, const string& author) {
      Book book = Book(title, author);
      books.push_back(book); // push_back 사용
      cout << "책이 추가되었습니다: " << title << " by " << author << endl;
   }

   // 모든 책 출력 메서드
   void displayAllBooks() const {
      if (books.empty()) {
         cout << "현재 등록된 책이 없습니다." << endl;
         return;
      }

      cout << "현재 도서 목록:" << endl;
      for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
         cout << "- " << books[i].title << " by " << books[i].author << endl;
      }
   }

   void searchByTitle(const string& title) const {
      cout << "찾으신 도서:\n";
      for (size_t i = 0; i < books.size(); i++) {
         if (title == books[i].title) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
            return;
         }
      }
      cout << "- 현재 찾으시는 책이 없습니다.\n";
   }

   string searchByAuthor(const string& author) const {
      cout << "찾으신 도서:\n";
      for (size_t i = 0; i < books.size(); i++) {
         if (author == books[i].author) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
            return books[i].title;
         }
      }
      cout << "- 현재 찾으시는 작가의 책이 없습니다.\n";
      return "";
   }

};



int main() {

   //책에 대한 정보가 manager, b_mamnager에 나눠서 들어가있다.
   //따라서 사용할 때 두 manager의 정보를 각각 수정해줘야해서 사용시 실수할 수 있다.
   //두 매니저를 가지고 있는 도서관 관리 class가 있다면 사용자 입장에서 실수가 줄어들 것 같다.

   BookManager manager;
   BorrowManager b_manager;

   // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
   // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
   while (true) {
      cout << "\n도서관 관리 프로그램" << endl;
      cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
      cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
      cout << "3. 제목으로 검색" << endl; // 현재 책 목록에 있는 모든 책 출력
      cout << "4. 작가로 검색" << endl; // 현재 책 목록에 있는 모든 책 출력
      cout << "5. 책 반납" << endl; // 현재 책 목록에 있는 모든 책 출력
      cout << "6. 종료" << endl; // 프로그램 종료
      cout << "선택: ";

      int choice; // 사용자의 메뉴 선택을 저장
      cin >> choice;

      if (choice == 1) {
         // 1번 선택: 책 추가
         // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
         string title, author;
         cout << "책 제목: ";
         cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
         getline(cin, title); // 제목 입력 (공백 포함)
         cout << "책 저자: ";
         getline(cin, author); // 저자명 입력 (공백 포함)
         manager.addBook(title, author); // 입력받은 책 정보를 추가
         b_manager.initializeStock(title);
      }
      else if (choice == 2) {
         // 2번 선택: 모든 책 출력
         // 현재 BookManager에 저장된 책 목록을 출력합니다.
         manager.displayAllBooks();
      }
      else if (choice == 3) {
         string title;
         string yn;
         cout << "찾으시는 책 제목: ";
         cin.ignore();
         getline(cin, title);
         manager.searchByTitle(title);
         int stock = b_manager.displayStock(title);
         if (stock > 0) {
            cout << "대여하시겠습니까?[y/n]: ";
            cin >> yn;
            if (yn == "y")
               b_manager.borrowBook(title);
         }
      }
      else if (choice == 4) {
         string author;
         string yn;
         cout << "찾으시는 작가: ";
         cin.ignore();
         getline(cin, author);
         string title = manager.searchByAuthor(author);
         int stock = b_manager.displayStock(title);
         if (stock > 0) {
            cout << "대여하시겠습니까?[y/n]: ";
            cin >> yn;
            if (yn == "y")
               b_manager.borrowBook(title);
         }
      }
      else if (choice == 5) {
         string title;
         cout << "반납하려는 책 제목: ";
         cin.ignore();
         getline(cin, title);
         b_manager.returnBook(title);
         
      }
      else if (choice == 6) {
         // 6번 선택: 종료
         // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
         cout << "프로그램을 종료합니다." << endl;
         break; // while 루프 종료
      }
      else {
         // 잘못된 입력 처리
         // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
         cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
         cin.ignore();
      }
   }

   return 0; // 프로그램 정상 종료
}
