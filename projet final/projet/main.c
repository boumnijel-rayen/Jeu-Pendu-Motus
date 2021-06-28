#include <stdio.h>
#include <stdlib.h>
#include <time.h>    //bibliothèque admet la fonction time(NULL)
#include<windows.h>  //bibliothèque admet la fonction kbhit()
#include <conio.h>   //bibliothèque admet les fonction de couleur
#include <string.h>  //bibliothèque admet les fonction de chaine


int main(){
    int x;

void textcolor (unsigned short color){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);    //fonction qui nous donnons un numéro de couleur nous donne sa couleur
SetConsoleTextAttribute(hcon,color);
}


void motus(){

char pseudo[30],mot[30],motv[30],motv1[30],mots[30],aux[30];
    char m[30][30];
    char mot1[30]="jour",mot2[30]="voiture",mot3[30]="carte",mot4[30]="programme",mot5[30]="motus",mot6[30]="aussi";
    int tent,i,count,alea,s,score,x,n=0,g,j,tri,s1,s2,score1;


    printf("                 *****************************************************************************************\n");
    printf("                 **************************************** M O T U S **************************************\n");
    printf("                 *****************************************************************************************\n\n\n\n\n");


    do{
    mots[0]=' ';mots[1]=' ';mots[2]=' ';mots[3]=' ';mots[4]=' ';mots[5]=' ';mots[6]=' ';mots[7]=' ';mots[8]=' ';
    printf("donner votre pseudo\n");
    scanf("%s",&pseudo);

    tent=7;


    srand(time(NULL));       // srand(time(NULL)) Pour nous donner un nouveau nombre aléatoire
    alea=1+rand()%6;        //effectuer un numéro aleatoire entre 1 et 6 dans alea


    switch (alea) {
    case 1:{for(i=0;i<30;i++){mot[i]=mot1[i]; } }
    break;
    case 2: {for(i=0;i<30;i++){mot[i]=mot2[i]; }}
    break;
    case 3: {for(i=0;i<30;i++){mot[i]=mot3[i]; }}
    break;
    case 4: {for(i=0;i<30;i++){mot[i]=mot4[i]; }}
    break;
    case 5: {for(i=0;i<30;i++){mot[i]=mot5[i]; }}
    break;
    case 6: {for(i=0;i<30;i++){mot[i]=mot6[i]; }}
    break;
    }



    s=time(NULL);        // time(NULL) fonction prédéfinie nous donne le nombre de seconds depuis qu'il a été fait la langage c
    motv[0]=mot[0];
    for(i=1;i<strlen(mot);i++){
    motv[i]='-';
    }





    printf("il vous reste %i tentatives et %i second\n",tent,70-(time(NULL)-s));
    for (i=0;i<strlen(mot);i++){
    printf("%c",motv[i]);
    }
    printf("  donner votre proposition composee de %i chiffre        ",strlen(mot));
    scanf("%s",mots);




    do{


        count=0;
    for (i=0;i<strlen(mot);i++){
    if (mot[i]==mots[i]){
        count++;
    }
    }




tent--;




     if ((count!=strlen(mot)) && (tent>=1)){

    printf("il vous reste %i tentatives et %i second\n",tent,70-(time(NULL)-s));
    for(i=0;i<strlen(mots);i++){
        g=0;
        if (mots[i]==mot[i]){
        textcolor(2);
        printf("%c",mots[i]);
        g=1;
        textcolor(15);
        }else{j=0;
        do{
        if (mots[i]==mot[j]){
        textcolor(6);
        printf("%c",mots[i]);
        g=1;
        textcolor(15);
        }
        j++;
        }while((j<strlen(mot))&&(g==0));
        }
        if (g==0){
        textcolor(12);
        printf("%c",mots[i]);
        textcolor(15);
        }
    }


    printf("  donner votre proposition composee de %i chiffre        ",strlen(mot));
    scanf("%s",mots);

    }




    }while((count!=strlen(mot)) && (tent>=0) && ((70-(time(NULL)-s))>0) ) ;



switch (tent) {
case 6:score=4;
break;
case 5:score=4;
break;
case 4:score=3;
break;
case 3:score=3;
break;
case 2:score=2;
break;
case 1:score=2;
break;
case 0:score=1;
break;
}





if ((70-(time(NULL)-s)) <= 0){
printf("\nLe temps expire, reessayez\n"); score=0;
}else{if(count == strlen(mot)){
printf("\nBIEN JOUE ! votre score est : %i \n",score);
}else{
printf("\nVous avez epuise vos tentatives, reessayez\n"); score=0;
}
}





    i=0;
    do{
        g=1;
    for (j=0;j<strlen(pseudo);j++){
    if (m[i][j]!=pseudo[j]){
    g=0;
    }
    }
    if (g==0){
    i++;
    }
    }while((g==0)&&(i<=n));




    if (g==0){
    for (j=0;j<30;j++){
        if(j<strlen(pseudo)){
    m[n][j]=pseudo[j];
        }else{
        m[n][j]=' ';
        }
    }
    m[n][21]=score+48;
    n++;
    }

    if (g==1){
    for (j=0;j<strlen(pseudo);j++){
    m[i][j]=pseudo[j];
    }
    m[i][21]=m[i][21]+score;
    }




    do{

    printf("----------------------------\n");
    printf("1.  rejouter\n2.  verifier score\n3.  classement\n4.  retour au menu preincipale\n5.  quitter l'application\n");
    printf("----------------------------\n");
    do{
    scanf("%i",&x);
    }while((x < 1) || (x > 5));

    switch (x){
    case 2:{

            i=0;
            do{
            g=1;
            for (j=0;j<strlen(pseudo);j++){
            if (m[i][j]!=pseudo[j]){
            g=0;
            }
            }
            if (g==0){
            i++;
            }

            }while(g==0);
            score1=m[i][21]-48;
            printf("votre score est %i\n",score1);
    }
    break;
    case 3:{
            tri =0;
   while(tri==0){
   tri = 1;
   for (i=0;i<n-1;i++){


   s1=m[i][21]-48;


   s2=m[i+1][21]-48;



   if(s1<s2){
   for (j=0;j<30;j++){
   aux[j]=m[i][j];
   m[i][j]=m[i+1][j];
   m[i+1][j]=aux[j];
   }
   tri=0;
   }

   }
   }
   printf("**********pseudo              score     *******************\n\n\n");
   for (i=0;i<n;i++){
       printf("**********");
   for (j=0;j<30;j++){
       if (j==21){
       printf("%i",m[i][j]-48);
       }else{
   printf("%c",m[i][j]);
       }
   }
   printf("*******************\n");
   }
    };
    break;
    case 4:main();
    break;
    case 5: exit(0);
    break;
    }


    }while((x==2) || (x==3));


}while (x==1);


}

void pendu(){


    char mot1[30]="jour",mot2[30]="voiture",mot3[30]="programme",mot4[30]="carte",mot5[30]="pendu",mot6[30]="aussi";
    char mot[20],word[30],lettre1[30];
    char lettre2[30],aux[30];
    char pseudo[30];
    char m[30][30];
    int alea,i,j,g,n=0,l,score,p,s,r,x,o,q,tri,s2,s1,score1,g1;
    char a,k;








    do{





        s=70;r=0;g1=0;
        lettre1[0]='a';lettre1[1]=' ';lettre1[2]='b';lettre1[3]=' ';lettre1[4]='c';lettre1[5]=' ';lettre1[6]='d';lettre1[7]=' ';lettre1[8]='e';lettre1[9]=' ';lettre1[10]='f';lettre1[11]=' ';lettre1[12]='g';
        lettre1[13]=' ';lettre1[14]='h';lettre1[15]=' ';lettre1[16]='i';lettre1[17]=' ';lettre1[18]='j';lettre1[19]=' ';lettre1[20]='k';lettre1[21]=' ';lettre1[22]='l';lettre1[23]=' ';lettre1[24]='m';
       lettre2[0]='n';lettre2[1]=' ';lettre2[2]='o';lettre2[3]=' ';lettre2[4]='p';lettre2[5]=' ';lettre2[6]='q';lettre2[7]=' ';lettre2[8]='r';lettre2[9]=' ';lettre2[10]='s';lettre2[11]=' ';lettre2[12]='t';
        lettre2[13]=' ';lettre2[14]='u';lettre2[15]=' ';lettre2[16]='v';lettre2[17]=' ';lettre2[18]='w';lettre2[19]=' ';lettre2[20]='x';lettre2[21]=' ';lettre2[22]='y';lettre2[23]=' ';lettre2[24]='z';





    printf("donner votre pseudo\n");
    l=-1;
    do{
    l++;
    p=getch();       // getch() permet de lire un carectere
    pseudo[l]=p;
    printf("%c",pseudo[l]);
    }while(p != 13);
    printf("\n");





    srand(time(NULL));
    alea=1+rand()%6;


    switch (alea) {
    case 1:{for(i=0;i<30;i++){mot[i]=mot1[i]; } }
    break;
    case 2: {for(i=0;i<30;i++){mot[i]=mot2[i]; }}
    break;
    case 3: {for(i=0;i<30;i++){mot[i]=mot3[i]; }}
    break;
    case 4: {for(i=0;i<30;i++){mot[i]=mot4[i]; }}
    break;
    case 5: {for(i=0;i<30;i++){mot[i]=mot5[i]; }}
    break;
    case 6: {for(i=0;i<30;i++){mot[i]=mot6[i]; }}
    break;
    }









    i=7;
    for (j=0;j<strlen(mot);j++){
    word[j]='*';
    }







    do{

        g=0;




        printf("\nquel est le mot secret?  ");
        for(j=0;j<strlen(mot);j++){
            printf("%c",word[j]);
            }
       printf("\n");





        for(k=0;k<25;k++){
            for (j=0;j<strlen(mot);j++){
                if ( (lettre1[k]==a)&&(mot[j]==a) ){
                    lettre1[k] ='-';
                        }
                    }
            printf("%c",lettre1[k]);
            }


        printf("\n");





            for(k=0;k<25;k++){
                for (j=0;j<strlen(mot);j++){
                    if ( (lettre2[k]==a) && (mot[j]== a) ){
                        lettre2[k] ='-';
                        }
                    }
                printf("%c",lettre2[k]);
                }






    printf("\ntaper '?' pour help\n");
    printf("\nil vous reste %i coups a jouer et \n",i);
    printf("\n              proposer une lettre :\r");
    printf("      second");




            while((s != 0) && (!kbhit())){  // !kbhit() permet de tester si l'utilisateur n'a frappé aucune touche
					printf("\r%d ",s);
					Sleep(1000);      // sleep(1000) permet d'arreter le programme 1000 ms
					if(s!=0)
					{
						s--;
					}

				}




            if (s!=0){
                a=getch();
                printf("   \n%c",a);
                if ( (a=='?')&&(g1==0) ) {
                g1=1;
                j=0;
                p=0;
                do{
                if (word[j]=='*'){
                p=1;
                }else{
                j++;
                }
                }while(p==0);
                a=mot[j];
                r++;
                }


                for (j=0;j<strlen(mot);j++){
                if(a==mot[j]){
                g=1;
                }
                }
                if (g==0){
                i--;
                }
            }




                for(j=0;j<strlen(mot);j++){
                    if (a == mot[j]){
                        word[j]=a;
                        }
                    }



    }while((i != 0) && (strcmp(mot,word) == 1) && (s!=0));


    switch (7-i){
    case 0:score=4-r;
    break;
    case 1:score=4-r;
    break;
    case 2:score=3-r;
    break;
    case 3:score=3-r;
    break;
    case 4:score=2-r;
    break;
    case 5:score=2-r;
    break;
    case 6:score=1-r;
    break;
    }




    if(strcmp(mot,word) != 1){
    printf("\ngagne ! le mot secret etait bien: %s\n et votre scoure est : %i\n",mot,score);
    }else {if(s==0){
    printf("\nLe temps expire, reessayez\n"); score=0;
    }else{if (i==0){
    printf("\nVous avez epuise vos tentatives, reessayez\n"); score=0;
    }
    }
    }






   i=0;

    do{
        g=1;
    for (j=0;j<l;j++){
    if (m[i][j]!=pseudo[j]){
    g=0;
    }
    }
    if (g==0){
    i++;
    }

    }while((g==0)&&(i<=n));




    if (g==0){
    for (j=0;j<30;j++){
        if(j<l){
    m[n][j]=pseudo[j];
        }else{
        m[n][j]=' ';
        }
    }
    m[n][21]=score+48;
    n++;
    }

    if (g==1){
    for (j=0;j<l;j++){
    m[i][j]=pseudo[j];
    }
    m[i][21]=m[i][21]+score;
    }





    do{

    printf("----------------------------\n");
    printf("1.  rejouter\n2.  verifier score\n3.  classement\n4.  retour au menu preincipale\n5.  quitter l'application\n");
    printf("----------------------------\n");
    do{
    x=getch();
    }while ((x < 49) || (x > 53));
    x=x-48;
    printf("%i\n",x);




    switch (x){
    case 2:{

            i=0;
            do{
            g=1;
            for (j=0;j<l;j++){
            if (m[i][j]!=pseudo[j]){
            g=0;
            }
            }
            if (g==0){
            i++;
            }

            }while(g==0);
            score1=m[i][21]-48;
            printf("votre score est %i\n",score1);
    }
    break;
    case 3:{
            tri =0;
   while(tri==0){
   tri = 1;
   for (i=0;i<n-1;i++){


   s1=m[i][21]-48;


   s2=m[i+1][21]-48;


   if(s1<s2){
   for (j=0;j<30;j++){
   aux[j]=m[i][j];
   m[i][j]=m[i+1][j];
   m[i+1][j]=aux[j];
   }
   tri=0;
   }

   }
   }
   printf("**********pseudo              score     *******************\n\n\n");
   for (i=0;i<n;i++){
       printf("**********");
   for (j=0;j<30;j++){
       if (j==21){
       printf("%i",m[i][j]-48);
       }else{
   printf("%c",m[i][j]);
       }
   }
   printf("*******************\n");
   }
    };
    break;
    case 4:main();
    break;
    case 5:exit(0);
    break;
    }



    }while((x==3)|| (x==2));



    a=' ';
    }while(x==1);



}


    printf("                       --------------------------------------\n");
    printf("                                 bienvenu au jeu\n");
    printf("                       --------------------------------------\n\n\n\n");
    printf("                       --------------------------------------\n");
    printf("                              veuillez choisir un jeu    \n");
    printf("                       --------------------------------------\n");
    printf("                       --------------------------------------\n");
    printf("                                  1. jeu pendu\n                                  2. jeu motus\n");
    printf("                       --------------------------------------\n\n\n\n");
    printf("                       --------------------------------------\n");
    printf("                                  3.quiter\n");
    printf("                       --------------------------------------\n");
    printf("taper ici\n");
    do{
    scanf("%i",&x);
    }while((x<1)||(x>3));
    switch(x){
    case 1:pendu();
    break;
    case 2:motus();
    break;
    case 3:exit(0);  // exit(0) permet d'arrete le programme et returnee 0
    break;
    }


return 0;
}
