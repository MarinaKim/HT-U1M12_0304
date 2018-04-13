
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
				if (((fp1 = fopen("case4_h_1.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "w")) != NULL))
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
					if (((fp1 = fopen("case4_h_1.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh_1.txt", "r")) != NULL))
					{
						printf("Файлы открыты\n");

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

			/*5.	Напечатать все элементы типизированного файла, каждый элемент которого — отдельное слово.
			Рассмотреть два варианта
	a.	известно, что в существующем файле записаны 12 слов
	b.	размер существующего файла неизвестен
	*/
		case 5: {
		} break;

			/*6.	Имеется файл, элементами которого являются отдельные буквы. Получить слово, образованное этими буквами*/
		case 6: {
		} break;

			/*7.	Имеется типизированный файл, элементами которого являются отдельные слова. Напечатать все слова,
			начинающиеся на букву с.*/
		case 7: {
		} break;

			/*8.	Имеется типизированный файл, в котором записаны 18 целых чисел. Переписать все положительные
			числа файла в массив в том же порядк*/
		case 8: {
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
		} break;
		}
	} while (n > 0);
}