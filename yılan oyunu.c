#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void tahtaBaslangici(int N, int M, int tahta[N][M], int yemekSayisi){				//OYUN ALANININ HAZIRLANMASINI SAGLAYAN FONKSIYON
	int i, j;
	int x, y;
	
	for(i = 0; i < N; ++i){
		for(j = 0; j < M; ++j){
			tahta[i][j] = -1;													//BUTUN OYUN ALANININ BOS OLMASI ICIN MATRISIN HER DEGERI -1 YAPILIYOR
		}
	}
	for(i = 0; i < yemekSayisi; ++i){			
		do{
			x = rand() % N;														//OYUN ALANINDA YEMEKLERIN YERLESECEGI YERLER RASTGELE SECILIYOR
			y = rand() % M;
		}while(tahta[x][y] != -1);
		tahta[x][y] = 0;
	}
}
void oyunTahtasi(int N, int M, int tahta[N][M]){								//OYUN ALANINI EKRANA YAZDIRAN FONKSIYON
	int i, j;
	for(i = 0; i < 3 * M + 2; ++i){
		printf("#");
	}
	printf("\n");
	for(i = 0; i < N; ++i){
		for(j = 0; j < M; ++j){
			if(j == 0){
				printf("#");
			}
			if(tahta[i][j] != -1){
				printf("%3d", tahta[i][j]);
			}
			else{
				printf("%3c",'-');
			}	
		}
		printf("#");
		printf("\n");
	}
	for(i = 0; i < 3 * M + 2; ++i){
		printf("#");
	}
	printf("\n\n");
}
void hamle(int N, int M, int tahta[N][M], int yilan[][3], int yilanBoyu){				//YILANIN HAREKETINE GORE OYUN ALANINI DUZENLEYEN FONKSIYON
	int i, j;
	for(i = 0; i < yilanBoyu; ++i){
		tahta[ yilan[i][0] ][ yilan[i][1] ] = yilan[i][2];
	}
}




int main(){
	printf("                                    YILAN OYNUNA HOS GELDINIZ\n");
    printf("  !!!Yon Tuslari!!!\n");
    printf("  ->Yukari: W\n");
    printf("  ->Asagi: S\n");
    printf("  ->Sol: A\n");
    printf("  ->Sag: D\n");
	srand(time(NULL));
	
	int N, M,yemeksayisi;
		
	printf("Oyun Alaninin Satir Degerini Giriniz: ");
	scanf("%d", &N);
	printf("Oyun Alaninin Sutun Degerini Giriniz: ");
	scanf("%d", &M);
	printf("Oyundaki Yemek Sayisini Giriniz: ");
	scanf("%d",&yemekSayisi);
	
	int tahta[N][M];
	int yilanX, yilanY;
	char yon;
	int i, j;
	int yemek;
	
	while(yemekSayisi >= N * M){								//YEMEK SAYISI OYUN ALANININ BUYUKLUGUNDEN BUYUK YA DA ESIT ISE UYARI VERIP TEKRARDAN YEMEK ISTENIYOR
    printf("Lutfen Daha Kucuk Bir Sayi Giriniz:");
	scanf("%d",&yemekSayisi);
	
}
    int yilan[yemekSayisi + 1][3];							//YILANIN HER PARCASININ KOORDINATLARINI VE OYUN ALANINDA YAZACAK DEGERINI TUTMAK ICIN YENÝ DIZI TANIMLIYOR
	int yilanBoyu = 1;
	int x, y;
	int oyunBitti;
	int hamleSayisi;
	int flag;
	
	tahtaBaslangici(N, M, tahta, yemekSayisi);				//OYUN ALANI ICIN HAZIRLANAN FONKSIYON CAGRILIYOR
	x = rand() % N;
	y = rand() % M;                                        //YILANIN BASLANGIC KONUMU RANDOM SECILIYOR
	while(tahta[x][y] != -1){								
        x = rand() % N;
		y = rand() % M;	
	}
	yilanX = x;
	yilanY = y;
	
	tahta[x][y] = 1;
	
	yilan[0][0] = yilanX;									//YILANIN BILGILERINI TUTAN DIZIYE KOORDINATLARI VE EKRANDA YAZACAK DEGERI ATIYOR
	yilan[0][1] = yilanY;
	yilan[0][2] = 1;
	
	yemek = 0;
	oyunBitti = 0;
	hamleSayisi = 1;
	flag = 0;
	while(oyunBitti == 0){											//OYUN BITENE KADAR DONEN DONGU
		oyunTahtasi(N, M, tahta);			
		scanf(" %c",&yon);									//YILANIN HAREKET EDECEGI YON BILGISI KULLANICIDAN ALINIYOR
		printf("Hamle Sayisi: %d\n",hamleSayisi);
		x = yilan[yilanBoyu - 1][0];								//YILANIN BASININ OLDUGU KOORDINATLAR ALINIYOR
		y = yilan[yilanBoyu - 1][1];
		
		if(yon == 'w' || yon == 'W'){
			printf("Yon: Up\n");
			x--;													//YUKARI HAREKET EDECEKSE X DEGERI AZALTILIYOR
			flag = 0;
		}
		else if(yon == 's' || yon == 'S'){				//ASAGI HAREKET EDECEKSE X DEGERI ARTTIRILIYOR
			printf("Yon: Down\n");
			x++;
			flag = 0;
		}
		else if(yon == 'a' || yon == 'A'){				//SOLA HAREKET EDECEKSE Y DEGERI AZALTILIYOR
		    printf("Yon: Left\n");
			y--;
			flag = 0;
		}
		else if(yon == 'd' || yon == 'D'){				//SAGA HAREKET EDECEKSE Y DEGERI ARTTIRILIYOR
		    printf("Yon:Right\n");
			y++;
			flag = 0;
		}
		else{
			printf("Yanlis Yon!\n\n");
			flag = 1;												//YANLIS HARF BASTIYSA UYARI VERIP FLAG DEGISKENI ILE TUTUYORUZ
		}
		
	if(x >= 0 && x < N && y >= 0 && y < M && (tahta[x][y] == 0 || tahta[x][y] == -1) && flag == 0){ 	//YAPILAN HAREKETE GORE GIDECEGI YER OYUN ALANINDA UYGUN ISE CALISACAK IF BLOGU
			hamleSayisi++;							
			if(yemek == 0){														//BIR ONCEKI TUR YEMEK YEMEDIYSE
				tahta[ yilan[0][0] ][ yilan[0][1] ] = -1;						//YILANIN KUYRUGU -1 YAPILIYOR
				for(i = 1; i < yilanBoyu; ++i){
					yilan[i - 1][0] = yilan[i][0];								//YILANIN KOORDINATLARINI TUTAN DIZI HAREKET ETMEYE UYGUN SEKILDE DEGISTIRILIYOR
					yilan[i - 1][1] = yilan[i][1];
				}
				yilan[yilanBoyu - 1][0] = x;									//YILANIN BASININ KOORDINATLARI HAREKET ETTIGI YER ILE DEGISTIRILIYOR
				yilan[yilanBoyu - 1][1] = y;
				yilan[yilanBoyu - 1][2] = 1;
			}
			else{																//BIR ONCEKI TUR YEMEK YEDIYSE
				for(i = 0; i < yilanBoyu; ++i){					
					yilan[i][2]++;												//YILANIN OYUN ALANINDA YAZACAK DEGERI 1 ARTTIRILIYOR
				}
				yilan[yilanBoyu][0] = x;										//YILANIN BASININ KOORDINATLARI HAREKET ETTIGI YER ILE DEGISTIRILIYOR
				yilan[yilanBoyu][1] = y;
				yilan[yilanBoyu][2] = 1;
				yilanBoyu++;													//YILAN UZUNLUGU ARTTIRILIYOR
			}
			if(tahta[x][y] == 0){												//EGER YENI GIDECEGI YERDE YEMEK VAR ISE 
				yemek = 1;														//DEGISKEN ILE TUTULUYOR
				yemekSayisi--;													//YEMEK SAYISI AZALIYOR
				if(yemekSayisi == 0){
					printf("TEBRIKLER KAZANDINIZ!\nHamle Sayisi: %d\nYilan Boyu: %d",hamleSayisi, yilanBoyu);		//YEMEK SAYISI 0 OLURSA KAZANDI BILGISI YAZDIRILIYOR
					oyunBitti = 1;
				}
			}
			else{																//EGER GIDECEGI YERDE YEMEK YOKSA YEMEK DEGISKENI 0 OLUYOR
				yemek = 0;
			}
			hamle(N, M, tahta, yilan, yilanBoyu);
		}
		else if(flag == 0){														//SECTIGI YON ICIN DOGRU TUSA BASTIYSA YANI FLAG 0 ISE VE GIDECEGI ALAN UYGUN DEGILSE
			for(i = 0; i < yilanBoyu; ++i){
				tahta[ yilan[i][0] ][ yilan[i][1] ] = -1;						//YILAN OYUNDAN SILINIYOR
			}
			oyunTahtasi(N, M, tahta);
			printf("OYUN BITTI!\nKalan Yemek Miktari: %d\nHamle Sayisi: %d\nYilan Boyu: %d", yemekSayisi, hamleSayisi, yilanBoyu);			//KAYBETTIGI BILGISI EKRANA YAZDIRILIYOR
			oyunBitti = 1;
		}
	}
	
	return 0;
}

