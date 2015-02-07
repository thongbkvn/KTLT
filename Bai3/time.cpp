#include <iostream>
using namespace std;

class Time
{
private:
    int s; //giay
    int m; //phut
    int h; //gio
public:
    Time(int h=0, int m=0, int s=0)
	{
	    if (s>=0 && m>=0 && h>=0)
		if (s<60 && m<60)
		{
		    this->s = s;
		    this->m = m;
		    this->h = h;
		}
		else
		{
		    this->s = 0;
		    this->m = 0;
		    this->h = 0;
		}
	}
    //Nhap thoi gian
    Time input(int h=0, int m=0, int s=0)
	{
	    Time tmp(h,m,s);
	    *this = tmp;
	    return tmp;
	}
    //Chuyen gio thoi gian ve so giay tinh tu 0:0:0
    int ttoi()
	{
	    return h*3600 + m*60 + s;
	}
    //Chuyen so nguyen ve thoi gian
    Time itot(int sec)
	{
	    Time result;
	    result.h = sec/3600;
	    result.m = (sec%3600)/60;
	    result.s = (sec%3600)%60;
	    return result;
	}
    //Xem thoi gian
    void view()
	{
	    cout<<h<<':'<<m<<':'<<s;
	}


    Time operator+(Time b)
	{
	    return itot(this->ttoi() + b.ttoi());
	}
    Time operator-(Time b)
	{
	    return itot(this->ttoi() - b.ttoi());
	}
    Time operator*(int b)
	{
	    return itot(this->ttoi() * b);
	}
    Time operator/(int b)
	{
	    return itot(this->ttoi() / b);
	}
    Time operator-(int b)
	{
	    return itot(this->ttoi() - b);
	}
    Time operator+(int b)
	{
	    return itot(this->ttoi() + b);
	}
};

int main()
{
    Time a(1, 1, 10), b;
    b = a*2;
    b.view();
    cout<<endl;
    return 0;
}
    
	    
    
    
