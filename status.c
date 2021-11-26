#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create status kosong */
void MakeEmpty (status *s){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    (*s).Neff = 0;
}

int Nbstatus (status s){
/* Mengirimkan banyaknya elemen efektif status */
/* Mengirimkan nol jika kosong */
/* *** Daya tampung container *** */
    return (s).Neff;
}

int MaxElmt (status s){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh status */
/* *** Selektor INDEKS *** */
    return IdxMax;
}

IdxType GetLastIdx (status s) {
/* Prekondisi : status s tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return (s).Neff;
}

IdxType GetPlayerIdx (status s, Player P){
/* Prekondisi : status s tidak kosong */
/* Mengirimkan idx player P dalam array */
/* *** Menghasilkan sebuah elemen *** */

    // Kamus
    int i = 0;

    // Algoritma
    while ((P.playerName) != (s.P.contents[i].playerName) && i < s.Neff)
    {
        i++;
    }
    // index status s ditemukan
    return i;
}

/* *** Menghasilkan sebuah elemen *** */
Player GetPlayer (status s, IdxType i) {
/* Prekondisi : status tidak kosong */
/* Mengirimkan elemen tabel yang ke-i */
    return (s).P.contents[i];
}

MAP getMapPlayer (status s, IdxType i){
/* Prekondisi : status tidak kosong */
/* Mengirimkan elemen tabel yang ke-i */
    return (s).contentsMapPlayer[i];
}

/* *** Selektor SET : Mengubah nilai status dan elemen status *** */
/* Untuk type private/limited private pada bahasa tertentu */
void Setstatus (status s, status *s_copy){
/* I.S. s terdefinisi, sembarang */
/* F.S. s_copy berisi salinan s*/
    
    for(int i = 1; i <= IdxMax; i++){
        (*s_copy).P.contents[i] = s.P.contents[i];
    }
}

void SetPlayer (status *s, IdxType i, Player P){
/* I.S. s terdefinisi, sembarang */
/* F.S. Elemen s yang ke-i bernilai P */
/* Mengeset nilai elemen status yang ke-i sehingga bernilai P */
    (*s).P.contents[i] = P;
}

void SetMap (status *s, IdxType i, MAP M){
/* I.S. s terdefinisi, sembarang */
/* F.S. Elemen s yang ke-i bernilai M */
/* Mengeset nilai elemen status yang ke-i sehingga bernilai M */
    (*s).contentsMapPlayer[i] = M;
}

void SetPortal (status *s, IdxType i, Portal Por){
/* I.S. s terdefinisi, sembarang */
/* F.S. Elemen s yang ke-i bernilai Por */
/* Mengeset nilai elemen status yang ke-i sehingga bernilai Por */
    (*s).Por = Por;
}

void SetNeff (status *s, IdxType i){
/* I.S. s terdefinisi, sembarang */
/* F.S. Nilai indeks efektif s bernilai i */
/* Mengeset nilai indeks elemen efektif sehingga bernilai i */
    (*s).Neff = i;
}

void SetRonde (status *s, IdxType i){
/* I.S. s terdefinisi, sembarang */
/* F.S. Nilai berupa ronde i yang sedang berlangsung */
/* Mengeset nilai ronde sehingga bernilai i */
    (*s).ronde = i;
}

void startRonde(status *s){
/* I.S. s terdefinisi, sembarang */
/* F.S. permainan dimulai dari ronde 1*/
    (*s).ronde = 1;
}

void NextRonde (status *s){
/* I.S. s terdefinisi, sembarang */
/* F.S. Permainan berlanjut ke ronde berikutnya */
    (*s).ronde += 1;

}

void UndoRonde (status *s){
/* I.S. s terdefinisi, sembarang */
/* F.S. ronde dikembalikan ke ronde sebelumnya*/
/*Jika kondisi awal berada di ronde 1 maka ronde akan bernilai IdxUndef*/
    if ((*s).ronde == 1){ //jika berada di ronde 1 maka undo akan menjadi IdxUndef
        (*s).ronde = IdxUndef;
    }
    else{
        (*s).ronde -= 1;
    }

}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */

/* ********** TEST Teleporter & Penghalang ********** */
/* Test Teleporter*/
boolean isTeleporter(status s, int rollDadu){ 
/* Mengirimkan true jika ada teleporter, dan false jika tidak*/
    return (s.Por.contents[rollDadu] != -1);
}

/*Test Penghalang*/
boolean isPenghalang(status s, int rollDadu, IdxType i){
/* Mengirimkan true jika ada penghalang, dan false jika tidak*/
    return (s.contentsMapPlayer[i].contents[rollDadu] == '#');
}

/* Posisi pemain */
/*Mengembalikan posisi pemain ditandai dengan tanda (*) pada MAP*/
int posisi(status s, IdxType i) { 
    char nilai_posisi = '*';
    for (int j = 1; j<= Lengthst(s); j++){
        if(s.contentsMapPlayer[i].contents[j] == nilai_posisi){
            return j;
        }
    }
}

/* Implementasi command map & inspect*/
/*Command MAP */
void map(status s){
/*Melakukan pencetakan nama pemain, peta, dan posisi pemain*/
    for (int i = 1; i <= Lengthst(s); i++){
        printf("%s : %s %d", s.P.contents[i].playerName, s.contentsMapPlayer[i].contents, posisi(s,i));
    }
}

/*Command inspect*/
void inspect(Portal P, MAP M){
/* Melakukan pencetakan apakah petak yang di input memiliki telporter atau penghalang*/
    int petak;
    scanf("Masukkan petak: %d\n", &petak);

    // petak memiliki teleporter
    if (P.contents[petak] != -1){ // -1 menunjukkan petak tidak memiliki teleporter
        printf("Petak %d memiliki teleporter menuju %d.\n", petak, P.contents[petak]);
    }

    else if (M.contents[petak] == '#'){
        printf("Petak %d merupakan petak terlarang.\n", petak);
    }
    
    else if((M.contents[petak] == '.') && (P.contents[petak] == -1)){
        printf("Petak %d merupakan petak kosong.\n", petak);
    }
}



