---
title: Glosatra - ein kleines Computerprogramm für Glosa
layout: post
published: true
date: 2018-10-11
---  
  
  



  
  
  

Glosatra ist ein kleines Computerprogramm, das dabei hilft, von Glosa
nach Englisch oder umgekehrt zu übersetzen, indem es einfach die Wörter
in einer Wörterbuchdatei nachschlägt.

  

### Dateien

In dem zip-Archiv [\>\>glosatra.zip\<\<](../dat/glosatra.zip) sind
folgende Dateien enthalten:

|  |                |  |                                                                                                                                                                                                                                                                          |
|  | -------------- |  | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
|  | `glosatra.exe` |  | (Glosatra, unter MS-DOS/Windows ausführbare Version, 181 kB. Läuft unter Win95, angeblich auch unter Windows NT und eingeschränkt unter Win98, dort könne man aber keine Optionen angeben. Ich kann es leider nicht reparieren, da ich kein Win98 habe. Entschuldigung.) |
|  | `glosatrb.exe` |  | (eine weitere (schwächere) MS-Win-Version, 144 kB. Aufruf mit `glosatrb` oder umbenennen.)                                                                                                                                                                               |
|  | `glosatre.exe` |  | (und noch eine MS-Win-Version, 181 kB. Diese verhält sich genau anders herum: `glosatre` für Englisch-Glosa und `glosatre -e` für Glosa-Englisch. Damit kann man die Richtung Englisch nach Glosa auch unter Win98 nutzen.)                                              |
|  | `glosatra`     |  | (unter Linux ausführbare Version, 30 kB)                                                                                                                                                                                                                                 |
|  | `glosatra.cc`  |  | (Quellcode, 29 kB)                                                                                                                                                                                                                                                       |

Außerdem benötigen Sie noch die Dateien
[\>\>`engl.txt`\<\<](../gid/engl.txt) (Wörterbuchdatei Englisch-Glosa)
und [\>\>`glen.txt`\<\<](../gid/glen.txt) (Wörterbuchdatei
Glosa-Englisch).

  

### Eigenschaften

  - Glosatra ist ein primitives Kommandozeilenprogramm für die Konsole.
    Es hat keine Menüs, Mausunterstützung, Grafik oder ähnliches.
  - Es "übersetzt" Glosa-Englisch und Englisch-Glosa.
  - Das Programm findet Wörter, Wortgruppen und Zusammensetzungen mit
    und ohne Bindestrich in den Wörterlisten (letzte Dinge nicht mit
    `-t`-Option).
  - Es versucht einen Vorschlag zu machen, auch wenn der Schlussvokal
    des Glosaworts im Text falsch ist (nicht mit `-t`-Option).
  - Es versucht englische Wörter zu erkennen, selbst wenn sie nicht in
    der Grundform vorliegen (nicht mit `-t`-Option).
  - Groß- und Kleinschreibung werden vernachlässigt.
  - Es kann die jeweils neueste Version des [Glosa Internet
    Dictionarys](../gid/index.html) verwendet werden, - einfach
    herunterladen, s. o.
  - Laden und laufen lassen, - keine komplizierte Installation wegen
    seiner Einfachheit.
  - Es läuft unter MS-DOS/Windows und Linux. Andere Plattformen sind
    sicher auch möglich. Der Quellcode steht oben zur Verfügung.
  - Es kann die Standard-I/O-Kanäle nutzen. So kann es von einem anderen
    Programm aus gestartet und genutzt werden, sogar innerhalb eines
    Texteditors.
  - Es ist kostenlos.
  - In keiner Weise beansprucht es, fehlerfrei, professionell oder
    komfortabel zu sein.
  - Entschuldigung für diesen dummen Fehler: Die Eingabe-Datei muss mit
    einem Leerzeichen, einem Komma, Punkt oder einem „Return“ enden.
    Andernfalls verliert man das letzte Wort.

  

### Installation und Anwendung

  - Sie haben das unter Ihrem System ausfürbare Programm, die
    Wörterlistendateien `glen.txt` und `engl.txt` und Ihre
    Glosa-Textdatei `intext.txt`, eine einfache ASCII-Textdatei, in dem
    Verzeichnis, in dem Sie gerade arbeiten (oder irgendwo, wo Ihr
    System diese Dateien findet).  
    Dann starten Sie die Konsole oder ein DOS-Fenster und geben ein  
    
    ``` 
        glosatra intext.txt outtext.txt 
      
    ```
    
    Ihr Text mit einer Vokabelliste wird dann in der Datei `outtext.txt`
    abgelegt. Sie können sie mit einem Editor oder direkt auf dem
    Bildschirm lesen mit  
    
    ``` 
        more outtext.txt. 
      
    ```

  - Mit `-i` erhalten Sie einen Hilfebildschirm:  
    
    ``` 
        glosatra -i
      
    ```
    
    (Bei MS-Win/DOS können die Optionen auch mit "/" angesteuert werden,
    also z. B. `glosatra /i`.)  
      

  - Um in die andere Richtung, also Englisch nach Glosa, zu übersetzen,
    verwenden Sie bitte `-e`:
    
    ``` 
        glosatra -e intext.txt outtext.txt
      
    ```

  - Wenn Sie eine andere Wörterlistendatei verwenden wollen, nehmen Sie
    die `-d:`-Option:  
    
    ``` 
        glosatra -d:meinevokliste.txt intext.txt outtext.txt
      
    ```
    
    Sie können versuchen, von und nach anderen Sprachen mit dieser
    Option zu übersetzen, wenn Sie eine Wörterlistendatei in einem
    Glosatra-lesbaren Format hätten. Aber bedenken Sie bitte, dass keine
    Sonderzeichen unterstützt werden und dass es schwierig wird,
    überhaupt etwas zu finden, wenn die Sprachen viele Flexionen
    haben.  
      

  - Wenn Ihre Dateien in anderen Verzeichnissen liegen, können Sie das
    natürlich angeben, z. B.:  
    
    ``` 
        c:\dir1\glosatra.exe -d:c:\dir2\glen.txt c:\dir3\intext.txt c:\dir4\outtext.txt
      
    ```

  - Glosatra ist langsam, aber mit der `-t`-Option erhalten Sie eine
    schnellere und weniger Ausgabe, die vielleicht sogar übersichtlicher
    ist:  
    
    ``` 
        glosatra -t intext.txt outtext.txt
      
    ```

  - Sie können den Standardausgabekanal nutzen und die Ausgabe direkt
    lesen oder sie in eine Datei umleiten. Oder sie wählen auch
    Standardeingabe, z. B.  
    
    ``` 
        echo " ... solo pusi textu ... "|glosatra 
      
    ```
    
    und wenden Glosatra in einer Pipe, einem Shell-Skript oder durch
    oder innerhalb eines anderen Programms an.  
      

  - Oder interaktiv: Geben Sie nach  
    
    ``` 
        glosatra
      
    ```
    
    bzw. für Englisch
    
    ``` 
        glosatra -e
      
    ```
    
    einfach einen Text ein. Nach jedem \<Return\> erhalten Sie eine
    Vokabelliste. Das Programm wird dann mit \<Control\>-`C` beendet.  
      

  - Man kann Glosatra sogar innerhalb eines Texteditors nutzen. Zum
    Beispiel mit dem Editor **Emacs** (
    [www.gnu.org/software/emacs/emacs.html](http://www.gnu.org/software/emacs/emacs.html)
    oder [www.xemacs.org](http://www.xemacs.org)):  
    Laden Sie Ihren Text in den Speicher mit "`emacs intext.txt`",
    markieren Sie den Block, den Sie übersetzen wollen mit
    \<Control\>-\<Space\> und den Cursortasten. Dann tippen Sie ein
    "\<Alt\>-`x shell-command-on-region` \<Return\>", und nach dem
    Prompt "`:`" dann "`glosatra`". Glosatras Ausgabe wird dann in einem
    neuen Fenster dargestellt. Mit "\<Alt\>-`1`" vor "\<Alt\>-x
    `shell-command-on-region: glosatra`" wird der markierte Text durch
    Glosatras Ausgabe ersetzt.

  

### Beispiel einer Ausgabe:

Nach

``` 
  echo "Nu tu pote uti tu puta-me te cerka plu verba. " | glosatra 
```

erhalten Sie:

``` 

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
```

  

### Ähnliche Programme

Vorbild für Glosatra war ein Programm von Charles Ganson (Oktober 1999),
das leider nicht mehr im Internet verfügbar zu sein scheint.

Ein weiteres Programm ist
[Glosaread](http://www.eikepreuss.de/glosa/glosaread.shtml), geschrieben
von [Eike Preuß](http://www.eikepreuss.de), November 2005. Es
unterstützt Maus und GUI-Fenster und läuft unter MS-Windows und Linux.

„Ernobe” schrieb
[Programme](http://www.costarricense.cr/pagina/ernobe/proglosa.htm) in
der [Icon-Sprache](http://www.cs.arizona.edu/icon/), November 2006.

  

### Fehlerreport an den Autor

Wenn Sie eine Textdatei haben, die das Programm zum Absturz bringt,
senden Sie sie mir bitte unter ![\[E-mail-Adresse als
PNG-Grafik\]](../pic/emailm.png)glosa.org. Ich würde mich freuen, wenn
Sie mir mitteilen, wenn Sie Glosatra mit anderen Sprachen oder auf
anderen Rechnersystemen anwenden. Bitte schreiben Sie keine Beschwerden
über meinen Programmierstil oder über den Funktionsumfang. Danke für
Ihren Besuch auf dieser Seite.

  

