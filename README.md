# BK_Tree_Spell_Check

Hi welcome to my Github Page. This document is a brief summary of my BK tree algorithm used for spell checking.
This project is a part of my Data Structures course's final project.

BK Trees are data structures that help in spell checking. Burkhard and Keller
proposed them for the first time in 1973. This approach improves the temporal
complexity of numerous string matching operations by utilizing two very simple
notions.

In our words dictionary we have about 112815 words which we use to build the BK tree
and calculate the Levenshtein distance. So if the user wishes to check if a word
exists in the dictionary, they can enter option ’1’ and enter the word. If the
word is present the same will be printed as output

In general, the BK Tree will have a depth of log n, where n is the size of the dictionary. At each level, we
visit two nodes in the tree and compute the edit distance between them. As a
consequence, our Time Complexity is O(L1*L2*log n), where L1 is the average
length of a word in our dictionary and L2 is the length of misspelled words. L1
and L2 are frequently small.
