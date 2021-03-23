  
  
  

# Glosatra - A Little Computer Program for Glosa

  
  
  

Glosatra is a little computer program, that helps to translate from and
into Glosa by simply looking up the words of a text in a dictionary.

  

### Files

You will find the following files in the zip-archive
[\>\>glosatra.zip\<\<](../dat/glosatra.zip):

|  |                |  |                                                                                                                                                                                                                                     |
|  | -------------- |  | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  | `glosatra.exe` |  | (MS-DOS/Windows executable, 181 kB. Runs under Win95. I was told: it runs under Windows NT, too, and limited under Win98, there you cannot use options. I cannot fix it, because I haven't got Win98. Sorry.)                       |
|  | `glosatrb.exe` |  | (Another (inferior) MS-Win-version, 144 kB. Invoke with `glosatrb` or rename it.)                                                                                                                                                   |
|  | `glosatre.exe` |  | (Yet another MS-Win-version, 181 kB. This one behaves exactly the other way round: `glosatre` for English-Glosa and `glosatre -e` for Glosa-English. By means of this you can use the direction English to Glosa also under Win98.) |
|  | `glosatra`     |  | (Linux executable, 30 kB)                                                                                                                                                                                                           |
|  | `glosatra.cc`  |  | (source code, 29 kB)                                                                                                                                                                                                                |

You also need the files [\>\>`engl.txt`\<\<](../gid/engl.txt)
(dictionary English-Glosa) and [\>\>`glen.txt`\<\<](../gid/glen.txt)
(dictionary Glosa-English).

  

### Properties

  - Glosatra is a primitive command line program for the console. It has
    no menus, mouse support, graphics and things like that.
  - It can "translate" Glosa-English and English-Glosa.
  - The program finds words, word groups and compounds with and without
    hyphem in the dictionary (last things not with `-t` option).
  - It tries to give a suggestion even if the final vowel of the Glosa
    word in the text is wrong (not with `-t` option).
  - It tries to recognize English words, even if they are not in the
    basic form (not with `-t` option).
  - No case sensitivity: capitalization or not does not matter.
  - It can use always the latest version of the [Glosa Internet
    Dictionary](../gid/index.html), just download it above.
  - Load and run, - no complicated installation because of its
    simplicity.
  - Runs on MS-DOS/Windows and Linux. It could certainly run on other
    platforms, too. The source code is offered above.
  - It can use standard-I/O-streams. So it could be started and used by
    other programs, even within a text editor.
  - It is free of charge.
  - It does in no way claim to be errorfree, professional or
    comfortable.
  - Sorry for this silly bug: the input-file has to end with a space, a
    comma, a full stop or a line feed. Otherwise you will loose the last
    word.

  
  

### Installation and Usage

  - You have the executable program for your system, the dictionary
    files `glen.txt` and `engl.txt` and your Glosa textfile
    `intext.txt`, a plain ASCII textfile, in the directory you are
    actually working in (or somewhere, where your system can find these
    files).  
    Then start your console or a DOS-window and type in  
    
    ``` 
        glosatra intext.txt outtext.txt 
      
    ```
    
    Your text with a vocabulary list will then be in the file
    `outtext.txt`. You can read it with an editor or just on the
    screen  
    
    ``` 
        more outtext.txt. 
      
    ```

  - You can view a help screen with `-i`:  
    
    ``` 
        glosatra -i
      
    ```
    
    (On MS-Win/DOS you can call the options also with "/", e. g.
    `glosatra /i`.)  
      

  - Translating in the other direction, English to Glosa, works with
    `-e`:
    
    ``` 
        glosatra -e intext.txt outtext.txt
      
    ```

  - When you want to take another dictionary file, take the
    `-d:`-option:  
    
    ``` 
        glosatra -d:mydictionary.txt intext.txt outtext.txt
      
    ```
    
    You can try to translate from and into other languages with this
    option, if you would have a dictionary file in a Glosatra-readable
    format for it. But note, that no special characters are supported
    and that you will get problems to find anything if your languages
    have a lot of inflections.  
      

  - When your files are in other directories, you can specify them of
    course, e. g.  
    
    ``` 
        c:\dir1\glosatra.exe -d:c:\dir2\glen.txt c:\dir3\intext.txt c:\dir4\outtext.txt
      
    ```

  - Glosatra is slow, but with the `-t`-option, you will get faster and
    fewer output, which is easier to survey:  
    
    ``` 
        glosatra -t intext.txt outtext.txt
      
    ```

  - You can use standard output and view the output directly or you
    direct it to a file. Or you choose also standard input, e. g.  
    
    ``` 
        echo " ... solo pusi textu ... "|glosatra 
      
    ```
    
    and apply Glosatra in a pipe, a shell script or by or within another
    program.  
      

  - Or interactively: After  
    
    ``` 
        glosatra
      
    ```
    
    or - for English
    
    ``` 
        glosatra -e
      
    ```
    
    simply type in your text. After each \<Return\> you will get a
    vocabulary list. The program ends with \<Control\>-`C`.  
      

  - You can use Glosatra even within a text editor. For example with the
    editor **Emacs** (
    [www.gnu.org/software/emacs/emacs.html](http://www.gnu.org/software/emacs/emacs.html)
    or [www.xemacs.org](http://www.xemacs.org)):  
    Load a text into the buffer with "`emacs intext.txt`", mark the
    block you want to translate with \<Control\>-\<Space\> and the
    cursor keys. Then type "\<Alt\>-`x shell-command-on-region`
    \<Return\>", and after the prompt "`:`" type "`glosatra`".
    Glosatra's output will be displayed in a new window. With
    "\<Alt\>-`1`" before "\<Alt\>-x `shell-command-on-region: glosatra`"
    the marked text will be replaced by Glosatra's output.

  
  

### Sample output:

After

``` 
  echo "Nu tu pote uti tu puta-me te cerka plu verba. " | glosatra 
```

you get:

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

  
  

### Similar Programs

Model for Glosatra has been a program by Charles Ganson (October 1999).
Unfortunately it does not seem to be online any more.

Another program is
[Glosaread](http://www.eikepreuss.de/glosa/glosaread.shtml), written by
[Eike Preuß](http://www.eikepreuss.de), November 2005. It supports mouse
and GUI-windows. It works under MS-Windows and Linux.

“Ernobe” wrote
[programs](http://www.costarricense.cr/pagina/ernobe/proglosa.htm) using
the [Icon](http://www.cs.arizona.edu/icon/) language, November 2006.

  

### Reporting Bugs

When you have a text file, that crashes down the program, please send it
to me under ![\[E-mail address as
PNG-image\]](../pic/emailm.png)glosa.org. It would be great, if you tell
me, when you use Glosatra with other languages or on other systems.
Please do not complain about my programming style or missing features.
Thank you for visiting this website.

  

Marcel Springer, [www.glosa.org](../index.html), 2002-08-07
... 2013-02-27
