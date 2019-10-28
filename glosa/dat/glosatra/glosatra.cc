
//  glosatra.C 
//  ========== 

//  Un programa te auxi translati Glosa. 
//  Marcel Springer, Hamburg, Deutsch-landa, http://www.glosa.org. 
//  2002-07-19 ... 2004-01-04 

//  Ge-uti kompila-programa: 
//    g++ de 
//      GCC,   http://gcc.gnu.org, e 
//      MinGW, http://www.mingw.org, e 
//    bcc32 de 
//      Borland C++ Compiler 5.5, http://www.borland.com 
//      (Si tu volu uti u Borland-kompila-programa; tu nece nomina 
//       u-ci programa-fonta-textu ad-in "glosatra.cpp"!  Vide plu 
//       "//"-nota pro Borland muta-ra!  U-ci es GNU-versio de 
//       programa-fonta-textu.). 

#include <iostream>                // Pro Borland muta "<iostream>" 
                                   //   ad-in "<iostream.h>"!
#include <cstdio>                  // <cstdio> es paleo.  Pe debi uti 
                                   //   <fstream> vice <cstdio>, sed 
                                   //   uno kompila-programa ne pote 
                                   //   "cin = indo". 
                                   // Pro Borland muta "<cstdio>" 
                                   //   ad-in "<stdio.h>"! 
#include <fstream> 
#include <cstring>                 // <cstring> es paleo.  Pe debi uti 
                                   //   <string> vice <cstring>.  Mi 
                                   //   proba id, sed <string> pa es ma 
                                   //   lento. 
                                   // Pro Borland muta "<cstring>" 
                                   //   ad-in "<_str.h>" 
                                   //   (alo "<string.h>")! 
#include <strstream>               // <strstream> es paleo.  Pe debi 
                                   //   uti <sstream> vice <strstream>, 
                                   //   sed <strstream> ma gru a paleo 
                                   //   <cstring> e <stringstream> nece 
                                   //   plus <string>. 

const unsigned char MLONGI = 255;  // maxi longi de line 
const unsigned char ASC1   =  48;  // (char *) ASC1 +1 = '1' 
const unsigned char ASCz   = 123;  // (char *) ASCz -1 = 'z' 

FILE      *exdo;                   // buta-dokumenta 
ifstream  vldo;                    // verba-lista dokumenta 
strstream lista;                   // verba-lista 
streampos loka[ASCz];              // loka de proto-litera in 
                                   // verba-lista 
char      verba[MLONGI] = "";      // u verba; qi debi gene translati 
char      pverba[MLONGI] = "";     // u paleo verba 
char      vstria[MLONGI] = "";     // line ex verba-lista 
char      vastria[MLONGI] = "";    // ge-muta vstria te auxi 
char      tako = 0;                // tako=1 semani tako-cerka, 
                                   //   =0 es norma lento cerka. 
char      english = 0;             // english=1 semani translati 
                                   //   English-Glosa, 
                                   //   =0 Glosa-English. 
/*
char      english = 1;             // english=1 semani translati 
                                   //   English-Glosa, 
                                   //   =0 Glosa-English. 
*/
char      nv = 0;                  // numera de plu verba 

void apofini(char xverba[MLONGI]); // Apo plu fini vokali! 
void cerka();                      // Cerka plu verba! 
void facvas();                     // Face verba-lista auxi-stria! 
char mutal(const char x);          // Muta plu litera! 
void parentesi();                  // Sorta plu parentesi []! 
void takocerka();                  // Tako cerka plu verba! 

int main(int argc, char* argv[]) 
{ 
  FILE *indo;                      // lekto-dokumenta 
  char stria[MLONGI] = "";         // ge-lekto line 
  char indono[MLONGI] = "";        // nomina de lekto-dokumenta 
  char exdono[MLONGI] = "";        // nomina de buta-dokumenta 
  char vldono[MLONGI] = "";        // nomina de verba-lista 
  unsigned char m1 = 0;            // memo-valu; 
  unsigned char m2 = 0;            // memo-valu; 
  unsigned char i1 = 0;            // index 
  unsigned char i2 = 0;            // index 
  unsigned char i3 = 0;            // index 

                                   // Saluta-info:  
  cerr << endl << 
    "GLOSATRA, u pusi programa te auxi translati Glosa.  "
    "Optio -i pro info. " << endl << endl; 

                                   // Proba plu parametri!: 
  for (i1=1; i1<argc; i1++) 
    { 
                                   // Plu optio: 
     if (argv[i1][0]=='-'
/*
                                   // Solo pro MS-DOS: 
                                   //   plu optio plus ko "/": 
         || argv[i1][0]=='/'

*/
        ) 
       {switch (argv[i1][1]) 
                                   // -d:...  
                                   //   semani: un hetero verba-lista 
                                   //   pa gene elekti.: 
          {case 'd': 
             if (strlen(argv[i1])<4) 
               {cerr << 
                  "Ero ko -d: nuli dokumenta-nomina pa gene dona pro " 
                    "verba-lista. " << endl << endl; 
                return 1;} 
             else 
               {i2=0; 
                do 
                  {vldono[i2]=argv[i1][i2+3];} 
                while (vldono[i2++]!='\0'); 
               }; 
             break; 
                                   // -e... 
                                   //   Translati ex English ad Glosa!: 
           case 'e': 
             english = 1; 
/*
                                   // Pro hetero programa-versio; pro 
                                   // qi English-Glosa es norma.: 
             english = 0; 
*/
             break; 
                                   // --...: 
           case '-': 
                                   // --version: 
             if (!strcmp(argv[i1], "--version")) 
               {cerr << "Versio: 2002-09-20. " << endl << endl; 
                return 0;}; 
                                   // --help: 
             if (strcmp(argv[i1], "--help")) 
               {cerr << "Ero: mi ne ski tu optio " << argv[i1] << ". " 
                  << endl << endl; 
                return 2;}; 
                                   // --help eqa -i.  Kura!: 
                                   // Ka-co ci nuli "break". 

                                   // -h: 
                                   // -h eqa -i.  Kura!: 
                                   // Ka-co ci nuli "break". 
           case 'h': 
                                   // -i... 
                                   //   Grafo info textu!: 
           case 'i': 
             cerr << endl << endl << 
               "Glosatra" << endl << 
               "========" << endl << 
               "U-ci eqa pusi e primitivi programa; qi debi auxi "
                 "translati Glosa.  Id" << endl << 
               "simpli cerka plu verba de textu in verba-lista "
                 "dokumenta e dona ex " << endl << 
               "lista de mu. " << endl << endl << 
               "Uti:" << endl << endl << 
               "  " << argv[0] << 
                 " [... plu optio ...] [fonta-textu.txt" 
               " [buta-textu.txt]] " << endl << endl << 
               "Plu optio: " << endl << endl << 
               "  -d:lista.txt  Uti verba-lista dokumenta lista.txt.  "
                 "Norma ('default') " << endl << 
               "                es glen.txt alo engl.txt pro -e. " 
                 << endl << 
               "  -e            Translati English-Glosa." << endl << 
               "  -i            Grafo u-ci info. " << endl << 
               "  -t            Tako cerka, mei ge-dona ex ra, posi " 
                 "ma boni ge-lekto. " << endl << endl << 
               "Marcel Springer, www.glosa.org, 2002 ... 2004"
                 << endl << endl;
                                   // Fini de programa: 
             return 0; 
             break; 
                                   // -f... 
                                   //   semani English "fast" = tako. 
           case 'f': 
                                   // -f eqa -t.  Kura!: 
                                   // Ka-co ci nuli "break". 

                                   // -t... 
                                   //   semani: tako cerka. 
           case 't': 
             tako = 1; 
             break; 
                                   // default: 
                                   //   = falsi optio --> ero e fini. 
           default: 
             cerr << "Ero: mi ne ski tu optio " << argv[i1] << ". " 
               << endl << endl; 
             return 3; 
             break; 
          }; 
       } 

                                   // Plu dokumenta-nomina: 
     else 
       {if (!strcmp(indono, "")) 
          {strcpy(indono, argv[i1]);} 
        else 
          {if (!strcmp(exdono, "")) 
             {strcpy(exdono, argv[i1]);} 
           else 
             {cerr << "Ero: tro poli dokumenta-nomina. " << endl 
                << endl; 
              return 4; 
             }; 
          } 
       }; 
    }; 

                                   // Norma nomina de verba-lista: 
  if (!strcmp(vldono, "")) 
    {if (english) 
       {strcpy(vldono, "engl.txt");} 
     else 
       {strcpy(vldono, "glen.txt");}; 
    }; 
                                   // Apri plu kanali!: 
  vldo.open(vldono); 
  if (!vldo) 
    {cerr << 
       "Ero: ne pa pote apri verba-lista dokumenta '" << vldono << 
       "'. " << endl << endl; 
     return 5; 
    }; 

  if (strcmp(indono, "")) 
    {if ((indo = fopen(indono, "r")) == NULL) 
       {cerr << 
          "Ero: ne pa pote apri fonta-dokumenta '" << indono << 
          "'. " << endl << endl; 
        return 6;}; 
    } 
  else 
    {indo = stdin;}; 

  if (strcmp(exdono, "")) 
    {if ((exdo = fopen(exdono, "w")) == NULL) 
       {cerr << 
          "Ero: ne pa pote apri buta-dokumenta '" << exdono << "'. " 
          << endl << endl; 
        return 7;}; 
    } 
  else 
    {exdo = stdout;}; 

                                   // Kargo verba-lista ad-in memo-me!: 
  if (tako) 
    {lista.clear(); 
     for (i1=0; i1<ASCz; i1++) {loka[i1]=lista.tellp();}; 
    }; 
  while(vldo.getline(vstria, MLONGI, '\n')) 
    { 
                                   // Ne uti plu line de verba-lista; 
                                   // qi proto ko "%"!: 
     if (vstria[0]!='%' && strstr(vstria, "  ")!=NULL) 
       { 
                                   // Face auxi-ra "vastria" e "nv"!: 
        facvas(); 
                                   // Memo loka de proto litera pro 
                                   // "takocerka()"!: 
        if (tako) 
          {m2 = mutal(vstria[0]); 
           if (m2>m1 && m2<ASCz && nv<2) 
             {loka[m2] = lista.tellp(); 
              m1 = m2; 
             }; 
          }; 
                                   // Grafo lista ad-in stream 
                                   // "lista"!: 
        lista << vstria << endl << vastria << endl; 
        lista.put (ASC1+nv); 
        lista << endl; 

       }; 
    } 
  lista << ends; 

                                   // Cefa-"while"-zona: 
                                   //   Lekto u textu!: 
  while(fgets(stria, MLONGI-1, indo) != NULL) 
    {fprintf (exdo, "%s------------------------------\n", stria); 
                                   // Skizo u stria!: 
     strcpy(verba, ""); 
     i2 = 0; 
     i3 = strlen(stria); 
     for (i1=0; i1<i3; i1++) 
       {verba[i2] = mutal(stria[i1]); 
                                   // Si English-Glosa; muta 
                                   // xxxn't ---> xxx not 
        if (english && i1+3<i3 && verba[i2]=='n') 
          {if (   stria[i1+1]=='\'' 
               && mutal(stria[i1+2])=='t' 
               && mutal(stria[i1+3])==' ') 
             {verba[i2] = ' '; 
              stria[i1+1] = 'o'; 
              i1--; 
                                   // "won't" --> "will not 
              if (!strcmp(verba, "wo ")) 
                {strcpy(verba, "will ");
                 i2 = 4; 
                }; 
             }; 
          }; 
                                   // ' ' semani: neo verba.: 
        if (verba[i2]==' ') 
          {verba[i2]='\0'; 
           if (i2) 
             { 
                                   // U maxi importa mero: cerka.: 
              if (tako) {takocerka();} else {cerka();}; 
              strcpy(verba, ""); 
              i2 = 0; 
             }; 
          } 
        else 
          {i2++;}; 
                                   // Si u neo frase pa proto; id ne 
                                   // fu es u Glosa verba-grega in 
                                   // verba-lista.: 
        if (stria[i1]=='.' || stria[i1]=='?') 
          {strcpy(pverba, "");}; 
       }; 
     fprintf (exdo, "==============================\n"); 
     fflush (exdo); 
    }; 

  return 0; 
}                                  // fini de "main". 

//--------------------------------- 

void apofini(char xverba[MLONGI])  // Apo plu fini vokali! 
{
  unsigned char i1 = strlen(xverba); 

                                   // Si translati English ad-in 
                                   //   Glosa: ... 
  if (english) 
    {
                                   // Muta fini -"ies " ad in -""! 
                                   // Exempla: 
                                   // " properties " --> " propert" 
     if (i1>7 && strstr(xverba, "ies ")!=NULL) 
       {xverba[i1-4]='\0'; 
        return;}; 
                                   // Muta fini -"es " ad in -""! 
                                   // Exempla: 
                                   // it crashes, languages 
     if (i1>6 && strstr(xverba, "es ")!=NULL) 
       {xverba[i1-3]='\0'; return;}; 
                                   // Muta fini -"s " ad in -" "! 
                                   // Exempla: files. 
     if (i1>5 && xverba[i1-2]=='s') 
       {xverba[i1-2]=' '; 
        xverba[i1-1]='\0'; 
        return; 
       }; 
                                   // Muta fini -"ingly " ad-in -""! 
                                   // Exempla: surprisingly. 
     if (i1>9 && strstr(xverba, "ingly ")!=NULL) 
       {xverba[i1-6]='\0'; return;}; 
                                   // Muta fini -"edly " ad-in -""! 
                                   // Exempla: excitedly. 
     if (i1>8 && strstr(xverba, "edly ")!=NULL) 
       {xverba[i1-5]='\0'; return;}; 
                                   // Muta fini -"ily " ad-in -"y "! 
                                   // Exempla: easily. 
     if (i1>7 && strstr(xverba, "ily ")!=NULL) 
       {xverba[i1-4]='y'; xverba[i1-3]=' '; xverba[i1-2]='\0'; 
        return;}; 
                                   // Muta fini -"ly " ad-in -""! 
                                   // Exempla: quickly. 
     if (i1>6 && strstr(xverba, "ly ")!=NULL) 
       {xverba[i1-3]=' '; xverba[i1-2]='\0'; 
        return;}; 
                                   // Muta fini -"ing " ad-in -""! 
                                   // Exempla: moving. 
     if (i1>7 && strstr(xverba, "ing ")!=NULL) 
       {xverba[i1-4]='\0'; 
                                   // Apo diplo konsona-litera pre 
                                   // -ing! 
                                   // Exempla: drag, dragging 
        if (strchr("aeiou", xverba[i1-5])==NULL 
            && xverba[i1-5] == xverba[i1-6]) 
          {xverba[i1-5]='\0';}; 
        return;
       }; 
                                   // Muta fini -"ed " ad-in -""! 
                                   // Exempla: replaced. 
     if (i1>6 && strstr(xverba, "ed ")!=NULL) 
       {xverba[i1-3]='\0'; 
                                   // Apo diplo konsona-litera pre -ed! 
                                   // Exempla: dragged. 
        if (strchr("aeiou", xverba[i1-4])==NULL 
            && xverba[i1-4] == xverba[i1-5]) 
          {xverba[i1-4]='\0';}; 
        return;
       }; 
                                   // Muta fini -"ier " ad-in -"y "! 
                                   // Exempla: easier. 
     if (i1>7 && strstr(xverba, "ier ")!=NULL) 
       {xverba[i1-4]='y'; xverba[i1-3]=' '; xverba[i1-2]='\0'; 
        return;}; 
                                   // Muta fini -"er " ad-in -""! 
                                   // Exempla: later. 
     if (i1>6 && strstr(xverba, "er ")!=NULL) 
       {xverba[i1-3]='\0'; return;}; 
                                   // Muta fini -"est " ad-in -""! 
                                   // Exempla: latest. 
     if (i1>7 && strstr(xverba, "est ")!=NULL) 
       {xverba[i1-4]='\0'; 
                                   // Apo diplo litera! 
                                   // Exempla: " biggest " --> " big". 
        if (xverba[i1-5]==xverba[i1-6]) {xverba[i1-5]='\0';}; 
        return;}; 
                                   // Muta fini -vokali+"tion " ad-in -""! 
                                   // Exempla: installation. 
     if (i1>9 && strstr(xverba, "tion ")!=NULL) 
       {if (strchr("aeiou", xverba[i1-6])!=NULL) 
          {xverba[i1-6]='\0';};
        return;}; 

                                   // Nuli litera-grega pa gene 
                                   // detekti.  Ki retro!: 
     return; 
    }; 

                                   // Si translati Glosa ad-in 
                                   //   English: ... 

                                   // Lase "xverba"; si id habe solo mo 
                                   // alo bi litera! 
                                   // (Nota: 
                                   //    2 litera + 2 space = 4): 
  if (i1>4) 
    { 
                                   // Si "xverba" habe tri litera; apo 
                                   // u fini space; si u verba ne fini 
                                   // ko vokali!: 
     if (i1==5) 
       {if (strchr("aeiou", xverba[3])==NULL) 
          {xverba[4]='\0';}; 
       } 
     else 
       { 
                                   // Si "xverba" habe tetra litera alo 
                                   // ma; apo u fini space!: 
        xverba[i1-1]='\0'; 
                                   // E po-co apo maxima bi fini 
                                   // vokali!: 
        if (strchr("aeiou", xverba[i1-2])!=NULL) 
          {xverba[i1-2]='\0'; 
           if (strchr("aeiou", xverba[i1-3])!=NULL) 
             {xverba[i1-3]='\0';}; 
          }; 
       }; 
    }; 
} 

void cerka()                       // Cerka plu verba! 
{ 
  char averba[MLONGI] = "";        // auxi-verba 
  char nvs[MLONGI] = "0";          // C-string ko numera de verba. 
  char va2stria[MLONGI] = "";      // kopi de "vastria" 
  unsigned char i1 = 0;            // index 
  unsigned char i2 = 0;            // index 
  unsigned char m1 = 0;            // memo-valu 

                                   // Face auxi-verba "averba"! 
                                   // Id habe bi " " peri "verba". 
  strcpy(averba, " "); 
  strcat(averba, verba); 
  strcat(averba, " "); 
                                   // Ki a proto de verba-lista!: 
  lista.clear(); lista.seekg(0); 
                                   // "while"-zona: 
  while(lista.getline(vstria, MLONGI, '\n') 
        && lista.getline(vastria, MLONGI, '\n') 
        && lista.getline(nvs, MLONGI, '\n')) 
    { 
                                   // Proba; si "verba" es in 
                                   // "vastria"!: 
     if (strstr(vastria, averba)!=NULL) 
       {if (nvs[0]=='1') 
                                   // Si "vastria" habe solo mo verba; 
                                   // id feno gru.  Dona id ex!: 
          {fprintf (exdo, "%s\n", vstria); 
           m1 = 1;} 
        else 
                                   // "vastria" habe ma de mo verba.: 
          {if (strcmp(pverba, "")) 
             { 
                                   // Proba; si "averba" e u paleo 
                                   // "pverba" es in "vastria"!: 
              if (strstr(vastria, pverba)!=NULL) 
                { 
                 strcpy(va2stria, vastria); 
                 i2 = strlen(pverba); 
                 if (pverba[i2-1]==' ') {i2--;}; 
                 while (strncmp(va2stria, pverba, i2)!=0) 
                   {i1 = 0; 
                    do 
                      {va2stria[i1]=va2stria[i1+1];} 
                    while (va2stria[i1++]!='\0'); 
                   }; 
                 i1 = 0; 
                 do 
                   {va2stria[i1]=va2stria[i1+i2];} 
                 while (va2stria[i1++]!='\0'); 
                 if (strstr(va2stria, averba)!=NULL) 
                   {fprintf (exdo, "%s\n", vstria); 
                    m1 = 1;} 
                }; 
             }; 
         }; 
       }; 
     }; 
                                   // "averba" gene u neo "pverba" pro 
                                   // seqe proto de "cerka".  Pre memo 
                                   // "averba", apo plu fini vokali!: 
  apofini(averba); 
  strcpy(pverba, averba); 

  if (!m1) 
                                   // U verba ne pa pote gene detekti 
                                   // a-nu.  Qe, posi u fini vokali es 
                                   // falsi? -- Proba id!: 
    { 
                                   // Ki a proto de verba-lista!: 
     lista.clear(); lista.seekg(0); 
                                   // "while"-zona: 
     while(lista.getline(vstria, MLONGI, '\n') 
           && lista.getline(vastria, MLONGI, '\n') 
           && lista.getline(nvs, MLONGI, '\n')) 
       { 
                                   // Proba; si "vastria" habe solo mo 
                                   // verba!: 
        if (nvs[0]=='1') 
          { 
           if (strstr(vastria, averba)!=NULL) 
                                   // Apo plu fini vokali de 
                                   //  "vastria"!: 
             {if (english) 
               {if (strlen(vastria)<strlen(averba)+5)
                  {fprintf (exdo, "%s\n", vstria); 
                                   // Proba, si u ge-detekti verba sati 
                                   // a-nu!: 
                   if (!strcmp(vastria, averba) 
                       || strlen(vastria)==strlen(averba)+1 
                       || (strlen(vastria)==strlen(averba)+2 
                          && (vastria[strlen(vastria)-2]=='e'
                             || vastria[strlen(vastria)-2]=='y'))) 
                                   // U ge-detekti verba feno fo boni 
                                   // gru.  Seqe-co sto cerka.  
                     {strcpy(va2stria, vastria); 
                                   // Pre ki retro, cerka plu English 
                                   // homo-verba ('homonyms'). 
                      while  
                       (lista.getline(vstria, MLONGI, '\n') 
                        && lista.getline(vastria, MLONGI, '\n') 
                        && lista.getline(nvs, MLONGI, '\n') 
                        && !strcmp(va2stria, vastria))
                          {fprintf (exdo, "%s\n", vstria);};  
                                   // Ki retro!: 
                      return;}; 
                   m1 = 1;
                  }; 
               } 
              else              
               {apofini(vastria);
                if (!strcmp(vastria, averba)) 
                                   // Ja, u gru verba pa gene detekti. 
                 {fprintf (exdo, "%s\n", vstria); 
                  m1 = 1;} 
               }; 
             }; 
          }; 
       }; 
    }; 
                                   // Printa "???"-info; si verba ne pa 
                                   // pote gene detekti!: 
  if (!m1) 
    {fprintf (exdo, "  ????? %s ... ne pa pote detekti. \n", verba);}; 
                                   // Ki versi!: 
  return; 
} 

void facvas()                      // Face verba-lista auxi-stria! 
{ 
  unsigned char i1 = 0;            // index 
  unsigned char i2 = 0;            // index 
  unsigned char m1 = 0;            // memo-valu 

  strcpy(vastria, vstria); 

  i1 = 0; 
  while(vastria[i1]!='\0') 
    { 
                                   // Kopi plu litera!: 
     vastria[i1] = vstria[i1]; 
                                   // Fini de laevo mero: 
     if (vstria[i1]==' ' && vstria[i1+1]==' ') 
       {vastria[i1+1]='\0'; vastria[i1]='\0'; m1=0;}; 
     i1++; 
    }; 
                                   // Destru plu adi-info 1+*GX!: 
  if (strstr(vastria, " ") !=NULL) 
    {i1 = strlen(vastria)-1; 
     m1=0; 
     do 
       {if (vastria[i1]!='G' 
            && vastria[i1]!='+' 
            && vastria[i1]!='1' 
            && vastria[i1]!='*' 
            && vastria[i1]!='X') 
              {m1=1;};
        i1--;} 
     while (vastria[i1]!=' '); 
     if (!m1) {vastria[i1]='\0';}; 
    }; 
                                   // Sorta plu "[]"-parentesi!: 
  parentesi(); 
                                   // Apo plu "{...}"-parentesi!:  
  i1 = 0; i2 = 0; m1 = 0; 
  while(vastria[i2]!='\0') 
    {if (vastria[i2]=='{') {m1=1;}; 
     if (!m1) {vastria[i1]=vastria[i2]; i1++;}; 
     if (vastria[i2]=='}') {m1=0;}; 
     i2++; 
    }; 
  vastria[i1]='\0'; 
                                   // Muta plu mega ad-in pusi litera 
                                   // e adi bi space-litera peri id!: 
  strcat(vastria, "  "); 
  i1 = strlen(vastria)-1; i2 = i1-1; 
  while(i1) 
    {vastria[i1]=mutal(vastria[i2]); 
     i1--; 
     i2--; 
    }; 
  vastria[0]=' '; 
                                   // Muta plura space-litera ad-in 
                                   // solo mo space-litera! 
                                   // Numera plu verba per "nv"!: 
  i1=0; i2=0; nv=-1; 
  while(vastria[i2]!='\0') 
    {vastria[i1]=vastria[i2]; 
     i2++; 
     if (vastria[i1]==' ') 
       {nv++; 
        while (vastria[i2]==' ') {i2++;}; 
       }; 
     i1++; 
    }; 
  vastria[i1]='\0'; 
} 

char mutal(const char x)           // Muta plu litera!: 
{ 
  char y = '\0'; 
                                   // Muta mega litera a pusi litera!: 
                                   // (64+1=A, 91-1=Z.) 
  if (x>64 && x<91) {y=x+32;} 
  else 
                                   // Plu pusi litera debi sta.: 
                                   // (96+1=a, 
                                   // const ASCz = 123, 123-1 = z)
    {if (x>96 && x<ASCz) {y=x;} 
                                   // Plu hetero litera debi gene 
                                   // space.: 
                                   // (Nota: Ci pe nece adi plu ra te 
                                   // uti speciali litera, homo plu 
                                   // Francais akcento !!!)
       else {y=32;}; 
    }; 
  return y; 
} 

void parentesi()                   // Sorta plu parentesi []! 
{ 
  char           dextro[MLONGI] = ""; 
  char           laevo[MLONGI]  = ""; 
  char           yverba[MLONGI] = ""; 
  unsigned char  i1 = 0; 
  unsigned char  ir = 0; 
  unsigned char  il = 0; 
  unsigned char  m1 = 2; 

  while (i1<strlen(vastria)) 
    {if (vastria[i1]=='[') 
       {m1=1; 
       } 
     else 
       {if (vastria[i1]==']') 
         {m1=2; 
          if (vastria[i1+1]==' ' && dextro[strlen(dextro)-1]==' ') 
            {ir--;}; 
         } 
        else 
          {if (m1==1) {laevo[il]=vastria[i1]; il++;} 
           else       {dextro[ir]=vastria[i1]; ir++;}; 
          }; 
       }; 
     i1++; 
    }; 

  laevo[il]='\0'; dextro[ir]='\0'; 
                                   // Evita supraflu space-litera " " 
                                   // ad inter-loka laevo-dextro!: 
  if (vastria[0]==' ') 
    {if (dextro[0]==' ') 
       {i1=0; 
        do 
          {dextro[i1]=dextro[i1+1];} 
        while (dextro[i1++]!='\0'); 
       }; 
    }; 

  strcpy (yverba, laevo); 
  strcat (yverba, dextro); 
                                   // Si "vastria" proto ko ' '; plus 
                                   // "yverba" nece proto ko ' '.: 
  if (vastria[0]==' ' && yverba[0]!=' ') 
    {strcpy (dextro, yverba); 
     strcpy (yverba, " "); 
     strcat (yverba, dextro); 
    }; 
                                   // Dona "yverba" homo "vastria" 
                                   // retro!: 
  strcpy(vastria, yverba); 
} 

void takocerka()                   // Tako cerka plu verba! 
{ 
  char  averba[MLONGI] = "";       // auxi-verba 
  char  nvs[MLONGI] = "0";         // C-string ko numera de verba. 
  char  m1 = 0;                    // memo-valu 

                                   // Face auxi-verba "averba"! 
                                   // Id habe bi " " peri "verba". 
  strcpy(averba, " "); 
  strcat(averba, verba); 
  strcat(averba, " "); 
                                   // Cerka proto litera in lista!: 
  lista.seekg(loka[mutal(averba[1])]); 
  lista.clear(); 
                                   // Cerka verba!: 
  m1 = 0; 
  while(!m1) 
   { 
                                   // Gene neo verba ex verba-"lista"!: 
    lista.getline(vstria, MLONGI, '\n'); 
    lista.getline(vastria, MLONGI, '\n'); 
    lista.getline(nvs, MLONGI, '\n'); 
                                   // Proba; si verba pa gene detekti!: 
    if (strstr(vastria, averba)!=NULL) 
      {if (nvs[0]=='1') 
                                   // "vastria" habe solo mo verba.: 
          {fprintf (exdo, "%s\n", vstria); 
           m1 = 1; 
           return; 
          }; 
      }; 
                                   // Fini u cerka a fini de lista!: 
    if (!lista) {m1=1;}; 
                                   // Fini u cerka; si neo proto-litera 
                                   // pa proto!: 
    if (mutal(vstria[0])>averba[1]) {m1=1;}; 
                                   // Si ne sucede: grafo info e ki 
                                   // ab retro!: 
    if (m1) 
      {fprintf (exdo, "  ????? %s ... ne pa pote tako detekti. \n", 
         verba);
       return; 
      }; 
   }; 
} 

