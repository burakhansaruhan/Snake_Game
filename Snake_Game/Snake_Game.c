#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int main() {
    int N,M,i,j,yemek,cikis,y,x,uzunluk,hamle,yemekyedi;
    int yilan[50][3];
    int tahta[50][50];
    char hareket;
    printf("-----------------YILAN OYUNU-----------------\n\n");
    system("COLOR 2");
    printf("Satir sayisi giriniz:");
    scanf("%d", &N);

    printf("Sutun sayisi giriniz:");
    scanf("%d", &M);

    printf("Yemek sayisini giriniz:");
    scanf("%d", &yemek);

    while(yemek>=N*M || yemek<=0){
    	system("COLOR 4");
        printf("Hatali yemek sayisi girdiniz.Lutfen tekrar yemek sayisini giriniz:");
        scanf("%d", &yemek);
    }

    printf("\n");
	system("COLOR 2");
    // Tahtayi olustur
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tahta[i][j] = -1;
        }
    }

    // Rastgele bir yere yilan ve yemleri koy
    srand(time(NULL));
    y = rand() % N;
    x = rand() % M;
    tahta[y][x] = 1;
    uzunluk = 1;

    for (i = 0; i < yemek; i++) {
    int y = rand() % N;
    int x = rand() % M;
    if (tahta[y][x] == -1) {
        tahta[y][x] = 0;
    } 
    else
        i--;
}

	for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (tahta[i][j] == -1) {
                printf("_|");
            } else {
                printf("%d|", tahta[i][j]);
            }
        }
        printf("\n");
}
    yilan[0][0] = y;
    yilan[0][1] = x;
    hamle=1;

    // Oyun baslasin. 
    cikis = 0;
    hamle=1;
    while (cikis == 0 && yemek!=0) {
    printf("Gitmek istediginiz yonu giriniz(U,L,D,R):");
    scanf(" %c",&hareket);
	printf("\n");
	
    while(hareket != 'U' && hareket != 'u' && hareket != 'L' && hareket != 'l' && hareket != 'D' && hareket != 'd' && hareket != 'R' && hareket != 'r'){
    system("COLOR 4");
    printf("Hatali giris yaptiniz.Lutfen (U,L,D,R) tuslarindan birini giriniz:");
    scanf(" %c",&hareket);
    }
	system("COLOR 2");
     if (hareket == 'U'|| hareket == 'u') 
    y--;
  else if (hareket == 'L' || hareket == 'l') 
    x--;
  else if (hareket == 'D' || hareket == 'd') 
    y++;
  else if (hareket == 'R' || hareket == 'r') 
    x++;

    //YILAN TAHTADAN CIKARSA
	if (x < 0 || x >= M || y < 0 || y >= N) 
        cikis = 1;

	//YILAN KENDI ÜSTÜNE GELIRSE
    for(i=0;i<uzunluk;i++){
            if(y == yilan[i][0] && x == yilan[i][1])
            cikis = 1;
        }
        
	if (cikis==1){								//YILAN TAHTANIN SINIRLARINI ASARSA VEYA KENDI USTUNE GELIRSE BUTUN TAHTA YOK OLUYOR VE SADECE YEMLER KALIYOR.
	for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (tahta[i][j] == 0) {
                printf("0|");
            } else {
                printf("_|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

	if (cikis==0){
    
 	tahta[yilan[uzunluk-1][0]][yilan[uzunluk-1][1]]=-1;			//ESKI SON ELEMANIN KOORDINATLARI SILINIYOR

 	yemekyedi=0;
	if (tahta[y][x] == 0) {
    uzunluk++;              	// YEM YERSE BÜYÜT
    yemek--;
    yemekyedi=1;
}
	
	for (i = uzunluk - 1; i > 0; i--) {				// YILANIN ELEMANLARINI 1 GERI KAYDIR
  yilan[i][0] = yilan[i - 1][0];
  yilan[i][1] = yilan[i - 1][1];
  yilan[i][2] = i+1;
}

	yilan[0][0] = y;								// YILANIN KAFASINI MATRISIN ILK INDISLERINE EKLIYOR
	yilan[0][1] = x;
	yilan[0][2] = 1;
	
    // TAHTAYA UYGULA
   if (yemekyedi==0){									//YEMEK YERSE SON ELEMAN BIR DIGER TUR YAZDIRILIYOR
   
   printf("YAPILAN HAMLE SAYISI:%d\n",hamle);  
    									
    for (i = 0; i < uzunluk; i++) {
        tahta[yilan[i][0]][yilan[i][1]] = yilan[i][2];
    }
	for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (tahta[i][j] == -1) {
                printf("_|");
            } else {
                printf("%d|", tahta[i][j]);
            }
        }
        printf("\n");
    }
	}
    else { 													//YEMEK YEMEDIYSE O TUR ILERLEME TAHTADA GOSTERILIYOR
	for (i = 0; i < uzunluk-1; i++) {
        tahta[yilan[i][0]][yilan[i][1]] = yilan[i][2];
    }
  
	printf("YAPILAN HAMLE SAYISI:%d\n",hamle);
	
	for (i = 0; i < N; i++) {								
        for (j = 0; j < M; j++) {
            if (tahta[i][j] == -1) {
                printf("_|");
            } else {
                printf("%d|", tahta[i][j]);
            }
        }
        printf("\n");
    }
	}
}
	hamle++;
}           												//WHILE DONGUSU BITISI

	if(yemek==0){
	printf("\n");
    printf("OYUN TAMAMLANDI! TEBRIKLER!\n");
    printf("YAPILAN HAMLE SAYISI:%d YILANIN UZUNLUGU:%d",hamle-1,uzunluk);
}
	else {
		system("COLOR 4");
    printf("\nKAYBETTINIZ!\n");
    printf("YAPILAN HAMLE SAYISI:%d YILANIN SON UZUNLUGU:%d KALAN YEMEK SAYISI:%d",hamle-1,uzunluk,yemek); //istenilirse burada yilan uzunlugu yilan yok oldugu için 0 yapilabilir.
}
    return 0;
}
