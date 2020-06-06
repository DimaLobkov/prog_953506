//Lab7 #6.2.2

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef char tLastname[15];
typedef char tFirstname[15];
typedef char tMiddlename[20];
typedef int tCourse;
typedef int tGroup;
typedef int tRoomNumber;
typedef char tOffence[3];
typedef char tPhoneNumber[15];
typedef char tProfession[30];

enum Faculties {
	FKP,
	FITU,
	FRE,
	FKSiS,
	FIK,
	IEF,
	VF
};

struct Resident {
	tLastname lastname;
	tFirstname firstname;
	tMiddlename middlename;
	Faculties faculty;
	tCourse course;
	tGroup group;
	tRoomNumber roomNumber;
	tOffence offence;
	Resident *next, *prev;
};

struct Staff {
	tProfession profession;
	tLastname lastname;
	tFirstname firstname;
	tMiddlename middlename;
	tPhoneNumber phoneNumber;
};

struct ResidentList {
	int amount;
	struct Resident* head;
};

struct ResidentList* Initialization(){
	struct ResidentList* residentList;
	residentList = (ResidentList*)malloc(sizeof(ResidentList));
	struct Resident* head;
	head = (Resident*)malloc(sizeof(Resident));
	residentList->head = head;
	residentList->head->prev = NULL;
	residentList->head->next = NULL;
	residentList->amount = 0;
	return(residentList);
}

void LoadStaff(Staff* staff){
	FILE* file;
	fopen_s(&file, "DormStaff.txt", "r");

	if (!file) {
		printf("\nNot found staff");
		return;
	}
	else{
		for (int i = 0; i < 8; i++){
			fgets(staff[i].profession, 30, file);
			fgets(staff[i].lastname, 15, file);
			fgets(staff[i].firstname, 15, file);
			fgets(staff[i].middlename, 20, file);
			fgets(staff[i].phoneNumber, 15, file);
		}
	}
	fclose(file);
	return;
}

void ShowStaff(Staff *staff) {
	for (int i = 0; i < 8; i++){
		printf_s("\n%s", staff[i].profession);
		printf_s("%s", staff[i].lastname);
		printf_s("%s", staff[i].firstname);
		printf_s("%s", staff[i].middlename);
		printf_s("%s", staff[i].phoneNumber);
	}
}

void LoadResidents(ResidentList* list) {
	FILE* file;
	fopen_s(&file, "DormResidents.txt", "r");
	char str[20] = "";
	while (fgets(str, 20, file) != NULL) {
		list->amount++;
		if (list->amount != 1) {
			Resident* prev = (Resident*)malloc(sizeof(Resident));
			prev->next = list->head;
			list->head->prev = prev;
			list->head = prev;
		}

		strcpy_s(list->head->lastname, str);
		fgets(list->head->firstname, 15, file);
		fgets(list->head->middlename, 20, file);
		fgets(str, 20, file);
		list->head->faculty = (Faculties)atoi(str);
		fgets(str, 20, file);
		list->head->course = atoi(str);
		fgets(str, 20, file);
		list->head->group = atoi(str);
		fgets(str, 20, file);
		list->head->roomNumber = atoi(str);
		fgets(list->head->offence, 3, file);
	}
}

const char* getFacultyName(enum Faculties fac)
{
	switch (fac)
	{
	case FKP: return "FKP";
	case FITU: return "FITU";
	case FRE: return "FRE";
	case FKSiS: return "FKSiS";
	case FIK: return "FIK";
	case IEF: return "IEF";
	case VF: return "VF";
	}
}

void Report(ResidentList* list) {
	Resident* ptr = list->head;
	while (ptr) {
		printf("\nStudent %s%s%s", ptr->lastname, ptr->firstname, ptr->middlename);
		printf("%s", getFacultyName(ptr->faculty));
		printf("\nCourse: %d", ptr->course);
		printf("\nGroup: %d", ptr->group);
		printf("\nRoom number: %d", ptr->roomNumber);
		printf("\nIs offences: %s\n", ptr->offence);
		ptr = ptr->next;
	}

	free(ptr);
}

void Delete(ResidentList* list, Staff* staff){
	free(staff);

	while (list->head->next != nullptr){
		list->head = list->head->next;
		free(list->head->prev);
	}

	free(list->head);
}


void AddResident(ResidentList* residentList){
	residentList->amount++;
	if (residentList->amount != 1) {
		Resident* prev = (Resident*)malloc(sizeof(Resident));
		prev->next = residentList->head;
		residentList->head->prev = prev;
		residentList->head = prev;
	}

	int student;
	printf("\nEnter Student's Lastname: ");
	fgets(residentList->head->lastname, 15, stdin);
	fflush(stdin);
	printf("\nEnter Student's Firstname: ");
	fgets(residentList->head->firstname, 15, stdin);
	fflush(stdin);
	printf("\nEnter Student's Middlename: ");
	fgets(residentList->head->middlename, 20, stdin);
	fflush(stdin);
	printf("\nEnter Student's Faculty number: ");
	scanf_s("%d", &student);
	residentList->head->faculty = (Faculties)student;
	printf("\nEnter Student's course: ");
	scanf_s("%d", &student);
	residentList->head->course = student;
	printf("\nEnter Student's group: ");
	scanf_s("%d", &student);
	residentList->head->group = student;
	printf("\nEnter Student's room number: ");
	scanf_s("%d", &student);
	residentList->head->roomNumber = student;
	printf("\nIs offence?(+ or -) ");
	fgets(residentList->head->offence, 3, stdin);
	fflush(stdin);
}

void DeleteResident(ResidentList* list){
	printf_s("Enter name: ");
	tLastname nameSearch;
	fgets(nameSearch, 15, stdin);
	fflush(stdin);

	while (list->head->next != nullptr){
		for (int i = 0; nameSearch[i] != '\0' || list->head->lastname[i] != '\0'; i++) {
			if (nameSearch[i] != list->head->lastname[i]) {
				list->head = list->head->next;
				break;
			}
		}

		if (list->head->prev && list->head->next){
			Resident* temp1 = (Resident*)malloc(sizeof(Resident));
			Resident* temp2 = (Resident*)malloc(sizeof(Resident));
			temp1 = list->head->prev;
			temp2 = list->head->next;
			temp1->next = temp2;
			temp2->prev = temp1;
		}
	}

	for (int i = 0; nameSearch[i] != '\0' || list->head->lastname[i] != '\0'; i++) {
		if (nameSearch[i] != list->head->lastname[i]) {
			break;
		}
	}

	if (list->head->prev && list->head->next){
		Resident* temp1 = (Resident*)malloc(sizeof(Resident));
		Resident* temp2 = (Resident*)malloc(sizeof(Resident));
		temp1 = list->head->prev;
		temp2 = list->head->next;
		temp1->next = temp2;
		temp2->prev = temp1;
	}
}

void SearchName(ResidentList* list){
	printf_s("Enter name: ");
	tFirstname nameSearch;
	fgets(nameSearch, 15, stdin);
	fflush(stdin);

	while (list->head->next != nullptr){
		for (int i = 0; nameSearch[i] != '\0' || list->head->firstname[i] != '\0'; i++) {
			if (nameSearch[i] != list->head->firstname[i]) {
				list->head = list->head->next;
				break;
			}
		}

		printf_s("\nLastname: %s", list->head->lastname);
		printf_s("\nSurname: %s", list->head->firstname);
		printf_s("\nCourse: %d", list->head->course);
		printf_s("\nGroup: %d", list->head->group);
		printf_s("\nFaculty: %s", getFacultyName(list->head->faculty));
		printf_s("\nRoom: %d", list->head->roomNumber);
	}

	for (int i = 0; nameSearch[i] != '\0' || list->head->firstname[i] != '\0'; i++) {
		if (nameSearch[i] != list->head->firstname[i]) {
			break;
		}
	}

	printf_s("\nLastname: %s", list->head->lastname);
	printf_s("\nSurname: %s", list->head->firstname);
	printf_s("\nCourse: %d", list->head->course);
	printf_s("\nGroup: %d", list->head->group);
	printf_s("\nFaculty: %s", getFacultyName(list->head->faculty));
	printf_s("\nRoom: %d", list->head->roomNumber);
}

void SearchRoom(ResidentList* list){
	printf_s("Enter room: ");
	tRoomNumber roomSearch;
	scanf_s("%d", &roomSearch);
	fflush(stdin);
	while (list->head->prev != nullptr) {
		list->head = list->head->prev;
	}
	while (list->head->next != nullptr){
		if (list->head->roomNumber == roomSearch) {
			printf_s("\nLastname: %s", list->head->lastname);
			printf_s("\nSurname: %s", list->head->firstname);
			printf_s("\nCourse: %d", list->head->course);
			printf_s("\nGroup: %d", list->head->group);
			printf_s("\nFaculty: %s", getFacultyName(list->head->faculty));
			printf_s("\nRoom: %d", list->head->roomNumber);
		}

		else {
			list->head = list->head->next;
		}
	}

	if (list->head->roomNumber == roomSearch){
		printf_s("\nLastname: %s", list->head->lastname);
		printf_s("\nSurname: %s", list->head->firstname);
		printf_s("\nCourse: %d", list->head->course);
		printf_s("\nGroup: %d", list->head->group);
		printf_s("\nFaculty: %s", getFacultyName(list->head->faculty));
		printf_s("\nRoom: %d", list->head->roomNumber);
	}
}

void Menu() {
	printf("\n\t\t Menu");
	printf("\n1) Add a resident to the dorm");
	printf("\n2) Delete a resident from the dorm");
	printf("\n3) Search by Lastname");
	printf("\n4) Search by room number");
	printf("\n5) Report");
	printf("\n6) Сontact information about the staff.");
	printf("\n7) Exit\n");
}

int main(){
	ResidentList* residentList = Initialization();
	LoadResidents(residentList);
	Staff* staff;
	staff = (Staff*)malloc(8 * sizeof(Staff));
	LoadStaff(staff);
	printf_s("Welcome to the DormDatabase!");
	bool forExit = true;
	do {
		Menu();
		int switcher = 0;
		scanf_s("%d", &switcher);
		switch (switcher) {
		case 1: AddResident(residentList); break;
		case 2: DeleteResident(residentList); break;
		case 3: SearchName(residentList); break;
		case 4: SearchRoom(residentList); break;
		case 5: Report(residentList); break;
		case 6: ShowStaff(staff); break;
		case 7: forExit = false; break;
		}
	} while (forExit);

	Delete(residentList, staff);
}