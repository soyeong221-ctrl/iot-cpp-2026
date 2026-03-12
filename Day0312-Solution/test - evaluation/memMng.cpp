#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Member {
private:
	int id;
	string name;
	string phone;
	string email;
public:
	Member(int id, string name, string phone, string email) {

		this->id = id;
		this->name = name;
		this->phone = phone;
		this->email = email;
	}

	int getID() { return id; }
	string getName() { return name; }
	string getPhone() { return phone; }
	string getEmail() { return email; }
	void setName(string name) { this->name = name; }
	void setPhone(string phone) { this->phone = phone; }
	void setEmail(string email) { this->email = email; }

	void input() {
		cout << "ID(only numbers): ";
		cin >> id;
		cout << "Name: ";
		cin >> name;
		cout << "Phone: ";
		cin >> phone;
		cout << "Email: ";
		cin >> email;
	}

	void update() {

		cout << "new Name: ";
		cin >> name;
		cout << "new Phone: ";
		cin >> phone;
		cout << "new Email: ";
		cin >> email;

		cout << "회원 정보 수정 완료.\n";
	}

	void print() {
		cout << left << setw(10) << id
			<< left << setw(20) << name
			<< left << setw(15) << phone
			<< left << setw(30) << email << endl;

	}


};

class MemberManager {
private:
	vector<Member> members;
public:
	void loadFromFile() {
		ifstream inFile("members.txt");
		if (!inFile) {
			cout << "저장된 회원 정보가 없습니다.\n";
			return;
		}

		int id;
		string name, phone, email;
		while (inFile >> id >> name >> phone >> email) {
			members.emplace_back(id, name, phone, email);
		}
		inFile.close();
	}
	void saveToFile() {
		ofstream outFile("members.txt");
		for (auto& m : members) {
			outFile << m.getID() << " " << m.getName() << " "
				<< m.getPhone() << " " << m.getEmail() << endl;
		}
		outFile.close();
	}
	bool exists(int id) {
		for (auto& m : members) {
			if (m.getID() == id) return true;
		}
		return false;
	}
	void addMember() {
		Member m(0, "", "", "");
		m.input();
		if (exists(m.getID())) {
			cout << "이미 존재하는 ID입니다. 등록 실패.\n";
			return;
		}

		members.push_back(m);
		cout << "회원 등록 성공.\n";
	}

	void viewMembers() {
		if (members.empty()) {
			cout << "등록된 회원이 없습니다.\n";
			return;
		}
		cout << left << setw(10) << "ID"
			<< left << setw(15) << "Name"
			<< left << setw(15) << "Phone"
			<< left << setw(25) << "Email" << endl;
		cout << string(65, '-') << endl;
		for (auto& m : members) {
			m.print();
		}
	}
	void searchMember() {
		int id;
		cout << "검색할 ID(only numbers): ";
		cin >> id;

		for (auto& m : members) {
			if (m.getID() == id) {
				m.print();
				return;
			}
		}
		cout << "ID " << id << "를 가진 회원이 없습니다.\n";
	}

	void updateMember() {
		int id;
		cout << "수정할 ID(only numbers)";
		cin >> id;

		for (auto& m : members) {
			if (m.getID() == id) {
				m.update(); //
				cout << "회원 정보 수정 완료\n";
				return;
			}
		}
		cout << "ID " << id << "를 가진 회원이 없습니다.\n";
	}


	void deleteMember() {
		int id;
		cout << "삭제할 ID(only numbers): ";
		cin >> id;

		for (auto it = members.begin(); it != members.end(); ++it) {
			if (it->getID() == id) {
				members.erase(it); 
				cout << "회원 삭제 완료.\n";
				return;
			}
		}
		cout << "ID " << id << "를 가진 회원이 없습니다.\n";
	}
};


int main() {

	MemberManager manager;
	manager.loadFromFile();
	char menu;
	while (true) {

		cout << "\n========== 회원관리 ==========\n";
		cout << "1. 등록\n";
		cout << "2. 전체조회\n";
		cout << "3. 검색\n";
		cout << "4. 수정\n";
		cout << "5. 삭제\n";
		cout << "Q. 종료\n";
		cout << "==============================\n";
		cout << "메뉴 선택: ";

		cin >> menu;
		switch (menu) {
		case '1':
			cout << "등록 메뉴 선택\n";
			// 등록 기능 구현
			manager.addMember();
			break;
		case '2':
			cout << "전체조회 메뉴 선택\n";
			// 전체조회 기능 구현
			manager.viewMembers();
			break;
		case '3':
			cout << "검색 메뉴 선택\n";
			// 검색 기능 구현
			manager.searchMember();
			break;
		case '4':
			cout << "수정 메뉴 선택\n";
			// 수정 기능 구현
			manager.updateMember();
			break;
		case '5':
			cout << "삭제 메뉴 선택\n";
			// 삭제 기능 구현
			manager.deleteMember();
			break;
		case 'Q':
		case 'q':
			manager.saveToFile();
			cout << "프로그램 종료\n";
			return 0;
		default:
			cout << "잘못된 메뉴 선택입니다. 다시 선택해 주세요.\n";
		}

	}

	return 0;
}