
/*Opgavebeskrivelse
Træk de rigtige kodestumper ind, så funktionen find_last returnerer en pointer til det sidste element, hvor id matcher parameteren k.
Hvis intet match findes, eller arrayet er tomt, skal funktionen returnere NULL.*/

/*Kodestumper du må bruge*/
NULL
Item
Item*
arr
size
k
r
&
return
->id



typedef struct {
    int id;
    char name[10];
} Item;

Item* find_last( Item* arr, int size, int k ){
    Item* r = NULL;

    for(int i = 0; i < size; i++){
        if(arr[i].id == k){ // . fordi arr[i] er en struct. Selvom arr er en pointer, så er arr[i] IKKE en pointer.
            r = &arr[i];   // & fordi vi vil gemme adressen
        }
    }
    return r;
}

int main(void){
    Item items[] = {
        {1, "A"},
        {2, "B"},
        {1, "C"}
    };

    Item* p = find_last(items, 3, 1);

    if(p != NULL){
        printf("%s\n", p->name);
    }
    return 0;
}