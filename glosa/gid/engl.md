---
title: Glosa Internet Dictionary English-Glosa
layout: post
published: true
lexicon: true
---

## Glosa Inter-Reti Diktionaria

The Glosa Internet Dictionary has three levels. All are in this file:

**Vocabularies**: `++` “Core”, `+` “Basic”, “`1`” Glosa-1000 list

**Origin**: “`G`” Greek origin, “`*`” primary lexicon extension, “`1*`” deviatiion from “`1`”, “`X`” to avoid, prefer the lexeme in brackets (=...).

`adj` adjective, `n` noun, `v` verb.

<input type="text" id="lexiconInput" onkeyup="lexiconInput()" placeholder="Search..." title="Type in a word">

<div class="table-wrapper"><table id="lexicon">
  <tr class="header"><th><strong>English</strong></th><th><strong>Glosa</strong></th></tr>
{% for row in site.data.lexicons.engl %}<tr><td>{{ row["english"] }}</td><td>{{row["glosa"]}}</td></tr>{% endfor %}
</table></div>


[History of modification](gidhist.htm). Contributors: Wendy Ashby, Paul Bartlett, Ron Clark, Charles Ganson, Robin Gaskell, Nick Hempshall, Gary Miller, William Patterson, Kevin Smith,
Marcel Springer. Date: 2013-04-30.
