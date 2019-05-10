int main()
{
	int satirSayisi, sutunSayisi, i, j, silSatir, silSutun;
	printf("Satýr Sayýsý Giriniz: ");
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
	// Index 0'dan baþladýðý için kullanýcýnýn yazdýðý deðerleri 1 azaltýyoruz.
	// Kullanýcý 2. satýr 1. Sütun'u silmek isterse matris[1][0]'ý silmiþ oluyor.
	silSatir = silSatir - 1;
	silSutun = silSutun - 1;

	// Tüm matris elemanlarýný gezecek olan döngü
	for(i = 0; i<satirSayisi; i++){
		for(j = 0; j<sutunSayisi; j++){
		// Eðer silinecek olan nesne ve sonrasýndaki nesnelerden biriyse
		// artýk memory üzerinde bir sonraki alandaki deðeri oraya taþýyabiliriz.
		// Örneðin; 1,2,3,4,5,6,7,8,9,10 var ise ve kullanýcý 5'i silmek istiyorsa
		// 5 ve sonrasýný seçmiþ oluyoruz. (Tek boyutlu dizide)
		// Çok boyutlu dizi olduðu için satýr numarasý ile silinecek olan nesnenin satýr              
                           //numarasýný kontrol ettim
		// Eðer silinecek olan satýrdan daha büyük ise zaten bizim nesneden sonraki bir 
                            //nesne olmuþ oluyor bu yüzden
		// bir sonraki deðeri ona aktarabiliriz.
if(silSatir == i && silSutun <= j){
// Memory üzerinde bir sonraki deðere eriþmemiz için 'MATRIS+SATIR' dizisinin 
//memory'deki lokasyonuna sütun //sayýsýný ve 1 fazlasýný eklemeliyiz.
		// Bu sayede bir sonraki deðere ulaþabiliriz.
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

