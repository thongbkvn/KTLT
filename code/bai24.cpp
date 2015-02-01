#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  char A[100] = {0}, a, b;
  int i, j, S;
  bool T[100] = {0}; //Khoi tao mang toan false

  //Xu ly doi so dong lenh
  if (argc >= 2)
    strncpy(A, argv[1], 100);
  else
    {
      printf("Nhap xau A: ");
      fgets(A, 100, stdin);
      A[strlen(A)-1] = 0; //Loai bo ki tu \n
    }
  if (argc >=4)
    {
      a = argv[2][0];
      b = argv[3][0];
    }
  else
    {
      printf("Nhap 2 ki tu: ");
      scanf("%c%c", &a, &b);
    }
  //Thong ke tan suat xuat hien cac ki tu
  printf("\nTan suat cac ki tu: ");
  for (i = 0; i < strlen(A); i++)
    {
      if (T[i]) //Neu da duoc dem thi khong dem lai
	continue;
      S = 1;
      T[i] = true;//Danh dau da duoc dem, buoc nay co the bo
      
      for (j = i+1; j<strlen(A); j++)
	if ((A[i] == A[j]) && !T[j]) //Neu chua duoc dem thi dem va danh dau
	  {
	    S++;
	    T[j] = true;
	  }
      printf("\n\"%c\": %d", A[i], S); //In ket qua sau moi buoc
    }

  //Thay cac ki tu a trong xau A boi ki tu b
  for (i=0; i < strlen(A); i++)
    if (A[i] == a)
      A[i] = b;

  printf("\n\nChuoi sau khi duoc thay: %s\n", A);
  return 0;
}
    
