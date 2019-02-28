#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct books
{
    char ISBN[6];
    char title[31];
    char authorName[31];
    char price[31];
    char year[31],numPage[31];
};

void addrecord(fstream & writeF,books & book)
{

    cout<<"Enter ISBN :"<<endl;
    cin.getline(book.ISBN,6);

    cout<<"Enter Title :"<<endl;
    cin.getline(book.title,31);


    cout<<"Enter Author Name :"<<endl;
    cin.getline(book.authorName,31);


    cout<<"Enter Price :"<<endl;
    cin>>book.price;
    cin.ignore();

    cout<<"Enter Year :"<<endl;
    cin>>book.year;
    cin.ignore();

    cout<<"Enter Number of Pages :"<<endl;
    cin>>book.numPage;
    cin.ignore();

    short strln;
    strln=strlen(book.ISBN);
    writeF.write((char *)&strln,sizeof(strln));
    writeF <<book.ISBN;

    strln=strlen(book.title);
    writeF.write((char *)&strln,sizeof(strln));
    writeF.write(book.title,strln);

    strln=strlen(book.authorName);
    writeF.write((char *)&strln,sizeof(strln));
    writeF <<book.authorName;

    strln=strlen(book.price);
    writeF.write((char *)&strln,sizeof(strln));
    writeF <<book.price;

    strln=strlen(book.year);
    writeF.write((char *)&strln,sizeof(strln));
    writeF <<book.year;

    strln=strlen(book.numPage);
    writeF.write((char *)&strln,sizeof(strln));
    writeF <<book.numPage;

    strln=1;
    writeF.write((char *)&strln,sizeof(strln));
    writeF <<'$';
}

void printAll(fstream & readF)
{   short s;
    readF.seekg(0,ios::beg);
    books record;
    while(!readF.eof())
    {
        readF.read((char*)&s,sizeof(s));
        readF.read(record.ISBN,s);
        record.ISBN[s]='\0';
        cout <<"ISBN            : "<<record.ISBN<<endl;

        readF.read((char*)&s,sizeof(s));
        readF.read(record.title,s);
        record.title[s]='\0';
        cout <<"Title           : "<<record.title<<endl;

        readF.read((char*)&s,sizeof(s));
        readF.read(record.authorName,s);
        record.authorName[s]='\0';
        cout <<"Author Name     : "<<record.authorName<<endl;

        readF.read((char*)&s,sizeof(s));
        readF.read(record.price,s);
        record.price[s]='\0';
        cout <<"Price           : "<<record.price<<endl;

        readF.read((char*)&s,sizeof(s));
        readF.read(record.year,s);
        record.year[s]='\0';
        cout <<"Year            : "<<record.year<<endl;

        readF.read((char*)&s,sizeof(s));
        readF.read(record.numPage,s);
        record.numPage[s]='\0';
        cout <<"Number Of pages : "<<record.numPage<<endl;
        readF.read((char *)&s,sizeof(s));
        readF.ignore();
    }
    readF.clear();
}
void printByTitle(fstream & readF,string title)
{
    short s;
    readF.seekg(0,ios::beg);
    books record;
    while(!readF.eof())
    {
        readF.read((char*)&s,sizeof(s));
        readF.read(record.ISBN,s);
        record.ISBN[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.title,s);
        record.title[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.authorName,s);
        record.authorName[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.price,s);
        record.price[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.year,s);
        record.year[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.numPage,s);
        record.numPage[s]='\0';

        readF.read((char *)&s,sizeof(s));
            if(record.title==title)
                {
                    cout <<"ISBN            : "<<record.ISBN<<endl;
                    cout <<"Title           : "<<record.title<<endl;
                    cout <<"Author Name     : "<<record.authorName<<endl;
                    cout <<"Price           : "<<record.price<<endl;
                    cout <<"Year            : "<<record.year<<endl;
                    cout <<"Number Of pages : "<<record.numPage<<endl;
                    cout <<"Thats it !!"<<endl;
                    break;
                }
        readF.ignore();
    }
    readF.clear();
}
void UpdateByISBN(fstream & readF,string isbn)
{
    int cer;
    short s;
    readF.seekg(0,ios::beg);
    books record;
    while(!readF.eof())
    {
        readF.read((char*)&s,sizeof(s));
        readF.read(record.ISBN,s);
        record.ISBN[s]='\0';
        if(record.ISBN==isbn)
        {
            cer=readF.tellg();
            //cout<<"yeaaa"<<cer<<endl;

        }

        readF.read((char*)&s,sizeof(s));
        readF.read(record.title,s);
        record.title[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.authorName,s);
        record.authorName[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.price,s);
        record.price[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.year,s);
        record.year[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.numPage,s);
        record.numPage[s]='\0';

        readF.read((char *)&s,sizeof(s));
            if(record.ISBN==isbn)
                {
                    readF.seekp((cer-3),ios::beg);
                    books b;
                    //cout<<"yeaaa"<<cer<<endl;
                    addrecord(readF,b);
                    break;
                }
        readF.ignore();
    }
    readF.clear();
}
void delet(fstream & readF,string isbn)
{
    int cer;
    short s;
    readF.seekg(0,ios::beg);
    books record;
    while(!readF.eof())
    {
        readF.read((char*)&s,sizeof(s));
        readF.read(record.ISBN,s);
        record.ISBN[s]='\0';
        if(record.ISBN==isbn)
        {
            cer=readF.tellg();
            //cout<<"yeaaa"<<cer<<endl;

        }

        readF.read((char*)&s,sizeof(s));
        readF.read(record.title,s);
        record.title[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.authorName,s);
        record.authorName[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.price,s);
        record.price[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.year,s);
        record.year[s]='\0';

        readF.read((char*)&s,sizeof(s));
        readF.read(record.numPage,s);
        record.numPage[s]='\0';

        readF.read((char *)&s,sizeof(s));
            if(record.ISBN==isbn)
                {
                    readF.seekp((cer-3),ios::beg);
                    //cout<<"yeaaa"<<cer<<endl;
                    readF << '&';
                    break;
                }
        readF.ignore();
    }
    readF.clear();
}
int main()
{
    fstream f,f1,f3,f5;
    f.open("file1.txt");

    books b,d,s;
    addrecord(f,b);
    addrecord(f,d);
    addrecord(f,s);
    printAll(f);
    f.close();

    f1.open("file1.txt",ios::out|ios::in);
    printByTitle(f1,"baba baba");
    f1.close();

    f3.open("file1.txt",ios::out|ios::in);
    //UpdateByISBN(f3,"2");
    f3.close();

    f5.open("file1.txt",ios::out|ios::in);
    delet(f5,"2");

    f5.close();
    return 0;
}
