
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
		printf("Введите номер задания: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			/*1.	Дана последовательность целых чисел, оканчивающаяся нулем. Записать все числа последовательности
			в типизированный файл*/
		case 1: {

			if ((fp = fopen("case1.txt", "w")) != NULL)
			{
				printf("Файл открыт\n");
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
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		} break;
			/*2.	Дан файл f, компоненты которого являются целыми числами. Записать в файл g все четные
			числа файла f, а в файл h — все нечетные. Порядок следования чисел сохраняется*/
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
				printf("Файлы открыты\n");

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
			/*3.	Дан символьный файл f. Записать в файл g ком¬поненты файла f в обратном порядке*/
		case 3: {

			char *mas = "Дан символьный файл f.";
			int countChar = strlen(mas);
			printf("Количество символов в файле: %d\n", countChar);

			if ((fp = fopen("case3.txt", "w")) != NULL)
			{
				for (int i = 0; i < countChar; i++)
					fprintf(fp, "%c", mas[i]);
			}
			fclose(fp);

			if ((fp = fopen("case3.txt", "r")) != NULL)
			{
				printf("Файл открыт\n");

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

			/*4.	Дан файл f, компоненты которого являются целыми числами. Никакая из компонент
			файла не равна нулю. Файл f содержит столько же отрицательных чисел, сколько и положительных.
			//Используя вспомогательный файл h, переписать компоненты файла f в файл g так, чтобы в файле g :
			//	//a.не было двух соседних чисел с одним знаком
				//	/*b.	сначала шли положительные, потом отрицательные числа
				/*c.	числа шли в следующем порядке: два положитель¬ных, два отрицательных, два положительных,
		//  два отрица¬тельных и т. д. (предполагается, что число компонент в файле f делится на 4)*/

		/*ВТОРОЙ ПУНКТ ЗАДАНИЯ НОМЕР 4 */
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
				printf("Файл открыт\n");
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h_2.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_2.txt", "w")) != NULL))
				{
					printf("Файлы открыты\n");
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
						printf("Файлы открыты\n");
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
				printf("Файл не открыт\n");
				exit(1);
			}
			fclose(fp);
		} break;

			/*ПЕРВЫЙ ПУНКТ ОТ ЗАДАНИЯ НОМЕР 4*/
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
				printf("Файл открыт\n");
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h_1.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "w")) != NULL))
				{
					printf("Файлы открыты\n");
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
						printf("Файлы открыты\n");
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

			/*ТРЕТИЙ ПУНКТ ОТ ЗАДАНИЯ НОМЕР 4*/
		case 43: {

			// создаем массив
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

			// записываем в новый файл
			if ((fp = fopen("case4_3.txt", "w")) != NULL)
			{
				for (int i = 0; i < 12; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			//открываем для чтения, переносим все в массив и сортируем по знаку в два доп файла
			if (((fp = fopen("case4_3.txt", "r")) != NULL))
			{
				printf("Файл открыт\n");
				for (int i = 0; i < 12; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h_3.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_3.txt", "w")) != NULL))
				{
					printf("Файлы открыты\n");
					for (int i = 0; i < 12; i++)
					{
						if (mas[i] < 0)
							fprintf(fp1, "%d\t", mas[i]);
						else
							fprintf(fp2, "%d\t", mas[i]);
					}
					fclose(fp1);
					fclose(fp2);

					// открываем два доп файла и сортируя, записываем в массив в нужном виде
					if (((fp1 = fopen("case4_h_3.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh_3.txt", "r")) != NULL))
					{
						printf("Файлы открыты\n");

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

			/*5.	Напечатать все элементы типизированного файла, каждый элемент которого — отдельное слово.
			Рассмотреть два варианта
	a.	известно, что в существующем файле записаны 12 слов
	b.	размер существующего файла неизвестен
	*/
		case 5: {
			char *mas = "Напечатать все элементы типизированного файла каждый элемент которого отдельное слово рассмотреть два.";
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

			/*6.	Имеется файл, элементами которого являются отдельные буквы. Получить слово, образованное этими буквами*/
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
				printf("набор букв, который присутвует в файле: %s\n", str);
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
				printf("вы знаете слово?1/0");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
				{
					printf("введите слово: ");
					scanf("%s", str1);

					int i = 0;
					while (i != 4)
					{
						if (word[i] == str1[i])
							i++;
						else
						{
							printf("не правильно\n"); break;
						}
					}
					if (i == 4)
					{
						printf("Правильно!\nЗаписать в файл?1/0");
						a = 0;
						scanf("%d", &a);
						switch (a)
						{
						case 1:
						{
							fprintf(fp, "%s", str1);
							printf("файл успешно записан\n");
						}break;
						case 0:
						{
							printf("файл не будет перезаписываться");
						}break;
						}
					}
				}break;

				case 0:
				{
					printf("переходим к следующему заданию\n");
				}break;
				}
			}
			fclose(fp);

		}break;

			/*7.	Имеется типизированный файл, элементами которого являются отдельные слова. Напечатать все слова,
			начинающиеся на букву с.*/
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
				printf("набор слов в данном файле:\n%s\n", str);
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

			/*8.	Имеется типизированный файл, в котором записаны 18 целых чисел. Переписать все положительные
			числа файла в массив в том же порядк*/
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

			/*9.	В существующем типизированном файле, элементами которого являются отдельные слова, изменить
			на заданное слово
a.	s-е слово
b.	последнее слово
*/
		case 9: {
		} break;

			/*10.	Элементами типизированного файла являются отдельные слова. Изменить все его элементы на другие
			слова (их значения вводятся с клавиатуры).*/
		case 10: {
		} break;

			/*11.	Имеется типизированный файл, элементами которого являются отдельные буквы, составляющие
			последовательность орпцессор. Получить новый файл, в котором буквы слова процессор будут расположены правильно*/
		case 11: {
		} break;

			/*12.	Имеется файл, элементами которого являются отдельные слова. Переписать их в другой файл.
			Размер заданного файла неизвестен.*/
		case 12: {
		} break;

			/*13.	Имеется файл с тридцатью числами. Записать в другой файл числа имеющегося файла в обратном порядке.*/
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