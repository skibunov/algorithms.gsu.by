#include <stdio.h>
#include <stdlib.h>


//Сортировка Слиянием, Скибунов Андрей. Вариант 26
void merge(int *a, int n)
{
  int mid = n / 2;
  if (n % 2 == 1) // находим середину
    mid++;
  int h = 1; // шаг
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n) 
  {
    step = h;
    int i = 0; //индекс первого пути
    int j = mid; // индекс второго пути
    int k = 0;   // индекс элемента в результате 
    while (step <= mid) 
    {
      while ((i < step) && (j < n) && (j < (mid + step))) 
      { // Пока не дошли до конца пути 
      // заполняем следуюзщий элемент
      // меньший из двух просматриваем 
        if (a[i] < a[j])  
        {
          c[k] = a[i];
          //printf("%d\n",c[k]);
          i++; k++;
        }
        else {
          c[k] = a[j];
          //printf("%d\n",c[k]);
          j++; k++;
        }
        
    }
      while (i < step) 
      { // Переписываем оставшиеся элементы первого пути (если второй кончился раньше)
        c[k] = a[i];
        i++; k++;
      }
      while ((j < (mid + step)) && (j<n)) 
      { // Переписываем оставшиеся элементы второй пути (если первый кончился раньше)
        c[k] = a[j];
        j++; k++;
      }
      
      
      step = step + h; // переход к следующему  этапу
    }
    h = h * 2;
    
    
    //Перенос в исходный массив
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
}

int main() {
  int i,j;		
  
  FILE *f;
  int count = 0;
  if((f = fopen("file.txt","r")) == NULL){
  	return 1;
  }		

  i = 0;
  j = 0;
  int a[8],b[8],c[8];
  while(feof(f) == 0){
  	fscanf(f, "%d", &a[i]);
  	i++;
  }			
		
	for (i = 0; i<8/2; i++)
      b[i] = a[i];
      
    for (i = 4; i<8; i++){
    	c[j] = a[i];
    	j++;
	}
      
      
    for(i = 0; i < 4; i++){
    	printf("%d ",b[i]);
	}  
	printf("\n");
	for(i = 0; i < 4; i++){
    	printf("%d ",c[i]);
	}  
      
    printf("\n");  
    merge(b,4);
	merge(c,4);
	for(i = 0; i < 4; i++){
    	printf("%d ",b[i]);
	}  
	printf("\n");
	for(i = 0; i < 4; i++){
    	printf("%d ",c[i]);
	}   
    printf("\n");
  
  merge(a, 8);
  
  for (i = 0; i<8; i++)
    printf("%d ", a[i]);
  printf("\n");
  
  getchar();
  return 0;
}
