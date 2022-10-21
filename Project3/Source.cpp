



#include <iostream>

using namespace std;


//class : Debtor(debtor - borclu)
//	fields : objectId, name, surname, workAddress, salary, phoneNumber
//	fields : hasLatePayment(bool), liveAddress, debt, Id(static)
//	methods : showDebtor
//
//
//	class : Bank
//	fields : name, debtors(array)
//	method : showAllDebtors,
//	method : borcu 1000 den yuxari olanlari gostermek
//	method : gecikmesi olanlari gostermek
//
//
//	QEYD : Kechdiymiz her shey istifade olunsun.
//	static field, copy constructor ve s



class Debtor {
	int objectId;
	char* name;
	char* surname;
	char* workAdress;
	double salary;
	char* phoneNumber;
	bool hasLatePayment;
	char* liveAdress;
	int debt;
	static int Id;
public:

	Debtor() :objectId(Id++) {

		this->name = nullptr;
		this->surname = nullptr;
		this->workAdress = nullptr;
		this->salary = 0;
		this->phoneNumber = nullptr;
		this->hasLatePayment = true;
		this->liveAdress = nullptr;
		this->debt = 0;
	}

	Debtor(const char* name, const char* surname, const char* workAdress, double salary, const char* phoneNumber, bool hasLatePayment, const char* liveAdress, int debt) :Debtor() {
		SetName(name);
		SetSurname(surname);
		SetWorkAdress(workAdress);
		SetSalary(salary);
		SetPhoneNumber(phoneNumber);
		SetHasLatePayment(hasLatePayment);
		SetLiveAdress(liveAdress);
		SetDebt(debt);
	}

	Debtor(const Debtor& other) {
		SetName(other.name);
		SetSurname(other.surname);
		SetWorkAdress(other.workAdress);
		SetSalary(other.salary);
		SetPhoneNumber(other.phoneNumber);
		SetHasLatePayment(other.hasLatePayment);
		SetLiveAdress(other.liveAdress);
		SetDebt(other.debt);
	}

	~Debtor() {
		delete[] name;
		delete[] surname;
		delete[] workAdress;
		delete[] phoneNumber;
		delete[] liveAdress;
	}

#pragma region Getter
	int GetObjectId() { return objectId; }

	char* GetName() { return name; }

	char* GetSurname() { return surname; }

	char* GetWorkAdress() { return workAdress; }

	double GetSalary() { return salary; }

	char* GetPhoneNumber() { return phoneNumber; }

	bool GetHasLatePayment() { return hasLatePayment; }

	char* GetLiveAdress() { return liveAdress; }

	int GetDebt() { return debt; }



#pragma endregion

#pragma region Setter

	void SetObjectId(int objectId) { this->objectId = objectId; }

	void SetName(const char* name) {
		delete this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetSurname(const char* surname) {
		delete this->surname;
		this->surname = new char[strlen(surname) + 1];
		strcpy_s(this->surname, strlen(surname) + 1, surname);
	}

	void SetWorkAdress(const char* workAdress) {
		delete this->workAdress;
		this->workAdress = new char[strlen(workAdress) + 1];
		strcpy_s(this->workAdress, strlen(workAdress) + 1, workAdress);
	}


	void SetSalary(int salary) {
		this->salary = salary;
	}

	void SetPhoneNumber(const char* phoneNumber) {
		delete this->phoneNumber;
		this->phoneNumber = new char[strlen(phoneNumber) + 1];
		strcpy_s(this->phoneNumber, strlen(phoneNumber) + 1, phoneNumber);
	}

	void SetHasLatePayment(int hasLatePayment) {
		this->hasLatePayment = hasLatePayment;
	}

	void SetLiveAdress(const char* liveAdress) {
		delete this->liveAdress;
		this->liveAdress = new char[strlen(liveAdress) + 1];
		strcpy_s(this->liveAdress, strlen(liveAdress) + 1, liveAdress);
	}

	void SetDebt(int debt) {
		this->debt = debt;
	}

#pragma endregion

	void showDebtors() {
		cout << "Id : " << objectId << endl;
		cout << "Name : " << name << endl;
		cout << "Surname : " << surname << endl;
		cout << "Salary : " << salary << endl;
		cout << "Phone Number : " << phoneNumber << endl;
		cout << "Work Adress : " << workAdress << endl;
		cout << "Live Adress : " << liveAdress << endl;
		cout << "Debt : " << debt << endl;
	}

};

int Debtor::Id = 1;


class Bank {

	char* name;
	int size = 3;
	Debtor* debtors = new Debtor[size]{
		Debtor("Huseyn","Mammadov","Space X",5000,"070 *** ** **",true,"Masazor",800),
		Debtor("Sarxan","Tanriverdiyev","Amazon",7000,"077 *** ** **",true,"N.Nerimanov",260),
		Debtor("Bahruz", "Nazarli", "Tesla", 12000, "050 *** ** **", false, "Nizami", 20000)
	};

public:

	Bank() :name(nullptr) {
	}

	~Bank() {
		delete[] name;
	}

	void showAllDebtors() {
		cout << "All Debtors : " << endl << endl;
		for (int i = 0; i < size; i++)
		{
			debtors[i].showDebtors();
			cout << endl;
		}
	}

	void showDebtorThousandDebt() {
		cout << "Borcu 1000 den yuxari olanlar : " << endl << endl;
		for (int i = 0; i < size; i++)
		{
			if (debtors[i].GetDebt() > 1000)
			{
				debtors[i].showDebtors();
				cout << endl;
			}
		}
	}

	void showLateDebtors() {
		cout << "Has Late Debtors : " << endl << endl;
		for (int i = 0; i < size; i++)
		{
			if (debtors[i].GetHasLatePayment())
			{
				debtors[i].showDebtors();
				cout << endl;
			}
		}
	}
};


int main() {
	Bank leoBank;
	leoBank.showAllDebtors();
	leoBank.showDebtorThousandDebt();
	leoBank.showLateDebtors();
}

