#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>

using namespace std;

struct Doktor
{
	char ad[40];
	char soyad[40];
	char id[5];
	char cinsiyet;
};

struct Hasta
{
	char ad[40];
	char soyad[40];
	char tc[11];
	char cinsiyet;
};

void DoktorEkle();
void DoktorListele();
void DoktorAra();
void DoktorSil();
void DoktorDuzenle();
void HastaEkle();
void HastaListele();
void HastaAra();
void HastaSil();
void HastaDuzenle();

int main()
{
	setlocale(LC_ALL , "Turkish");
	char secim;
	
	do
	{
		char secim2;
		char secim3;
		system("cls");
		cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^|" << endl ;
		cout << "|      Ho� geldiniz       |" << endl ;
		cout << "|      Se�im Yap�n�z      |" << endl ;
		cout << "|     1- Doktor Giris     |" << endl ;
		cout << "|     2- Hasta Giris      |" << endl ;
		cout << "|_________________________|" << endl ;
		char sec;
		cin >> sec;
		
		if(sec == '1')
		{
			do
				{
					system("cls");
					cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^|" << endl ;
					cout << "|      Ho� geldiniz       |" << endl ;
					cout << "|      Se�im Yap�n�z      |" << endl ;
					cout << "|    1- Doktor Ekleme     |" << endl ;
					cout << "|    2- Doktor Listeleme  |" << endl ;
					cout << "|    3- Doktor Arama      |"<< endl;
					cout << "|    4- Doktor Sil        |"<< endl;
					cout << "|    5- Doktor D�zenle    |"<< endl;
					cout << "|_________________________|" << endl ;
					
					char sec2;
					cin >> sec2;
					
					switch(sec2) 
					{
						case '1' : 
						{
						DoktorEkle();
						break;	
						}
						case '2' : 
						{
						DoktorListele();
						 break;
						}
						case '3' : 
						{
						DoktorAra();
						 break;
						}
						case '4' : 
						{
						DoktorSil();
						 break;
						}
						case '5' : 
						{
						DoktorDuzenle();
						 break;
						}
					}
				cout << endl;
				cout << "�st men�ye d�nmek ister misiniz? (e/h)";
				secim2=getche();
				}while(secim2== 'e' || secim2=='E');
		}
		else if(sec == '2')
		{
			do
				{
					system("cls");
					cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^|" << endl ;
					cout << "|      Ho� geldiniz       |" << endl ;
					cout << "|      Se�im Yap�n�z      |" << endl ;
					cout << "|    1- Hasta Ekleme      |" << endl ;
					cout << "|    2- Hasta Listeleme   |" << endl ;
					cout << "|    3- Hasta Arama       |"<< endl;
					cout << "|    4- Hasta Sil         |"<< endl;
					cout << "|    5- Hasta D�zenle     |"<< endl;
					cout << "|_________________________|" << endl ;
					
					char sec;
					cin >> sec;
					
					switch(sec) 
					{
						{
						case '1' : 
						HastaEkle();
						
						break;	
						}
						case '2' : 
						{
						 HastaListele();
						 break;
						}
						case '3' : 
						{
						 HastaAra();
						 break;
						}
						case '4' : 
						{
						 HastaSil();
						 break;
						}
						case '5' : 
						{
						 HastaDuzenle();
						 break;
						}
					}
				
				cout << "�st men�ye d�nmek ister misiniz? (e/h)";
				secim3=getche();
				}while(secim3== 'e' || secim3=='E');
		}
		
	
	cout << endl;
	cout << "Ana men�ye d�nmek ister misiniz? (e/h)";
	secim=getche();
	}while(secim== 'e' || secim=='E');
	

	system("pause");
	return 0;
}

Doktor dr;
Hasta hasta;

void DoktorEkle()
{
	ofstream yaz("doktor.dat",ios::binary | ios::app);
	
	char secim;
	int adet=0;
	do
	{
		cout << "Doktor ad� giriniz : ";
		cin >> dr.ad;
		cout << "Doktor soyad� giriniz : ";
		cin >> dr.soyad;
		cout << "Doktor id giriniz : ";
		cin >> dr.id;
		cout << "Doktor cinsiyet giriniz(E/K) :";
	    dr.cinsiyet = getche();
	    cout <<endl;
		yaz.write((char*)&dr, sizeof(dr));
		adet++;
		cout << "Ba�ka bir doktor eklemek ister misiniz? (E/H) : ";
		secim=getche();
	}
	while(secim== 'e' || secim=='E');
	cout << endl;
	cout << adet << " doktor eklendi." << endl;
	yaz.close();
	}


void DoktorListele()
{
	ifstream oku("doktor.dat",ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	int doktors = oku.tellg()/sizeof(dr);
	cout << "Toplam girilen doktor say�s� : " << doktors << endl;
	
	if(doktors>0)
	{
		for(int i=0; i < doktors; i++ )
		{
			oku.seekg(i*sizeof(dr));
			oku.read((char*)&dr, sizeof(dr));
			
			cout << i+1 << ". doktorun bilgileri : " << endl;
			cout << "Doktor ad� : " << dr.ad << endl;
			cout << "Doktor soyad� : " << dr.soyad << endl;
			cout << "Doktor id : " << dr.id << endl;
			if(dr.cinsiyet == 'k' || dr.cinsiyet == 'K')
			cout << "Doktor cinsiyeti : Kad�n " << endl;
			else if(dr.cinsiyet == 'e' || dr.cinsiyet == 'E')
			cout << "Doktor cinsiyeti : Erkek " << endl;
		}
	}
	else
	cout << "Kay�t bulunamad�! " << endl;
	
	oku.close();
	}
	
void DoktorAra()
{
	ifstream oku("doktor.dat",ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	int doktors = oku.tellg()/sizeof(dr);
	
	char id[5];
	cout << "Aranan doktor id bilgisi : ";
	cin >> id;
	
	if(doktors>0)
	{
		for(int i=0; i < doktors; i++ )
		{
			oku.seekg(i*sizeof(dr));
			oku.read((char*)&dr, sizeof(dr));
			
			if(strcmp(dr.id,id)==0)
			{
			cout << "Bulunan doktorun bilgileri : " << endl;
			cout << "Doktor ad� : " << dr.ad << endl;
			cout << "Doktor soyad� : " << dr.soyad << endl;
			cout << "Doktor id : " << dr.id << endl;
			if(dr.cinsiyet == 'k' || dr.cinsiyet == 'K')
			cout << "Doktor cinsiyeti : Kad�n " << endl;
			else if(dr.cinsiyet == 'e' || dr.cinsiyet == 'E')
			cout << "Doktor cinsiyeti : Erkek " << endl;
			}
		
		}
	}
	else
	cout << "Kay�t bulunamad�! " << endl;
	
	oku.close();
}

void DoktorSil()
{
    char drid[5];
    char secim = ' ';
    bool var = false;
    
    ifstream oku("doktor.dat", ios::binary);
    ofstream yeniDosya("YedekDoktor.dat", ios::binary | ios::app);
    
    oku.seekg(0, ios::end);
    int doktorsayisi = oku.tellg() / sizeof(dr);
    
    cout << "Kayd�n� silece�iniz doktor id bilgisi : ";
    cin >> drid;
    
    for (int i = 0; i < doktorsayisi; i++)
    {
        oku.seekg(i * sizeof(dr));
        oku.read((char*)&dr, sizeof(dr));
        
        if (strcmp(dr.id, drid) == 0)
        {
            cout << "�lgili doktorun bilgileri : " << endl;
            cout << "Doktor ad� : " << dr.ad << endl;
            cout << "Doktor soyad� : " << dr.soyad << endl;
            cout << "Doktor id : " << dr.id << endl;
            if (dr.cinsiyet == 'k' || dr.cinsiyet == 'K')
                cout << "Doktor cinsiyeti : Kad�n " << endl;
            else if (dr.cinsiyet == 'e' || dr.cinsiyet == 'E')
                cout << "Doktor cinsiyeti : Erkek " << endl;
            
            cout << "\nSilmek istenilen kay�t do�ru mu? (E/H) : ";
            secim = getche();
            if (secim == 'e' || secim == 'E')
            {
                var = true; 
            }
            else
            {
                yeniDosya.write((char*)&dr, sizeof(dr));  
            }
        }
        else
        {
            yeniDosya.write((char*)&dr, sizeof(dr));  
        }
    }
    
    oku.close();
    yeniDosya.close();
    
    if (var)
    {
        remove("doktor.dat");
        rename("YedekDoktor.dat", "doktor.dat");
        cout << "\n Kayit Silindi" << endl;
    }
    else
    {
        remove("YedekDoktor.dat");
        cout << "\n Kay�t bulunamad�" << endl;
    }
}

void DoktorDuzenle()
{
	char drid[5];
	char secim = ' ';
	bool var = false;
	
	ifstream oku("doktor.dat",ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	int doktorsayisi=oku.tellg()/sizeof(dr);
	
	cout << "Kayd�n� d�zeltece�iniz id : ";
	cin >> drid;
	
	for(int i=0; i<doktorsayisi; i++)
	{
		oku.seekg(i*sizeof(dr));
		oku.read((char*)&dr,sizeof(dr));
		
		if(strcmp(dr.id,drid) == 0)
		{
			cout << "�lgili doktorun bilgileri : " << endl;	
			cout << "Doktor ad� : " << dr.ad << endl;
			cout << "Doktor soyad� : " << dr.soyad << endl;
			cout << "Doktor id : " << dr.id << endl;
			if(dr.cinsiyet == 'k' || dr.cinsiyet == 'K')
			cout << "Doktor cinsiyeti : Kad�n " << endl;
			else if(dr.cinsiyet == 'e' || dr.cinsiyet == 'E')
			cout << "Doktor cinsiyeti : Erkek " << endl;
			
			cout << "\nD�zeltmek istenilen kay�t do�ru mu? (E/H) : ";
			secim = getche();
			if(secim == 'E' || secim == 'e')
			{
				var = true;
				ofstream dosya("Yedek.dat",ios::binary | ios::app);
				cout << endl;
				cout << "Doktor ad� giriniz : ";
				cin >> dr.ad;
				cout << "Doktor soyad� giriniz : ";
				cin >> dr.soyad;
				cout << "Doktor id giriniz : ";
				cin >> dr.id;
				cout << "Doktor cinsiyet giriniz(E/K) :";
			    dr.cinsiyet = getche();
			    cout << endl;
			    
			    dosya.write((char*)&dr, sizeof(dr));
			    dosya.close();
			}
			else
			{
				Doktor dkr;
            	ofstream y_dosya("Yedek.dat",ios::binary | ios::app);
                
                strcpy(dkr.ad,dr.ad);
				strcpy(dkr.soyad,dr.soyad);
				strcpy(dkr.id,dr.id);
				dr.cinsiyet = dkr.cinsiyet;
                         
             	y_dosya.write((char*)&dkr, sizeof(dkr));
                y_dosya.close();
			}
		}
	}

	oku.close();
		if(var)
		{
			remove("doktor.dat");
			rename("Yedek.dat","doktor.dat");
            cout<<"\n Kayit D�zeltildi"<<endl;
		}
		else
		{
			remove("Yedek.dat");
			cout << "\n Kay�t bulunamad�" << endl;
		}
}

void HastaEkle()
{
	ofstream yaz("hasta.dat",ios::binary | ios::app);
	
	char secim;
	int adet=0;
	do
	{
		cout << "Hasta ad� giriniz : ";
		cin >> hasta.ad;
		cout << "Hasta soyad� giriniz : ";
		cin >> hasta.soyad;
		cout << "Hasta TC giriniz : ";
		cin >> hasta.tc;
		cout << "Hasta cinsiyet giriniz(E/K) :";
	    hasta.cinsiyet = getche();
	    cout <<endl;
		yaz.write((char*)&hasta, sizeof(hasta));
		adet++;
		cout << "Ba�ka bir Hasta eklemek ister misiniz? (E/H) : ";
		secim=getche();
		cout << endl;
	}
	while(secim== 'e' || secim=='E');
	cout << endl;
	cout << adet << " doktor eklendi." << endl;
	yaz.close();
}

void HastaListele()
{
	ifstream oku("hasta.dat",ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	int hastalar = oku.tellg()/sizeof(hasta);
	cout << "Toplam girilen hasta say�s� : " << hastalar << endl;
	
	if(hastalar>0)
	{
		for(int i=0; i < hastalar; i++ )
		{
			oku.seekg(i*sizeof(hasta));
			oku.read((char*)&hasta, sizeof(hasta));
			
			cout << i+1 << ". hastan�n bilgileri : " << endl;
			cout << "Hasta ad� : " << hasta.ad << endl;
			cout << "Hasta soyad� : " << hasta.soyad << endl;
			cout << "Hasta TC : " << hasta.tc << endl;
			if(dr.cinsiyet == 'k' || hasta.cinsiyet == 'K')
			cout << "Hasta cinsiyeti : Kad�n " << endl;
			else if(dr.cinsiyet == 'e' || hasta.cinsiyet == 'E')
			cout << "Hasta cinsiyeti : Erkek " << endl;
		}
	}
	else
	cout << "Kay�t bulunamad�! " << endl;
	
	oku.close();
}
void HastaAra()
{
	ifstream oku("hasta.dat",ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	int hastalar = oku.tellg()/sizeof(hasta);
	
	char tc[5];
	cout << "Aranan Hasta TC bilgisi : ";
	cin >> tc;
	
	if(hastalar>0)
	{
		for(int i=0; i < hastalar; i++ )
		{
			oku.seekg(i*sizeof(hasta));
			oku.read((char*)&hasta, sizeof(hasta));
			
			if(strcmp(hasta.tc,tc)==0)
			{
			cout << "Bulunan hastan�n bilgileri : " << endl;
			cout << "Hasta ad� : " << hasta.ad << endl;
			cout << "Hasta soyad� : " << hasta.soyad << endl;
			cout << "Hasta id : " << hasta.tc << endl;
			if(hasta.cinsiyet == 'k' || hasta.cinsiyet == 'K')
			cout << "Hasta cinsiyeti : Kad�n " << endl;
			else if(hasta.cinsiyet == 'e' || hasta.cinsiyet == 'E')
			cout << "Hasta cinsiyeti : Erkek " << endl;
			}
		
		}
	}
	else
	cout << "Kay�t bulunamad�! " << endl;
	
	oku.close();
}
void HastaSil()
{
    char hastatc[11];  
    char secim = ' ';
    bool var = false;
    
    ifstream oku("hasta.dat", ios::binary);
    ofstream yeniDosya("YedekHasta.dat", ios::binary | ios::app);
    
    oku.seekg(0, ios::end);
    int hasta_sayisi = oku.tellg() / sizeof(hasta);
    
    cout << "Kayd�n� silece�iniz Hasta TC bilgisi : ";
    cin >> hastatc;
    
    for (int i = 0; i < hasta_sayisi; i++)
    {
        oku.seekg(i * sizeof(hasta));
        oku.read((char*)&hasta, sizeof(hasta));
        
        if (strcmp(hasta.tc, hastatc) == 0)
        {
            cout << "�lgili hastan�n bilgileri : " << endl;
            cout << "Hasta ad� : " << hasta.ad << endl;
            cout << "Hasta soyad� : " << hasta.soyad << endl;
            cout << "Hasta TC : " << hasta.tc << endl;
            if (hasta.cinsiyet == 'k' || hasta.cinsiyet == 'K')
                cout << "Hasta cinsiyeti : Kad�n " << endl;
            else if (hasta.cinsiyet == 'e' || hasta.cinsiyet == 'E')
                cout << "Hasta cinsiyeti : Erkek " << endl;
            
            cout << "\nSilmek istenilen kay�t do�ru mu? (E/H) : ";
            secim = getche();
            if (secim == 'e' || secim == 'E')
            {
                var = true;  
            }
            else
            {
                yeniDosya.write((char*)&hasta, sizeof(hasta));  
            }
        }
        else
        {
            yeniDosya.write((char*)&hasta, sizeof(hasta));  
        }
    }
    
    oku.close();
    yeniDosya.close();
    
    if (var)
    {
        remove("hasta.dat");
        rename("YedekHasta.dat", "hasta.dat");
        cout << "\n Kayit Silindi" << endl;
    }
    else
    {
        remove("YedekHasta.dat");
        cout << "\n Kay�t bulunamad�" << endl;
    }
}


void HastaDuzenle()
{
	char hastatc[5];
	char secim = ' ';
	bool var = false;
	
	ifstream oku("hasta.dat",ios::binary | ios::app);
	
	oku.seekg(0,ios::end);
	int hasta_sayisi = 	oku.tellg()/sizeof(hasta);
	
	cout << "Kayd�n� d�zeltece�iniz TC : ";
	cin >> hastatc;
	
	for(int i=0; i<hasta_sayisi; i++)
	{
		oku.seekg(i*sizeof(hasta));
		oku.read((char*)&hasta,sizeof(hasta));
		
		if(strcmp(hasta.tc,hastatc)==0)
		{
			cout << "�lgili hastan�n bilgileri : " << endl;	
			cout << "Hasta ad� : " << hasta.ad << endl;
			cout << "Hasta soyad� : " << hasta.soyad << endl;
			cout << "Hasta TC : " << hasta.tc << endl;
			if(hasta.cinsiyet == 'k' || hasta.cinsiyet == 'K')
			cout << "Hasta cinsiyeti : Kad�n " << endl;
			else if(hasta.cinsiyet == 'e' || hasta.cinsiyet == 'E')
			cout << "Hasta cinsiyeti : Erkek " << endl;
			
			cout << "\nD�zeltmek istenilen kay�t do�ru mu? (E/H) : ";
			secim = getche();
			if(secim == 'E' || secim == 'e')
			{
				var = true;
				ofstream dosya("YedekHasta.dat",ios::binary | ios::app);
				cout << endl;
				cout << "Hasta ad� giriniz : ";
				cin >> hasta.ad;
				cout << "Hasta soyad� giriniz : ";
				cin >> hasta.soyad;
				cout << "Hasta TC giriniz : ";
				cin >> hasta.tc;
				cout << "Hasta cinsiyet giriniz(E/K) :";
			    hasta.cinsiyet = getche();
			    cout << endl;
			    
			    dosya.write((char*)&hasta, sizeof(hasta));
			    dosya.close();
			}
			else
			{
				Hasta hastaD;
            	ofstream y_dosya("YedekHasta.dat",ios::binary | ios::app);
                
                strcpy(hastaD.ad,hasta.ad);
				strcpy(hastaD.soyad,hasta.soyad);
				strcpy(hastaD.tc,hasta.tc);
				hasta.cinsiyet = hastaD.cinsiyet;
                         
             	y_dosya.write((char*)&hastaD, sizeof(hastaD));
                y_dosya.close();
			}
		}
	}
	oku.close();
		if(var)
		{
			remove("Hasta.dat");
			rename("YedekHasta.dat","Hasta.dat");
            cout<<"\n Kayit D�zeltildi"<<endl;
		}
		else
		{
			remove("YedekHasta.dat");
			cout << "\n Kay�t bulunamad�" << endl;
		}
}

