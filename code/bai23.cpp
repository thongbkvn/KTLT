#include <iostream>
#include <iomanip>
using namespace std;
#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 2
//Cap phat bo nho cho ma tran A
void allocMatrix(int ***A, int m, int n)
{
  *A = new int*[m];
  int i, j;
  for (i=0; i<m; i++)
    (*A)[i] = new int[n];
  for (i=0; i<m; i++)
    for (j=0; j<n; j++)
      (*A)[i][j] = 0;
}

//Nhap ma tran tu ban phim
void inMatrix(int **A, int m, int n)
{
  cout<<"Nhap ma tran "<<m<<"x"<<n<<": "<<endl;
  int i,j;
  for (i=0; i<m; i++)
    {
      for (j=0; j<n; j++)
	{
	  cout<<'('<<i+1<<','<<j+1<<") :";
	  cin>>A[i][j];
	}
      cout<<endl;
    }
}

//Xuat ma tran ra man hinh
void outMatrix(int **A, int m, int n)
{
  int i, j;
  cout<<"\nMa tran "<<m<<"x"<<n<<": "<<endl;
  for (i=0; i<m; i++)
    {
      for (j=0; j<n; j++)
	cout<<setw(8)<<A[i][j];
      cout<<endl;
    }
  cout<<endl;
}

//Nhan 2 ma tran, tra ve con tro toi ma tran ket qua
int** mulMatrix(int **A, int m, int n, int **B, int p, int q)
{
  if (n != p)
    return NULL;
  int i,j,k, **C;
  allocMatrix(&C, m, q);
  
  for (i=0; i<m; i++)
    for (j=0; j<q; j++)
      {
	C[i][j] = 0;
	for (k=0; k<n; k++)
	  C[i][j] += A[i][k] * B[k][j];
      }
  return C; 	
}

//Xoa ma tran A gom m hang
void delMatrix(int **A, int m)
{
  int i;
  for (i=0; i<m; i++)
    delete [] A[i];
  delete [] A;
}

int main()
{
  int **A, **B, **C;

  //Cap phat bo nho cac ma tran
  allocMatrix(&A, ROW1, COL1);
  allocMatrix(&B, ROW2, COL2);
  //Nhap vao ma tran tu ban phim
  inMatrix(A, ROW1, COL1);
  inMatrix(B, ROW2, COL2);

  //Neu nhan duoc thi xuat ket qua ra man hinh
  if ((C = mulMatrix(A, ROW1, COL1, B, ROW2, COL2)) != NULL)
    outMatrix(C, ROW1, COL2);

  //Giai phong bo nho
  delMatrix(A, ROW1);
  delMatrix(B, ROW2);
  if (C != NULL)
    delMatrix(C, ROW1);
  return 0;
}
