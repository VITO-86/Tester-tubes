#ifndef status_H
#define status_H

#include "boolean.h"
#include "listskill.h"
#include "player.h"
#include "map.h"

#define IdxMax 4
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;

typedef struct
{
    ArrayP P;
    MAP contentsMapPlayer [IdxMax]; // menyimpan map dari setiap pemain yang bermain
    Portal Por; // Portal yang terdapat pada peta
    int Neff; // banyaknya elemen aktif 
    int ronde; // ronde dalam permainan
} status;

/* SELEKTOR MAP */
#define Lengthst(s) (s).Neff

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create status kosong */
void MakeEmpty (status *s);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Nbstatus (status s);
/* Mengirimkan banyaknya elemen efektif status*/
/* Mengirimkan nol jika kosong */
/* *** Daya tampung container *** */
int MaxElmt (status s);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh status */

/* *** Selektor INDEKS *** */
IdxType GetLastIdx (status s);
IdxType GetPlayerIdx (status s, Player P);
/* Prekondisi : status s tidak kosong */
/* Mengirimkan idx player P dalam array */
/* *** Menghasilkan sebuah elemen *** */

/* *** Menghasilkan sebuah elemen *** */
Player GetPlayer (status s, IdxType i); 
/* Prekondisi : status tidak kosong */
/* Mengirimkan elemen tabel yang ke-i */
MAP getMapPlayer (status s, IdxType i);
/* Prekondisi : status tidak kosong */
/* Mengirimkan elemen tabel yang ke-i */


/* *** Selektor SET : Mengubah nilai status dan elemen status *** */
/* Untuk type private/limited private pada bahasa tertentu */
void Setstatus (status s, status *s_copy);
/* I.S. s terdefinisi, sembarang */
/* F.S. s_copy berisi salinan s*/
void SetPlayer (status *s, IdxType i, Player P);
/* I.S. s terdefinisi, sembarang */
/* F.S. Elemen s yang ke-i bernilai P */
/* Mengeset nilai elemen status yang ke-i sehingga bernilai P */
void SetMap (status *s, IdxType i, MAP M);
/* I.S. s terdefinisi, sembarang */
/* F.S. Elemen s yang ke-i bernilai M */
/* Mengeset nilai elemen status yang ke-i sehingga bernilai M */
void SetPortal (status *s, IdxType i, Portal Por);
/* I.S. s terdefinisi, sembarang */
/* F.S. Elemen s yang ke-i bernilai Por */
/* Mengeset nilai elemen status yang ke-i sehingga bernilai Por */

void SetNeff (status *s, IdxType i);
/* I.S. s terdefinisi, sembarang */
/* F.S. Nilai indeks efektif s bernilai i */
/* Mengeset nilai indeks elemen efektif sehingga bernilai i */

void SetRonde (status *s, IdxType i);
/* I.S. s terdefinisi, sembarang */
/* F.S. Nilai berupa ronde i yang sedang berlangsung */
/* Mengeset nilai ronde sehingga bernilai i */

void startRonde(status *s);
/* I.S. s terdefinisi, sembarang */
/* F.S. permainan dimulai dari ronde 1*/

void NextRonde (status *s);
/* I.S. s terdefinisi, sembarang */
/* F.S. Permainan berlanjut ke ronde berikutnya */


void UndoRonde (status *s);
/* I.S. s terdefinisi, sembarang */
/* F.S. ronde dikembalikan ke ronde sebelumnya*/
/*Jika kondisi awal berada di ronde 1 maka ronde akan bernilai IdxUndef*/


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTab (status s);
/* Mengirimkan true jika status s kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (status s);
/* Mengirimkan true jika status s penuh, mengirimkan false jika tidak */

/* ********** TEST Teleporter & Penghalang ********** */
/* Test Teleporter*/
boolean isTeleporter(status s, int rollDadu);
/* Mengirimkan true jika ada teleporter, dan false jika tidak*/
/*Test Penghalang*/
boolean isPenghalang(status s, int rollDadu, IdxType i);
/* Mengirimkan true jika ada penghalang, dan false jika tidak*/

/* Posisi pemain */
/*Mengembalikan posisi pemain ditandai dengan tanda (*) pada MAP*/
int posisi(status s, IdxType i); 

/* Implementasi command map & inspect*/
/*Command MAP */
void map(status s);
/*Melakukan pencetakan nama pemain, peta, dan posisi pemain*/
/*Command inspect*/
void inspect(Portal P, MAP M);
/* Melakukan pencetakan apakah petak yang di input memiliki telporter atau penghalang*/



#endif
