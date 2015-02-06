#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50
using namespace std;

int main(int argc, char **argv)
{
  int n; //So hoc sinh trong lop
  int i,j;//Cac bien vong lap
  char **DSlop, *tg; //Bien con tro quan ly danh sach hoc sinh
  char name[MAX_LENGTH]; //Luu ten tam nhap vao tu ban phim
  ifstream inp;
  //Xu ly tham so dong lenh
  if (argc >= 2)
    inp.open(argv[1]);
  else
    inp.open("bai2.in");
  if (argc == 3)
    {
      n = atoi(argv[2]);
      inp>>i; //Loai bo dong dau tien ghi so hoc sinh cua lop
    }
  else
    inp>>n;
    
  //Cap phat bo nho de luu so luong n hoc sinh
  DSlop = new char*[n];

  //Nhap danh sach hoc sinh tu ban phim
  cout<<"Nhap ho ten tu file "<<endl;
  inp.ignore(1);
  for (i=0; (i<n)&&(!inp.eof()); i++)
    {
      inp.getline(name, MAX_LENGTH);
      DSlop[i] = new char[strlen(name) + 1]; //Cap phat vung nho de luu tru ten
      strcpy(DSlop[i], name);
    }

  //Sap xep danh sach cac hoc sinh
  for (i=0; i<n-1; i++)
    for (j=i+1; j<n; j++)
      if (strcmp(DSlop[i], DSlop[j]) > 0)
	{
	  tg = DSlop[i];
	  DSlop[i] = DSlop[j];
	  DSlop[j] = tg;
	}
  //Hien thi danh sach hoc sinh
  cout<<"\nDanh sach hoc sinh theo thu tu: "<<endl;
  for (i=0; i<n; i++)
    cout<<DSlop[i]<<endl;
  
  //Giai phong bo nho
  for (i=0; i<n; i++)
    delete [] DSlop[i];
  delete [] DSlop;
  inp.close();
  return 0;
}
