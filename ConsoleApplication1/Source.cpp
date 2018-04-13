
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
			int mas[10];
			for (int i = 0; i < 10; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case3.txt", "w")) != NULL)
			{
				for (int i = 0; i < 10; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if ((fp = fopen("case3.txt", "r")) != NULL)
			{
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}

				if ((fp1 = fopen("case3_new.txt", "w")) != NULL)
				{
					for (int i = 9; i >= 0; i--)
						fprintf(fp1, "%d\t", mas[i]);
				}
				fclose(fp1);
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
				if (((fp1 = fopen("case4_h_1.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "w")) != NULL))
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
					if (((fp1 = fopen("case4_h_1.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "r")) != NULL))
					{
						printf("����� �������\n");

						for (int i = 0; i < 12; i = i + 2)
						{
							if (i % 4 <= 1)
							{
								fscanf(fp1, "%d\t", mas[i]);
								printf("%d\t", mas[i]);
							}
							else
							{
								fscanf(fp2, "%d\t", mas[i]);
								printf("%d\t", mas[i]);
							}
						}
					}fclose(fp1);
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
		} break;

			/*6.	������� ����, ���������� �������� �������� ��������� �����. �������� �����, ������������ ����� �������*/
		case 6: {
		} break;

			/*7.	������� �������������� ����, ���������� �������� �������� ��������� �����. ���������� ��� �����,
			������������ �� ����� �.*/
		case 7: {
		} break;

			/*8.	������� �������������� ����, � ������� �������� 18 ����� �����. ���������� ��� �������������
			����� ����� � ������ � ��� �� ������*/
		case 8: {
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
		} break;
		}
	} while (n > 0);
}