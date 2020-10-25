---
title: Glosalist archives 2003—2019
layout: page
---

{%- assign postsByYear = site.pages | where: "layout", "email" | sort: "postDate" | group_by_exp:"email", "email.postDate | date: '%B %Y'"  -%}
{%- assign YearLinks = site.pages | where: "layout", "email" | sort: "postDate" | group_by_exp:"email", "email.postDate | date: '%Y'"  -%}
Fast links: {% for year in YearLinks | sort  %}<a href="#{{ year.name }}">{{ year.name }}</a>&ensp;
{%- endfor -%}

{% for year in postsByYear | sort  %}
<h2 id="{{ year.name | slice: -4,4 }}">{{ year.name }}</h2>
<span>
{%- for spage in year.items -%}
<span style="border: 15px;background: beige;padding: 15px;vertical-align: super;margin: 15px;display: inline-block;box-shadow: 5px 11px 20px 5px #a48888;"><a href="{{ spage.url | prepend: site.baseurl }}">{{ spage.title | replace: "] ", "]<br>"}}</a><br><span style="font-family:sans-serif;">{{ spage.authorName }}</span><br>on <span style="font-family:sans-serif;font-size:smaller;">{{ spage.postDate | date:   "%-d %b %Y" }}</span></span>&ensp;
{%- endfor -%}
</span>
{%- endfor -%}

