# README

## Instructions

You are allowed to work in groups of up to 3 people to
complete this challenge. After you have completed the
challenge you must submit your work to Gradescope. To do
this you must download your code from repl.it. To do this
look for the three vertical dots to the left of this file
near the add folder icon. Clicking on this will allow you
to download your work as a zip file. You must submit that
zip file to the associated assignment in Gradescope.

## Problem 1

Define a structure to represent time (hours, minutes,
seconds). Then write a function elapsed_time that takes as
its arguments two time structures and returns a time 
structure that represents the elapsed time (in hours,
minutes, and seconds) between the two times. So
the call:

```
elapsed_time(time1, time2)
```

where `time1` represents 3:45:15 and `time2` represents
9:44:03, should return a time structure that represents
5 hours, 58 minutes, and 48 seconds. Be careful with 
times that cross midnight.

Write a test in your `main` function that shows that your
`elapsed_time` function works properly.

## Problem 2

Write a function called `removeString` to remove a
specified number of characters from a character string.
The function should take three arguments: the source
string, the starting index number in the source string,
and the number of characters to remove. So, if the
character array text contains the string
"the wrong son", the call

```
removeString (text, 4, 6);
```

has the effect of removing the characters “wrong” (the
word “wrong” plus the space that follows) from the array
text. The resulting string inside text is then "the son".

Write a test in your `main` function that shows that your
`removeString` function works properly.

Good Luck!