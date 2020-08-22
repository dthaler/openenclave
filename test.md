**Title**

# Goal

Our goal is to create three levels of nested ordered lists, with the
top level using the numeric style ("1"), the second level using the
alphabetic style ("a"), and the third level using the roman numeral
style ("i").

# Makrdown Ordered Lists

First, we try to use four-space indentation with ordered lists in markdown.

1. Number "1"

    a. Letter "a".  Notice that github renders the second level using roman
       numerals, which is not what we want.

    b. Letter "b"

2. Number "2"

    a. Letter "a"

        i. Roman numeral "i".  Notice how this renders as a code block rather than doing a word wrap at the appropriate place.  This makes this text hard to read.

        ii. Roman numeral "ii".

    b. Letter "b"

        i. Roman numeral "i".

        ii. Roman numeral "ii".

# CSS Styles for Github-Generated HTML

As explained in a [stackoverflow thread[(https://stackoverflow.com/questions/51956361/custom-css-file-for-readme-md-in-a-github-repo),
Github does not allow custom CSS files to modify the HTML generated from
markdown.

# Makrdown Ordered Lists

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
