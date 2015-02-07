#include <iostream>
#include <iomanip>
#define WIDE 8
#include <stdlib.h>
using namespace std;

class matrix
{
    int m, n, **A;
    char name;
public:
    //Ham tao ma tran kich thuoc m*n
    matrix(int m=0, int n=0, char name='\0')
	{
	    //Neu m hoac n la 0 thi khong cap phat
	    if (m==0 || n==0)
	    {
		m=0;
		n=0;
		A=NULL;
	    }
	    //Luu kich thuoc mang
	    this->m = m;
	    this->n = n;
	    this->name = name;
	    //Cap phat bo nho
	    A = new int*[m];
	    for (int i=0; i<m; i++)
		A[i] = new int[n];
	}
    //Ham tao sao chep
    matrix(const matrix &b)
	{
	    m = b.m;
	    n = b.n;
	    name = '\0';
	    //Cap phat nho
	    A = new int*[m];
	    for (int i=0; i<m; i++)
		A[i] = new int[n];
	    //Chep du lieu
	    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		    A[i][j] = b.A[i][j];
	}
    //Dat ten cho ma tran
    void setname(char name)
	{
	    this->name = name;
	}
    
    //Cap phat cho ma tran
    void realloc(int m, int n)
	{
	    //Neu bang kich thuoc cu thi thoat
	    if (this->m == m && this->n == n)
		return;
	    //Luu mang vao sap huy bien tam
	    int **tmp = this->A;
	    //Cap phat mang moi
	    this->A = new int*[m];
	    for (int i=0; i<m; i++)
		A[i] = new int[n];
	    
	    int a=this->m<m ? this->m : m;
	    int b=this->n<n ? this->n : n;
	    //Sao chep du lieu sang 
	    for (int i=0; i<a; i++)
		for (int j=0; j<b; j++)
		    A[i][j] = tmp[i][j];
	    //Huy vung du lieu da cap phat
	    if (tmp != NULL)
	    {
		for (int i=0; i<this->m; i++)
		    delete [] tmp[i];
		delete [] tmp;
	    }
	    //Luu kich thuoc ma tran moi
	    this->m = m;
	    this->n = n;
	}
		

    //Da nang hoa toan tu gan
    matrix& operator=(const matrix& b)
	{
	    //Neu kich thuoc khac nhau thi cap phat lai kich thuoc moi
	    if (m != b.m || n != b.n)
		realloc(b.m, b.n);
	    
	    //Kiem tra tu gan
	    if (this == &b)
		return *this;
	    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		    A[i][j] = b.A[i][j];
	    return *this;
	}
    //Da nang hoa toan tu cong ma tran voi ma tran
    matrix operator+(matrix b)
	{
	    //Neu khong cung kich thuoc thi bao loi
	    if (m != b.m || n != b.n)
	    {
		cout<<"Khong the cong 2 ma tran khac kich thuoc"<<endl;
		exit(1);
	    }
	    matrix tmp(m,n);
	    //Cong 2 ma tran
	    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		    tmp.A[i][j] = A[i][j] + b.A[i][j];
	    return tmp;
	}
    //Da nang hoa toan tu tru ma tran voi ma tran
    matrix operator-(matrix b)
	{
	    //Neu khong cung kich thuoc bao loi
	    if (m != b.m || n != b.n)
	    {
		cout<<"Khong the tru 2 ma tran kich thuoc"<<endl;
		exit(-1);
	    }
	    matrix tmp(m,n);

	    //Tru hai ma tran
	    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		    tmp.A[i][j] = A[i][j] - b.A[i][j];
	    return tmp;
	}
    
    //Da nang hoa toan tu nhan ma tran voi 1 so nguyen
    matrix operator*(int b)
	{
	    matrix tmp(m,n);
	    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		    tmp.A[i][j] = A[i][j] * b;
	    return tmp;
	}

    ///Da nang hoa toan tu nhan ma tran voi ma tran
    matrix operator*(matrix b)
	{
	    //Kiem tra kich thuoc dau vao
	    if (n != b.m)
	    {
		cout<<"Khong the nhan 2 ma tran kich thuo khong phu hop"<<endl;
		exit(-1);
	    }

	    matrix tmp(m, b.n);
	    for (int i=0; i<m; i++)
		for (int j=0; j<b.n; j++)
		{
		    tmp.A[i][j] = 0;
		    for (int k=0; k<n; k++)
			tmp.A[i][j] += A[i][k]*b.A[k][j];
		}
	    return tmp;
	}
    //++ tien to
    matrix& operator++()
	{
	    //Neu khong phai la ma tran vuong thi khong thuc hien duoc
	    if (m != n)
	    {
		cout<<"Khong phai la ma tran vuong"<<endl;
		exit(-1);
	    }
	    //Tang gia tri cac phan tu tren duong cheo chinh len 1
	    for (int i=0; i<m; i++)
		A[i][i] += 1;
	    return *this;
	}
    //hau to ++, khong duoc lam ve trai phep gan
    matrix operator++(int)
	{
	    //Luu ket qua tam
	    matrix tmp = *this;
	    if (m != n)
	    {
		cout<<"Khong phai la ma tran vuong"<<endl;
		exit(-1);
	    }
	    //Tang gia tri cac phan tu tren duong cheo chinh len 1
	    for (int i=0; i<m; i++)
		A[i][i] += 1;
	    return tmp;
	}
    //Da nang hoa toan tu += voi ma tran
    matrix& operator+=(matrix b)
	{
	    // *this = *this + b
	    //Kiem tra kich thuoc dau vao
	    if (m != b.m || n != b.n)
	    {
		cout<<"Khong the cong hai ma tran khac kisch thuoc"<<endl;
		exit(-1);
	    }
     
	    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		    A[i][j] += b.A[i][j];
	    return *this;
	}

    friend ostream& operator<<(ostream &out, matrix &b);
    friend istream& operator>>(istream &in, matrix &b);
		
};

//Da nang hoa toan tu nhap cua ostream
ostream& operator<<(ostream &out, matrix &b)
{
    out<<"Matrix "<<b.name<<": "<<endl;
    for (int i=0; i<b.m; i++)
    {
	for (int j=0; j<b.n; j++)
	    out<<setw(WIDE)<<b.A[i][j];
	out<<endl;
    }
    return out;
}
//Da nang hoa toan tu xuat cua lop istream
istream& operator>>(istream &in, matrix &b)
{

    cout<<"Input matrix "<<b.name<<": "<<endl;
    for (int i=0; i<b.m; i++)
    {
	cout<<"Row "<<i<<": "<<endl;
	for (int j=0; j<b.n; j++)
	{
	    cout<<b.name<<'['<<i<<','<<j<<"]: ";
	    in>>b.A[i][j];
	}
	cout<<endl;
    }

    cout<<"Input complete!"<<endl;
    return in;
}
int main()
{
    matrix a(2,2,'A'),c(1,1,'C'), b(1,2,'B');
    //Nhap a
    cin>>a;
    cout<<a;
    b=a;
    c = a+b+a;
    cout<<c;
    return 0;
}
	       
