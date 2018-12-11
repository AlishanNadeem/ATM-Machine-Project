#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// CNIC NUMBER = 4210101234567 PIN CODE = 1234
// CNIC NUMBER2 = 4210176543210 PIN CODE = 0123
 
float currAmount = 100000;

void delay()
{
	int c,d;
	for (c = 1; c <= 14000; c++)
    	for (d = 1; d <= 14000; d++)
    {}
}
void delayMin()
{
	int c,d;
	for (c = 1; c <= 10000; c++)
    	for (d = 1; d <= 10000; d++)
    {}
}

void welcome()
{
	printf("\n\n\t\t\t \t     ------------ ATM MACHINE ------------ \n\n");
}

void takeReceipt()
{
	char sml=1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    ----- PLEASE TAKE YOUR RECIEPT -----\n\n\n\n\n\n\n\n");
	delayMin();
	system("cls");
	delayMin();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    ----- PLEASE TAKE YOUR RECIEPT -----\n\n\n\n\n\n\n\n");
	delayMin();
	system("cls");
	delayMin();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    ----- PLEASE TAKE YOUR RECIEPT -----\n\n\n\n\n\n\n\n");
	delayMin();
	system("cls");
	delayMin();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t----- THANKYOU FOR USING ATM %c -----\n\n\n\n\n\n\n\n\n\n", sml);
	exit(0);
}

void inp_transferfund(cnicNum)
{
	FILE *fp2, *fp3;
	char key, accNum[15], currBal[55];
	float currAmo, amount2;
	temp3:
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		system("cls");
		printf("\n\n\t\t\t\t ------------ TRANSFER FUNDS ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fscanf(fp3, "%s", currBal);
		printf("%s", currBal);
		printf(" Rs\n\n");
		fclose(fp3);   
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\n\n\t\t        Enter 14 Digits Account Number (to whom you want to transfer)\n\n\t\t\t\t\t       ");
		scanf("%s", &accNum);
		if(strlen(accNum) == 14)
		{temp1:
			fp2 = fopen("rec\\cnic1\\cashwithdraw.txt", "a+");
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
			system("cls");
			printf("\n\n\t\t\t\t ------------ TRANSFER FUNDS ------------ \n\n");
			printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
			fscanf(fp3, "%s", currBal);
			printf("%s", currBal);
			fclose(fp3);
			printf(" Rs\n\n");
			printf("-------------------------------------------------------------------------------------------------------------------\n\n");
			printf("\n\n\n\n\n\n\t\t\t\t    Enter Amount (MIN RS 500 & MAX 25000)\n\n\t\t\t\t\t\t     ");
			scanf("%f", &amount2);
			if(amount2 >= 500 && amount2 <= 25000)
			{
				fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
				fscanf(fp3, "%s", currBal);
				currAmo = atof(currBal);
				fclose(fp3);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				temp2:
				fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
				system("cls");
				printf("\n\n\t\t\t\t ------------ TRANSFER FUNDS ------------ \n\n");
				printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, currAmo - amount2);
				printf("-------------------------------------------------------------------------------------------------------------------\n\n");
				fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
				fprintf(fp3, "%.2f", currAmo - amount2);
				fclose(fp3);
				printf("\n\n\n\n\n\n\t\t   You Successfully transfered Rupees %.2f/= to Account (%s)", amount2, accNum);
				fprintf(fp2, "\nYou Transfered Amount Rs %.2f/= to Account # %s\n", amount2, accNum);
				fclose(fp2);
				printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
				key = getch();
				if (key == 8)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
					delay();
					mainMenu(cnicNum);
				}
				else if (key == 27)
				{
					takeReceipt();
				}
				else
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
					delay();
					goto temp2;
				}		
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t----- ENTER AMOUNT BETWEEN RS 500-25,000 -----");Beep(1000, 400);Beep(1000, 400);
				delay();delayMin();
				goto temp1;
			}
		}	
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t ----- PLEASE ENTER A VALID ACCOUNT NUMBER -----  \n");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp3;
		}
}

void opt_1(cnicNum)
{
	FILE *fp2, *fp3;
	char sel_amount, key, currBal[55];
	float currAmo;
	repeat:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
	fscanf(fp3, "%s", currBal);
	printf("%s", currBal);
	fclose(fp3);
	printf(" Rs \n\n");
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");
	printf("Select Amount \n\n\n");
	printf("\t\t\tPRESS 1, For RS 500\t\t\tPRESS 2, For RS 1000\n\n\n\t\t\tPRESS 3, For RS 5000\t\t\tPRESS 4, For RS 10000\n\n\n\t\t\tPRESS 5, For RS 20000\t\t\tPRESS 6, For RS 25000\n\n\n");
	printf("\t\t\t If you want to go back to MAIN MENU, PRESS BACKSPACE Key\n");
	sel_amount=getch();
	if(sel_amount == '1')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		currAmo = atof(currBal);
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, currAmo - 500);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
		fprintf(fp3, "%.2f", currAmo - 500);
		fclose(fp3);
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		fprintf(fp2, "\nWithdrawl Amount Rs 500/=\n");
		fclose(fp2);
		temp:
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		printf("%s", currBal);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\t\t\t\t   YOU WITHDRAWL AMOUNT RUPEES 500/=");
		printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
		key = getch();
		if (key == 8)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		}
		else if(key == 27)
		{
			takeReceipt();
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp;
		}
	}
	else if(sel_amount == '2')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		currAmo = atof(currBal);
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, currAmo - 1000);
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
		fprintf(fp3, "%.2f", currAmo - 1000);
		fclose(fp3);
		fprintf(fp2, "\nWithdrawl Amount Rs 1000/=\n");
		fclose(fp2);
		temp1:
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		printf("%s", currBal);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\t\t\t\t   YOU WITHDRAWL AMOUNT RUPEES 1000/=");
		printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
		key = getch();
		if (key == 8)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		}
		else if(key == 27)
		{
			takeReceipt();
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp1;
		}
	}
	else if(sel_amount == '3')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		currAmo = atof(currBal);
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, (currAmo - 5000));
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
		fprintf(fp3, "%.2f", currAmo - 5000);
		fclose(fp3);
		fprintf(fp2, "\nWithdrawl Amount Rs 5000/=\n");
		fclose(fp2);
		temp2:
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		printf("%s", currBal);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\t\t\t\t   YOU WITHDRAWL AMOUNT RUPEES 5000/=");
		printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
		key = getch();
		if (key == 8)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		}
		else if(key == 27)
		{
			takeReceipt();
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp2;
		}
	}
	else if(sel_amount == '4')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();	
		fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		currAmo = atof(currBal);
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, (currAmo - 10000));
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
		fprintf(fp3, "%.2f", currAmo - 10000);
		fclose(fp3);
		fprintf(fp2, "\nWithdrawl Amount Rs 10000/=\n");
		fclose(fp2);
		temp3:
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		printf("%s", currBal);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\t\t\t\t   YOU WITHDRAWL AMOUNT RUPEES 10000/=");
		printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
		key = getch();
		if (key == 8)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		}
		else if(key == 27)
		{
			takeReceipt();
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp3;
		}
	}
	else if(sel_amount == '5')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		currAmo = atof(currBal);
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, (currAmo - 20000));
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
		fprintf(fp3, "%.2f", currAmo - 20000);
		fclose(fp3);
		fprintf(fp2, "\nWithdrawl Amount Rs 20000/=\n");
		fclose(fp2);
		temp4:
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		printf("%s", currBal);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\t\t\t\t   YOU WITHDRAWL AMOUNT RUPEES 20000/=");
		printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
		key = getch();
		if (key == 8)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		}
		else if(key == 27)
		{
			takeReceipt();
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp4;
		}
	}
	else if(sel_amount == '6')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		currAmo = atof(currBal);
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, (currAmo - 25000));
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
		fprintf(fp3, "%.2f", currAmo - 25000);
		fclose(fp3);
		fprintf(fp2, "\nWithdrawl Amount Rs 25000/=\n");
		fclose(fp2);
		temp5:
		system("cls");
		printf("\n\n\t\t\t\t ------------ FAST CASH ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		fscanf(fp3, "%s", currBal);
		fclose(fp3);
		printf("%s", currBal);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\t\t\t\t   YOU WITHDRAWL AMOUNT RUPEES 25000/=");//cashdeposit
		printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
		key = getch();
		if (key == 8)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		}
		else if(key == 27)
		{
			takeReceipt();
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp5;
		}
	}
	else if(sel_amount == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else 
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE SELECT A VALID OPTION -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto repeat;
	}
}
void opt_2(cnicNum)
{
	FILE *fp2, *fp3;
	char key, currBal[55];
	float currAmo, amount;
	opt:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ CASH WITHDRAW ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
	fscanf(fp3, "%s", currBal);
	printf("%s", currBal);
	printf(" Rs\n\n");
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\t\t\t If you want to go back to MAIN MENU, PRESS BACKSPACE Key\n\n\t\t\t\t  Otherwise PRESS ENTER Key to Proceed");
	key = getch();
	if (key == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else if (key == 13)
	{
		system("cls");
		delayMin();
		opt2:
		system("cls");
		printf("\n\n\t\t\t\t ------------ CASH WITHDRAW ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		printf("%s", currBal);
		printf(" Rs\n\n");
		fclose(fp3);
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\n\n\t\t\t\t   Enter Amount (MIN RS 500 & MAX 50000)\n\n\t\t\t\t\t\t  ");
		scanf("%f", &amount);
		if(amount < 500 || amount > 50000) 
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t----- ENTER AMOUNT BETWEEN RS 500-50,000 -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto opt2;
		}
		else 
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			temp:
			fp2 = fopen("rec\\cnic1\\cashwithdraw.txt", "a+");
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
			currAmo = atof(currBal);
			fclose(fp3);
			system("cls");
			printf("\n\n\t\t\t\t ------------ CASH WITHDRAW ------------ \n\n");
			printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, currAmo - amount);
			printf("-------------------------------------------------------------------------------------------------------------------\n\n");
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");	
			fprintf(fp3, "%.2f" , currAmo - amount);
			fclose(fp3);
			printf("\n\n\n\n\n\n\t\t\t   YOU SUCCESSFULLY WITHDRAWL AMOUNT RUPEES %.2f/=", amount);
			fprintf(fp2,"\nWithdrawl Amount Rs %.2f/=\n", amount);
			fclose(fp2);
			printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
			key = getch();
			if (key == 8)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				mainMenu(cnicNum);
			}
			else if (key == 27)
			{
				takeReceipt();
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
				delay();
				goto temp;
			}
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto opt;
	}
}

void opt_3(cnicNum)
{
	FILE *fp2, *fp3;
	char key, currBal[55];
	float currAmo, amount;
	opt:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ CASH DEPOSIT ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
	fscanf(fp3, "%s", currBal);
	printf("%s", currBal);
	fclose(fp3);
	currAmo = atof(currBal);
	printf(" Rs\n\n");
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\t\t\t If you want to go back to MAIN MENU, PRESS BACKSPACE Key\n\n\t\t\t\t  Otherwise PRESS ENTER Key to Proceed");
	key = getch();
	if (key == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else if (key == 13)
	{
		system("cls");
		delayMin();
		opt2:
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		system("cls");
		printf("\n\n\t\t\t\t ------------ CASH DEPOSIT ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fscanf(fp3, "%s", currBal);
		printf("%s", currBal);
		fclose(fp3);
		printf(" Rs\n\n");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\n\n\n\n\n\t\t\t\t   Enter Amount (MIN RS 500 & MAX 25000)\n\n\t\t\t\t\t\t  ");
		scanf("%f", &amount);
		if(amount < 500 || amount > 25000) 
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t----- ENTER AMOUNT BETWEEN RS 500-25,000 -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto opt2;
		}
		else 
		{
			fp2 = fopen("rec\\cnic1\\cashwithdraw.txt", "a+");
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
			fscanf(fp3, "%s", currBal);
			currAmo = atof(currBal);
			fclose(fp3);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			system("cls");
			printf("\n\n\t\t\t\t ------------ CASH DEPOSIT ------------ \n\n");
			printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, currAmo + amount);
			printf("-------------------------------------------------------------------------------------------------------------------\n\n");
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
			fprintf(fp3, "%.2f" ,currAmo + amount);
			fclose(fp3);
			fprintf(fp2,"\nDeposit Amount Rs %.2f/=\n", amount);
			fclose(fp2);
			temp:
			system("cls");
			printf("\n\n\t\t\t\t ------------ CASH DEPOSIT ------------ \n\n");
			printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE :", cnicNum);
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
			fscanf(fp3, "%s", currBal);
			fclose(fp3);
			printf("%s", currBal);
			printf(" Rs \n\n");
			printf("-------------------------------------------------------------------------------------------------------------------\n\n");
			printf("\n\n\n\n\n\n\t\t\t   YOU SUCCESSFULLY DEPOSITED AMOUNT RUPEES %.2f/=", amount);
			printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
			key = getch();
			if (key == 8)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				mainMenu(cnicNum);
			}
			else if (key == 27)
			{
				takeReceipt();
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
				delay();
				goto temp;
			}
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto opt;
	}
}

void opt_4(cnicNum)
{
	FILE *fp3;
	char accNum[20], key, bank, opt_transfer, currBal[55]; 
	float amount2, c;
	temp:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ TRANSFER FUNDS ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
	fscanf(fp3, "%s", currBal);   
	printf("%s", currBal);
	printf(" Rs\n\n");
	fclose(fp3);
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\n\t\t\t\t    Select the funds transfer option");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\tPRESS 1, For Conventional");
   	printf("\n\n\n\t\t\t\t\tPRESS 2, For IBAN\n\n\t\t\t\t");
   	printf("\n\n\n\n\n\n\n\t\t\t   If you want to go back to MAINMENU, PRESS BACKSPACE Key");
	opt_transfer = getch();
	switch(opt_transfer)
	{
		case '1':
			banks:
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
			system("cls");
			printf("\n\n\t\t\t\t ------------ TRANSFER FUNDS ------------ \n\n");
			printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
			fscanf(fp3, "%s", currBal);   
			printf("%s", currBal);
			printf(" Rs\n\n");
			fclose(fp3);   
			printf("-------------------------------------------------------------------------------------------------------------------\n\n");	
			printf("\n\tPlease select bank");
			printf("\n\n\n\n\n\t\t1:Al Baraka Bank\t   2:Allied Bank\t\t3:Askari Bank\n\n\n\t\t4:Bank Alfalah\t\t   5:Bank Al-Habib\t\t6:Bank Islami\n\n\n\t\t7:Dubai Islamic Bank\t   8:Faysal bank\t        9:Standard Bank");
			printf("\n\n\n\n\n\n\n\t\t\t   If you want to go back, PRESS BACKSPACE Key");
			bank = getch();	
			switch (bank)
			{
				case '1':
					inp_transferfund(cnicNum);
				break;
				case '2':
					inp_transferfund(cnicNum);
				break;
				case '3':
					inp_transferfund(cnicNum);
				break;
				case '4':
					inp_transferfund(cnicNum);
				break;
				case '5':
					inp_transferfund(cnicNum);
				break;
				case '6':
					inp_transferfund(cnicNum);
				break;
				case '7':
					inp_transferfund(cnicNum);
				break;
				case '8':
					inp_transferfund(cnicNum);
				break;
				case '9':
					inp_transferfund(cnicNum);
				break;
				case 8:
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
					delay();
					goto temp;
				default:
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     -----PLEASE SELECT A VALID OPTION-----");Beep(1000, 400);Beep(1000, 400);
					delay();
					goto banks;	
			}
		break;
		case '2':
			inp_transferfund(cnicNum);
		break;
		case 8:
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			mainMenu(cnicNum);
		break;
		default:
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     -----PLEASE SELECT A VALID OPTION-----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp;
	}
}

void opt_5(cnicNum)
{
	FILE *fp2, *fp3;
	char key, currBal[55];
	float amount, currAmo;
	temp:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ FOR LOAN ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
	fscanf(fp3, "%s", currBal);
	printf("%s", currBal);
	printf(" Rs\n\n");
	fclose(fp3);
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");	
	printf("\t\t\t If you want to go back to MAIN MENU, PRESS BACKSPACE Key\n\n\t\t\t\t  Otherwise PRESS ENTER Key to Proceed");
	key = getch();
	if (key == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else if (key == 13)
	{
		fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
		system("cls");
		printf("\n\n\t\t\t\t ------------ FOR LOAN ------------ \n\n");
		printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
		fscanf(fp3, "%s", currBal);
		printf("%s", currBal);
		printf(" Rs\n\n");
		fclose(fp3);
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");		
		printf("NOTE : You can only receive loan of MAXIMUM RS 50000");
		printf("\n\n\n\n\n\n\t\t\t\t       Enter Amount (MAX 50000)\n\n\t\t\t\t\t\t  ");
		scanf("%f", &amount);
		if(amount <= 50000)
		{temp1:
			fp2 = fopen("rec\\cnic1\\cashwithdraw.txt","a+");
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
			fscanf(fp3, "%s", currBal);
			fclose(fp3);
			currAmo = atof(currBal);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			system("cls");
			printf("\n\n\t\t\t\t ------------ FOR LOAN ------------ \n\n");
			printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : %.2f Rs\n\n", cnicNum, currAmo + amount);
			printf("-------------------------------------------------------------------------------------------------------------------\n\n");
			printf("\n\n\n\n\n\n\t\t\tYOU SUCCESSFULLY RECEIVED LOAN OF AMOUNT RUPEES %.2f/=", amount);
			fp3 = fopen("rec\\cnic1\\currbalance.txt", "w+");
			fprintf(fp3, "%.2f", currAmo + amount);
			fclose(fp3);
			fprintf(fp2, "\nYou owe to the bank of Rs %.2f/=\n", amount);
			fclose(fp2);
			printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
			key = getch();
			if (key == 8)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				mainMenu(cnicNum);
			}
			else if (key == 27)
			{
				takeReceipt();
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
				delay();
				goto temp1;
			}
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t----- YOU CAN ONLY RECIEVE LOAN OF MAX 50000 -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp;
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto temp;
	}
}

void opt_6(cnicNum)
{
	FILE *fp2, *fp3;
	char c, key, currBal[55];
	temp:
	fp2 = fopen("rec\\cnic1\\cashwithdraw.txt", "r");
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ E - STATEMENTS ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\t\t\t\t\t\t\t\t\t\tBALANCE : ", cnicNum);
	fscanf(fp3 ,"%s", currBal);
	printf("%s", currBal);
	fclose(fp3);
	printf(" Rs\n\n");
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");
	do
	{
		c = fgetc(fp2);
		putchar(c);
	}
		
	while (c != EOF);
	fclose(fp2);
	printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
	key = getch();
	if (key == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else if(key == 27)
	{
		takeReceipt();
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto temp;
	}
}


void opt_7(cnicNum)
{
	FILE *fp3;
	char key, c;
	temp:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");  
	system("cls");
	printf("\n\n\t\t\t\t ------------ BALANCE INQUIRY ------------ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\tCNIC # : %s \n\t\t\t\t\t\t\t\t\t\tPIN CODE : **** \n\n", cnicNum);
	printf("-------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\tYour Current Balance is Rupees ");
		do
		{
			c = getc(fp3);
			printf("%c", c);
		}
		while(c!=EOF);
	printf("/=");
	printf("\n\n\n\n\n\n\n\t\t\tIf you want to go back to MAINMENU, PRESS BACKSPACE Key \n\n\t\t\t         and If you want to END, PRESS ESC Key");
	key = getch();
	if (key == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else if(key == 27)
	{
		takeReceipt();
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto temp;
	}
}

void opt_8(cnicNum)
{
	FILE *fp1;
	int i;
	char code[5];
	char pin[5], newpin[5], renew[5], key; 
	a:
	fp1 = fopen("rec\\cnic1\\Pincode.txt", "r");
	system("cls");
	printf("\n\n\t\t\t\t ------------ CHANGE YOUR PIN CODE ------------ \n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t    If you want to go back to MAIN MENU, PRESS BACKSPACE Key\n\n\t\t\t\t     Otherwise PRESS ENTER Key to Proceed");
	key = getch();
	if (key == 8)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		mainMenu(cnicNum);
	}
	else if (key == 13)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
		delay();
		b:
		system("cls");
		printf("\n\n\t\t\t\t ------------ CHANGE YOUR PIN CODE ------------ \n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Enter Your Recent Pin Code\n\n\t\t\t\t\t\t      ");
		scanf("%s", &pin);
		fscanf(fp1, "%s", &code);
		if(strlen(pin) == 4)
		{
			for(i=0; i<3; i++)
			{
				system("cls");delayMin();printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     Verifying Your PIN");delay();
			}
			if(strcmp(pin, code) == 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t ----- PIN CODE VERIFIED -----");
				delay();delayMin();
				system("cls");
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t----- YOU ENTERED WRONG PIN -----");Beep(1000, 400);Beep(1000, 400);
				delay();delayMin();
				system("cls");
				goto b;
			}
			fclose(fp1);
		 	c:
			printf("\n\n\t\t\t\t ------------ CHANGE YOUR PIN CODE ------------ \n\n");
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Enter Your Recent Pin Code\n\n\t\t\t\t\t\t      ****");
			printf("\n\n\n\t\t\t\t\t    Enter Your New Pin Code\n\n\t\t\t\t\t\t      ");
			scanf("%s", &newpin);
			if(strlen(newpin) == 4)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				d:
				system("cls");
				printf("\n\n\t\t\t\t ------------ CHANGE YOUR PIN CODE ------------ \n\n");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Enter Your Recent Pin Code\n\n\t\t\t\t\t\t      ****");
				printf("\n\n\n\t\t\t\t\t    Enter Your New Pin Code\n\n\t\t\t\t\t\t      ****");
				printf("\n\n\n\t\t\t\t\tPLEASE Re-Enter Your New Pin Code\n\n\t\t\t\t\t\t      ");
				scanf("%s", &renew);
				fp1 = fopen("rec\\cnic1\\Pincode.txt", "r+");
				if(strlen(renew) == 4)
				{
					system("cls");
					for(i=0; i<3; i++)
					{	
						system("cls");delayMin();printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t      Matching Your PIN");delay();
					}
					if(strcmp(renew, newpin) == 0)
					{
						system("cls");
						printf("\n\n\t\t\t\t ------------ CHANGE YOUR PIN CODE ------------ \n\n");
						printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Enter Your Recent Pin Code\n\n\t\t\t\t\t\t      ****");
						printf("\n\n\n\t\t\t\t\t    Enter Your New Pin Code\n\n\t\t\t\t\t\t      ****");
						printf("\n\n\n\t\t\t\t\tPLEASE Re-Enter Your New Pin Code\n\n\t\t\t\t\t\t      ****");
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
						delay();
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    ----- PINCODE SUCCESSFULLY CHANGED -----\n\n\n\n\n\n\n\n\n");
						delay();
						fprintf(fp1, "%s", renew);
						fclose(fp1);
						mainMenu(cnicNum);
					}
					else
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t----- MISMATCHED PIN CODE -----");Beep(1000, 400);Beep(1000, 400);
						delay();
						system("cls");
						goto c;
					}
				}		
				else
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t----- MISMATCHED PIN CODE -----");Beep(1000, 400);Beep(1000, 400);
					delay();
					system("cls");
					goto c;
				}
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ----- INVALID PIN CODE -----");Beep(1000, 400);Beep(1000, 400);
				delay();
				system("cls");
				goto c;
			}
		}	
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ----- INVALID PIN CODE -----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto b;
		}
	}	
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ----- PLEASE PRESS A VALID KEY -----");Beep(1000, 400);Beep(1000, 400);
		delay();
		goto a;
	}
}

int mainMenu(cnicNum)
{
	FILE *fp3;
	char option, currBal[55];
	float currAmo;
	temp:
	fp3 = fopen("rec\\cnic1\\currbalance.txt", "r");
	fscanf(fp3, "%s", currBal);
	fclose(fp3);
	currAmo = atof(currBal);
	system("cls");
	welcome();
	printf("\n\n\n\n\n\n\n\t\tPRESS 1, For Fast Cash\t\t\t\tPRESS 2, For Cash Withdrawl \n\n\n");
	printf("\t\tPRESS 3, For Cash Deposit\t\t\tPRESS 4, For Transfer Fund \n\n\n");
	printf("\t\tPRESS 5, For Loan\t\t\t\tPRESS 6, For E-Statements \n\n\n");
	printf("\t\tPRESS 7, For Balance Inquiry\t\t\tPRESS 8, Change Your Pin Code \n\n\n\n\t\t\t\t\t   PRESS ESC Key, To Exit");
	option = getch();
	switch (option)
	{option:
		case '1':
			if(currAmo > 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				opt_1(cnicNum);
			}
			else 
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t----- SORRY! YOU HAVE INSUFFICIENT BALANCE -----");Beep(1000, 400);Beep(1000, 400);
				delay();delayMin();
				system("cls");
				goto temp;
			}
		break;
		case'2':
			if(currAmo > 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				opt_2(cnicNum);
			}
			else 
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t----- SORRY! YOU HAVE INSUFFICIENT BALANCE -----");Beep(1000, 400);Beep(1000, 400);
				delay();delayMin();
				system("cls");
				goto temp;
			}
		break;
		case '3':
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			opt_3(cnicNum);
		break;
		case'4':
			if(currAmo > 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				opt_4(cnicNum);
			}
			else 
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t----- SORRY! YOU HAVE INSUFFICIENT BALANCE -----");Beep(1000, 400);Beep(1000, 400);
				delay();delayMin();
				system("cls");
				goto temp;
			}
		break;
		case'5':
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			opt_5(cnicNum);
		break;
		case '6':
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			opt_6(cnicNum);
		break;
		case '7':
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			opt_7(cnicNum);
		break;
		case '8':
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
			delay();
			opt_8(cnicNum);
		break;
		case 27 :
			system("cls");
			Beep(1000,400);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tExiting.");delayMin();printf(".");delayMin();printf(".");delayMin();printf(".");
			delay();
			system("cls");
			char sml=1;
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t----- THANKYOU FOR USING ATM %c -----\n\n\n\n\n\n\n\n\n\n", sml);
			exit(0);
		break;
		default : 
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     -----PLEASE SELECT A VALID OPTION-----");Beep(1000, 400);Beep(1000, 400);
			delay();
			goto temp;				
	}
}

int pinCode(cnicNum)
{
	FILE *fp, *fp1;
	char pinCode[5],num[15], code[5];
	temp:
	fp = fopen("rec\\cnic1\\cnicnum.txt", "r");
	fp1 = fopen("rec\\cnic1\\Pincode.txt", "r");
	system("cls");
	welcome();
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    Enter 4 Digit PIN Code \n\n\t\t\t\t\t\t     ");
	scanf("%s", &pinCode);
	fscanf(fp1, "%s", &code);
	fscanf(fp, "%s", &num);
	if(strlen(pinCode) == 4)
	{
		if(strcmp(cnicNum, num) == 0)
		{
			if(strcmp(pinCode,code) == 0 )
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT.");delayMin();printf(".");delayMin();printf(".");
				delay();
				mainMenu(cnicNum);
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t      ----- YOU ENTERED WRONG PIN -----");Beep(1000, 400);Beep(1000, 400);Beep(1000, 400);Beep(1000, 400);
				system("cls");
				goto temp;
			}
		}	
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t ----- INVALID PIN CODE ----- \n");
		Beep(1000, 400);Beep(1000, 400);Beep(1000, 400);Beep(1000, 400);
		goto temp;
	}
	fclose(fp1);
	fclose(fp);	
}

void cnicNumber()
{
	FILE *fp;
	char cnicNum[14], num[15], num2[15];
	temp:
	fp = fopen("rec\\cnic1\\cnicnum.txt", "r");
	welcome();
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter Your 13 Digit CNIC Number \n\n\t\t\t\t\t\t ");
	scanf("%s", &cnicNum);
	fscanf(fp, "%s", &num);
	if(strlen(cnicNum) == 13)
	{
		if(( strcmp(cnicNum , num)) == 0)
		{
			delayMin();
			pinCode(cnicNum);
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     ----- YOU ARE NOT REGISTERED -----");Beep(1000, 400);Beep(1000, 400);Beep(1000, 400);Beep(1000, 400);
			system("cls");
			goto temp;
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t ----- PLEASE ENTER A VALID CNIC NUMBER ----- \a");
		delay();
		system("cls");
		goto temp;
	}
	fclose(fp);
}

int main() 
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ------------ WELCOME TO ATM ------------");
	delay();delay();delay();
	system("cls");
	cnicNumber();
	return 0;
}
