---
title: Interglossa and Glosa
layout: post
published: true
---

## Isolating planned language(s)


In his books «[The Loom of Language](http://gen.lib.rus.ec/book/index.php?md5=4058ACD459B2D713D79AEA991FCDCFDE)» (1944) and «[Interglossa]()» (1943), the British biologist and statistician [L.Hogben](https://en.wikipedia.org/wiki/Lancelot_Hogben) set a framework for a scientific communication (meta)language. Under a symbolic name «Interglossa» for this lingua franca, he formulated three principles that a candidate language should adhere to in order to become receivable as an [auxilary](https://en.wikipedia.org/wiki/International_auxiliary_language) language:
1. The grammar: [analytic](https://en.wikipedia.org/wiki/Analytic_language) or even [isolating](https://en.wikipedia.org/wiki/Isolating_language).
1. The lexicon:  internationalized.
1. The phonetics: facilitated (e.g. [Toki Pona](https://en.wikipedia.org/wiki/Toki_Pona)).

## Glosa, an unfinished product

Among other attempts within this framework (Interglossa ipso, L.Hogben 1943; Lingua (Sistem)Frater, Pham Xuan Thai 1957, Paul O. Barlett 1998), **Glosa is the most articulated project**. It was created as a modified version of the Interglossa, by
R.Clark and W.Ashby (1972,1992) and promoted by M.Springer
 
 on the basis sustained Interglossa 


This site tries to present the language Glosa, a Hogben's “Interglossa” variety, in a neutral  and systematic manner. 

<!---- Planned language activists are known for fanaticism when promoting their handicrafts, (biased) first-hand discourse is here:

[Glosa self praise]


[
[Glosa- [--*]   Place lekto info in       [Glosa_info_in_Glosa]_Glosa,        [Glosa_information_in
logo]]  English]_English,        [Glosa-Info_in_Deutsch]_Deutsch      alo
brevi_info in       [Glosa-Info_in_Español]_Castellano_(Español),        [Glosa-Info_in
Français]_Français,        [Glosa-Info_in_Italiano]_Italiano,        [Glosa-Info_in_Magyar]
Magyar,        [Glosa-Info_in_Nederlands]_Nederlands       alo      [Glosa-Info_in_Ruski]
Ruski.
   [Click_here_for_Glosa_information_in_English]
  ****** Glosa ******
  ***** es un internatio auxi-lingua. *****
                                                              
     Proto de pagina pa es 1996.
  Ultima muta pa es 2018-10-11.

  Marcel Springer, (adresa/Impressum, Datenschutzerklärung).


--->



Jekyll provides for both pages and posts in its default configuration. I have left this as-is.

{% newthought 'In this first iteration'%} of the _Tufte-Jekyll_ theme, a post and a page have exactly the same layout. That means that all the typographic and structural details are identical between the two.

## Pages and Posts

Jekyll provides for both pages and posts in its default configuration. I have left this as-is.

### Posts

Conceptually, posts are for recurring pieces of similar content such as might be found in a typical blog entry. Post content all sits in a `_posts` folder named `_posts` and files are created in this folder{% sidenote 1 'Yes, a page has essentially the same old shit as a post'%} that are names with a date pre-pended to the title of the post. For instance `2105-02-20-this-is-a-post.md` is a perfectly valid post filename.

Posts will always have a section above the content itself consisting of YAML front matter, which is meta-data information about the post{% sidenote post 'Please, be careful when moving boxes, you can hurt your back!' %}. Minimally, a post title must always be present for it to be processed properly.

    ---
    Title: Some Title
    ---
    ## Content
    
    Markdown formatted content *here*.

### Pages

Pages are any HTML documents _or_ Markdown documents with YAML front matter that are then converted to content. Page material is more suited to static, non-recurring types of content. Like this

I am not going to re-write the Jekyll documentation. Read it and you will figure out how the site is structured.
