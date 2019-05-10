int main()
{
	int satirSayisi, sutunSayisi, i, j, silSatir, silSutun;
	printf("Sat�r Say�s� Giriniz: ");
	scanf("%d", &satirSayisi);
	printf("Sutun Sayisi Giriniz: ");
	scanf("%d", &sutunSayisi);
	int matris[satirSayisi][sutunSayisi];
	for(i = 0; i < satirSayisi; i++){
		for(j = 0; j < sutunSayisi; j++){
			printf("%d. Satir %d. Sutun = ", i+1, j+1);
			scanf("%d", &matris[i][j]);
		}
	}
	printf("\nOlusturulan Dizi\n");
	for(i = 0; i < satirSayisi; i++){
		for(j = 0; j < sutunSayisi; j++){
			printf("%d ", matris[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Silinecek Satir Sutun: ");
	scanf("%d %d", &silSatir, &silSutun);
	// Index 0'dan ba�lad��� i�in kullan�c�n�n yazd��� de�erleri 1 azalt�yoruz.
	// Kullan�c� 2. sat�r 1. S�tun'u silmek isterse matris[1][0]'� silmi� oluyor.
	silSatir = silSatir - 1;
	silSutun = silSutun - 1;

	// T�m matris elemanlar�n� gezecek olan d�ng�
	for(i = 0; i<satirSayisi; i++){
		for(j = 0; j<sutunSayisi; j++){
		// E�er silinecek olan nesne ve sonras�ndaki nesnelerden biriyse
		// art�k memory �zerinde bir sonraki alandaki de�eri oraya ta��yabiliriz.
		// �rne�in; 1,2,3,4,5,6,7,8,9,10 var ise ve kullan�c� 5'i silmek istiyorsa
		// 5 ve sonras�n� se�mi� oluyoruz. (Tek boyutlu dizide)
		// �ok boyutlu dizi oldu�u i�in sat�r numaras� ile silinecek olan nesnenin sat�r              
                           //numaras�n� kontrol ettim
		// E�er silinecek olan sat�rdan daha b�y�k ise zaten bizim nesneden sonraki bir 
                            //nesne olmu� oluyor bu y�zden
		// bir sonraki de�eri ona aktarabiliriz.
if(silSatir == i && silSutun <= j){
// Memory �zerinde bir sonraki de�ere eri�memiz i�in 'MATRIS+SATIR' dizisinin 
//memory'deki lokasyonuna s�tun //say�s�n� ve 1 fazlas�n� eklemeliyiz.
		// Bu sayede bir sonraki de�ere ula�abiliriz.
				matris[i][j] = *(*(matris+i)+j+1);
			}
			if(silSatir < i){
				matris[i][j] = *(*(matris+i)+j+1);
			}
		}
	}
	printf("\nYeni Dizi\n");
	for(i = 0; i < satirSayisi; i++){
		for(j = 0; j < sutunSayisi; j++){
			printf("%d ", matris[i][j]);
		}
		printf("\n");
	}
	getch();
}

