---
title: Dictionary English-Glosa
layout: post
published: true
lexicon: true
---

{% marginnote '1' '**Vocabularies**: `++` “Core”, `+` “Basic”, “`1`” Glosa-1000 list.<br>**Origin**: “`G`” Greek origin, “`*`” primary lexicon extension, “`1*`” deviatiion from “`1`”, “`X`” to avoid, prefer the lexeme in brackets (=...).<br>`adj` adjective, `n` noun, `v` verb.<br>[History of modification](gidhist.htm). Contributors: Wendy Ashby, Paul Bartlett, Ron Clark, Charles Ganson, Robin Gaskell, Nick Hempshall, Gary Miller, William Patterson, Kevin Smith, Marcel Springer. Date: 2013-04-30.' %}English-Glosa Reti Diktionaria. [Ki a Glosa-English](glen).

<input type="text" id="lexiconInput" onkeyup="lexiconInput()" placeholder="Search..." title="Type in a word">

<div class="table-wrapper"><table id="lexicon">
  <tr class="header"><th><strong>English</strong></th><th><strong>Glosa</strong></th></tr>
{% for row in site.data.lexicons.engl %}<tr><td>{{ row["english"] }}</td><td>{{row["glosa"]}}</td></tr>{% endfor %}
</table></div>
