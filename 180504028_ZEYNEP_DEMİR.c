#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
FILE *dosya,*yedek; 
struct hasta{
	int hastano;
	char hasta_adi[50];
	int hasta_yasi;
	int odano;
	char oda_kayit_tarihi[10];
	int ilac_no;
	char ilac_adi[50];
	int gunluk_ilac_adet;
};
struct hasta bilgi;
void ekle(); 
void liste();
void sil();
void ara();
void guncelle(void);
int main(){

	while(1){
	int secim;
	system("color C");
	printf("**************************************** \n");
	printf("Lutfen secim yapiniz \n");
	printf("1--->EKLE  \n");
	printf("2--->LISTELE   \n");
	printf("3--->GUNCELLE  \n");
	printf("4--->ARA\n");
	printf("5--->SIL \n");
	printf("0--->CIK  \n");
	printf("**************************************** \nSeciminiz=");
	scanf("%d",&secim);
	
   				 if(secim==1)
					{
						ekle();
					}
			else if(secim==2)
				 	{
						liste();
					}
				else if(secim==3)
					{
					 guncelle();
					}
				else if(secim==4)
					{
						ara();
					}
				else if(secim==5)
					{
						sil();
					}
					else if(secim==0)
					{
						exit(1);
					}
	}
 return 0;
}

void ekle(){
	system("color E");
 int i=0;
 char secim;
 dosya=fopen("hastane.txt","a+"); 
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 do{ 
  i++;
  puts("************************HASTA BILGILERINI GIRINIZ****************** ");
  printf("Hastanin numarasini giriniz:");
	scanf("%d",&bilgi.hastano);

	printf("Hastanin adini giriniz(! bosluk birakmayiniz):");
	scanf("%s",&bilgi.hasta_adi);

	printf("Hastanin yasini giriniz:");
	scanf("%d",&bilgi.hasta_yasi);

	printf("Hastanin oda numarasini giriniz:");
	scanf("%d",&bilgi.odano);

	printf("Hastanin oda kayit tarihini giriniz (gg.aa.yy):");
	scanf("%s",&bilgi.oda_kayit_tarihi);

	printf("Hastanin ilac numarasini giriniz:");
	scanf("%d",&bilgi.ilac_no);

	printf("Hastanin ilac adini giriniz:");
	scanf("%s",&bilgi.ilac_adi);
	printf("Hastanin gunluk ilac adet sayisini giriniz:");
	scanf("%d",&bilgi.gunluk_ilac_adet);
		fprintf(dosya,"hasta no:%d",bilgi.hastano);
			fprintf(dosya," \n Hasta Adi:%s",bilgi.hasta_adi);
				fprintf(dosya," \n Hasta yasi:%d",bilgi.hasta_yasi);
					fprintf(dosya," \n Oda no:%d",bilgi.odano);
						fprintf(dosya," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fprintf(dosya," \n ilac numarasi:%d",bilgi.ilac_no);
								fprintf(dosya," \n ilac adi:%s",bilgi.ilac_adi);
									fprintf(dosya," \n gunluk ilac adet sayisi:%d",bilgi.gunluk_ilac_adet);
										fprintf(dosya," \n*********************************************** \n \n");
												printf("\n***************Veriler dosyaya kaydedildi**********************\n");
													printf("\n \n");
  puts("Yeni bir kayit icin E tusuna basiniz,Cikmak için bir tusa basiniz.......\n");
 }while(getch()=='E');
 fclose(dosya);
 puts("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
}

void liste(){
	system("color C");
	 puts("************************LISTELEME ISLEMI****************** ");
 dosya = fopen("hastane.txt","r"); 
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 while(!feof(dosya)){
  	fscanf(dosya,"hasta no:%d",&bilgi.hastano);
			fscanf(dosya," \n Hasta Adi:%s",bilgi.hasta_adi);
				fscanf(dosya," \n Hasta yasi:%d",&bilgi.hasta_yasi);
					fscanf(dosya," \n Oda no:%d",&bilgi.odano);
						fscanf(dosya," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fscanf(dosya," \n ilac numarasi:%d",&bilgi.ilac_no);
								fscanf(dosya," \n ilac adi:%s",bilgi.ilac_adi);
									fscanf(dosya," \n gunluk ilac adet sayisi:%d",&bilgi.gunluk_ilac_adet);
										fscanf(dosya," \n*********************************************** \n \n");
   if(bilgi.hastano!= 0){ 
   printf("hasta no:%d",bilgi.hastano);
			printf(" \n Hasta Adi:%s",bilgi.hasta_adi);
				printf(" \n Hasta yasi:%d",bilgi.hasta_yasi);
					printf(" \n Oda no:%d",bilgi.odano);
						printf(" \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							printf(" \n ilac numarasi:%d",bilgi.ilac_no);
								printf(" \n ilac adi:%s",bilgi.ilac_adi);
									printf(" \n gunluk ilac adet sayisi:%d",bilgi.gunluk_ilac_adet);
										printf(" \n*********************************************** \n \n");
   }
 }
 fclose(dosya);
 puts("\nBilgiler listelendi devam etmek icin bir tusa basin ...");
 getch();
}
void sil(){
	system("color E");
	 puts("************************SILME ISLEMINI SECTINIZ****************** ");
 int numara,durum=0;
 printf("\nSilinecek hasta numarasini giriniz : ");
 scanf("%d",&numara);
 printf("*******************************************\n");
 dosya = fopen("hastane.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  	fscanf(dosya,"hasta no:%d",&bilgi.hastano);
			fscanf(dosya," \n Hasta Adi:%s",bilgi.hasta_adi);
				fscanf(dosya," \n Hasta yasi:%d",&bilgi.hasta_yasi);
					fscanf(dosya," \n Oda no:%d",&bilgi.odano);
						fscanf(dosya," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fscanf(dosya," \n ilac numarasi:%d",&bilgi.ilac_no);
								fscanf(dosya," \n ilac adi:%s",bilgi.ilac_adi);
									fscanf(dosya," \n gunluk ilac adet sayisi:%d",&bilgi.gunluk_ilac_adet);
										fscanf(dosya," \n*********************************************** \n \n"); 
    if(numara != bilgi.hastano){ 
  		  fprintf(yedek,"hasta no:%d",&bilgi.hastano);
			fprintf(yedek," \n Hasta Adi:%s",bilgi.hasta_adi);
				fprintf(yedek," \n Hasta yasi:%d",&bilgi.hasta_yasi);
					fprintf(yedek," \n Oda no:%d",&bilgi.odano);
						fprintf(yedek," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fprintf(yedek," \n ilac numarasi:%d",&bilgi.ilac_no);
								fprintf(yedek," \n ilac adi:%s",bilgi.ilac_adi);
									fprintf(yedek," \n gunluk ilac adet sayisi:%d",&bilgi.gunluk_ilac_adet);
										fprintf(yedek," \n*********************************************** \n \n");
    }
    else durum=1; 
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){
  remove("hastane.txt");
  rename("yedek.txt","hastane.txt"); 
  puts("Silme islemi tamamlandi devam etmek icin bir tusa basin \n");
 } 
 else{ 
  remove("yedek.txt");
  printf(" %d numarasinda bir HASTA bulunamadi devam etmek icin bir tusa basin ... \n",numara);
 }
}
void ara(){
	system("color C");
	 puts("************************ARAMA ISLEMINI SECTINIZ****************** ");
 int durum=0,numara;
 printf("\n Hasta numarasini giriniz : ");
 scanf("%d",&numara);
  printf("*******************************************\n");
 dosya=fopen("hastane.txt","r");
 if( dosya==NULL ){
  puts("Dosya acilamadi");
 }
  while(!feof(dosya)){
   fscanf(dosya,"hasta no:%d",&bilgi.hastano);
			fscanf(dosya," \n Hasta Adi:%s",bilgi.hasta_adi);
				fscanf(dosya," \n Hasta yasi:%d",&bilgi.hasta_yasi);
					fscanf(dosya," \n Oda no:%d",&bilgi.odano);
						fscanf(dosya," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fscanf(dosya," \n ilac numarasi:%d",&bilgi.ilac_no);
								fscanf(dosya," \n ilac adi:%s",bilgi.ilac_adi);
									fscanf(dosya," \n gunluk ilac adet sayisi:%d",&bilgi.gunluk_ilac_adet);
										fscanf(dosya," \n*********************************************** \n \n");
   if(bilgi.hastano==numara){
    printf("hasta no:%d",bilgi.hastano);
			printf(" \n Hasta Adi:%s",bilgi.hasta_adi);
				printf(" \n Hasta yasi:%d",bilgi.hasta_yasi);
					printf(" \n Oda no:%d",bilgi.odano);
						printf(" \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							printf(" \n ilac numarasi:%d",bilgi.ilac_no);
								printf(" \n ilac adi:%s",bilgi.ilac_adi);
									printf(" \n gunluk ilac adet sayisi:%d",bilgi.gunluk_ilac_adet);
										printf(" \n*********************************************** \n \n");
										
    durum=1;
   }
  }
  fclose(dosya);
  if(durum == 0){ 
   puts("Kayit bulunamadi devam etmek icin bir tusa basiniz...");
  }
  
}
void guncelle(){
	system("color E");
	 puts("************************GUNCELLEME ISLEMINI SECTINIZ****************** ");
 int numara,durum=0;
 printf("\nBilgilerini degistireceginiz hastanin numarasini giriniz: ");
 scanf("%d",&numara);
  printf("*******************************************\n");
 dosya = fopen("hastane.txt","r");
 yedek = fopen("yedek.txt","w");
 while(!feof(dosya)){
   fscanf(dosya,"hasta no:%d",&bilgi.hastano);
			fscanf(dosya," \n Hasta Adi:%s",bilgi.hasta_adi);
				fscanf(dosya," \n Hasta yasi:%d",&bilgi.hasta_yasi);
					fscanf(dosya," \n Oda no:%d",&bilgi.odano);
						fscanf(dosya," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fscanf(dosya," \n ilac numarasi:%d",&bilgi.ilac_no);
								fscanf(dosya," \n ilac adi:%s",bilgi.ilac_adi);
									fscanf(dosya," \n gunluk ilac adet sayisi:%d",&bilgi.gunluk_ilac_adet);
										fscanf(dosya," \n*********************************************** \n \n");
			if(numara != bilgi.hastano){ 
  		  fprintf(yedek,"hasta no:%d",&bilgi.hastano);
			fprintf(yedek," \n Hasta Adi:%s",bilgi.hasta_adi);
				fprintf(yedek," \n Hasta yasi:%d",&bilgi.hasta_yasi);
					fprintf(yedek," \n Oda no:%d",&bilgi.odano);
						fprintf(yedek," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fprintf(yedek," \n ilac numarasi:%d",&bilgi.ilac_no);
								fprintf(yedek," \n ilac adi:%s",bilgi.ilac_adi);
									fprintf(yedek," \n gunluk ilac adet sayisi:%d",&bilgi.gunluk_ilac_adet);
										fprintf(yedek," \n*********************************************** \n \n");}
    if(numara == bilgi.hastano){ 
  		  printf("Hastanin yeni numarasini giriniz:");
	scanf("%d",&bilgi.hastano);

	printf("Hastanin yeni adini giriniz(! bosluk birakmayiniz):");
	scanf("%s",&bilgi.hasta_adi);

	printf("Hastanin yeni yasini giriniz:");
	scanf("%d",&bilgi.hasta_yasi);

	printf("Hastanin yeni oda numarasini giriniz:");
	scanf("%d",&bilgi.odano);

	printf("Hastanin yeni oda kayit tarihini giriniz (gg.aa.yy):");
	scanf("%s",&bilgi.oda_kayit_tarihi);

	printf("Hastanin yeni ilac numarasini giriniz:");
	scanf("%d",&bilgi.ilac_no);

	printf("Hastanin yeni ilac adini giriniz:");
	scanf("%s",&bilgi.ilac_adi);
	
	printf("Hastanin yeni gunluk ilac adet sayisini giriniz:");
	scanf("%d",&bilgi.gunluk_ilac_adet);
	
		 fprintf(yedek,"hasta no:%d",bilgi.hastano);
			fprintf(yedek," \n Hasta Adi:%s",bilgi.hasta_adi);
				fprintf(yedek," \n Hasta yasi:%d",bilgi.hasta_yasi);
					fprintf(yedek," \n Oda no:%d",bilgi.odano);
						fprintf(yedek," \n Oda kayit Tarihi:%s",bilgi.oda_kayit_tarihi);
							fprintf(yedek," \n ilac numarasi:%d",bilgi.ilac_no);
								fprintf(yedek," \n ilac adi:%s",bilgi.ilac_adi);
									fprintf(yedek," \n gunluk ilac adet sayisi:%d",bilgi.gunluk_ilac_adet);
										fprintf(yedek," \n*********************************************** \n \n");
													durum=1;	
  }
   fclose(dosya);
 fclose(yedek);
  if(durum == 1){
  remove("hastane.txt");
  rename("yedek.txt","hastane.txt"); 
  puts("Guncelleme islemi tamamlandi devam etmek icin bir tusa basin \n");
  liste();
  main();
 } 
 else{ 
  remove("yedek.txt");
  printf(" %d numarasinda bir HASTA bulunamadi devam etmek icin bir tusa basin ... \n",numara);
  main();
 }
}

}
