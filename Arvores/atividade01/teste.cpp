#define fmt "%d"
typedef int Item;
typedef struct arv {
 struct arv *esq;
 Item item;
 struct arv *dir;
}*Arv;
