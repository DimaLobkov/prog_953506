/*Калькулятор. Разработать программу, позволяющую
пользователю рассчитать оптимальный тариф в сети Velcom. Меню
программы должно содержать следующие функции:
1. Ввод пользователем входных параметров (количество минут
разговоров внутри сети / другим операторам / на городскую
линию (в среднем в месяц), количество SMS).
2. Расчет оптимального для данного пользователя тарифа.
3. Информационные услуги (перечень существующих тарифов с
описанием)
4. Обратная связь (контактная информация компании Velcom)
5. Выход из программы.
Примечание: информация о тарифах: www.velcom.by*/

#include <stdio.h>
#include <conio.h>


int TheEnd() {		//для завершения программы
	system("cls");
	printf("\nThank you for using our product!\nThe end of the session...\n\n");
	return -1;
}

void Feedback() {	//вывод контактных данных
	system("cls");
	printf("For A1 communication services, please call:\n");
	printf("* 150-single contact center number (free call from all networks of operators in Belarus)\n");
	printf("* 7100 - (from mobile A1-0.03 BYN.)\n* roaming by phone +375 29 6 000 150 (payment according to roaming rates)\n\n");
	printf("Community A1 of Belarus: vb.me/a1belarus_community\nElectronic address for service of physical persons : 150@A1.by\n");
	printf("E-mail address for the processing of applications of legal entities: legal@A1.by\n");
	printf("E-mail address for consultations on legal entities ' services: corp@A1.by\n\n");
	printf("Media representatives can address any questions about A1's work to the head of the corporate communications Department, Nikolai Bredelev, ");
	printf("by phone +375 29 604 06 94, and address n.bredelev@A1.by");
	printf("\n\nClick on any button to continue...");
	_getch();
	system("cls");
}

void Tariffs(int select, int optimal) { //сведения о тарфиных планах
	system("cls");
	while (!(select == -1)) {
		if (optimal == 0) {
			printf("\t\tList of tariffs\n\t1) Bez limita\n\t2) Komfort S\n\t3) Komfort M\n\t4) Startoviy\n\t5) Smart beskonechniy\n\t6) Lemon Y\n\t7)Exit");
			printf("\nYour answer: ");
			scanf_s("%d", &select);
		}

		system("cls");
		switch (select) {
		case 1: printf("\t\tBez limita\n* The tariff plan provides unlimited Internet access in terms of speed and volume\n");
				printf("* Also, the tariff plan provides 500 minutes to all networks that are spent on calls in the A 1 network, as well as in the networks of other mobile operators and on the stationary network of the Republic of Belarus\n\n");
				printf("* In-network calls - 0,05 BYN\n* Calls to other networks - 0,10 BYN\n* SMS - 0,075 BYN\n\n");
				printf("\tInternational calls\n* CIS - 0,65 BYN\n* Europe - 1,06 BYN\n* Other countries - 1,95 BYN");
				printf("\n\nSubscription fee - 24,90 BYN");
				break;
		case 2: printf("\t\tKomfort S\n* 1 GB of Internet traffic\n* Unlimited minutes inside the network\n");
				printf("* 60 minutes to other networks\n* Unlimited package for messengers: Telegram, Viber, Whatsapp\n\n");
				printf("* 1 MB of Internet traffic - 0,02 BYN\n* In-network calls - 0,00 BYN\n* Calls to other networks - 0,10 BYN\n* SMS - 0,075 BYN\n\n");
				printf("\tInternational calls\n* CIS - 0,65 BYN\n* Europe - 1,06 BYN\n* Other countries - 1,95 BYN");
				printf("\n\nSubscription fee - 13,30 BYN");
				break;
		case 3: printf("\t\tKomfort M\n* 10 GB of Internet traffic\n* Unlimited minutes inside the network\n");
				printf("* 120 minutes to other networks\n* Unlimited package for messengers: Telegram, Viber, Whatsapp\n");
				printf("* Package Unlimited on social networks: Facebook, Instagram, Pinterest, Twitter, Snapchat, Odnoklassniki, VK, Tinder, BOOM, Facebook Messenger\n\n");
				printf("* 1 MB of Internet traffic - 0,02 BYN\n* In-network calls - 0,00 BYN\n* Calls to other networks - 0,10 BYN\n* SMS - 0,075 BYN\n\n");
				printf("\tInternational calls\n* CIS - 0,65 BYN\n* Europe - 1,06 BYN\n* Other countries - 1,95 BYN");
				printf("\n\nSubscription fee - 20,90 BYN");
				break;
		case 4: printf("\t\tStartoviy\n* 500 MB of Internet traffic\n* Unlimited minutes inside the network\n");
				printf("* 10 minutes to other networks\n* SMS about the end of the enabled Internet traffic for free\n");
				printf("* ONLY 0.5 kopecks / MB over 1 GB, 2 kopecks / MB up to 1 GB for future Internet use\n\n");
				printf("* 1 MB of Internet traffic - 0,02 BYN\n* In-network calls - 0,00 BYN\n* Calls to other networks - 0,10 BYN\n* SMS - 0,075 BYN\n\n");
				printf("\tInternational calls\n* CIS - 0,65 BYN\n* Europe - 1,06 BYN\n* Other countries - 1,95 BYN");
				printf("\n\nSubscription fee - 8,59 BYN");
				break;
		case 5: printf("\t\tSmart beskonechniy\n* Unlimited Internet traffic\n* Unlimited minutes inside the network\n");
				printf("* 1000 minutes to other networks\n* Unlimited package for messengers: Telegram, Viber, Whatsapp\n");
				printf("* Unlimited SMS within the network\n* Unlimited MMS within the network\n* VOKA TV Basic\n\n");
				printf("* 1 MB of Internet traffic - 0,02 BYN\n* In-network calls - 0,00 BYN\n* Calls to other networks - 0,0963 BYN\n* SMS - 0,075 BYN\n\n");
				printf("\tInternational calls\n* CIS - 0,65 BYN\n* Europe - 1,06 BYN\n* Other countries - 1,95 BYN");
				printf("\n\nSubscription fee - 60,11 BYN");
				break;
		case 6: printf("\t\tLemon Y\n* 8 GB of Internet traffic\n* Unlimited minutes inside the network\n");
				printf("* 50 minutes to other networks\n* Unlimited package for messengers: Telegram, Viber, Whatsapp\n");
				printf("* Package Unlimited on social networks: Facebook, Instagram, Pinterest, Twitter, Snapchat, Odnoklassniki, VK, Tinder, BOOM, Facebook Messenger\n\n");
				printf("* 1 MB of Internet traffic - 0,00 BYN\n* In-network calls - 0,00 BYN\n* Calls to other networks - 0,10 BYN\n* SMS - 0,0481 BYN\n\n");
				printf("\tInternational calls\n* CIS - 0,65 BYN\n* Europe - 1,06 BYN\n* Other countries - 1,95 BYN");
				printf("\n\nSubscription fee - 20,90 BYN");
				break;
		case 7: system("cls"); return;
		default: printf("Your select is incorrect. Please try again.\n\n");
		}
		printf("\n\nClick on any button to continue...");
		_getch();
		system("cls");

		if (optimal == 1) {
			select = -1;
		}
	}
}

void OptimalTariff(float tr, float A1, float MTS, float fee) {		//вычисление наиболее оптимального тарифа для потенциального абонента
	int tar[6] = { 0, 0, 0, 0, 0, 0 };
	if (tr == -1) tar[0]++, tar[4]++;
	else if (tr < 0.75) tar[3]++;
	else if (tr < 4.5) tar[1]++;
	else if (tr < 9) tar[5]++;
	else tar[2]++;

	if (A1 == -1) tar[1]++, tar[2]++, tar[3]++, tar[4]++, tar[5]++;
	else tar[0]++;

	if (MTS == -1) tar[4]++;
	else if (MTS < 30) tar[3]++;
	else if (MTS < 55) tar[5]++;
	else if (MTS < 90) tar[1]++;
	else if (MTS < 310) tar[2]++;
	else if (MTS < 750) tar[0]++;
	else tar[4]++;

	if (fee < 10.95) tar[3]++;
	else if (fee < 17.1) tar[1]++;
	else if (fee < 22.9) tar[2]++, tar[5]++;
	else if (fee < 42.51) tar[0]++;
	else tar[4]++;
	
	int indexTar[6] = { 1,2,3,4,5,6 }, x;
	for (int i = 5; i >= 0; i--) {
		for (int j = i; j > 0; j--) {
			if (tar[j] > tar[j - 1]) {
				x = tar[j];
				tar[j] = tar[j - 1];
				tar[j - 1] = x;
				x = indexTar[j];
				indexTar[j] = indexTar[j - 1];
				indexTar[j - 1] = x;
			}
		}
	}

	printf("Your optimal tariff is ");
	if (indexTar[0]==1) printf("Bez limita");
	else if (indexTar[0] == 2) printf("Komfort S");
	else if (indexTar[0] == 3) printf("Komfort M");
	else if (indexTar[0] == 4) printf("Startoviy");
	else if (indexTar[0] == 5) printf("Smart beskonechniy");
	else if (indexTar[0] == 6) printf("Lemon Y");

	printf("\n\nClick on \"F\" to learn more about this tariff\n(any other to exit)");
	char transfer = _getch();
	if (transfer == 'f') { 
		Tariffs(indexTar[0], 1); 
	}

	system("cls");
}

void Input() {	//сбор оптимальных характеристик для тарифа
	system("cls");
	float traffic, minA1, otherMin, fee;
	printf("Enter the optimal values for your tariff according to the following parameters:\n\nThe volume of Internet traffic (GB, no-limit: -1 ): ");
	scanf_s("%f", &traffic);
	printf("\nMinutes inside the network (no-limit: -1): ");
	scanf_s("%f", &minA1);
	printf("\nMinutes to other networks (no-limit: -1): ");
	scanf_s("%f", &otherMin); 
	printf("\nSubscription fee: ");
	scanf_s("%f", &fee);
	system("cls");
	OptimalTariff(traffic, minA1, otherMin, fee);
}

int main() 
{
	int select = 0;		//для switch
	printf("Welcome to the A1.Calculator!\nPlease select desired action\n\n");
	while (!(select == -1)) {
		printf("\t\tList of actions\n\t1) Necessary requirements for a tariff\n\t2) Information about tariffs\n\t3) Feedback\n\t4) Exit the program\n");
		printf("Your answer: ");
		scanf_s("%d", &select);
		switch (select) {
		case 1: Input(); break;
		case 2: Tariffs(0, 0); break;
		case 3: Feedback(); break;
		case 4: select = TheEnd(); break;
		default: printf("Your select is incorrect. Please try again.\n\n");
				printf("Click on any button to continue...");
				_getch();
				system("cls");
		}
	}
	return 0;
}