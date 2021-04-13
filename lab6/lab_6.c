#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Договорная деятельность организации
typedef struct _Documentation
{
	char name[21];//вид договора
	char start[21];//срок заключения
	char end[21]; //срок истечения договора
	struct _Documentation* next;//Указатель на следующий элемент списка
	struct _Documentation* prev;//Указатель на предыдущий элемент списка
}Documentation;

typedef struct _Organization
{
	char cypher[21];//шифр договора
	char company[21];//наименование организации
	char string[21];//наименование контрагента сроки выполнения
	int sum; //сумма договора
	Documentation* document;//вид договора
	struct _Organization* next;//Указатель на следующий элемент списка
	struct _Organization* prev;//Указатель на предыдущий элемент списка
}Organization;

void new_element(Organization** list, const char* cypher, const char* company,const char* string, int sum, const char* name, const char* start, const char* end);
void new_element_career(Documentation** list, const char* name, const char* start, const char* end);
void add_element(Organization** list);
void add_element_career(Documentation** list);
void print(Organization* list);
void delete_element(Organization** list);
void delete_element_career(Organization** list);
void change_element(Organization** list);
void sort_char(Organization** list);
void sort_int(Organization** list);
void write(Organization* list);
void read(Organization** list);

void main_menu(Organization** list);
void menu_add_element(Organization** list);
void menu_add_element_career(Organization** list);
void menu_change_element(Organization** list);


int main()
{
	setlocale(0,"Russian");
	Organization* list = NULL;
	main_menu(&list);
}

void new_element(Organization** list, const char* cypher, const char* company, const char* string, int sum, const char* name, const char* start, const char* end)
{
	Organization* b = (Organization*)calloc(1, sizeof(Organization));
	if (b)
	{
		strcpy_s(b->cypher, 21, cypher);
		strcpy_s(b->company, 21, company);
		strcpy_s(b->string, 21, string);
		b->sum = sum;
		new_element_career(&b->document, name, start, end);
		b->prev = (*list);
		if (*list)
		{
			(*list)->next = b;
		}
		(*list) = b;
	}
}
void new_element_career(Documentation** list, const char* name, const char* start, const char* end)
{
	Documentation* b = (Documentation*)calloc(1, sizeof(Documentation));
	if (b)
	{
		strcpy_s(b->name, 21, name);
		strcpy_s(b->start, 21, start);
		strcpy_s(b->end, 21, end);

		b->prev = (*list);
		if (*list)
		{
			(*list)->next = b;
		}
		(*list) = b;
	}
}
void add_element(Organization** list)
{
	char a[21], d[21], c[21], b[21], e[21], h[21];
	int s;
	printf("Введите шифр договора: ");
	scanf_s("%s%*c", a, 21);
	printf("Введите наименование организации: ");
	scanf_s("%s%*c", b, 21);
	printf("Введите наименование контрагента сроки выполнения: ");
	scanf_s("%s%*c", c, 21);
	printf("Введите сумма договора: ");
	scanf_s("%i%*c", &s);
	printf("Введите вид договора: ");
	scanf_s("%s%*c", d, 21);
    printf("Введите срок заключения: ");
	scanf_s("%s%*c", e, 21);
    printf("Введите срок истечения договора: ");
	scanf_s("%s%*c", h, 21);
	new_element(list, a, b, c, s, d, e, h);
}
void add_element_career(Documentation** list)
{
	char a[21], b[21], c[21];
	printf("Введите вид договора: ");
	scanf_s("%s%*c", a, 21);
	printf("Введите срок заключения: ");
	scanf_s("%s%*c", b, 21);
	printf("Введите срок истечения договора:");
	scanf_s("%s%*c", c, 21);
	new_element_career(list, a, b, c);
}
void print(Organization* list)
{
	printf("________________________________________________________________________________\n");
	printf("|   |    |            |                |     |                Договор          |\n");
	printf("| № |Шифр|Наименование|Сроки выполнения|Сумма|_________________________________|\n");
	printf("|   |    |            |                |     | № | Вид | Срок | Срок истечения |\n");
	printf("________________________________________________________________________________\n");
	int i = 1;
	while (list != NULL)
	{
		Documentation* a = list->document;
		int j = 1;
		if (a != NULL)
		{
			printf("|%3i|%4s|%12s|%16s|%5i|%3i|%5s|%6s|%16s|\n", i++, list->cypher, list->company,list->string,list->sum, j++, a->name, a->start, a->end);
			a = a->prev;
			while (a != NULL)
			{
				printf("|   |    |            |                |     |__________________________________\n");
				printf("|   |    |            |                |     |%3i|%5s|%6s|%16s|\n", j++, a->name, a->start, a->end);
				a = a->prev;
			}
		}
		else
		{
			printf("|%3i|%4s|%12s|%16s|%5i|%3i|                 |                    |                    |\n", i++, list->cypher, list->company,list->string,list->sum, j++);
		}
		printf("________________________________________________________________________________\n");
		list = list->prev;
	}
}
void delete_element(Organization** list)
{
	printf("Удаление элемента списка по номеру:\n");
	printf("Введите номер элемента списка: ");
	int nom;
	scanf_s("%i", &nom);
	if (nom <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	Organization* p = (*list), * w;
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->prev;
	}
	if (p != NULL)
	{
		if (p == (*list))
		{
			(*list) = (*list)->prev;
			(*list)->next = p->next;
			free(p);
		}
		else
		{
			w = p->next;
			w->prev = p->prev;
			free(p);
		}
		printf("Элемент списка удалён успешно\n");
	}
	else
	{
		printf("Элементов в списке меньше, чем введённое число\n");
	}
}
void delete_element_career(Organization** list)
{
	printf("Выбор элемента списка:\n");
	int nomer;
	Organization* a = (*list);
	printf("Введите номер элемента списка: ");
	scanf_s("%i%*c", &nomer);
	if (nomer <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	for (int i = 1; i < nomer && a != NULL; i++)
	{
		a = a->prev;
	}
	if (a == NULL)
	{
		printf("Элементов в списке меньше, чем введённое число\n");
		return;
	}
	system("cls");
	printf("Удаление элемента списка карьеры элемента %i по номеру:\n", nomer);
	printf("Введите номер элемента списка карьеры элемента %i: ", nomer);
	int nom;
	scanf_s("%i", &nom);
	if (nom <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	Documentation* p = a->document, * w;
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->prev;
	}
	if (p != NULL)
	{
		if (p == a->document)
		{
			a->document = a->document->prev;
			free(p);
		}
		else
		{
			w = p->next;
			w->prev = p->prev;
			free(p);
		}
		printf("Элемент успешно удалён из список карьеры элемента %i по номеру %i\n", nomer, nom);
	}
	else
	{
		printf("Элементов в списке карьеры элемента %i меньше, чем введённое число\n", nomer);
	}
}
void change_element(Organization** list)
{
	printf("Введите номер элемента списка: ");
	int nom;
	scanf_s("%i", &nom);
	if (nom <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	system("cls");
	Organization* p = (*list);
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->prev;
	}
	if (p != NULL)
	{
		menu_change_element(&p);
	}
	else
	{
		printf("Элементов в списке меньше, чем введённый номер\n");
	}
}
void sort_char(Organization** list)
{
	Organization* new_list = NULL;
	while ((*list) != NULL)
	{
		Organization* node = (*list);
		(*list) = (*list)->prev;
		if ((new_list == NULL) || (strcmp(node->cypher, new_list->cypher) == -1))
		{
			node->prev = new_list;
			new_list = node;
		}
		else
		{
			Organization* current = new_list;
			while ((current->prev != NULL) && !(strcmp(node->cypher, (current->prev)->cypher) == -1))
			{
				current = current->prev;
			}
			node->prev = current->prev;
			current->prev = node;
		}
	}
	if (new_list)
	{
		(*list) = new_list;
	}
	printf("Элементы списка отсортированны\n");
}
void sort_int(Organization** list)
{
	printf("Выбор элемента списка:\n");
	int nomer;
	Organization* aaa = (*list);
	printf("Введите номер элемента списка: ");
	scanf_s("%i%*c", &nomer);
	if (nomer <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	for (int i = 1; i < nomer && aaa != NULL; i++)
	{
		aaa = aaa->prev;
	}
	if (aaa == NULL)
	{
		printf("Элементов в списке меньше, чем введённое число\n");
		return;
	}
	Documentation* a = NULL, * b = NULL, * c = NULL, * e = NULL, * tmp = NULL;
	while (e != aaa->document->prev)
	{
		c = a = aaa->document;
		b = a->prev;
		while (a != e)
		{
			if (strcmp(a->start,b->start))
			{
				if (a == aaa->document)
				{
					tmp = b->prev;
					b->prev = a;
					a->prev = tmp;
					aaa->document = b;
					c = b;
				}
				else
				{
					tmp = b->prev;
					b->prev = a;
					a->prev = tmp;
					c->prev = b;
					c = b;
				}
			}
			else
			{
				c = a;
				a = a->prev;
			}
			b = a->prev;
			if (b == e)
			{
				e = a;
			}
		}
	}
	printf("Элементы списка отсортированны\n");
}
void write(Organization* list)
{
	const char name[] = "file.dat";
	FILE* f;
	fopen_s(&f, name, "w");
	while (list != NULL)
	{
		Documentation* a = list->document;
		if (a != NULL)
		{
			fprintf(f, "%21s%21s%21s%18i%21s%21s%21s\n", list->cypher, list->company, list->string, list->sum, a->name, a->start, a->end);
			a = a->prev;
			while (a != NULL)
			{
				fprintf(f, "                                          %18s%21s%21s\n", a->name, a->start, a->end);
				a = a->prev;
			}
		}
		else
		{
			fprintf(f, "%21s%21s%21s%18i\n",list->cypher, list->company, list->string, list->sum);
		}
		list = list->prev;
	}
	fclose(f);
	printf("Список успешно добавлен в файл\n");
}
void read(Organization** list)
{
	const char name[] = "file.dat";
	FILE* f;
	fopen_s(&f, name, "r");
	while ((*list) != NULL)
	{
		Organization* p = (*list);
		if ((*list))
		{
			while ((*list)->document != NULL)
			{
				Documentation* q = (*list)->document;
				if ((*list)->document)
				{
					(*list)->document = (*list)->document->prev;
				}
				free(q);
			}
			(*list) = (*list)->prev;
		}
		free(p);
	}
	int z, k = 0, q = 0;;
	Organization* b = (Organization*)calloc(1, sizeof(Organization));
	Documentation* a = (Documentation*)calloc(1, sizeof(Documentation));
	char* str = (char*)calloc(101, sizeof(char));
	//char str[117] = { '\0' };
	while ((z = fgets(str, 104, f)/*fscanf_s(f, "%s%s%s%s%i%lg%*c", b->surname, 21, b->name, 21, a->team, 21, a->sport, 21, &a->score, &a->point)*/) > 0)
	{
		if (str[20] != ' ')
		{
			k++;
		}
		q++;
	}
	if (k == 0)
	{
		printf("Файл пуст\n");
	}
	else
	{
		do
		{
			fseek(f, 0, SEEK_SET);
			fseek(f, (q - 1) * 104, SEEK_CUR);
			int z, x = q;
			while ((z = fgets(str, 104, f)) > 0)
			{
				if (str[20] != ' ')
				{
					break;
				}
				x--;
				fseek(f, 0, SEEK_SET);
				fseek(f, (x - 1) * 104, SEEK_CUR);
			}
			fseek(f, 0, SEEK_SET);
			fseek(f, (x - 1) * 104, SEEK_CUR);
			fscanf_s(f, "%s%s%s%i%s%s%s%*c", b->cypher, 21, b->company, 21, b->string, 21, &b->sum, a->name, 21, a->start, 21, a->end, 21);
			int qq = x;
			while (qq - q != 0)
			{
				fscanf_s(f, "%s%s%s%*c", a->name, 21, a->start, 21, a->end, 21);
				qq++;
			}
			new_element(list, b->cypher,b->company,b->string,b->sum, a->name, a->start, a->end);
			while (q - x != 0)
			{
				qq--;
				fseek(f, 0, SEEK_SET);
				fseek(f, (qq - 1) * 104, SEEK_CUR);
				if (qq == x)
				{
					fscanf_s(f, "%s%s%s%i%s%s%s%*c", b->cypher, 21, b->company, 21, b->string, 21, &b->sum, a->name, 21, a->start, 21, a->end, 21);
				}
				else
				{
					fscanf_s(f, "%s%s%s%*c", a->name, 21, a->start, 21, a->end, 21);
				}
				new_element_career(&(*list)->document, a->name, a->start, a->end);
				q--;
				/*fgets(str, 117, f);
				str += 42;
				char team[21], sport[21];
				int score;
				double point;
				strncpy(team, str, 21);
				strncpy(sport, str, 21);*/
			}
			q--;
		} while (q > 0);
		fclose(f);
		printf("Список успешно извлечён из файла\n");
	}
}

void main_menu(Organization** list)
{
	system("pause");
	system("cls");
	printf("Выберите действие:\n"
		"1. Добавить элемент в список организации;\n"
		"2. Добавить элемент в список документов;\n"
		"3. Вывод элементов списка на экран;\n"
		"4. Удаление элемента списка организации по номеру;\n"
		"5. Удаление элемента списка документов по номеру;\n"
		"6. Изменить значение элемента списка по номеру;\n"
		"7. Сортировка элементов списка документов по названию шрифру;\n"
		"8. Сортировка элементов списка товаров по сроку заключения;\n"
		"9. Запись в файл;\n"
		"10. Чтение из файла;\n"
		"0. Выход.\n");
	printf("Ваш выбор: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		menu_add_element(list);
		break;
	case 2:
		menu_add_element_career(list);
		break;
	case 3:
		if (*list == NULL)
		{
			printf("Список пуст, нечего выводить на экран\n");
		}
		else
		{
			print(*list);
		}
		break;
	case 4:
		if (*list == NULL)
		{
			printf("Список пуст, нечего удалять\n");
		}
		else
		{
			delete_element(list);
		}
		break;
	case 5:
		if (*list == NULL)
		{
			printf("Список пуст, нечего удалять\n");
		}
		else
		{
			if ((*list)->document == NULL)
			{
				printf("Список карьеры пуст, нечего удалять\n");
			}
			else
			{
				delete_element_career(list);
			}
		}
		break;
	case 6:
		if ((*list) == NULL)
		{
			printf("Список пуст, нечего изменять\n");
		}
		else
		{
			change_element(list);
		}
		break;
	case 7:
		if ((*list) == NULL)
		{
			printf("Список пуст, нечего сортировать\n");
		}
		else
		{
			sort_char(list);
		}
		break;
	case 8:
		if (*list == NULL)
		{
			printf("Список пуст, нечего сортировать\n");
		}
		else
		{
			if ((*list)->document == NULL)
			{
				printf("Список карьеры пуст, нечего сортировать\n");
			}
			else
			{
				sort_int(list);
			}
		}
		break;
	case 9:
		write(*list);
		break;
	case 10:
		read(list);
		break;
	case 0:
		exit(0);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		break;
	}
	main_menu(list);
}
void menu_add_element(Organization** list)
{
	system("cls");
	printf("Выберите действие:\n"
		"1. Добавить элемент в начало списка;\n"
		"2. Добавить элемент в список по номеру;\n"
		"3. Добавить элемент в конец списка;\n"
		"0. Назад.\n");
	printf("Ваш выбор: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		printf("Добавление элемента в начало списка:\n");
		add_element(list);
		printf("Элемент успешно добавлен в начало списка\n");
		break;
	case 2:
		printf("Добавление элемента в список по номеру:\n");
		int n, kol = 0;
		printf("Введите номер элемента списка: ");
		scanf_s("%i%*c", &n);
		if (n <= 0)
		{
			printf("Введён не верный номер\n");
			break;
		}
		if (n == 1)
		{
			add_element(list);
			printf("Элемент успешно добавлен в список по номеру %i\n", n);
		}
		else
		{
			for (Organization* i = (*list); i != NULL; i = i->prev)
			{
				kol++;
			}
			if (kol + 1 == n)
			{
				Organization* w = NULL, * p = (*list);
				add_element(&w);
				while (p->prev != NULL)
				{
					p = p->prev;
				}
				p->prev = w;
				w->next = p;
				printf("Элемент успешно добавлен в список по номеру %i\n", n);
			}
			else
			{
				Organization* w = NULL, * p = (*list);
				for (int i = 1; i < n && p != NULL; i++)
				{
					p = p->prev;
				}
				if (p != NULL)
				{
					add_element(&w);
					w->prev = p;
					w->next = p->next;
					(w->prev)->next = w;
					(w->next)->prev = w;
					printf("Элемент успешно добавлен в список по номеру %i\n", n);
				}
				else
				{
					printf("Элементов в списке меньше, чем введённое число\n");
				}
			}
		}
		break;
	case 3:
		printf("Добавление элемента в конец списка:\n");
		if ((*list) == NULL)
		{
			add_element(list);
		}
		else
		{
			Organization* w = NULL, * p = (*list);
			add_element(&w);
			while (p->prev != NULL)
			{
				p = p->prev;
			}
			p->prev = w;
			w->next = p;
		}
		printf("Элемент успешно добавлен в конец списка\n");
		break;
	case 0:
		main_menu(list);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		menu_add_element(list);
		break;
	}
	main_menu(list);
}
void menu_add_element_career(Organization** list)
{
	printf("Выбор элемента списка:\n");
	int nomer;
	Organization* a = (*list);
	printf("Введите номер элемента списка: ");
	scanf_s("%i%*c", &nomer);
	if (nomer <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	for (int i = 1; i < nomer && a != NULL; i++)
	{
		a = a->prev;
	}
	if (a == NULL)
	{
		printf("Элементов в списке меньше, чем введённое число\n");
		return;
	}
	system("cls");
	printf("Выберите действие:\n"
		"1. Добавить элемент в начало списка документы элемента %i;\n"
		"2. Добавить элемент в список документы элемента %i по номеру;\n"
		"3. Добавить элемент в конец списка документы элемента %i;\n"
		"0. Назад.\n", nomer, nomer, nomer);
	printf("Ваш выбор: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		printf("Добавление элемента в начало списка документы элемента %i:\n", nomer);
		add_element_career(&a->document);
		printf("Элемент успешно добавлен в начало списка документы элемента %i\n", nomer);
		break;
	case 2:
		printf("Добавление элемента в список документы элемента %i по номеру:\n", nomer);
		int n, kol = 0;
		printf("Введите номер элемента списка документы элемента %i: ", nomer);
		scanf_s("%i%*c", &n);
		if (n <= 0)
		{
			printf("Введён не верный номер\n");
			break;
		}
		if (n == 1)
		{
			add_element_career(&a->document);
			printf("Элемент успешно добавлен в список документы элемента %i по номеру %i\n", nomer, n);
		}
		else
		{
			for (Documentation* i = a->document; i != NULL; i = i->prev)
			{
				kol++;
			}
			if (kol + 1 == n)
			{
				Documentation* w = NULL, * p = a->document;
				add_element_career(&w);
				while (p->prev != NULL)
				{
					p = p->prev;
				}
				p->prev = w;
				w->next = p;
				printf("Элемент успешно добавлен в список документы элемента %i по номеру %i\n", nomer, n);
			}
			else
			{
				Documentation* w = NULL, * p = a->document;
				for (int i = 1; i < n && p != NULL; i++)
				{
					p = p->prev;
				}
				if (p != NULL)
				{
					add_element_career(&w);
					w->prev = p;
					w->next = p->next;
					(w->prev)->next = w;
					(w->next)->prev = w;
					printf("Элемент успешно добавлен в список документы элемента %i по номеру %i\n", nomer, n);
				}
				else
				{
					printf("Элементов в списке документы элемента %i меньше, чем введённое число\n", nomer);
				}
			}
		}
		break;
	case 3:
		printf("Добавление элемента в конец списка элемента %i:\n", nomer);
		if (a->document == NULL)
		{
			add_element_career(&a->document);
		}
		else
		{
			Documentation* w = NULL, * p = a->document;
			add_element_career(&w);
			while (p->prev != NULL)
			{
				p = p->prev;
			}
			p->prev = w;
			w->next = p;
		}
		printf("Элемент успешно добавлен в конец спискаэлемента %i\n", nomer);
		break;
	case 0:
		main_menu(list);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		menu_add_element_career(list);
		break;
	}
	main_menu(list);
}
void menu_change_element(Organization** list)
{
	printf("Введите номер элемента списка документы: ");
	int nomer;
	scanf_s("%i", &nomer);
	if (nomer <= 0)
	{
		printf("Введён не верный номер\n");
		return;
	}
	Documentation* w = (*list)->document;
	for (int i = 1; i < nomer && w != NULL; i++)
	{
		w = w->prev;
	}
	if (w == NULL)
	{
		printf("Элементов в списке документы меньше, чем введённый номер\n");
		return;
	}
	printf("Выберите действие:\n");
	printf("1. Изменить Шифр договора;\n2. Изменить наименование организации;\n3. Изменить наименование контрагента сроки выполнения;\n4. Изменить сумма договора;\n5. Изменить вид договора;\n6. Изменить срок заключения;\n7. Изменить срок истечения договора\n8. Изменить все данные;\n0. Назад.\n");
	printf("Ваш выбор: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	printf("Изменение элемента списка:\n");
	switch (nom)
	{
	case 1:
		printf("Старый Шифр договора: %s\n", (*list)->cypher);
		printf("Новый шифр договора: ");
		scanf_s("%s%*c", (*list)->cypher, 21);
		break;
	case 2:
		printf("Старое наименование организации: %s\n", (*list)->company);
		printf("Новая количество на складе: ");
		scanf_s("%s%*c", (*list)->company, 21);
		break;
	case 3:
		printf("Старое наименование контрагента сроки выполнения: %s\n", (*list)->string);
		printf("Новая стоимость единицы: ");
		scanf_s("%s%*c", (*list)->string, 21);
		break;
	case 4:
		printf("Старая сумма договора: %i\n",(*list)->sum);
		printf("Новая сумма договора: ");
		scanf_s("%i%*c", &(*list)->sum, 21);
		break;
	case 5:
		printf("Старый вид договора: %s\n", w->name);
		printf("Новый вид договора: ");
		scanf_s("%s%*c", w->name, 21);
		break;
    case 6:
		printf("Старый срок заключения: %s\n", w->start);
		printf("Новый срок заключения: ");
		scanf_s("%s%*c", w->start, 21);
		break;
    case 7:
		printf("Старый срок истечения договора: %s\n", w->end);
		printf("Новый срок истечения договора: ");
		scanf_s("%s%*c", w->end, 21);
		break;
	case 8:
		printf("Старый Шифр договора: %s\n", (*list)->cypher);
		printf("Новый шифр договора: ");
		scanf_s("%s%*c", (*list)->cypher, 21);
		printf("Старое наименование организации: %s\n", (*list)->company);
		printf("Новая количество на складе: ");
		scanf_s("%s%*c", (*list)->company, 21);
		printf("Старое наименование контрагента сроки выполнения: %s\n", (*list)->string);
		printf("Новая стоимость единицы: ");
		scanf_s("%s%*c", (*list)->string, 21);
		printf("Старая сумма договора: %i\n",(*list)->sum);
		printf("Новая сумма договора: ");
		scanf_s("%i%*c", &(*list)->sum, 21);
		printf("Старый вид договора: %s\n", w->name);
		printf("Новый вид договора: ");
		scanf_s("%s%*c", w->name, 21);
        printf("Старый срок заключения: %s\n", w->start);
		printf("Новый срок заключения: ");
		scanf_s("%s%*c", w->start, 21);
		printf("Старый срок истечения договора: %s\n", w->end);
		printf("Новый срок истечения договора: ");
		scanf_s("%s%*c", w->end, 21);
		break;
	case 0:
		printf("Переход к предидущему меню\n");
		main_menu(list);
		break;
	default:
		printf("Выбрано неверное действие. Повторите выбор\n");
		system("pause");
		system("cls");
		menu_change_element(list);
		break;
	}
}
