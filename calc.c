#include <stdio.h>


int negatif(int nb[], int taille){
    int i = 0;

    for(i=0;i<taille;i++)
        if (nb[taille-i-1] < 0){
            return 1;
        }
    return 0;
}
int i_a_convertir(int nb_tabl[], int tabl_taille){
    int i;
    for (i = 0;i < tabl_taille; i++){
        if  (nb_tabl[i] != 0){
            return i;
        }
    }
}
void conversion(int nb[], int taille){
    int degres = i_a_convertir(nb, 1000);
    nb[degres]=nb[degres]*-1;
}
void convert2(int nb[], int taille){
    int nbv1 = i_a_convertir(nb,1000);
    nb[nbv1] = nb[nbv1] * -1;
}
int detecter(int nb[], int taille){
    int i;
    int negativite = 0;
    for (i=0; i<taille; i++){
        if (nb[i]<0){
            return 2;
        }
    }
    return 1;
}
int compare(int nb1[], int nb2[], int taille){
    int i;
    if ((negatif(nb1,1000) == 0 && negatif(nb2,1000) == 0) || (negatif(nb1,1000) == 1 && negatif(nb2,1000) == 1)){
        for (i = 0;i < taille; i++){
            if  (nb1[i] > nb2[i]){
                return 1;
            }
            else if (nb1[i] < nb2[i]){
                return 2;
            }
        }
    }
    else if  (negatif(nb1,1000) == 1 && (negatif(nb2,1000) == 0)){
        return 2;
    }
    else if (negatif(nb2,1000) == 1 && negatif(nb1,1000) == 0){
        return 1;
        }
        return 3;
    }
char flush_space(){
    char c;
    scanf("%c", &c);
    while(c==' ')
    scanf("%c", &c);
    return c;
}
void shift(int tab[], int taille_tab, int taille_nb){
    int i;
    for(i=0; i<taille_nb; i++){
        tab[taille_tab-i-1]=tab[taille_nb-i-1];
        tab[taille_nb-i-1]=0;
    }
}
int is_num(char c){
    return c>='0' && c<='9';
}
int convert(char c){
    return c-'0';
}
char lire_nombre(int tab[], int taille){
    char cur=0; int minus=0; int i=0;
    cur=flush_space();
    if(cur=='-'){
        minus=1;
        cur=flush_space();
    }
    tab[0]=minus ?-convert(cur) : convert(cur);
    scanf("%c", &cur);
    for(i=1; is_num(cur);i++){
        tab[i]=convert(cur);
        scanf("%c", &cur);
    }
    shift(tab, taille, i);
    if(cur==' ')
        return flush_space();
    else 
        return cur;
}

void display(int tab[], int taille){
    int i=0;
    for(i=0; i<taille && tab[i]==0; i++)
    ;
    for(;i<taille;i++)
        printf("%d", tab[i]);
    printf("\n");
}
void add_positive_num(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int ret=0;
    int cur=0;
    int dizaine;
    int unite;
    for(i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        dizaine=cur/10;
        unite=cur%10;
        res[taille-i-1]=unite;
        ret=dizaine;
    }
}
int nombrechiffres(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab && tab[i]==0; i++);
        
    return tailletab-i;
}
void sous_neg_num(int res[], int nb1[], int nb2[], int taille){
    int i = 0;
    int cur = 0;
    for (i = 0;i < taille;i++){
            if (nb2[taille-i-1] < nb1[taille-i-1]){
            nb2[taille-i-1] = nb2[taille-i-1]+10;
            nb1[taille-i-2] = nb1[taille-i-2]+1;
            cur=nb2[taille-i-1] - nb1[taille-i-1];
        }
        else {
            cur=nb2[taille-i-1] - nb1[taille-i-1];
        }
        res[taille-i-1] = cur;
        }
        convert2(res,1000);
}
void soustraction_n(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0;
    for(i=0; i<taille; i++){
        if (nb1[taille-i-1]<nb2[taille-i-1]){
            nb1[taille-i-1]=nb1[taille-i-1]+10;
            nb2[taille-i-2]=nb2[taille-i-2]+1;
            cur=nb1[taille-i-1]-nb2[taille-i-1];
        }
        else {
            cur=nb1[taille-i-1]-nb2[taille-i-1];
        }
        res[taille-i-1]=cur;
    }
}
void soustraction(int res[], int nb1[], int nb2[], int taille){
    int negatif1 = negatif(nb1, 1000);
    int negatif2 = negatif(nb2, 1000);
    int pou = compare(nb1, nb2, 1000);
    
    if (negatif1 == 0 && negatif2 == 0){
        if  (pou == 1){
            soustraction_n(res, nb1, nb2, 1000);
        }
        else if (pou == 2){
            sous_neg_num(res, nb1, nb2, 1000);
        }
    }
    else if (negatif1 == 1 && negatif2 == 0){
        convert2(nb1,1000);
        add_positive_num(res, nb1, nb2, 1000);
        convert2(res,1000);
    }
    else if (negatif1 == 0 && negatif2 == 1){
        convert2(nb2,1000);
        add_positive_num(res, nb1, nb2, 1000);
    }
    else if (negatif1 == 1 && negatif2 == 1){
        convert2(nb1,1000);
        convert2(nb2,1000);
        soustraction(res, nb2, nb1, 1000);
    }
}
void addition(int res[], int nb1[], int nb2[], int taille){
    int comp = compare(nb1,nb2,1000);
    int negatif1 = negatif(nb1,1000);
    int negatif2 = negatif(nb2,1000);

    if(negatif1 == 0 && negatif2 == 0){
        add_positive_num(res, nb1, nb2, taille);
    }
    else if (negatif1 == 0 && negatif2 == 1){
        convert2(nb2,1000);
        soustraction(res, nb1, nb2, taille);
        }
    else if (negatif1 == 1 && negatif2 == 0){
        convert2(nb1,1000);
        soustraction(res, nb1, nb2, taille);
        convert2(res,1000);
    }
    else if (negatif1 == 1 && negatif2 == 1){
        convert2(nb2,1000); 
        convert2(nb1,1000);
        addition(res, nb1, nb2, taille);
        convert2(res,1000);
    }
}
int chiffre(int tabl[], int tailletabl){
    int i;
    for (i=0;i<tailletabl && tabl[i]==0;i++);
    return tailletabl-i;
}
void decalage(int nb[1000], int decale){
    int i; 
    int az = chiffre(nb, 1000); 
    for (i=0; i<=az; i++){
        nb[1000-az-decale+i]=nb[1000-az+i];
    }
    for (i=0; i<decale; i++){
        nb[1000-i-1]=0;
    }
}
void multiplie(int resm[], int nb1[], int nb2[], int taille){
    int i;
    int j;
    int az = chiffre(nb2, taille);
    for (i=0; i<az; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decalage(rest, i);
        addition(resm, resm, rest, 1000);
    }
}

void multiplication(int res[], int nb1[], int nb2[], int taille){

    int negatif1 = negatif(nb1,1000);
    int negatif2 = negatif(nb2,1000);

    if (negatif1 == 0 && negatif2 == 0){
        multiplie(res,nb1,nb2,1000);
    }
    else if (negatif1 == 0 && negatif2 == 1){
        convert2(nb2, 1000);
        multiplie(res,nb1,nb2,1000);
        convert2(res,1000);
    }
    else if (negatif1 == 1 && negatif2 == 1){
        convert2(nb2, 1000); 
        convert2(nb1, 1000);
        multiplie(res,nb1,nb2,1000);
    }
    else if (negatif1 == 1 && negatif2 == 0){
        convert2(nb1, 1000);
        multiplie(res,nb1,nb2,1000);
        convert2(res,1000);
    }

}
void soustractiondivision(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0, C1=0, C2=0, ret=0;
    for(i=0; i<taille; i++){
        C1=nb1[taille-i-1];
        C2=nb2[taille-i-1]+ret;
        if (C1<C2){
            ret=1;
            cur=10+C1-C2;
        }
        else {
            ret=0;
            cur=C1-C2;
        }
        res[taille-i-1]=cur;
    }
}
void division(int res[], int nb1[], int nb2[], int taille){
    int i, y;
    int comparaisonzb = 0;
    int antebi[1000] = {0}; 
    int zindo[1000]= {0}; 
    int resf[1000]= {0};
    antebi[999] = 1;
    int degnb1 = nombrechiffres(nb1, 1000);
    int degnb2 = nombrechiffres(nb2, 1000);
    int ecartDeg = degnb1 - degnb2 ;
    int detecter1 = detecter(nb1, 1000);
    int detecter2 = detecter(nb2, 1000);
    if (detecter1==2 && detecter2==1){
    conversion(nb1, 1000);
    for (i=0; i<taille; i++){
        zindo[i]=nb2[i];
    }
    for(i=ecartDeg; i >= 0; i--){
      decalage(nb2,i);
      comparaisonzb = compare(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisonzb == 1 || comparaisonzb==3){
            soustractiondivision(nb1, nb1, nb2, 1000);
            addition(resf, resf, antebi, 1000);
            comparaisonzb = compare(nb1, nb2, 1000);
       }
        decalage(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++){
             nb2[y]=zindo[y];
    }
    }
    conversion(res, 1000);
    }
    else if (detecter1==1 && detecter2==2){
        conversion(nb2, 1000);
        for (i=0; i<taille; i++)zindo[i]=nb2[i];

    for(i=ecartDeg; i >= 0; i--){
      decalage(nb2,i);
      comparaisonzb = compare(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisonzb == 1 || comparaisonzb==3){
            soustractiondivision(nb1, nb1, nb2, 1000);
            addition(resf, resf, antebi, 1000);
            comparaisonzb = compare(nb1, nb2, 1000);
       }
        decalage(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=zindo[y];
    }
    conversion(res, 1000);
    }
    else if (detecter1==2 && detecter2==2){
        conversion(nb1, 1000);
        conversion(nb2, 1000);
        for (i=0; i<taille; i++)zindo[i]=nb2[i];

    for(i=ecartDeg; i >= 0; i--){
      decalage(nb2,i);
      comparaisonzb = compare(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisonzb == 1 || comparaisonzb==3){
            soustractiondivision(nb1, nb1, nb2, 1000);
            addition(resf, resf, antebi, 1000);
            comparaisonzb = compare(nb1, nb2, 1000);
       }
        decalage(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=zindo[y];
    }
    }
    else {
        for (i=0; i<taille; i++)zindo[i]=nb2[i];

    for(i=ecartDeg; i >= 0; i--){
      decalage(nb2,i);
      comparaisonzb = compare(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (comparaisonzb == 1 || comparaisonzb==3){
            soustractiondivision(nb1, nb1, nb2, 1000);
            addition(resf, resf, antebi, 1000);
            comparaisonzb = compare(nb1, nb2, 1000);
       }
        decalage(resf,i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=zindo[y];
    }
    }
}
void modulo(int res[], int nb1[], int nb2[], int taille){
    int i, y;
    int res1[1000]={0};
    int res2[1000]={0};
    int nb1vrai[1000]={0};
    int detecter1 = detecter(nb1, 1000);
    int detecter2 = detecter(nb2, 1000);
    if (detecter1==2 && detecter2==1){
    conversion(nb1, 1000);
    for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    conversion(res, 1000);
    }
    else if (detecter1==1 && detecter2==2){
    conversion(nb2, 1000);
    for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    }
    else if (detecter1==2 && detecter2==2){
        conversion(nb1, 1000);
        conversion(nb2, 1000);
        for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    conversion(res, 1000);
    }
    else {
        for (i=0; i<taille; i++){
        nb1vrai[i]=nb1[i];
    }
    division(res1, nb1, nb2, taille);
    multiplication(res2, res1, nb2, taille);
    for (y=0; y<taille; y++){
        nb1[y]=nb1vrai[y];
    }
    soustraction(res, nb1, res2, taille);
    }
}
int vidange(int res[], int taille){
    int i;
    int vide[1000]={0};
    int comparaisonzb=compare(vide, res, 1000);
    for (i=0; i<taille; i++){
        if (comparaisonzb==3){
            printf("0");
            return 0;
        }
    }
}
int main(){
    int nb1[1000]={0};
    int nb2[1000]={0};
    int nb3[1000]={0};
    int res1[1000]={0};
    int res2[1000]={0};
    char op1, op2;
    op1=lire_nombre(nb1, 1000);
    op2=lire_nombre(nb2, 1000);
    int degnb1 = nombrechiffres(nb1, 1000);
    int degnb2 = nombrechiffres(nb2, 1000);
    int degnb3 = nombrechiffres(nb3, 1000);
    int detecter1 = detecter(nb1, 1000);
    int detecter2 = detecter(nb2, 1000);
    int detecter3 = detecter(nb3, 1000);
    int vide[1000] = {0};
    int i;
    int comparaisonzb = compare(nb1, nb2, 1000);
    int comparaisonzb2 = compare(nb2, nb3, 1000);
    if(op2!='\n')
        lire_nombre(nb3, 1000);
    if (op2=='\n'){
        if (op1=='-'){
            soustraction(res1, nb1, nb2, 1000);
            display(res1, 1000);
        }
        else if (op1=='+'){
            addition(res1, nb1, nb2, 1000);
            display(res1, 1000);
        }
        else if (op1 == '*'){
            multiplication(res1, nb1, nb2, 1000);
            display(res1, 1000);
        }
        else if (op1=='/'){
        division(res1, nb1, nb2, 1000);
        vidange(res1, 1000);
        display(res1, 1000);
        }
        else if (op1=='%'){
        modulo(res1, nb1, nb2, 1000);
        vidange(res1, 1000);
        display(res1, 1000);
        }
    }













    else {
        if ( op1 == '+' && op2 == '+'){
            addition(res1, nb1, nb2, 1000);
            addition(res2,res1,nb3,1000);
            display(res2,1000);
    }
        else if ( op1 == '+' && op2 == '-'){
            addition(res1, nb1, nb2, 1000);
            soustraction(res2,res1,nb3,1000);
            display(res2,1000);
        }
        else if ( op1 == '-' && op2 == '+'){
            soustraction(res1, nb1, nb2, 1000);
            addition(res2, res1, nb3, 1000);
            display(res2,1000);
        }
        else if ( op1 == '-' && op2 == '-'){
            soustraction(res1, nb1, nb2, 1000);
            soustraction(res2,res1,nb3,1000);
            display(res2,1000);
        }
        else if ( op1 == '*' && op2 == '*'){
            multiplication(res1, nb1, nb2, 1000);
            multiplication(res2, res1, nb3, 1000);
            display(res2,1000);
        }
        else if ( op1 == '*' && op2 == '+'){
            multiplication(res1, nb1, nb2, 1000);
            addition(res2, res1, nb3, 1000);
            display(res2,1000);
        }
        else if ( op1 == '*' && op2 == '-'){
            multiplication(res1, nb1, nb2, 1000);
            soustraction(res2, res1, nb3, 1000);
            display(res2,1000);
        }
        else if ( op1 == '+' && op2 == '*'){
            multiplication(res1, nb2, nb3, 1000);
            addition(res2,nb1, res1, 1000);
            display(res2,1000);
        }
        else if ( op1 == '-' && op2 == '*'){
            multiplication(res1, nb2, nb3, 1000);
            soustraction(res2, nb1, res1, 1000);
            display(res2,1000);
        }
        else if (op1=='+' && op2=='/'){
        division(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
        }
        else if (op1=='+' && op2=='%'){
        modulo(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
        }
        else if (op1=='-' && op2=='/'){
        division(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
        }
        else if (op1=='-' && op2=='%'){
        modulo(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        vidange(res2, 1000);
        display(res2, 1000);        
        }
        else if (op1=='*' && op2=='/'){
        multiplication(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='*' && op2=='%'){
        multiplication(res1, nb1, nb2, 1000);
        modulo(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='/' && op2=='/'){
        division(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='/' && op2=='*'){
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='/' && op2=='-'){
        division(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='/' && op2=='+'){
        division(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='/' && op2=='%'){
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='%' && op2=='%'){
        modulo(res1, nb1, nb2, 1000);
        modulo(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='%' && op2=='*'){
        modulo(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='%' && op2=='/'){
        modulo(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='%' && op2=='+'){
        modulo(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    else if (op1=='%' && op2=='-'){
        modulo(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        vidange(res2, 1000);
        display(res2, 1000);
    }
    return 0;
}
}
