\
\
\

Glosatra - u pusi puta-me programa pro Glosa
============================================

\
\
\

Glosatra eqa pusi puta-me programa; qi auxi translati ex English ad
Glosa e retro: id simpli cerka plu verba de ali textu in verba-lista.

\

### Plu puta-me dokumenta

Tu pote detekti plu seqe dokumenta in zip-dokumenta
[\>\>glosatra.zip\<\<](http://www.glosa.org/dat/glosatra.exe):

  ------ ---------------- ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
         `glosatra.exe`          (programa; qi funktio per MS-DOS/Windows, 181 kB. Id funktio per Win95. Pe dice a mi: id funktio plus per Windows NT, e ko limita per Win98. La tu ne pote dona plu optio. Mi ne pote repara id; kausa mi ne habe Win98. Penite.)
         `glosatrb.exe`          (un hetero (mei boni) MS-Win-versio, 144 kB. Uti id per `glosatrb` alo muta nomina de id.)
         `glosatre.exe`          (e ankora un hetero MS-Win-version, 181 kB. U-ci funktio vice: `glosatre` pro English-Glosa e `glosatre -e` pro Glosa-English. Per u-ci, pe pote uti u direkti English ad Glosa plus per Win98.)
         `glosatra`              (programa; qi funktio per Linux, 30 kB)
         `glosatra.cc`           (fonta programa-textu, 29 kB)
  ------ ---------------- ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Tu plus nece habe plu dokumenta [\>\>`engl.txt`\<\<](../gid/engl.txt)
(verba-lista English-Glosa) e [\>\>`glen.txt`\<\<](../gid/glen.txt)
(verba-lista Glosa-English).

\

### Plu qalita de programa

-   Glosatra eqa primitive komanda-stria programa pro konsola. Id ne
    habe plu menu, id ne pote uti mus, id habe nuli pikto e nuli hetero
    tali ra.
-   Id pote \"translati\" Glosa-English e English-Glosa.
-   Id detekti plu verba, verba-fa e kompositi ko e minus hifem (\"-\")
    in verba-lista (plu ultima ra ne ko `-t` optio).
-   Id tenta dona sugesti, klu si fini-vokali de Glosa-verba in textu
    habe falsi (ne ko `-t` optio).
-   Id tenta rekogni plu English verba, klu si mu ne habe norma forma
    (ne ko `-t` optio).
-   Id ne face difere de mega e pusi litera.
-   Id pote uti panto-tem u maxi-neo versio de [Glosa Inter-Reti
    Diktionaria](../gid/index.html), nu-fu kata-kargo mu (vide supra).
-   Kargo e uti, - ne komplexi instala; kausa id habe fo simpli.
-   Id funktio per MS-DOS/Windows e Linux. Id sura pote funktio plus per
    hetero sistema. U fonta programa-textu gene ofere, vide supra.
-   Id pote uti plu norma in/ex-kanali (standard-I/O). Seqe-co id pote
    gene proto alo gene uti ex plu hetero programa, klu in
    textu-editora-programa.
-   Id es gratis.
-   Id ne pretende; id habe nuli ero alo id es profesionali alo komodi.
-   Penite de u-ci stupidi ero: un in-dokumenta nece fini ko
    space-litera, koma, punkta alo stria-fini-litera. Hetero-co tu sio
    lose un ultima verba.

\

### Instala e uti

-   Tu habe u programa; qi funktio in tu sistema; plu verba-lista
    dokumenta `glen.txt` e `engl.txt` e tu Glosa textu `intextu.txt`; qi
    eqa simpli ASCII textu-dokumenta; in direktori; tu es in \[qi\] (alo
    ali-lo; qi-lo tu sistema pote detekti plu-la dokumenta).\
    Po-co proto u konsola alo DOS-fenestra e tipo\

            glosatra intextu.txt extextu.txt 
          

    Tu textu ko verba-lista fu es in dokumenta `extextu.txt`. Tu pote
    lekto id per editora-programa alo rekti epi skuta\

            more extextu.txt. 
          

-   Tu pote vide auxi-skuta ko `-i`:\

            glosatra -i
          

    (A MS-Win/DOS, tu pote invoka plu optio plus ko \"/\", per exempla
    `glosatra /i`.)\
    \

-   Translati in hetero direkti, English ad-in Glosa, funktio ko `-e`:

            glosatra -e intextu.txt extextu.txt
          

-   Si tu volu uti hetero verba-lista dokumenta, prende `-d`-optio:\

            glosatra -d:midiktionaria.txt intextu.txt extextu.txt
          

    Tu pote tenta translati ex e ad-in plu hetero lingua kon u-ci optio,
    si tu sio habe verba-lista dokumenta ko formati; qi pote gene lekto
    ex Glosatra. Sed place nota; Glosatra ne pote manu speciali litera e
    tu posi detekti nuli verba; si tu plu lingua habe poli inflexio.\
    \

-   Si tu dokumenta es in hetero direktori, tu pote nomina mu, sura.
    Exempla:\

            c:\dir1\glosatra.exe -d:c:\dir2\glen.txt c:\dir3\intext.txt c:\dir4\extextu.txt
          

-   Glosatra habe lento, sed ko `-t`-optio, tu fu gene ma tako e mei
    ex-textu; qi plus posi pote gene examina ma facili:\

            glosatra -t intextu.txt extextu.txt
          

-   Tu pote uti norma ex-kanali (standard output) e vide plu ex-ra
    direkti alo tu direkti plu ex-ra ad dokumenta. Alo tu elekti plus
    norma in-kanali (standard input), exempla\

            echo " ... solo pusi textu ... "|glosatra 
          

    e tu uti Glosatra in pipa, ostraka-programa (shell script), alo ex
    alo in hetero programa.\
    \

-   Alo \"inter-akti\": Po\

            glosatra
          

    alo \-- pro English \--

            glosatra -e
          

    simpli tipo in tu textu. Po singu \<Return\>, tu fu gene u
    verba-lista. Fini u programa ko \<Control\>-`C`.\
    \

-   Tu pote uti Glosatra klu per textu-editora-programa. Exempla ko
    editora **Emacs** (
    [www.gnu.org/software/emacs/emacs.html](http://www.gnu.org/software/emacs/emacs.html)
    alo [www.xemacs.org](http://www.xemacs.org)):\
    Kargo textu ad-in memo-me ko \"`emacs intext.txt`\", marka bloka; tu
    volu translati; ko \<Control\>-\<Space\> e plu indika-ra-klavi.
    Po-co tipo \"\<Alt\>-`x   shell-command-on-region` \<Return\>\", e
    po prompti \"`:`\" tipo \"`glosatra`\". U ex-ra de Glosatra fu gene
    monsta in neo fenestra. Ko \"\<Alt\>-`1`\" pre \"\<Alt\>-x
    `shell-command-on-region: glosatra`\" u ge-marka textu fu gene versi
    ex plu ex-ra de Glosatra.

\

### Exempla de plu ex-ra:

Po

      echo "Nu tu pote uti tu puta-me te cerka plu verba. " | glosatra 

tu fu gene:


    GLOSATRA, u pusi programa te auxi translati Glosa.  Optio -i pro info.

    "Nu tu pote uti tu puta-me te cerka plu verba. "
    ------------------------------
    nu 1++           now; present; present {now}; present {tense}; up-to-date
    tu 1++           you {singular}; your {singular}; thou
    pote 1++         able; can; capable; may
    uti 1++          use; employ; treatment; useful
    tu 1++           you {singular}; your {singular}; thou
    puta 1++         calculate; compute; idea; reckon; think; thought; trim {v}
    me[-] {short affix form of mekani} 1++  device; mechanism
    puta-me 1++      computer
    puta-me sporta 1  computer game
    te {short form of tende} 1+  aim; deliberate; in order to; intend; intention; intentional; object {purpose}; purpose; tend; tendency
    te[-] {short affix form of textili} 1+  cloth; fabric; textile
    cerka 1++        grope; quest; look for; search; seek
    plu 1++          s[-] {plural sign}; more than one; plural; some
    verba 1++        word
    ==============================

\

### Plu hetero programa

Modela pro Glosatra pa es u programa ex Charles Ganson (1999, meno 10).
Mali-fortuna id feno, id ne du es in inter-reti.

Un hetero programa es
[Glosaread](http://www.eikepreuss.de/glosa/glosaread.shtml), ge-grafo ex
[Eike Preuß](http://www.eikepreuss.de), kron meno 11, 2005. Id suporta
mus e GUI-fenestra. Id funktio per MS-Windows e Linux.

"Ernobe" pa grafo plu
[programa](http://www.costarricense.cr/pagina/ernobe/proglosa.htm) per
[Icon-lingua](http://www.cs.arizona.edu/icon/), 2006 meno 11.

\

### Reporta plu ero ad autori

Si tu habe textu dokumenta; qi pote krasc u programa, place bali id ad
mi ad ![\[E-grama-adresa homo PNG-imagi\]](../pic/emailm.png){width="47"
height="20"}glosa.org. Id sio es gluko; si tu grafo a mi; si tu uti
Glosatra ko plu hetero lingua alo per hetero puta-me sistema. Place ne
protesta de mi programa-stilo alo plu facia; tu este minus. Gratia de tu
visita u-ci pagina.

\

Marcel Springer, [www.glosa.org](../index.html), 2002-08-07 \...
2012-07-31

\
\
