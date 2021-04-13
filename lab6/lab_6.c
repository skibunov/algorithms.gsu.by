#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//���������� ������������ �����������
typedef struct _Documentation
{
	char name[21];//��� ��������
	char start[21];//���� ����������
	char end[21]; //���� ��������� ��������
	struct _Documentation* next;//��������� �� ��������� ������� ������
	struct _Documentation* prev;//��������� �� ���������� ������� ������
}Documentation;

typedef struct _Organization
{
	char cypher[21];//���� ��������
	char company[21];//������������ �����������
	char string[21];//������������ ����������� ����� ����������
	int sum; //����� ��������
	Documentation* document;//��� ��������
	struct _Organization* next;//��������� �� ��������� ������� ������
	struct _Organization* prev;//��������� �� ���������� ������� ������
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
	printf("������� ���� ��������: ");
	scanf_s("%s%*c", a, 21);
	printf("������� ������������ �����������: ");
	scanf_s("%s%*c", b, 21);
	printf("������� ������������ ����������� ����� ����������: ");
	scanf_s("%s%*c", c, 21);
	printf("������� ����� ��������: ");
	scanf_s("%i%*c", &s);
	printf("������� ��� ��������: ");
	scanf_s("%s%*c", d, 21);
    printf("������� ���� ����������: ");
	scanf_s("%s%*c", e, 21);
    printf("������� ���� ��������� ��������: ");
	scanf_s("%s%*c", h, 21);
	new_element(list, a, b, c, s, d, e, h);
}
void add_element_career(Documentation** list)
{
	char a[21], b[21], c[21];
	printf("������� ��� ��������: ");
	scanf_s("%s%*c", a, 21);
	printf("������� ���� ����������: ");
	scanf_s("%s%*c", b, 21);
	printf("������� ���� ��������� ��������:");
	scanf_s("%s%*c", c, 21);
	new_element_career(list, a, b, c);
}
void print(Organization* list)
{
	printf("________________________________________________________________________________\n");
	printf("|   |    |            |                |     |                �������          |\n");
	printf("| � |����|������������|����� ����������|�����|_________________________________|\n");
	printf("|   |    |            |                |     | � | ��� | ���� | ���� ��������� |\n");
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
	printf("�������� �������� ������ �� ������:\n");
	printf("������� ����� �������� ������: ");
	int nom;
	scanf_s("%i", &nom);
	if (nom <= 0)
	{
		printf("����� �� ������ �����\n");
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
		printf("������� ������ ����� �������\n");
	}
	else
	{
		printf("��������� � ������ ������, ��� �������� �����\n");
	}
}
void delete_element_career(Organization** list)
{
	printf("����� �������� ������:\n");
	int nomer;
	Organization* a = (*list);
	printf("������� ����� �������� ������: ");
	scanf_s("%i%*c", &nomer);
	if (nomer <= 0)
	{
		printf("����� �� ������ �����\n");
		return;
	}
	for (int i = 1; i < nomer && a != NULL; i++)
	{
		a = a->prev;
	}
	if (a == NULL)
	{
		printf("��������� � ������ ������, ��� �������� �����\n");
		return;
	}
	system("cls");
	printf("�������� �������� ������ ������� �������� %i �� ������:\n", nomer);
	printf("������� ����� �������� ������ ������� �������� %i: ", nomer);
	int nom;
	scanf_s("%i", &nom);
	if (nom <= 0)
	{
		printf("����� �� ������ �����\n");
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
		printf("������� ������� ����� �� ������ ������� �������� %i �� ������ %i\n", nomer, nom);
	}
	else
	{
		printf("��������� � ������ ������� �������� %i ������, ��� �������� �����\n", nomer);
	}
}
void change_element(Organization** list)
{
	printf("������� ����� �������� ������: ");
	int nom;
	scanf_s("%i", &nom);
	if (nom <= 0)
	{
		printf("����� �� ������ �����\n");
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
		printf("��������� � ������ ������, ��� �������� �����\n");
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
	printf("�������� ������ ��������������\n");
}
void sort_int(Organization** list)
{
	printf("����� �������� ������:\n");
	int nomer;
	Organization* aaa = (*list);
	printf("������� ����� �������� ������: ");
	scanf_s("%i%*c", &nomer);
	if (nomer <= 0)
	{
		printf("����� �� ������ �����\n");
		return;
	}
	for (int i = 1; i < nomer && aaa != NULL; i++)
	{
		aaa = aaa->prev;
	}
	if (aaa == NULL)
	{
		printf("��������� � ������ ������, ��� �������� �����\n");
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
	printf("�������� ������ ��������������\n");
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
	printf("������ ������� �������� � ����\n");
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
		printf("���� ����\n");
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
		printf("������ ������� �������� �� �����\n");
	}
}

void main_menu(Organization** list)
{
	system("pause");
	system("cls");
	printf("�������� ��������:\n"
		"1. �������� ������� � ������ �����������;\n"
		"2. �������� ������� � ������ ����������;\n"
		"3. ����� ��������� ������ �� �����;\n"
		"4. �������� �������� ������ ����������� �� ������;\n"
		"5. �������� �������� ������ ���������� �� ������;\n"
		"6. �������� �������� �������� ������ �� ������;\n"
		"7. ���������� ��������� ������ ���������� �� �������� ������;\n"
		"8. ���������� ��������� ������ ������� �� ����� ����������;\n"
		"9. ������ � ����;\n"
		"10. ������ �� �����;\n"
		"0. �����.\n");
	printf("��� �����: ");
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
			printf("������ ����, ������ �������� �� �����\n");
		}
		else
		{
			print(*list);
		}
		break;
	case 4:
		if (*list == NULL)
		{
			printf("������ ����, ������ �������\n");
		}
		else
		{
			delete_element(list);
		}
		break;
	case 5:
		if (*list == NULL)
		{
			printf("������ ����, ������ �������\n");
		}
		else
		{
			if ((*list)->document == NULL)
			{
				printf("������ ������� ����, ������ �������\n");
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
			printf("������ ����, ������ ��������\n");
		}
		else
		{
			change_element(list);
		}
		break;
	case 7:
		if ((*list) == NULL)
		{
			printf("������ ����, ������ �����������\n");
		}
		else
		{
			sort_char(list);
		}
		break;
	case 8:
		if (*list == NULL)
		{
			printf("������ ����, ������ �����������\n");
		}
		else
		{
			if ((*list)->document == NULL)
			{
				printf("������ ������� ����, ������ �����������\n");
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
		printf("������� �������� ��������. ��������� �����\n");
		break;
	}
	main_menu(list);
}
void menu_add_element(Organization** list)
{
	system("cls");
	printf("�������� ��������:\n"
		"1. �������� ������� � ������ ������;\n"
		"2. �������� ������� � ������ �� ������;\n"
		"3. �������� ������� � ����� ������;\n"
		"0. �����.\n");
	printf("��� �����: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		printf("���������� �������� � ������ ������:\n");
		add_element(list);
		printf("������� ������� �������� � ������ ������\n");
		break;
	case 2:
		printf("���������� �������� � ������ �� ������:\n");
		int n, kol = 0;
		printf("������� ����� �������� ������: ");
		scanf_s("%i%*c", &n);
		if (n <= 0)
		{
			printf("����� �� ������ �����\n");
			break;
		}
		if (n == 1)
		{
			add_element(list);
			printf("������� ������� �������� � ������ �� ������ %i\n", n);
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
				printf("������� ������� �������� � ������ �� ������ %i\n", n);
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
					printf("������� ������� �������� � ������ �� ������ %i\n", n);
				}
				else
				{
					printf("��������� � ������ ������, ��� �������� �����\n");
				}
			}
		}
		break;
	case 3:
		printf("���������� �������� � ����� ������:\n");
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
		printf("������� ������� �������� � ����� ������\n");
		break;
	case 0:
		main_menu(list);
		break;
	default:
		printf("������� �������� ��������. ��������� �����\n");
		menu_add_element(list);
		break;
	}
	main_menu(list);
}
void menu_add_element_career(Organization** list)
{
	printf("����� �������� ������:\n");
	int nomer;
	Organization* a = (*list);
	printf("������� ����� �������� ������: ");
	scanf_s("%i%*c", &nomer);
	if (nomer <= 0)
	{
		printf("����� �� ������ �����\n");
		return;
	}
	for (int i = 1; i < nomer && a != NULL; i++)
	{
		a = a->prev;
	}
	if (a == NULL)
	{
		printf("��������� � ������ ������, ��� �������� �����\n");
		return;
	}
	system("cls");
	printf("�������� ��������:\n"
		"1. �������� ������� � ������ ������ ��������� �������� %i;\n"
		"2. �������� ������� � ������ ��������� �������� %i �� ������;\n"
		"3. �������� ������� � ����� ������ ��������� �������� %i;\n"
		"0. �����.\n", nomer, nomer, nomer);
	printf("��� �����: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		printf("���������� �������� � ������ ������ ��������� �������� %i:\n", nomer);
		add_element_career(&a->document);
		printf("������� ������� �������� � ������ ������ ��������� �������� %i\n", nomer);
		break;
	case 2:
		printf("���������� �������� � ������ ��������� �������� %i �� ������:\n", nomer);
		int n, kol = 0;
		printf("������� ����� �������� ������ ��������� �������� %i: ", nomer);
		scanf_s("%i%*c", &n);
		if (n <= 0)
		{
			printf("����� �� ������ �����\n");
			break;
		}
		if (n == 1)
		{
			add_element_career(&a->document);
			printf("������� ������� �������� � ������ ��������� �������� %i �� ������ %i\n", nomer, n);
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
				printf("������� ������� �������� � ������ ��������� �������� %i �� ������ %i\n", nomer, n);
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
					printf("������� ������� �������� � ������ ��������� �������� %i �� ������ %i\n", nomer, n);
				}
				else
				{
					printf("��������� � ������ ��������� �������� %i ������, ��� �������� �����\n", nomer);
				}
			}
		}
		break;
	case 3:
		printf("���������� �������� � ����� ������ �������� %i:\n", nomer);
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
		printf("������� ������� �������� � ����� �������������� %i\n", nomer);
		break;
	case 0:
		main_menu(list);
		break;
	default:
		printf("������� �������� ��������. ��������� �����\n");
		menu_add_element_career(list);
		break;
	}
	main_menu(list);
}
void menu_change_element(Organization** list)
{
	printf("������� ����� �������� ������ ���������: ");
	int nomer;
	scanf_s("%i", &nomer);
	if (nomer <= 0)
	{
		printf("����� �� ������ �����\n");
		return;
	}
	Documentation* w = (*list)->document;
	for (int i = 1; i < nomer && w != NULL; i++)
	{
		w = w->prev;
	}
	if (w == NULL)
	{
		printf("��������� � ������ ��������� ������, ��� �������� �����\n");
		return;
	}
	printf("�������� ��������:\n");
	printf("1. �������� ���� ��������;\n2. �������� ������������ �����������;\n3. �������� ������������ ����������� ����� ����������;\n4. �������� ����� ��������;\n5. �������� ��� ��������;\n6. �������� ���� ����������;\n7. �������� ���� ��������� ��������\n8. �������� ��� ������;\n0. �����.\n");
	printf("��� �����: ");
	int nom;
	scanf_s("%i%*c", &nom);
	system("cls");
	printf("��������� �������� ������:\n");
	switch (nom)
	{
	case 1:
		printf("������ ���� ��������: %s\n", (*list)->cypher);
		printf("����� ���� ��������: ");
		scanf_s("%s%*c", (*list)->cypher, 21);
		break;
	case 2:
		printf("������ ������������ �����������: %s\n", (*list)->company);
		printf("����� ���������� �� ������: ");
		scanf_s("%s%*c", (*list)->company, 21);
		break;
	case 3:
		printf("������ ������������ ����������� ����� ����������: %s\n", (*list)->string);
		printf("����� ��������� �������: ");
		scanf_s("%s%*c", (*list)->string, 21);
		break;
	case 4:
		printf("������ ����� ��������: %i\n",(*list)->sum);
		printf("����� ����� ��������: ");
		scanf_s("%i%*c", &(*list)->sum, 21);
		break;
	case 5:
		printf("������ ��� ��������: %s\n", w->name);
		printf("����� ��� ��������: ");
		scanf_s("%s%*c", w->name, 21);
		break;
    case 6:
		printf("������ ���� ����������: %s\n", w->start);
		printf("����� ���� ����������: ");
		scanf_s("%s%*c", w->start, 21);
		break;
    case 7:
		printf("������ ���� ��������� ��������: %s\n", w->end);
		printf("����� ���� ��������� ��������: ");
		scanf_s("%s%*c", w->end, 21);
		break;
	case 8:
		printf("������ ���� ��������: %s\n", (*list)->cypher);
		printf("����� ���� ��������: ");
		scanf_s("%s%*c", (*list)->cypher, 21);
		printf("������ ������������ �����������: %s\n", (*list)->company);
		printf("����� ���������� �� ������: ");
		scanf_s("%s%*c", (*list)->company, 21);
		printf("������ ������������ ����������� ����� ����������: %s\n", (*list)->string);
		printf("����� ��������� �������: ");
		scanf_s("%s%*c", (*list)->string, 21);
		printf("������ ����� ��������: %i\n",(*list)->sum);
		printf("����� ����� ��������: ");
		scanf_s("%i%*c", &(*list)->sum, 21);
		printf("������ ��� ��������: %s\n", w->name);
		printf("����� ��� ��������: ");
		scanf_s("%s%*c", w->name, 21);
        printf("������ ���� ����������: %s\n", w->start);
		printf("����� ���� ����������: ");
		scanf_s("%s%*c", w->start, 21);
		printf("������ ���� ��������� ��������: %s\n", w->end);
		printf("����� ���� ��������� ��������: ");
		scanf_s("%s%*c", w->end, 21);
		break;
	case 0:
		printf("������� � ����������� ����\n");
		main_menu(list);
		break;
	default:
		printf("������� �������� ��������. ��������� �����\n");
		system("pause");
		system("cls");
		menu_change_element(list);
		break;
	}
}
