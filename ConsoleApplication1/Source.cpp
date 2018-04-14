
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<Windows.h>
#include<time.h>

using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	FILE *fp = NULL;
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	int n;
	do
	{
		printf("������� ����� �������: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			/*1.	���� ������������������ ����� �����, �������������� �����. �������� ��� ����� ������������������
			� �������������� ����*/
		case 1: {

			if ((fp = fopen("case1.txt", "w")) != NULL)
			{
				printf("���� ������\n");
				int *a[10];
				int mas[10] = { 1,2,3,4,5,6,7,8,9,0 };

				for (int i = 0; i < 10; i++)
				{
					fprintf(fp, "%d\t", *(mas + i));
					fprintf(fp, "\n");
				}
			}
			if (fclose(fp) == 0)
			{
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		} break;
			/*2.	��� ���� f, ���������� �������� �������� ������ �������. �������� � ���� g ��� ������
			����� ����� f, � � ���� h � ��� ��������. ������� ���������� ����� �����������*/
		case 2: {
			int mas[10];
			for (int i = 0; i < 10; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if (((fp = fopen("case2_g.txt", "w")) != NULL) && (fp1 = fopen("case2_h.txt", "w")))
			{
				printf("����� �������\n");

				for (int i = 0; i < 10; i++)
				{
					if (mas[i] % 2 == 0)
						fprintf(fp, "%d\t", mas[i]);
					else
						fprintf(fp1, "%d\t", mas[i]);
				}
			}
			fclose(fp);
			fclose(fp1);
		} break;
			/*3.	��� ���������� ���� f. �������� � ���� g ���������� ����� f � �������� �������*/
		case 3: {

			char *mas = "��� ���������� ���� f.";
			int countChar = strlen(mas);
			printf("���������� �������� � �����: %d\n", countChar);

			if ((fp = fopen("case3.txt", "w")) != NULL)
			{
				for (int i = 0; i < countChar; i++)
					fprintf(fp, "%c", mas[i]);
			}
			fclose(fp);

			if ((fp = fopen("case3.txt", "r")) != NULL)
			{
				printf("���� ������\n");

				for (int i = 0; i < countChar; i++)
				{
					fscanf(fp, "%c", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}

				if ((fp1 = fopen("case3_new.txt", "w")) != NULL)
				{
					for (int i = countChar - 1; i >= 0; i--)
						fprintf(fp1, "%c", mas[i]);
				}
				fclose(fp1);
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}

			fclose(fp);
		} break;

			/*4.	��� ���� f, ���������� �������� �������� ������ �������. ������� �� ���������
			����� �� ����� ����. ���� f �������� ������� �� ������������� �����, ������� � �������������.
			//��������� ��������������� ���� h, ���������� ���������� ����� f � ���� g ���, ����� � ����� g :
			//	//a.�� ���� ���� �������� ����� � ����� ������
				//	/*b.	������� ��� �������������, ����� ������������� �����
				/*c.	����� ��� � ��������� �������: ��� ��������������, ��� �������������, ��� �������������,
		//  ��� ������������� � �. �. (��������������, ��� ����� ��������� � ����� f ������� �� 4)*/

		/*������ ����� ������� ����� 4 */
		case 4: {
			int mas[10];
			for (int i = 0; i < 5; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			for (int i = 5; i < 10; i++)
			{
				mas[i] = -20 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case4_2.txt", "w")) != NULL)
			{
				for (int i = 0; i < 10; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if (((fp = fopen("case4_2.txt", "r")) != NULL))
			{
				printf("���� ������\n");
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h_2.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_2.txt", "w")) != NULL))
				{
					printf("����� �������\n");
					for (int i = 0; i < 10; i++)
					{
						if (mas[i] < 0)
							fprintf(fp1, "%d\t", mas[i]);
						else
							fprintf(fp2, "%d\t", mas[i]);
					}
					fclose(fp1);
					fclose(fp2);
					if (((fp1 = fopen("case4_h_2.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh_2.txt", "a+")) != NULL))
					{
						printf("����� �������\n");
						for (int i = 0; i < 5; i++)
						{
							fscanf(fp1, "%d", &mas[i]);
							/*printf("%d\t", mas[i]);*/
						}
						for (int i = 0; i < 5; i++)
						{
							fprintf(fp2, "%d\t", mas[i]);
						}
					}
					fclose(fp1);
					fclose(fp2);

				}
			}
			else
			{
				printf("���� �� ������\n");
				exit(1);
			}
			fclose(fp);
		} break;

			/*������ ����� �� ������� ����� 4*/
		case 41: {

			int mas[10];
			for (int i = 0; i < 5; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			for (int i = 5; i < 10; i++)
			{
				mas[i] = -20 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case4_1.txt", "w")) != NULL)
			{
				for (int i = 0; i < 10; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if (((fp = fopen("case4_1.txt", "r")) != NULL))
			{
				printf("���� ������\n");
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h_1.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "w")) != NULL))
				{
					printf("����� �������\n");
					for (int i = 0; i < 10; i++)
					{
						if (mas[i] < 0)
							fprintf(fp1, "%d\t", mas[i]);
						else
							fprintf(fp2, "%d\t", mas[i]);
					}
					fclose(fp1);
					fclose(fp2);
					if (((fp1 = fopen("case4_h_1.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "r")) != NULL))
					{
						printf("����� �������\n");
						for (int i = 0; i < 10; i++)
						{
							if (i % 2 == 0)
							{
								fscanf(fp1, "%d", &mas[i]);
								printf("%d\t", mas[i]);
							}
							else
							{
								fscanf(fp2, "%d", &mas[i]);
								printf("%d\t", mas[i]);
							}
						}

					}
					fclose(fp1);
					fclose(fp2);
					if (((fp2 = fopen("case4_hh_1.txt", "w+")) != NULL))
					{
						for (int i = 0; i < 10; i++)
						{
							fprintf(fp2, "%d\t", mas[i]);
						}
					}
					fclose(fp2);
				}
			}
		}break;

			/*������ ����� �� ������� ����� 4*/
		case 43: {

			// ������� ������
			int mas[12];
			for (int i = 0; i < 6; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			for (int i = 6; i < 12; i++)
			{
				mas[i] = -20 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			// ���������� � ����� ����
			if ((fp = fopen("case4_3.txt", "w")) != NULL)
			{
				for (int i = 0; i < 12; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			//��������� ��� ������, ��������� ��� � ������ � ��������� �� ����� � ��� ��� �����
			if (((fp = fopen("case4_3.txt", "r")) != NULL))
			{
				printf("���� ������\n");
				for (int i = 0; i < 12; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h_3.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_3.txt", "w")) != NULL))
				{
					printf("����� �������\n");
					for (int i = 0; i < 12; i++)
					{
						if (mas[i] < 0)
							fprintf(fp1, "%d\t", mas[i]);
						else
							fprintf(fp2, "%d\t", mas[i]);
					}
					fclose(fp1);
					fclose(fp2);

					// ��������� ��� ��� ����� � ��������, ���������� � ������ � ������ ����
					if (((fp1 = fopen("case4_h_3.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh_3.txt", "r")) != NULL))
					{
						printf("����� �������\n");

						for (int i = 0; i < 12; i++)
						{

							if (i % 4 <= 1)
							{
								fscanf(fp1, "%d", &mas[i]);
								printf("%d\t", mas[i]);
							}
							else
							{
								fscanf(fp2, "%d", &mas[i]);
								printf("%d\t", mas[i]);
							}
						}
					}
					fclose(fp1);
					fclose(fp2);

					if (((fp2 = fopen("case4_hh_3.txt", "w+")) != NULL))
					{
						for (int i = 0; i < 10; i++)
						{
							fprintf(fp2, "%d\t", mas[i]);
						}
					}
					fclose(fp2);
				}
			}
		}break;

			/*5.	���������� ��� �������� ��������������� �����, ������ ������� �������� � ��������� �����.
			����������� ��� ��������
	a.	��������, ��� � ������������ ����� �������� 12 ����
	b.	������ ������������� ����� ����������
	*/
		case 5: {
			char *mas = "���������� ��� �������� ��������������� ����� ������ ������� �������� ��������� ����� ����������� ���.";
			if ((fp = fopen("case5.txt", "w")) != NULL)
			{
				/**/
				fprintf(fp, "%s", mas);
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp);
			char mas_s[12][20];
			if ((fp = fopen("case5.txt", "r")) != NULL)
			{
				for (int i = 0; i < 12; i++)
				{
					fscanf(fp, "%s", &mas_s[i]);
					/*printf("%s\n", mas_s[i]);*/
				}
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp);

			if ((fp1 = fopen("case5_new.txt", "w")) != NULL)
			{
				for (int i = 0; i < 12; i++)
				{
					fprintf(fp1, "%s\n", mas_s[i]);
				}
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp1);

		} break;

			/*6.	������� ����, ���������� �������� �������� ��������� �����. �������� �����, ������������ ����� �������*/
		case 6: {

			if ((fp = fopen("case6.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char*str = "e l l o h";
				fprintf(fp, "%s", str);
				printf("����� ����, ������� ���������� � �����: %s\n", str);
			}
			fclose(fp);


			if ((fp = fopen("case6.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int a;
				char str1[20] = " ";
				char word[10] = "hello";
				printf("�� ������ �����?1/0");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
				{
					printf("������� �����: ");
					scanf("%s", str1);

					int i = 0;
					while (i != 4)
					{
						if (word[i] == str1[i])
							i++;
						else
						{
							printf("�� ���������\n"); break;
						}
					}
					if (i == 4)
					{
						printf("���������!\n�������� � ����?1/0");
						a = 0;
						scanf("%d", &a);
						switch (a)
						{
						case 1:
						{
							fprintf(fp, "%s", str1);
							printf("���� ������� �������\n");
						}break;
						case 0:
						{
							printf("���� �� ����� ����������������");
						}break;
						}
					}
				}break;

				case 0:
				{
					printf("��������� � ���������� �������\n");
				}break;
				}
			}
			fclose(fp);

		}break;

			/*7.	������� �������������� ����, ���������� �������� �������� ��������� �����. ���������� ��� �����,
			������������ �� ����� �.*/
		case 7: {

			int dl;
			if ((fp = fopen("case7.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char *str = "calling no cardinal mother channel ";
				fprintf(fp, "%s", str);
				printf("����� ���� � ������ �����:\n%s\n", str);
				dl = strlen(str);
			}
			fclose(fp);

			if ((fp = fopen("case7.txt", "r")) != NULL)
			{
				char mas[50];
				for (int i = 0; i < dl; i++)
				{
					mas[i] = getc(fp);
					if (i == 0 && mas[i] == 'c')
					{
						int j = i;
						do {
							printf("%c", mas[j]);
							j++;
							mas[j] = getc(fp);
						} while (mas[j] != ' ');
						printf("\n");
						i = j;
					}

					else if (mas[i] == 'c'&&mas[i - 1] == ' ')
					{
						int k = i;
						do {
							printf("%c", mas[k]);
							k++;
							mas[k] = getc(fp);
						} while (mas[k] != ' '&&k != dl);
						printf("\n");
						i = k;
					}
				}
			}
			fclose(fp);
		} break;

			/*8.	������� �������������� ����, � ������� �������� 18 ����� �����. ���������� ��� �������������
			����� ����� � ������ � ��� �� ������*/
		case 8: {
			int mas[10];
			for (int i = 0; i < 18; i++)
			{
				mas[i] = -10 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case8.txt", "w")) != NULL)
			{
				for (int i = 0; i < 18; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if ((fp = fopen("case8.txt", "r")) != NULL)
			{
				for (int i = 0; i < 18; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}

				if ((fp1 = fopen("case8_new.txt", "w")) != NULL)
				{
					for (int i = 0; i < 18; i++)
					{
						if (mas[i] > 0)
						{
							fprintf(fp1, "%d\t", mas[i]);
						}
					}
				}
				fclose(fp1);
			}
			fclose(fp);
		} break;

			/*9.	� ������������ �������������� �����, ���������� �������� �������� ��������� �����, ��������
			�� �������� �����
a.	s-� �����
b.	��������� �����
*/
		case 9: {
		} break;

			/*10.	���������� ��������������� ����� �������� ��������� �����. �������� ��� ��� �������� �� ������
			����� (�� �������� �������� � ����������).*/
		case 10: {
		} break;

			/*11.	������� �������������� ����, ���������� �������� �������� ��������� �����, ������������
			������������������ ���������. �������� ����� ����, � ������� ����� ����� ��������� ����� ����������� ���������*/
		case 11: {
		} break;

			/*12.	������� ����, ���������� �������� �������� ��������� �����. ���������� �� � ������ ����.
			������ ��������� ����� ����������.*/
		case 12: {
		} break;

			/*13.	������� ���� � ��������� �������. �������� � ������ ���� ����� ���������� ����� � �������� �������.*/
		case 13: {
			int mas[10];
			for (int i = 0; i < 30; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case13.txt", "w")) != NULL)
			{
				for (int i = 0; i < 30; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if ((fp = fopen("case13.txt", "r")) != NULL)
			{
				for (int i = 0; i < 30; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}

				if ((fp1 = fopen("case13_new.txt", "w")) != NULL)
				{
					for (int i = 29; i >= 0; i--)
						fprintf(fp1, "%d\t", mas[i]);
				}
				fclose(fp1);
			}
			fclose(fp);
		} break;
		}
	} while (n > 0);
}