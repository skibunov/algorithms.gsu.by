#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Punctuation_marks(char* s){
	int i,j;

	int len = length(s); // ������� ����� ������
	
	int tochka = 0;
	int zapyataya = 0;
	int dvoetochie = 0;
	int tire = 0;
	int voprositel = 0;
	int vosklicatel = 0;
	
	for(i = 0; i < len; i++){
		if(s[i] == '.'){
			tochka++;
		}
		
		if(s[i] == ','){
			zapyataya++;
		}
		
		if(s[i] == ';'){
			dvoetochie++;
		}
		
		if(s[i] == '-'){
			tire++;
		}
		
		if(s[i] == '?'){
			voprositel++;
		}
		
		if(s[i] == '!'){
			vosklicatel++;
		}
		
	}
	
	if(tochka != 0){
		printf("����� = %d\n",tochka);
	}
	
	if(zapyataya != 0){
		printf("������� = %d\n",zapyataya);
	}
	
	if (dvoetochie != 0){
		printf("��������� = %d\n",dvoetochie);
	}

	if(tire != 0){
		printf("���� = %d\n",tire);
	}
	
	if(voprositel != 0){
		printf("�������������� ���� = %d\n",voprositel);
	}
	
	if(vosklicatel != 0){
		printf("��������������� ���� = %d\n",vosklicatel);
	}
	
	if(tochka == 0 && zapyataya == 0 && dvoetochie == 0 && tire == 0 && voprositel == 0 && vosklicatel == 0){
		printf("������ ���������� �� ���������� � ������\n");
	} 
	
}


int main(){
	srand(time(NULL));
    setlocale(LC_ALL,"Rus");
	
	
	char* s = calloc(255,sizeof(char));
	
	puts("Enter string: ");
	gets(s);
	
	if(length(s) == 0){
		main();
	}
	

	
	Punctuation_marks(s);
	
	
}

//���������� ����� ������
int length(char* s){
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	return i;
}
