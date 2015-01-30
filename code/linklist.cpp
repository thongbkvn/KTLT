#include <iostream>
#include <fstream>
#include <string.h>
#define MAX_LENGTH 1000
#define MAX_CHAR 50
using namespace std;


class Node
{
  int page; 
  Node *next;

  Node()
  {
    page = 0;
    next = NULL;
  }

  friend class List;
};

//Chia sentence thanh cac word, thay doi gia tri con tro cua sentence
void split(char* &sentence, char* &word)
{
  while (*sentence==' ')
    sentence++;
  word=sentence;
  while ((*sentence!=' ')&&(*sentence!='\0'))
    sentence++;
  if (*sentence==' ')
    {
      *sentence='\0';
      sentence++;
    }
}
/*
  Cac phuong thuc:
  -Insert(): Them 1 tu khoa, neu da ton tai thi khong them vao nua.
  -IndexKey(): Them chi muc cho tu khoa.
  -ListIndex(): Hien thi danh sach chi muc cua tu khoa
*/
class List
{
  char key[MAX_CHAR];
  Node *P;
  List *next;
public:
  List()
  {
    bzero(key, MAX_CHAR);
    P = NULL;
    next = NULL;
  }
  //Them tu khoa, neu tu khoa da ton tai thi khong them vao nua
  bool Insert(const char* keyword)
  {
    List *p;
    for (p = this; p != NULL; p = p->next)
      if (strcmp(p->key, keyword) <= 0)
	break;
    if (strcmp(p->key, keyword) != 0)
      {
	List *tmp = new List;
	strcpy(tmp->key, keyword);
	tmp->next = next;
	next = tmp;
	return true;
      }
    return false;
  }
  //Danh chi muc cho tu khoa
  bool IndexKey(const char* keyword, int page)
  {
    List *p;
    for (p = this; p != NULL; p = p->next)
      if (strcmp(p->key, keyword) == 0)
	{    
	  cout<<"Indexed "<<keyword<<endl;
	  if (p->P != NULL)
	    {
	      Node *tmp = new Node;
	      tmp->page = page;
	      tmp->next = p->P;
	      p->P=tmp;
	    }
	  else
	    {
	      p->P = new Node;
	      p->P->page = page;
	      p->P->next = NULL;
	    }
	  return true;
	}
    return false;
  }
  //Hien danh sach chi muc cua tu khoa
  bool ListIndex(const char* keyword)
  {
    List *p;
    for (p = this; (p != NULL) && (strcmp(p->key, keyword) != 0); p = p->next);
    if (p == NULL)
      return false;
    Node *tmp;
    for (tmp = p->P; tmp != NULL; tmp = tmp->next)
      cout<<tmp->page<<' ';
    cout<<endl;
    return true;
  }
  //Hien danh sach cac tu khoa duoc danh chi muc, dung de debug
  int ListKeyWord()
  {
    List *p;
    int n = 0;
    cout<<"List of keyword: ";
    for (p = this; p != NULL; p = p->next)
      {
	cout<<p->key<<' ';
	if (n%10 == 9)
	  cout<<endl;
	n++;
      }
    cout<<endl;
    return n;
  }
};

int main()
{
  List a;
  ifstream ListWord("bai3.in"); //Danh sach tu khoa
  ifstream Document("document.in"); //File can danh chi muc
  char *line = new char[MAX_LENGTH], *word, *tmp;
  int n = 1; //Bien dem so trang
  cout<<"LINK LIST VERSION\n------------------"<<endl;
  cout<<"Import keyword from \"bai3.in\"..."<<endl;
  while (!ListWord.eof())
    {
      char KeyWord[MAX_CHAR];
      ListWord>>KeyWord;
      a.Insert(KeyWord);
    }

  cout<<"Indexing..."<<endl;
  
  while (!Document.eof())
    {
      Document.getline(line, MAX_LENGTH);
      tmp = line;
      while (strlen(tmp)>0)
	{
	  split(tmp, word);
	  a.IndexKey(word, n);
	}
      n++;
    }
    
  word = new char[MAX_CHAR];
  do
    {
      cout<<"Enter keyword: ";
      cin>>word;
      if (strcmp(word, "QUIT") == 0)
	break;
      if (!a.ListIndex(word))
	cout<<"Keyword not found"<<endl;
    } while (1);
  
  delete [] line;
  delete [] word;
  ListWord.close();
  Document.close();
  cout<<"\n------------\nExit program"<<endl;
  return 0;
}
  
  
  
