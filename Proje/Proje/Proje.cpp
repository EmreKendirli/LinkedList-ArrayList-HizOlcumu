#include <iostream>
using namespace std;
#include <chrono>
#include <sstream> 


struct ArrayList {
    int* bas;
    void olustur();
    void ekle(int sayi, int sira);
    void guncelle(int sayi, int sira);
    void sil(int sil);
    void yazdir();
    void bosalt();
    int sayac;
};


struct Node {
    int deger;
    Node* sonraki;
};
struct LinkedList {
    Node* bas;
    void olustur();
    void yazdir();
    void ekle(int sayi, int sira);;
    void guncelle(int sayi, int sira);
    void sil(int sil);
    void bosalt();
    int sayac=0;

};
int main()
{
    
    LinkedList* linkedList = new LinkedList();
    linkedList->olustur();
    ArrayList* arrayList = new ArrayList();
    for (int i = 0; i < 100; i++)
    {

        linkedList->ekle(i, i);
    }
    for (int i = 0; i < 100; i++)
    {
        arrayList->olustur();
        arrayList->ekle(i, i);
    }
   
    auto begin1 = std::chrono::high_resolution_clock::now();

    
    linkedList->guncelle(50, 25);

    auto end1 = std::chrono::high_resolution_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);

    cout << "LinkedList 100 verili listede (50,25) degeri guncelleme hizi:  " << elapsed1.count() <<" microsaniye"<< endl;
   



    auto begin2 = std::chrono::high_resolution_clock::now();

    arrayList->guncelle(50, 25);
   
    
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);

    cout << "ArrayList 100 verili listede (50,25) degeri guncelleme hizi : "<<elapsed2.count() << " microsaniye" << endl;
}
void LinkedList::olustur()
{
    bas = NULL; 
}
void LinkedList::yazdir()
{
    Node* tara;
    tara = bas;
    if (!tara)
    {
        cout << "liste bos" << endl;
        return;
    }
    while (tara)
    {
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}
void LinkedList::ekle(int sayi, int sira)
{
    sayac = 0;
    Node* a = new Node();
    Node* tara = bas;

    a->deger = sayi;
    if (bas == NULL)
    {
        a->sonraki = tara;
        bas = a;
        return;
    }
    while (tara->sonraki)
    {
        if (sayac == sira-1 )
        {
            a->sonraki = tara->sonraki;
            tara->sonraki = a;
            return;
        }
        else
        {
            tara = tara->sonraki;
            sayac++;
        }
    }
    if (sayac + 1 >= sira)
    {
        tara->sonraki = a;
        return;
    }
}
void LinkedList::guncelle(int sayi, int sira)
{
    Node* n = new Node();
    if (bas == NULL)
    {
        bas=n;
    }
    Node* tara = bas;
    for (int i = 0; i < sira - 1; i++)
    {
        tara = tara->sonraki;
    }
    tara->deger = sayi;

}
void LinkedList::sil(int sil)
{
    Node* tara = bas;
    Node* tara1;
    for (int i = 1; i < sil - 1; i++)
    {
        tara = tara->sonraki;
    }
    tara1 = tara->sonraki;
    tara->sonraki = tara1->sonraki;
    delete tara1;
}
void LinkedList::bosalt() {
    Node* tara;
    while (bas != NULL)
    {
        tara = bas;
        bas = bas->sonraki;
        delete tara;
    }
}



void ArrayList::olustur() {
    
    bas = new int[sayac + 1];
    sayac++;
}
void ArrayList::bosalt() {
    delete bas;
   // sayac = 0;
}
void ArrayList::ekle(int sayi, int sira) 
{
    int* arr = new int[sayac + 1];
 
   for (int i = 0; i < sayac; i++)
    {

        arr[i] = bas[i];
    }

    bas[sira] = sayi;
    for (int i = 0; i < sayac + 1; i++)
    {
        if (i > sira)
        {
            bas[i] = arr[i - 1];
        }
    }
    sayac++;


}
void ArrayList::guncelle(int sayi, int sira) {
    bas[sira] = sayi;
}
void ArrayList::sil(int sil) {

    for (int i = 0; i < sayac - 1; i++)
    {
        if (i >= sil)
        {
            bas[i] = bas[i + 1];
        }

    }
    sayac--;
}
void ArrayList::yazdir()
{
    if (sayac == 0)
    {
        cout << "Dizi Bos";
    }
    for (int i = 0; i < sayac; i++)
    {
        cout << bas[i] << " ";
    }
    cout << endl;
}
