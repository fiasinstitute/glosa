---
title: Glosa Internet Dictionary English-Glosa
layout: post
published: true
---


<style>
* {
  box-sizing: border-box;
}

#myInput {
  background-image: url('/css/searchicon.png');
  background-position: 10px 10px;
  background-repeat: no-repeat;
  width: 100%;
  font-size: 16px;
  padding: 12px 20px 12px 40px;
  border: 1px solid #ddd;
  margin-bottom: 12px;
}

#myTable {
  border-collapse: collapse;
  width: 100%;
  border: 1px solid #ddd;
  font-size: 18px;
}

#myTable th, #myTable td {
  text-align: left;
  padding: 12px;
}

#myTable tr {
  border-bottom: 1px solid #ddd;
}

#myTable tr.header, #myTable tr:hover {
  background-color: #f1f1f1;
}
</style>
	

## Glosa Inter-Reti Diktionaria


Persons who have - more or less directly - worked on this file:	
Wendy Ashby (Glosa author), Paul Bartlett, Ron Clark (Glosa author),
Charles Ganson, Robin Gaskell, Nick Hempshall, Gary Miller,
William Patterson (former editor), Kevin Smith,
Marcel Springer (maintainer of this list, .

Date: 2013-04-30.

-----


Sources for the words have been several publications by Ronald Clark and
Wendy Ashby, © Glosa Education Organization (GEO, 35 Wingfield Road;
Kingston Upon Thames; Surrey KT2 5LR; ENGLAND), namely “Glosa Basic
Reference”, “English - Glosa 1000”, “English - Glosa 1000 classified”,
“Glosa 6000”, “18 Steps to Fluency in Euro-Glosa” (Glosa-English
list), “Central Glosa” (lists “5000 English to Glosa 1000” and “Useful
Prefixes”), “Français - Glosa 1000”, “Español - Glosa 1000” and others
and the friendly correspondence with Glosa author Wendy Ashby.

The Glosa Internet Dictionary has three levels. All are in this file:

	- “Literary”-dictionary (“Mega”, large)= all words.
	- “Basic”-dictionary (“Basi”, middle): its words are marked with “`+`”
	(or “`++`”).
	- “Core”-dictionary (“Centra”, small, with only most useful
	“Basic”-words): words are marked with “`++`”.

Suggestion: prefer `++`, then `+`.

Other abbreviations:	
“`G`” marks Glosa words with Greek origin.	
“`1`” marks Glosa 1000 words (words, that appear in one of the several
Glosa-1000-lists).	
“`*`” marks a word not original GEO (Clark/Ashby).	
“`1*`” means only a slight modification from a Glosa-1000-word.	
“`X`”-words should be avoided. The prefered synonym is in brackets
(=...).	
and: `adj` adjective, `n` noun, `v` verb.

See also history-file [www.glosa.org/gid/gidhist.htm](gidhist.htm).

<input type="text" id="myInput" onkeyup="myFunction()" placeholder="Search for names.." title="Type in a name">

<table id="myTable">
  <tr class="header"><th style="width:60%;">English</th><th style="width:40%;">Glosa</th></tr>
{% for row in site.data.lexicons.engl %}<tr><td>{{ row["english"] }}</td><td>{{row["glosa"]}}</td></tr>{% endfor %}
</table>

<script>
function myFunction() {
  var input, filter, table, tr, td, i, txtValue;
  input = document.getElementById("myInput");
  filter = input.value.toUpperCase();
  table = document.getElementById("myTable");
  tr = table.getElementsByTagName("tr");
  for (i = 0; i < tr.length; i++) {
    td = tr[i].getElementsByTagName("td")[0];
    if (td) {
      txtValue = td.textContent || td.innerText;
      if (txtValue.toUpperCase().indexOf(filter) > -1) {
        tr[i].style.display = "";
      } else {
        tr[i].style.display = "none";
      }
    }       
  }
}
</script>
