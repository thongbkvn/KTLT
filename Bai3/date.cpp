#include <iostream>
using namespace std;
#define Y 1970
class date
{
private:
    int d;
    int m;
    int y;
    
public:
    //Ham tao 
    date(int d=1, int m=1, int y=Y)
	{
	    if (d > 0 && m > 0)
		if (y>=1970 && m<=12 && d<=dinm(m))
		{
		    this->d = d;
		    this->m = m;
		    this->y = y;
		}
		else
		{
		    this->d = 1;
		    this->m = 1;
		    this->y = Y;
		}
	}
    date input(int d=1, int m=1, int y=Y)
	{
	    date tmp(d,m,y);
	    *this = tmp;
	    return tmp;
	}
    //Kiem tra nam nhuan
    bool leapyear(int y = -1)
	{
	    if (y == -1)
		y = this->y;
	    if ((y%4 != 0) || ((y%100 == 0) && (y%400 != 0)))
		return false;
	    return true;
	}
    
    //Tinh so ngay trong thang
    int dinm(int m = -1)
	{
	    if (m == -1)
		m = this->m;
	    static int A[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	    return (m != 2) ? A[m] : (leapyear()?29:28);
	}

    //Doi ngay thang nam ra so ngay tinh tu 1/1/Y
    int dtoi()
	{
	    int i, S=0;
	    for (i = Y; i < y; i++)
		S += 365 + leapyear(i);
	    for (i = 1; i < m; i++)
		S += dinm(i);
	    S += d;
	    return S;
	}

    //Doi so ngay tinh tu 1/1/Y ra ngay, thang, nam
    date itod(int n)
	{
	    date result(1,1,Y);
	    while (n >= 365+result.leapyear())
	    {
		n -= 365 + result.leapyear();
		result.y += 1;
	    }
	    while (n >= result.dinm())
	    {
		n -= result.dinm();
		if (result.m + 1 < 12)
		    result.m += 1;
		else
		{
		    result.m = 1;
		    result.y += 1;
		}
	    }

	    result.d = n;
	    return result;
	}

    date operator+(int day)
	{
	    int tmp;
	    date result;
	    tmp = this->dtoi();
	    tmp += day;
	    result = itod(tmp);
	    return result;
	}

    date operator-(int day)
	{
	    return itod(dtoi()-day);
	}

    int operator-(date b)
	{
	    return this->dtoi()- b.dtoi();
	}

    void view()
	{
	    cout<<d<<'/'<<m<<'/'<<y;
	}
};

int main()
{
    date a(1,1,2000),b;
    b = a + 1536;
    b.view();
    cout<<endl;
    return 0;
}
