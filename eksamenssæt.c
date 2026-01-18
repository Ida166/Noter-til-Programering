/*Spørgsmål 1 – Datatyper og printf
Definér en variabel x af en passende type, så følgende kode udskriver:
Tallet er 3.14*/

double x = 3.14;
printf("Tallet er %.2f", x);

/*Spørgsmål 2 – Compile-fejl
Følgende kode kompilerer ikke.
Angiv den første linje, hvor compile-fejlen opstår, og forklar hvorfor.*/

int main(void){
    int a = 5;
    int* p; // den peger ikke på et sted i hukommelsen da den ikke er initaliseret.
    *p = a;
    printf("%d", *p);
    return 0;
}

/*Spørgsmål 4 – Typekonvertering
// Hvad udskriver programmet, og hvorfor?*/

int main(void){
    int a = 5;
    double b = 2;
    printf("%lf", a / b); //De udskriver 2,5
    return 0;
}

/*Spørgsmål 5 – Arrays og loops
Hvad udskriver følgende program?*/

int main(void){
    int arr[] = {10, 20, 30, 40};
    for(int i = 3; i >= 0; i--){
        printf("%d ", arr[i]); // 40 30 20 10
    }
    return 0;
}

/*Spørgsmål 6 – Logiske udtryk
Hvad udskriver programmet?*/

int main(void){
    int a = 0;
    int b = 5;

    if(a || b > 3) //udskirives a 5 > 3
        printf("X ");
    if(!a && b) //udskrives da a = 0 er samme som falsk og alle værdier der ikk er 0 er sande
        printf("Y ");
    printf("Z"); //Udskrives altid

    return 0;
} //Der udskrives X Y Z


/*Spørgsmål 7 – Struct og pointere
Tilføj den manglende kode, så programmet kompilerer og udskriver: 42 Q */

typedef struct{
    int x;
    char c;
} data_t;

void print(data_t* d){
    printf("%d %c", d->x, d->c); //d er en pointer og pointere skal bruge -> for at tilgå et felt i structen
}                                //d->x betyder: gå til structen som d peger på, og hent feltet x

int main(void){
    data_t d;
    d.x = 42;
    d.c = 'Q';

    print(&d);
    return 0;
}

/*Spørgsmål 8 – Strenge og '\0'
Hvad udskriver programmet?*/

int main(void){
    char s[] = {'H','E','J','\0','X','Y'};
    printf("%s", s); //Der udskrives HEJ da \0 er null terminatoren og stopper læsningen af stringen
    return 0;
}

/*Spørgsmål 9 – Funktionskald og værdier
Hvad udskrives?*/

void foo(int x){
    x = 10; // denne skulle have været pointeren *x
}

int main(void){
    int a = 5;
    foo(a); //denne skulle have været adresseoperatoren så fo(&a)
    printf("%d", a); //Der udskrives 5 for variablen bliver ikke opdateret
    return 0;
}

/*Spørgsmål 10 – Hukommelse og sizeof
Antag:
char = 1 byte
int = 4 bytes
double = 8 bytes
Hvor mange bytes fylder følgende struct i alt?*/

typedef struct{
    char a;
    int b;
    char c;
} s_t; //den fylder 6 bytes

/*Spørgsmål 11 – Rekursion
Hvad returnerer funktionen for f(3)?*/

int f(int x){
    if(x == 0) return 1;
    return x * f(x - 1); 
}

/*f(3) = 3 * f(2) = 6
f(2) = 2 * f(1) = 2
f(1) = 1 * f(0) = 1
f(0) = 1*/



/*Spørgsmål 12 – Pointer-parametre
Hvad udskriver programmet?*/

void inc(int* x){
    (*x)++;
}

int main(void){
    int a = 4;
    inc(&a);
    printf("%d", a); // der udskrives 5
    return 0;
}

/*Spørgsmål 13 – Dynamisk hukommelse
Hvilken linje mangler der for at undgå memory leak?*/

int main(void){
    int* arr = malloc(10 * sizeof(int));
    arr[0] = 42;
    printf("%d", arr[0]);
    // Her skal der stå free(arr);
    return 0;
}

/*Spørgsmål 14 – switch og fall-through
Hvad udskriver programmet, hvis input er 'b'?*/

switch(c){
    case 'a':
        printf("1");
        break;
    case 'b': // b matcher og 2 udskrives
        printf("2"); // der er ikken oget break så den køer videre
    case 'c':
        printf("3"); // 3 udskrives 
        break; //Break stopper
    default:
        printf("4");
} //Der printes 23

/*Spørgsmål 15 – Ternary operator
Hvilke af følgende return-statements er korrekte, hvis funktionen skal returnere 1,
når p ikke er NULL og *p er positiv?*/

int test(int* p){
    return p && *p > 0; //p evalueres først, hvis p == NULL → falsk og højresiden evalueres ikke
    return p != NULL ? *p > 0 : 0; //Hvis p != NULL: evalueres *p > 0, Hvis p == NULL: returneres 0
    return *p > 0 && p != NULL; // denne er forkert de andre er rigtige
    return p == NULL ? 0 : *p > 0; //Først tjek: p == NULL, Kun hvis den er falsk, evalueres *p > 0
}

/*Spørgsmål 16 – Indlejrede loops
Hvad udskriver programmet?*/

int main(void){
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= i; j++){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
/*Den printer følgende*/
1
12
123
/*Forkalring: Iteration for iteration
i = 1 → j = 1 → 1
i = 2 → j = 1,2 → 12
i = 3 → j = 1,2,3 → 123 */

/*Spørgsmål 17 – Stack vs heap
Hvilken variabel skal allokeres dynamisk for at programmet virker korrekt, og hvorfor?*/

char* make_copy(char* s){
    char buffer[100]; // det er buffer, forklaring: Data der returneres fra en funktion, skal ligge på heapen eller være statisk. Stack-variabler forsvinder, når funktionen slutter
    strcpy(buffer, s); 
    return buffer;
}

/*Spørgsmål 18 – Kædede structs
Hvad udskriver programmet?*/

typedef struct node{
    int v;
    struct node* next;
} node_t;

int main(void){
    node_t a = {1, NULL};
    node_t b = {2, NULL};
    node_t c = {3, NULL};

    a.next = &b;
    b.next = &c;

    node_t* p = &a;
    while(p){
        printf("%d ", p->v);
        p = p->next;
    }
    return 0;
}

/*Der udskrives følgende*/
1 2 3