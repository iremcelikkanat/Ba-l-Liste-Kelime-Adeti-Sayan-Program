#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prolab "kelimeler.txt"
struct linkList
{
    int adet;
    char kelime[100];
    struct linkList *sonrasi;
};
struct linkList *ilk=NULL;
struct linkList *son=NULL;
void yazdir(struct linkList *b)
{ int i=0;

     FILE *dosya2;
        dosya2 = fopen("sonuc.txt", "w+");
    if (dosya2 == 0)
    {
        printf("output file not opened \n");
        return 1;
    }
    else
    {
        printf("output file opened \n");
    }
       while (b->sonrasi != NULL)
    { printf("%d. %s :%d\n",i+1,b->kelime,b->adet);
         i++;

        fprintf(dosya2, "%d-%s %d \n",i,b->kelime, b->adet);

        b = b->sonrasi;
    }
}
struct linkList *sona_ekle(struct linkList *r,int x,char *kelime)
{
    if(ilk==NULL)//linklist bossa
    {
        r=(struct linkList*)malloc(sizeof(struct linkList));
        r->adet=x;
        strcpy(r->kelime,kelime);
        ilk=r;
        son=r;
        son->sonrasi=NULL;
        return r;
    }
    struct linkList *yeni=(struct linkList*)malloc(sizeof(struct linkList));
    yeni->adet=x;
    strcpy(yeni->kelime,kelime);
    son->sonrasi=yeni;
    son=yeni;
    son->sonrasi=NULL;
    return r;
}
struct linkList *basa_ekle(struct linkList *r,int x,char *kelime)
{
    if(ilk==NULL)//linklist bossa
    {
        r=(struct linkList*)malloc(sizeof(struct linkList));
        r->adet=x;
        strcpy(r->kelime,kelime);
        ilk=r;
        son=r;
        son->sonrasi=NULL;
        return r;
    }
    if(ilk->adet<x)//ilk elemanin adetinden büyükse
    {
        struct linkList *temp=(struct linkList*)malloc(sizeof(struct linkList));
        temp->adet=x;
        strcpy(temp->kelime,kelime);
        temp->sonrasi=r;
        ilk=temp;

        return temp;
    }
}

struct linkList *araya_ekle(struct linklist *r,int x,char *kelime)
{
    struct linkList *iter=r;
    while(iter->sonrasi!=NULL && iter->sonrasi->adet>x)
    {
        iter=iter->sonrasi;
    }
    if(son->adet==x){
      r=sona_ekle(r,x,kelime);
      return r;
    }else{
    struct linkList *temp=(struct linkList*)malloc(sizeof(struct linkList));
    temp->sonrasi=iter->sonrasi;
    iter->sonrasi=temp;
    temp->adet=x;
    strcpy(temp->kelime,kelime);
    return r;
    }
}
int sayma(char *okuma)
{
    FILE *dosya;
    dosya=fopen(prolab,"r");
    int sayi=0;
    char bak[100];

    if((dosya=fopen(prolab,"r"))!=NULL)
    {

        while(!feof(dosya))
        {

            fscanf(dosya,"%s ",bak);
            if(strcmp(okuma,bak)==0)
            {
                sayi++;
            }
        }
        return sayi;
    }
    else
    {
        printf("dosya acilamadi.");
        exit(1);
    }
    fclose(dosya);
}

struct linkList *siralama(struct linkList *liste,int x,char *kelime)
{
       if(ilk->adet<x)//ilk elemandan buyuk durumu root degisiyor
        {
            liste=basa_ekle(liste,x,kelime);
            return liste;
        }
        else if(son->adet>x) //sondan küçükse son degisiyor
        {
            liste=sona_ekle(liste,x,kelime);
            return liste;
        }
        else
        {
            liste=araya_ekle(liste,x,kelime);
            return liste;
        }
};

struct linkList *karsilastirma(struct linkList *liste,int x,char *kelime)
{
    struct linkList *iter=liste;
    int sayac=0;
    while(iter->sonrasi!=NULL)
    {
        if(strcmp(iter->kelime,kelime)==0)
        {

            sayac++;

        }
        iter=iter->sonrasi;
    }
    if(sayac==0)
    {
        // siralama
        liste=siralama(liste,x,kelime);

    }else{
        sayac=0;
    }

    return  liste;
};

int main()
{
    FILE *dosya;
    struct linkList *liste=(struct linkList*)malloc(sizeof(struct linkList));
    struct linkList *iter=liste;
    int sayi;
    char okunan[100];

    if((dosya=fopen(prolab,"r"))!=NULL)
    {
        while(!feof(dosya))
        {
            fscanf(dosya,"%s",okunan);
             if(ilk==NULL)
            {
                sayi=sayma(okunan);
                liste=basa_ekle(liste,sayi,okunan);
            }else{
                sayi=sayma(okunan);
                liste=karsilastirma(liste,sayi,okunan);
            }
        }
    }
    else
    {
        printf("dosya acilamadi.");
        exit(1);
    }
    fclose(dosya);
    printf("dosyada yazilanlar: \n");
    yazdir(liste);


    return 0;
}
