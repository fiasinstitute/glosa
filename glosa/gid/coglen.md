---
title: Glosa Dictionary, 2000 most frequent words
layout: post
published: true
lexicon: true
---


<input type="text" id="lexiconInput" onkeyup="lexiconInput()" placeholder="Search..." title="Type in a word">

<div class="table-wrapper"><table id="lexicon">
  <tr class="header"><th><strong>Glosa</strong></th><th><strong>English</strong></th></tr>
{% for row in site.data.lexicons.gl2000 %}<tr><td>{{ row["glosa"] }}</td><td>{{row["english"]}}</td></tr>{% endfor %}
</table></div>
