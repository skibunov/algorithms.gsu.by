#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Organization
{
	char cypher[21];
	char name[21];
	char nameString[21];
	int summ;
	char view[21];
	struct Organization* next;//Указатель на следующий элемент списка
}Organization;

void new_el(Organization**, const char*, const char*, const char*,const int, const char*);
void add(Organization**);
void print(Organization*);
void delete_el(Organization**);
void change(Organization**);
void sort_int(Organization**);
void sort_char(Organization**);
void write(Organization*);
void read(Organization**);
void menu(Organization**);
void menu_change(Organization**);
void menu_sort(Organization**);

int main()
{
	setlocale(LC_ALL, "Russian");
	Organization* head = NULL;
	menu(&head);
}

void new_el(Organization** list,const char* cypher, const char* name,const char* nameString, const int summ, const char* view)//создание нового элемента
{
	Organization* b = (Organization*)calloc(1, sizeof(Organization));//выделение памяти под новый элемент планеты
	if (b)
	{
		strcpy(b->cypher,cypher);
		strcpy(b->name,name);
		strcpy(b->nameString,nameString);
		b->summ = summ;
		strcpy(b->view,view);
		b->next = (*list);//заносим указатель на следующий элемент списка
		(*list) = b;
	}
}
void add(Organization** list)//добавление элемента в начало списка
{
	printf("Добавление элемента в начало списка:\n");
	char a[21] = { '\0' }, b[21] = { '\0' }, c[21] = { '\0' }, e[21] = { '\0' };
	int d = 0;
	printf("Введите шифр договора: ");
	scanf("%s%*c", a, 21);
	printf("Введите наименоваение организации: ");
	scanf("%s%*c", b, 21);
	printf("Введите наименоваение контрагента строки выполнения: ");
	scanf("%s%*c", c, 21);
    printf("Введите сумму договора: ");
	scanf("%i%*c", &d);
	printf("Введите вид договора: ");
	scanf("%s%*c", e, 21);
	new_el(list, a, b, c, d, e);//вызов функции для создания элемента
	printf("Элемент успешно добавлен в список\n");
}
void print(Organization* list) //фунция вывода на экран
{
	printf("_______________________________________________________________________________________________________________________________\n");
	printf("| № | Шифр договора     |   Наименоваение организации   |       наименоваение контрагента строки выполнения       |  Сумма договора    |   Вид договора   |\n");
	printf("_______________________________________________________________________________________________________________________________\n");
	int i = 1;
	while (list != NULL)//цикл по всему списку
	{
		printf("|%3i|%20s|%20s|%20s|%23i|%25s|\n", i++, list->cypher, list->name, list->nameString, list->summ, list->view);
		printf("_______________________________________________________________________________________________________________________________\n");
		list = list->next;//переход к следующему элементу списка
	}
}
void delete_el(Organization** list)//удаление элемента из списка
{
	printf("Введите номер элемента списка: ");
	int nom;
	scanf("%i", &nom);//получаем номер для удаления
	if (nom <= 0)//проверяем корректность номера
	{
		printf("Введён неверный номер\n");
		return;
	}
	Organization* p = (*list), * w;
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->next;//идем по спику к нашему номеру
	}
	if (p != NULL)
	{
		if (p == (*list))//если элемент первый,переносим указатель на 1
		{
			(*list) = (*list)->next;
			free(p);
		}
		else
		{
			w = (*list);
			while (w->next != p)
			{
				w = w->next;
			}
			w->next = p->next;
			free(p);
		}
		printf("Элемент списка удалён успешно\n");
	}
	else
	{
		printf("Элементов в списке меньше, чем введённое число\n");
	}
}
void change(Organization** list)//изменение элемента
{
	printf("Введите номер элемента списка: ");
	int nom;//получаем номер для изменения
	scanf("%i", &nom);
	if (nom <= 0)//проверяем корректность введенного номера
	{
		printf("Введён не верный номер\n");
		return;
	}
	Organization* p = (*list);
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->next;//получаем наш элемент списка
	}
	if (p != NULL)
	{
		menu_change(&p);//если он существует, вызываем меню изменения
	}
	else
	{
		printf("Элементов в списке меньше, чем введённый номер\n");//иначе генерируем ошибку
	}
}
void sort_int(Organization** list)//сортировка по числовому полю
{
	Organization* a = NULL, * b = NULL, * c = NULL, * e = NULL, * tmp = NULL;//объявляем переменные
	while (e != (*list)->next)//цикл по списку
	{
		c = a = (*list);//текущий элемент
		b = a->next; //следующий
		while (a != e)
		{
			if (a->summ > b->summ)//если текущий больше следующего
			{
				if (a == (*list))//меняем их местами
				{
					tmp = b->next;
					b->next = a;
					a->next = tmp;
					(*list) = b;
					c = b;
				}
				else
				{
					tmp = b->next;
					b->next = a;
					a->next = tmp;
					c->next = b;
					c = b;
				}
			}
			else//иначе идем дальше
			{
				c = a;
				a = a->next;
			}
			b = a->next;
			if (b == e)
			{
				e = a;
			}
		}
	}
	printf("Элементы списка отсортированны по сумме\n");
}
void sort_char(Organization** list)//сортировка по символьному полю
{
	Organization* new_list = NULL;
	while ((*list) != NULL)//цикл по списку
	{
		Organization* node = (*list);//текущий
		(*list) = (*list)->next;//следующий
		if ((new_list == NULL) || (strcmp(node->cypher, new_list->cypher) == -1))//если выполняется проверка, то меняем местами
		{
			node->next = new_list;
			new_list = node;
		}
		else
		{
			Organization* current = new_list;
			while ((current->next != NULL) && !(strcmp(node->cypher, (current->next)->cypher) == -1))//идем дальше по списку
			{
				current = current->next;
			}
			node->next = current->next;//меняем местами
			current->next = node;
		}
	}
	if (new_list)
	{
		(*list) = new_list;//заносим новый список в наш список
	}
	printf("Элементы списка отсортированны по шифру договора\n");
}
void write(Organization* list)//запись в файл
{
	const char fname[] = "save.dat";//заносим название файла
	FILE* f=fopen(fname, "w");//открываем файл для записи
	while (list != NULL)// заносим весь наш список в файл
	{
		fprintf(f, "%21s%21s%21s%18i%21s\n",list->cypher, list->name, list->nameString, list->summ, list->view);
		list = list->next;
	}
	fclose(f);//закрываем файл
	printf("Список успешно добавлен в файл\n");
}
void read(Organization** list)//чтение из файла
{
	const char fname[] = "list.dat";//заносим название файла
	FILE* f=fopen(fname, "r");//открываем файл для чтения
	Organization* b = (Organization*)calloc(0,sizeof(Organization));//выделяем память под объект планеты
	while ((*list) != NULL)
	{
		Organization* p = (*list);
		if ((*list))
		{
			(*list) = (*list)->next;
		}
		free(p);
	}
	int z, k = 0;
	while ((z = fscanf(f, "%s%s%s%i%s\n", b->cypher, b->name, b->nameString, &b->summ, b->view)) > 0)//пока есть элементы списка цикл считает количество элементов
	{
		k++;
	}

	do
	{
		fseek(f, 0, SEEK_SET);
		fseek(f, (k-1) * 120, SEEK_CUR);//устанавливаем указатель файла
		fscanf(f, "%s%s%s%i%s%\n", b->cypher, b->name, b->nameString, &b->summ, b->view); //считываем данные элемента
		new_el(list, b->cypher, b->name, b->nameString, b->summ, b->view);//заносим элемент в список
		k--;//уменьшаем количество элементов
	} while (k);
	fclose(f);//уменьшаем количество элементов
	printf("Список успешно извлечён из файла\n");
}

void menu(Organization** list)//меню
{
	system("pause");
	system("cls");
	printf("Выберите действие:\n");//выбор действия
	printf("1. Добавить элемент в начало списка;\n2. Вывод элементов списка на экран;\n3. Удалить элемент списка;\n4. Изменения значений элемента списка;\n5. Сортировка элементов списка;\n6. Запись списка в файл;\n7. Чтение списка из файла;\n0. Выход.\n");
	printf("Ваш выбор: ");
	int nom;
	scanf("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		add(list);
		break;
	case 2:
		printf("Вывод элементов списка на экран\n");
		if ((*list) == NULL)
		{
			printf("Список пуст, нечего выводить на экран\n");
		}
		else
		{
			print(*list);
		}
		break;
	case 3:
		printf("Удаление элемента списка:\n");
		if ((*list) == NULL)
		{
			printf("Список пуст, нечего удалять\n");
		}
		else
		{
			delete_el(list);
		}
		break;
	case 4:
		printf("Изменение элемента списка:\n");
		if ((*list) == NULL)
		{
			printf("Список пуст, нечего изменять\n");
		}
		else
		{
			change(list);
		}
		break;
	case 5:
		printf("Сортировка элементов списка:\n");
		if ((*list) == NULL)
		{
			printf("Список пуст, нечего сортировать\n");
		}
		else
		{
			menu_sort(list);
		}
		break;
	case 6:
		write(*list);
		break;
	case 7:
		read(list);
		break;
	case 0:
		exit(0);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		break;
	}
	menu(list);
}
void menu_change(Organization** list)//меню изменения элемента
{
	printf("Выберите действие:\n");
	printf("1. Изменить шифр договора;\n2. Изменить наименование организации;\n3. Изменить наименование контрагента строки выполнения;\n4. Изменить сумма договора;\n5. Изменить вид договора;\n6. Изменить все данные;\n0. Назад.\n");
	printf("Ваш выбор: ");
	int nom;
	scanf("%i%*c", &nom);
	system("cls");
	printf("Изменение элемента списка:\n");
	switch (nom)
	{
	case 1:
		printf("Старый шифр договора: %s\n", (*list)->cypher);
		printf("Новый шифр договора: ");
		scanf("%s%*c", (*list)->cypher, 21);
		break;
	case 2:
		printf("Старое наименование организации: %s\n", (*list)->name);
		printf("Новое наименование организации: ");
		scanf("%s%*c", (*list)->name,21);
		break;
	case 3:
		printf("Старое наименование контрагента строки выполнения: %s\n", (*list)->nameString);
		printf("Новое наименование контрагента строки выполнения: ");
		scanf("%s%*c", (*list)->nameString, 21);
		break;
	case 4:
		printf("Старая сумма договора: %i\n", (*list)->summ);
		printf("Новая сумма договора: ");
		scanf("%i%*c", &(*list)->summ);
		break;
	case 5:
		printf("Старый вид договора: %s\n", (*list)->view);
		printf("Новый вид договора: ");
		scanf("%s%*c", (*list)->view, 21);
		break;
	case 6:
		printf("Старый шифр договора: %s\n", (*list)->cypher);
		printf("Новый шифр договора: ");
		scanf("%s%*c", (*list)->cypher, 21);
		printf("Старое наименование организации: %s\n", (*list)->name);
		printf("Новое наименование организации: ");
		scanf("%s%*c", (*list)->name,21);
		printf("Старое наименование контрагента строки выполнения: %s\n", (*list)->nameString);
		printf("Новое наименование контрагента строки выполнения: ");
		scanf("%s%*c", (*list)->nameString, 21);
		printf("Старая сумма договора: %i\n", (*list)->summ);
		printf("Новая сумма договора: ");
		scanf("%i%*c", &(*list)->summ);
		printf("Старый вид договора: %s\n", (*list)->view);
		printf("Новый вид договора: ");
		scanf("%s%*c", (*list)->view, 21);
		break;
	case 0:
		printf("Переход к предыдущему меню\n");
		menu(list);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		system("pause");
		system("cls");
		menu_change(list);
		break;
	}
}
void menu_sort(Organization** list)//меню сортировки
{
	printf("Выберите действие:\n");
	printf("1. Отсортировать по шифру договора;\n2. Отсортировать по сумме;\n0. Назад.\n");
	printf("Ваш выбор: ");
	int nom;
	scanf("%i%*c", &nom);
	system("cls");
	printf("Сортировка элементов списка:\n");
	switch (nom)
	{
	case 1:
		sort_char(list);
		break;
	case 2:
		sort_int(list);
		break;
	case 0:
		printf("Переход к предыдущему меню\n");
		menu(list);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		system("pause");
		system("cls");
		menu_sort(list);
		break;
	}
}
