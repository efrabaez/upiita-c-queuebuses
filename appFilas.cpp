#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _Bus {
        int id, seats;
        struct _Bus *next;
        } Bus;

void menu();
Bus * allocateMemory(int, int);
Bus * push(Bus *, int, int );
Bus *pop(Bus* );
void show(Bus *);

int main(int argc, char *argv[]) 
{
  menu();
	system("pause");	
	return 0;
}

void menu(){
  int opt=0,id=0, i=0, f=0;
  Bus *f1=NULL, *f2=NULL, *f3=NULL, *finalLine=NULL;
  srand(time(NULL));
  do{
    printf("\n1.Dar de alta autobuses\n2.Simular\n(-1).Salir\nOpcion: ");
    scanf("%i",&opt);
    switch (opt)
    {
      case 1:
        printf("Ingresa numero de autobuses F1: ");
        scanf("%i",&f);
        id=100;
        for(i = 0; i < f; i++){
          id+=1;
          f1=push(f1, id, rand () % 11 + 30);
        }      
        printf("Ingresa numero de autobuses F2: ");
        scanf("%i",&f);
        id=200;
        for(i = 0; i < f; i++){
          id+=1;
          f2=push(f2, id, rand () % 11 + 30);
        }  
        printf("Ingresa numero de autobuses F3: ");
        scanf("%i",&f);
        id=300;
        for(i = 0; i < f; i++){
          id+=1;
          f3=push(f3, id, rand () % 11 + 30);
        }             
        show(f1);
        show(f2);
        show(f3);       
      break;
      case 2:
        while(f1 || f2 || f3) {
          if (f1 && f2 && f3) {
            if (f1->seats < f2->seats && f1->seats < f3->seats) {
              if (f2->seats < f3->seats) {
                //printf("menor: %i\nMedio: %i\nMayor: %i", f1->seats, f2->seats, f3->seats);
                finalLine=push(finalLine, f1->id, f1->seats); 
                finalLine=push(finalLine, f2->id, f2->seats);
                finalLine=push(finalLine, f3->id, f3->seats);                                                
              }else{
                //printf("menor: %i\nMedio: %i\nMayor: %i", f1->seats, f3->seats, f2->seats);
                finalLine=push(finalLine, f1->id, f1->seats); 
                finalLine=push(finalLine, f3->id, f3->seats); 
                finalLine=push(finalLine, f2->id, f2->seats);                   
              }
            }else if( f2->seats < f3->seats){
              if (f1->seats < f3->seats) {
                //printf("menor: %i\nMedio: %i\nMayor: %i", f2->seats, f1->seats, f3->seats);
                finalLine=push(finalLine, f2->id, f2->seats); 
    
                finalLine=push(finalLine, f1->id, f1->seats); 
    
                finalLine=push(finalLine, f3->id, f3->seats); 
                      
              }else{
                //printf("menor: %i\nMedio: %i\nMayor: %i", f2->seats, f3->seats, f1->seats);
                finalLine=push(finalLine, f2->id, f2->seats); 
                finalLine=push(finalLine, f3->id, f3->seats); 
                finalLine=push(finalLine, f1->id, f1->seats);     
              }              
            }else{
              if (f1->seats < f2->seats) {
                //printf("menor: %i\nMedio: %i\nMayor: %i", f3->seats, f1->seats, f2->seats);
                finalLine=push(finalLine, f3->id, f3->seats); 
                finalLine=push(finalLine, f1->id, f1->seats); 
                finalLine=push(finalLine, f2->id, f2->seats);          
              }else{
                //printf("menor: %i\nMedio: %i\nMayor: %i", f3->seats, f2->seats, f1->seats);
                finalLine=push(finalLine, f3->id, f3->seats); 
                finalLine=push(finalLine, f2->id, f2->seats); 
                finalLine=push(finalLine, f1->id, f1->seats);      
              }                
            }  
          }else if (f1 && f2 && !f3) {     
            if (f1->seats < f2->seats) {
              finalLine=push(finalLine, f1->id, f1->seats);
              finalLine=push(finalLine, f2->id, f2->seats);
            }else{
              finalLine=push(finalLine, f2->id, f2->seats);
              finalLine=push(finalLine, f1->id, f1->seats);
            }           
          }else if (f1 && f3 && !f2) {
            if (f1->seats < f3->seats) {
              finalLine=push(finalLine, f1->id, f1->seats);
              finalLine=push(finalLine, f3->id, f3->seats);
            }else{
              finalLine=push(finalLine, f3->id, f3->seats);
              finalLine=push(finalLine, f1->id, f1->seats);
            }            
          }else if (f1 && !f2 && !f3) {
            finalLine=push(finalLine, f1->id, f1->seats);           
          }else if (f2 && f3 && !f1) {
            if (f2->seats < f3->seats) {
              finalLine=push(finalLine, f2->id, f2->seats);
              finalLine=push(finalLine, f3->id, f3->seats);
            }else{
              finalLine=push(finalLine, f3->id, f3->seats);
              finalLine=push(finalLine, f2->id, f2->seats);
            }
          }else if (f2 && !f1 && !f3) {
            finalLine=push(finalLine, f2->id, f2->seats);
          }else if (f3 && !f1 && !f2) {
            finalLine=push(finalLine, f3->id, f3->seats);
          } 
            f1=pop(f1);
            f2=pop(f2);
            f3=pop(f3);              
      } 
      show(finalLine); 
      break;
    }
  } while (opt!=-1);
}


Bus * allocateMemory(int _id, int _seats){
  Bus * nData;
  nData = (Bus*)malloc(sizeof(Bus));
  nData->id= _id;
  nData->seats=_seats;
  nData->next=NULL;
  return nData;     
}

Bus * push(Bus *_front, int _id, int _seats){
 Bus *nFront, *nAux;
  nFront = allocateMemory(_id, _seats);
	if(_front==NULL){
		_front=nFront;
	}else{
		nAux = _front;
		while(nAux->next){
			nAux=nAux->next;
		}
		nAux->next=nFront;
	}
  return _front;
}

void show(Bus *cabeza){
  if(cabeza == NULL){
    printf("\nTu Cola esta vacia.\n");
  }
  while(cabeza!=NULL){
    printf("id: %i|seats: %i\n",cabeza->id,cabeza->seats);
    cabeza=cabeza->next;
  }
}

Bus *pop(Bus *_start){
  Bus *aux;
    if(_start!=NULL){
      aux=_start;
      _start=_start->next;
      free(aux);
    }
  return _start;
}