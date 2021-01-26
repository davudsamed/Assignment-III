////****************************************************************************
//**					       SAKARYA ÜNÝVERSÝTESÝ
//**			        BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
//**						 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
//**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
//**
//**				ÖDEV NUMARASI…...: 3
//**				ÖÐRENCÝ ADI......: Davud Samed Tombul
//**				ÖÐRENCÝ NUMARASI.: B171210007
//**				DERS GRUBU.......: 1D
//****************************************************************************/

#include<iostream>//Cout gibi temel komutlarý kullanmamýzý saðlayan kütüphane.
#include<locale.h>//Türkçe karakterleri kullanabilmemiz için gerekli kütüphane.
#include<math.h>//Kare alma iþlemini yapabilmemiz için gerekli kütüphane.
//Her seferinde std:: yazarak uðraþmamak için kullandýðýmýz komut.
using namespace std;

//Global deðiþkenler


//Fonksiyon bildirisi
void yazdir();

//Giriþ matrisimizin boyutu


//Yapý içerisinde üye olarak matrislerimizi, çekirdek ve sonuç matrisinin boyutunu ve kayma miktarýný tanýmladým.
struct Ýslem
{

	int giris[5][5] = { 2,3,4,5,4,
						4,3,2,1,3,
						5,6,7,8,5,
						2,3,7,5,4,
						2,4,6,2,1 };

	int sonuc[100][100], cekirdek[100][100];

	int cekirdekBoyut, kaymaMiktari, sonucBoyut;
	
	
}Yapý;//Yapý oluþturuluyor.



int main()
{
	int toplam = 0, sayac1 = 0, sayac2 = 0;

	setlocale(LC_ALL, "Turkish");
	

	//Giriþ matrisimizi main yani ana fonksiyonda kullanabilmek için çaðýrýyoruz.
	Ýslem girisM;

	int girisBoyut = sqrt(sizeof(girisM.giris) / 4);

	cout << "Çekirdeðin boyutunu giriniz: " << endl;
	cin >> Yapý.cekirdekBoyut;

	cout << "Çekirdeðin kayma miktarýný giriniz: " << endl;
	cin >> Yapý.kaymaMiktari;

	Yapý.sonucBoyut = ((girisBoyut - Yapý.cekirdekBoyut) / Yapý.kaymaMiktari) + 1;

	//Kayma miktarý ve çekirdek boyutunun toplamýnýn giriþ boyutundan büyük olduðu durumlarda iþlem yapýlamaz.
	if (Yapý.cekirdekBoyut+Yapý.kaymaMiktari>girisBoyut|| (girisBoyut-Yapý.cekirdekBoyut)%Yapý.kaymaMiktari !=0)
	{
		cout << "Bu iþlem yapýlamaz" << endl;
	}
	else
	{
		cout << "Çekirdeðin elemanlarýný giriniz: ";

		//Çekirdeðin elemanlarýný kullanýcýdan almamýz için gerekli iteratif iþlemler.
		for (int i = 0; i < Yapý.cekirdekBoyut; i++)
		{
			for (int j = 0; j < Yapý.cekirdekBoyut; j++)
			{
				cout << "cekirdek[" << i << "][" << j << "] = ";
				cin >> Yapý.cekirdek[i][j];
				cout << "\n";
			}
		}

		//Kullanýcýnýn girdiði çekirdek elemanlarý ve çekirdek kayma miktarýný kullanarak sonuc matrisinin elemanlarýný üretmemizi saðlayan for döngüleri.
		for (int k = 0; k < Yapý.sonucBoyut; k++)
		{
			for (int t = 0; t < Yapý.sonucBoyut; t++)
			{
				for (int q = 0; q < Yapý.cekirdekBoyut; q++)
				{
					for (int w = 0; w < Yapý.cekirdekBoyut; w++)
					{
						toplam += girisM.giris[q + sayac2][w + sayac1] * Yapý.cekirdek[q][w];
					}
				}
				sayac1 += Yapý.kaymaMiktari;
				Yapý.sonuc[k][t] = toplam;
				toplam = 0;

				//Çekirdek giriþ matrisinde bulunduðun satýrýn en sonuna gittiðinde sayac1 sýfýrlanýr ve çekirdeðin alt satýra geçmesi için sayac 2 kayma miktarý kadar arttýrýlýr.
				if (sayac1+ Yapý.cekirdekBoyut>girisBoyut)
				{
					sayac2 += Yapý.kaymaMiktari;
					sayac1 = 0;
				}
				//Giriþ matrisi üzerinde dolanan çekirdeðimiz son satýr ve sütüna kadar geldikten sonra iþlemi bitirmek için goto komutunu kullandým.
				if (sayac2+Yapý.cekirdekBoyut > girisBoyut)
				{
					goto Paris;
				}
			}
		}

		//Gerekli çarpým iþlemleri sona erdiðinde goto komutu kullanarak derleyicinin iþleme buradan devam etmesini saðladým.
	Paris:

		//Sonuc fonksiyonunun ekrana yazdýrýlmasýný saðlayan fonksiyonumuzu çaðýrma iþlemi.
		yazdir();
	}

	//Giriþ verileri hatalý girildiðinde derleyici ara basamaklarý atlayarak goto komutu ile bu satýra gelir.

	system("pause");

	return 0;
}

//Sonuç matrisini yazdýrmaya yarayan fonksiyonun ana gövdesi.
void yazdir()
{
	for (int i = 0; i < Yapý.sonucBoyut; i++)
	{
		for (int j = 0; j < Yapý.sonucBoyut; j++)
		{
			cout << "\t" << Yapý.sonuc[i][j];
		}

		cout << "\n";
	}
}
