# Goal

Our goal is to create three levels of nested ordered lists, with the
top level using the numeric style ("1"), the second level using the
alphabetic style ("a"), and the third level using the roman numeral
style ("i").

# Makrdown Ordered Lists

First, we try to use four-space indentation with ordered lists in markdown.

1. Number "1"

    a. Letter "a".

    b. Letter "b"

2. Number "2"

    a. Letter "a"

        i. Roman numeral "i".  Notice how this renders as a code block rather than doing a word wrap at the appropriate place.  This makes this text hard to read.  But at least the number style is correct.

        ii. Roman numeral "ii".

    b. Letter "b"

        i. Roman numeral "i".

        ii. Roman numeral "ii".

# CSS Styles for Github-Generated HTML

As explained in a [stackoverflow thread[(https://stackoverflow.com/questions/51956361/custom-css-file-for-readme-md-in-a-github-repo),
Github does not allow custom CSS files to modify the HTML generated from
markdown.

# HTML Ordered Lists

We now try embedding HTML in the Markdown, since the
[stackoverflow thread[(https://stackoverflow.com/questions/51956361/custom-css-file-for-readme-md-in-a-github-repo)
explains that some style can be done using this method.
It explains:

> this is documented in the [github/Markup](https://github.com/github/markup)project (specifically step 2). They used to link to the code, but they are apparently using something different now, which is not public. As per [#1246](https://github.com/github/markup/issues/124://github.com/github/markup/issues/1246) the list of allowed elements and attributes is [here](https://gist.github.com/kivikakk/622b5dcf395e26c49e2334f0eb19e6f9).

The last link claims that "type" is supported on the "ol" tag, and
the [W3C site](https://www.w3schools.com/tags/tag_ol.asp) explains
that the "type" attribute on the "ol" tag specifies the numbering style.

<ol type="A"> <!-- "a" works here -->
  <li>One
    <ol type="a"> <!-- this is forced to roman, "1" doesn't work -->
      <li>This is the first sub-bullet.</li>
      <li>This is the second sub-bullet.</li>
    </ol>
  </li>
  <li>Two
    <ol type="i">
      <li>This is the first sub-bullet.</li>
      <li>This is the second sub-bullet.</li>
  </ol>
  </li>
  <li>Three
    <ol type="A">
      <li>Alpha
        <ol type="I">
          <li>Uno</li>
          <li>Dos</li>
        </ol>
      </li>
      <li>Bravo
        <ol type="i">
          <li>Uno</li>
          <li>Dos</li>
        </ol>
      </li>
      <li>Charlie
        <ol type="i">
          <li>Uno</li>
          <li>Dos</li>
        </ol>
      </li>
    </ol>
  </li>
  <li>Four
    <ol type="a">
      <li>Alpha
        <ol type="i">
          <li>Uno</li>
          <li>Dos</li>
        </ol>
      </li>
      <li>Bravo
        <ol type="i">
          <li>Uno</li>
          <li>Dos</li>
        </ol>
      </li>
    </ol>
  </li>
</ol>
