# Goal

Our requirement is to create three levels of nested ordered lists, with the
top level using the numeric style ("1"), the second level using the
alphabetic style ("a"), and the third level using the roman numeral
style ("i").

Among any ways to meet the above requirement, we also want it to display
as nicely as if it were HTML or PDF.

# Simon's test

1. Number "1"

a. Letter "a"

b. Letter "b"

i. Roman "i"

ii. Roman "ii"

2. Number "2"

# Markdown Custom Lists

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

Bottom line is this method does meet the strict requirement, but does not
meet our goal of displaying nicely so is considered as a last resort.

Let's now try other ways to do it.

# Markdown Ordered Lists

Next we'll see what the Github behavior is when just using whatever the
default ordered list styles are:

1. Number "1"

    1. Number "1" indented four spaces.  Notice that this automatically uses roman numerals, whereas we require letters at this level.

    2. Number "2" indented four spaces.

2. Number "2"

    1. Number "1" indented four spaces.

        1. Number "1" indented eight spaces.  Notice that this automatically uses letters, whereas we require roman numerals at this level.

        2. Number "2" indented eight spaces.

    2. Number "2" indented four spaces.

Since the resulting numbering styles do not meet the requirement, we cannot
use this method.

# CSS Styles for Github-Generated HTML

As explained in a [stackoverflow thread](https://stackoverflow.com/questions/51956361/custom-css-file-for-readme-md-in-a-github-repo),
Github does not allow custom CSS files to modify the HTML generated from
markdown.

# HTML Ordered Lists

We now try embedding HTML in the Markdown, since the
[stackoverflow thread](https://stackoverflow.com/questions/51956361/custom-css-file-for-readme-md-in-a-github-repo)
explains that some styling can be done using this method.
It explains:

> this is documented in the [github/Markup](https://github.com/github/markup) project (specifically step 2). They used to link to the code, but they are apparently using something different now, which is not public. As per [#1246](https://github.com/github/markup/issues/124://github.com/github/markup/issues/1246) the list of allowed elements and attributes is [here](https://gist.github.com/kivikakk/622b5dcf395e26c49e2334f0eb19e6f9).

The last link claims that "type" is supported on the "ol" tag, and
the [W3C site](https://www.w3schools.com/tags/tag_ol.asp) explains
that the "type" attribute on the "ol" tag specifies the numbering style.

Let's start with the top level being type "A":

<ol type="A">
  <li>This should be numbered "A".  Yes this works!  Let's now try using the same technique at the second level, to use letters:
    <ol type="a">
      <li>This should be numbered "a", but notice how it is instead forced to roman numerals.</li>
      <li>This should be numbered "b".</li>
    </ol>
  </li>
  <li>Let's try using type "I" for the following sub-bullets:
    <ol type="I">
      <li>This should be numbered "I", but it's instead forced to use lower case.</li>
      <li>This should be numbered "II".</li>
    </ol>
  </li>
  <li>Let's try using type "a" for the following sub-bullets:
    <ol type="a">
      <li>This should be numbered "a", but it's instead forced to use roman numerals.</li>
      <li>This should be numbered "b".</li>
    </ol>
  </li>
  <li>Let's try using type "1" for the following sub-bullets:
    <ol type="1">
      <li>This should be numbered "1", but it's instead forced to use roman numerals.</li>
      <li>Finally, let's try changing the style of the third level.  We'll start with trying roman numerals:
        <ol type="i">
          <li>This should be numbered "i".</li>
          <li>This should be numbered "ii".</li>
        </ol>
      </li>
      <li>Also try numerals ("1"):
        <ol type="1">
          <li>This should be numbered "1".</li>
          <li>This should be numbered "2".</li>
        </ol>
      </li>
    </ol>
  </li>
</ol>

Since the resulting numbering styles do not meet the requirement, we cannot
use this method either.

# Conclusion

Since none of the other methods meet the stated requirement,
that leaves us with the original poorly rendered style as the only
known method usable in Github.
