#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std ���

/*
* book Ŭ������ ������ ���� ������ �� �ִ�. OCP�� ����� ���ɼ��� ����.
* ������ �ִ� �����Ͱ� �ٸ� book�� ���� ���� �ֱ� ������ book interface�� �����ϰ� ���� Book�� BasicBook���� �����ϴ� ���� Ȯ�强�� ����
*/
class Book {
public:
   string title;
   string author;

   Book(const string& title, const string& author) 
      : title(title), author(author) {
   }
};

class BorrowManager //������ ������ class�� ���� �����Ƿ� �������̽��� �ʿ����. Manager���� ���� ����� �ٸ� �� ���� ������
{
   unordered_map<string, int> stock; //���� book�� title�� ����ȴٸ� ������ �ʿ�������. unordered_map<Book, int>�� �� ������
public:
   void initializeStock(const string& title, int quantity = 3) {
      stock.insert(make_pair(title, quantity));
   }
   void borrowBook(const string& title) {
      if (stock.find(title) != stock.end() && stock[title] <= 0)
         cout << "�뿩 �Ұ���\n";
      else
      {
         stock[title]--;
         cout << "�뿩�߽��ϴ�\n";
      }
   }
   void returnBook(const string& title) {
      if (stock.find(title) == stock.end())
         cout << "��ϵ��� ���� å �Դϴ�.\n";
      stock[title]++;
   }
   int displayStock(const string& title) const {
      if (stock.find(title) != stock.end()) {
         cout << "- �뿩���� ��: " << stock.find(title)->second << "\n";
         return stock.find(title)->second;
      }
   }
};

class BookManager { //������ ������ class�� ���� �����Ƿ� �������̽��� �ʿ����. Manager���� ���� ����� �ٸ� �� ���� ������
private:
   vector<Book> books; // å ��� ����

public:
   // å �߰� �޼���
   void addBook(const string& title, const string& author) {
      Book book = Book(title, author);
      books.push_back(book); // push_back ���
      cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
   }

   // ��� å ��� �޼���
   void displayAllBooks() const {
      if (books.empty()) {
         cout << "���� ��ϵ� å�� �����ϴ�." << endl;
         return;
      }

      cout << "���� ���� ���:" << endl;
      for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
         cout << "- " << books[i].title << " by " << books[i].author << endl;
      }
   }

   void searchByTitle(const string& title) const {
      cout << "ã���� ����:\n";
      for (size_t i = 0; i < books.size(); i++) {
         if (title == books[i].title) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
            return;
         }
      }
      cout << "- ���� ã���ô� å�� �����ϴ�.\n";
   }

   string searchByAuthor(const string& author) const {
      cout << "ã���� ����:\n";
      for (size_t i = 0; i < books.size(); i++) {
         if (author == books[i].author) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
            return books[i].title;
         }
      }
      cout << "- ���� ã���ô� �۰��� å�� �����ϴ�.\n";
      return "";
   }

};



int main() {

   //å�� ���� ������ manager, b_mamnager�� ������ ���ִ�.
   //���� ����� �� �� manager�� ������ ���� ����������ؼ� ���� �Ǽ��� �� �ִ�.
   //�� �Ŵ����� ������ �ִ� ������ ���� class�� �ִٸ� ����� ���忡�� �Ǽ��� �پ�� �� ����.

   BookManager manager;
   BorrowManager b_manager;

   // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
   // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
   while (true) {
      cout << "\n������ ���� ���α׷�" << endl;
      cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
      cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
      cout << "3. �������� �˻�" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
      cout << "4. �۰��� �˻�" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
      cout << "5. å �ݳ�" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
      cout << "6. ����" << endl; // ���α׷� ����
      cout << "����: ";

      int choice; // ������� �޴� ������ ����
      cin >> choice;

      if (choice == 1) {
         // 1�� ����: å �߰�
         // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
         string title, author;
         cout << "å ����: ";
         cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
         getline(cin, title); // ���� �Է� (���� ����)
         cout << "å ����: ";
         getline(cin, author); // ���ڸ� �Է� (���� ����)
         manager.addBook(title, author); // �Է¹��� å ������ �߰�
         b_manager.initializeStock(title);
      }
      else if (choice == 2) {
         // 2�� ����: ��� å ���
         // ���� BookManager�� ����� å ����� ����մϴ�.
         manager.displayAllBooks();
      }
      else if (choice == 3) {
         string title;
         string yn;
         cout << "ã���ô� å ����: ";
         cin.ignore();
         getline(cin, title);
         manager.searchByTitle(title);
         int stock = b_manager.displayStock(title);
         if (stock > 0) {
            cout << "�뿩�Ͻðڽ��ϱ�?[y/n]: ";
            cin >> yn;
            if (yn == "y")
               b_manager.borrowBook(title);
         }
      }
      else if (choice == 4) {
         string author;
         string yn;
         cout << "ã���ô� �۰�: ";
         cin.ignore();
         getline(cin, author);
         string title = manager.searchByAuthor(author);
         int stock = b_manager.displayStock(title);
         if (stock > 0) {
            cout << "�뿩�Ͻðڽ��ϱ�?[y/n]: ";
            cin >> yn;
            if (yn == "y")
               b_manager.borrowBook(title);
         }
      }
      else if (choice == 5) {
         string title;
         cout << "�ݳ��Ϸ��� å ����: ";
         cin.ignore();
         getline(cin, title);
         b_manager.returnBook(title);
         
      }
      else if (choice == 6) {
         // 6�� ����: ����
         // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
         cout << "���α׷��� �����մϴ�." << endl;
         break; // while ���� ����
      }
      else {
         // �߸��� �Է� ó��
         // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
         cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
         cin.ignore();
      }
   }

   return 0; // ���α׷� ���� ����
}
