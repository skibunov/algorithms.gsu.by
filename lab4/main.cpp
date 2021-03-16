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
	struct Organization* next;//��������� �� ��������� ������� ������
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

void new_el(Organization** list,const char* cypher, const char* name,const char* nameString, const int summ, const char* view)//�������� ������ ��������
{
	Organization* b = (Organization*)calloc(1, sizeof(Organization));//��������� ������ ��� ����� ������� �������
	if (b)
	{
		strcpy(b->cypher,cypher);
		strcpy(b->name,name);
		strcpy(b->nameString,nameString);
		b->summ = summ;
		strcpy(b->view,view);
		b->next = (*list);//������� ��������� �� ��������� ������� ������
		(*list) = b;
	}
}
void add(Organization** list)//���������� �������� � ������ ������
{
	printf("���������� �������� � ������ ������:\n");
	char a[21] = { '\0' }, b[21] = { '\0' }, c[21] = { '\0' }, e[21] = { '\0' };
	int d = 0;
	printf("������� ���� ��������: ");
	scanf("%s%*c", a, 21);
	printf("������� ������������� �����������: ");
	scanf("%s%*c", b, 21);
	printf("������� ������������� ����������� ������ ����������: ");
	scanf("%s%*c", c, 21);
    printf("������� ����� ��������: ");
	scanf("%i%*c", &d);
	printf("������� ��� ��������: ");
	scanf("%s%*c", e, 21);
	new_el(list, a, b, c, d, e);//����� ������� ��� �������� ��������
	printf("������� ������� �������� � ������\n");
}
void print(Organization* list) //������ ������ �� �����
{
	printf("_______________________________________________________________________________________________________________________________\n");
	printf("| � | ���� ��������     |   ������������� �����������   |       ������������� ����������� ������ ����������       |  ����� ��������    |   ��� ��������   |\n");
	printf("_______________________________________________________________________________________________________________________________\n");
	int i = 1;
	while (list != NULL)//���� �� ����� ������
	{
		printf("|%3i|%20s|%20s|%20s|%23i|%25s|\n", i++, list->cypher, list->name, list->nameString, list->summ, list->view);
		printf("_______________________________________________________________________________________________________________________________\n");
		list = list->next;//������� � ���������� �������� ������
	}
}
void delete_el(Organization** list)//�������� �������� �� ������
{
	printf("������� ����� �������� ������: ");
	int nom;
	scanf("%i", &nom);//�������� ����� ��� ��������
	if (nom <= 0)//��������� ������������ ������
	{
		printf("����� �������� �����\n");
		return;
	}
	Organization* p = (*list), * w;
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->next;//���� �� ����� � ������ ������
	}
	if (p != NULL)
	{
		if (p == (*list))//���� ������� ������,��������� ��������� �� 1
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
		printf("������� ������ ����� �������\n");
	}
	else
	{
		printf("��������� � ������ ������, ��� �������� �����\n");
	}
}
void change(Organization** list)//��������� ��������
{
	printf("������� ����� �������� ������: ");
	int nom;//�������� ����� ��� ���������
	scanf("%i", &nom);
	if (nom <= 0)//��������� ������������ ���������� ������
	{
		printf("����� �� ������ �����\n");
		return;
	}
	Organization* p = (*list);
	for (int i = 1; i < nom && p != NULL; i++)
	{
		p = p->next;//�������� ��� ������� ������
	}
	if (p != NULL)
	{
		menu_change(&p);//���� �� ����������, �������� ���� ���������
	}
	else
	{
		printf("��������� � ������ ������, ��� �������� �����\n");//����� ���������� ������
	}
}
void sort_int(Organization** list)//���������� �� ��������� ����
{
	Organization* a = NULL, * b = NULL, * c = NULL, * e = NULL, * tmp = NULL;//��������� ����������
	while (e != (*list)->next)//���� �� ������
	{
		c = a = (*list);//������� �������
		b = a->next; //���������
		while (a != e)
		{
			if (a->summ > b->summ)//���� ������� ������ ����������
			{
				if (a == (*list))//������ �� �������
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
			else//����� ���� ������
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
	printf("�������� ������ �������������� �� �����\n");
}
void sort_char(Organization** list)//���������� �� ����������� ����
{
	Organization* new_list = NULL;
	while ((*list) != NULL)//���� �� ������
	{
		Organization* node = (*list);//�������
		(*list) = (*list)->next;//���������
		if ((new_list == NULL) || (strcmp(node->cypher, new_list->cypher) == -1))//���� ����������� ��������, �� ������ �������
		{
			node->next = new_list;
			new_list = node;
		}
		else
		{
			Organization* current = new_list;
			while ((current->next != NULL) && !(strcmp(node->cypher, (current->next)->cypher) == -1))//���� ������ �� ������
			{
				current = current->next;
			}
			node->next = current->next;//������ �������
			current->next = node;
		}
	}
	if (new_list)
	{
		(*list) = new_list;//������� ����� ������ � ��� ������
	}
	printf("�������� ������ �������������� �� ����� ��������\n");
}
void write(Organization* list)//������ � ����
{
	const char fname[] = "save.dat";//������� �������� �����
	FILE* f=fopen(fname, "w");//��������� ���� ��� ������
	while (list != NULL)// ������� ���� ��� ������ � ����
	{
		fprintf(f, "%21s%21s%21s%18i%21s\n",list->cypher, list->name, list->nameString, list->summ, list->view);
		list = list->next;
	}
	fclose(f);//��������� ����
	printf("������ ������� �������� � ����\n");
}
void read(Organization** list)//������ �� �����
{
	const char fname[] = "list.dat";//������� �������� �����
	FILE* f=fopen(fname, "r");//��������� ���� ��� ������
	Organization* b = (Organization*)calloc(0,sizeof(Organization));//�������� ������ ��� ������ �������
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
	while ((z = fscanf(f, "%s%s%s%i%s\n", b->cypher, b->name, b->nameString, &b->summ, b->view)) > 0)//���� ���� �������� ������ ���� ������� ���������� ���������
	{
		k++;
	}

	do
	{
		fseek(f, 0, SEEK_SET);
		fseek(f, (k-1) * 120, SEEK_CUR);//������������� ��������� �����
		fscanf(f, "%s%s%s%i%s%\n", b->cypher, b->name, b->nameString, &b->summ, b->view); //��������� ������ ��������
		new_el(list, b->cypher, b->name, b->nameString, b->summ, b->view);//������� ������� � ������
		k--;//��������� ���������� ���������
	} while (k);
	fclose(f);//��������� ���������� ���������
	printf("������ ������� �������� �� �����\n");
}

void menu(Organization** list)//����
{
	system("pause");
	system("cls");
	printf("�������� ��������:\n");//����� ��������
	printf("1. �������� ������� � ������ ������;\n2. ����� ��������� ������ �� �����;\n3. ������� ������� ������;\n4. ��������� �������� �������� ������;\n5. ���������� ��������� ������;\n6. ������ ������ � ����;\n7. ������ ������ �� �����;\n0. �����.\n");
	printf("��� �����: ");
	int nom;
	scanf("%i%*c", &nom);
	system("cls");
	switch (nom)
	{
	case 1:
		add(list);
		break;
	case 2:
		printf("����� ��������� ������ �� �����\n");
		if ((*list) == NULL)
		{
			printf("������ ����, ������ �������� �� �����\n");
		}
		else
		{
			print(*list);
		}
		break;
	case 3:
		printf("�������� �������� ������:\n");
		if ((*list) == NULL)
		{
			printf("������ ����, ������ �������\n");
		}
		else
		{
			delete_el(list);
		}
		break;
	case 4:
		printf("��������� �������� ������:\n");
		if ((*list) == NULL)
		{
			printf("������ ����, ������ ��������\n");
		}
		else
		{
			change(list);
		}
		break;
	case 5:
		printf("���������� ��������� ������:\n");
		if ((*list) == NULL)
		{
			printf("������ ����, ������ �����������\n");
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
		printf("������� �������� ��������. ��������� �����\n");
		break;
	}
	menu(list);
}
void menu_change(Organization** list)//���� ��������� ��������
{
	printf("�������� ��������:\n");
	printf("1. �������� ���� ��������;\n2. �������� ������������ �����������;\n3. �������� ������������ ����������� ������ ����������;\n4. �������� ����� ��������;\n5. �������� ��� ��������;\n6. �������� ��� ������;\n0. �����.\n");
	printf("��� �����: ");
	int nom;
	scanf("%i%*c", &nom);
	system("cls");
	printf("��������� �������� ������:\n");
	switch (nom)
	{
	case 1:
		printf("������ ���� ��������: %s\n", (*list)->cypher);
		printf("����� ���� ��������: ");
		scanf("%s%*c", (*list)->cypher, 21);
		break;
	case 2:
		printf("������ ������������ �����������: %s\n", (*list)->name);
		printf("����� ������������ �����������: ");
		scanf("%s%*c", (*list)->name,21);
		break;
	case 3:
		printf("������ ������������ ����������� ������ ����������: %s\n", (*list)->nameString);
		printf("����� ������������ ����������� ������ ����������: ");
		scanf("%s%*c", (*list)->nameString, 21);
		break;
	case 4:
		printf("������ ����� ��������: %i\n", (*list)->summ);
		printf("����� ����� ��������: ");
		scanf("%i%*c", &(*list)->summ);
		break;
	case 5:
		printf("������ ��� ��������: %s\n", (*list)->view);
		printf("����� ��� ��������: ");
		scanf("%s%*c", (*list)->view, 21);
		break;
	case 6:
		printf("������ ���� ��������: %s\n", (*list)->cypher);
		printf("����� ���� ��������: ");
		scanf("%s%*c", (*list)->cypher, 21);
		printf("������ ������������ �����������: %s\n", (*list)->name);
		printf("����� ������������ �����������: ");
		scanf("%s%*c", (*list)->name,21);
		printf("������ ������������ ����������� ������ ����������: %s\n", (*list)->nameString);
		printf("����� ������������ ����������� ������ ����������: ");
		scanf("%s%*c", (*list)->nameString, 21);
		printf("������ ����� ��������: %i\n", (*list)->summ);
		printf("����� ����� ��������: ");
		scanf("%i%*c", &(*list)->summ);
		printf("������ ��� ��������: %s\n", (*list)->view);
		printf("����� ��� ��������: ");
		scanf("%s%*c", (*list)->view, 21);
		break;
	case 0:
		printf("������� � ����������� ����\n");
		menu(list);
		break;
	default:
		printf("������� �������� ��������. ��������� �����\n");
		system("pause");
		system("cls");
		menu_change(list);
		break;
	}
}
void menu_sort(Organization** list)//���� ����������
{
	printf("�������� ��������:\n");
	printf("1. ������������� �� ����� ��������;\n2. ������������� �� �����;\n0. �����.\n");
	printf("��� �����: ");
	int nom;
	scanf("%i%*c", &nom);
	system("cls");
	printf("���������� ��������� ������:\n");
	switch (nom)
	{
	case 1:
		sort_char(list);
		break;
	case 2:
		sort_int(list);
		break;
	case 0:
		printf("������� � ����������� ����\n");
		menu(list);
		break;
	default:
		printf("������� �������� ��������. ��������� �����\n");
		system("pause");
		system("cls");
		menu_sort(list);
		break;
	}
}
