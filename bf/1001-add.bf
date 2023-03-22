,[>,] # read the first digit into cell 1 and the second digit into cell 2
++++++++ # set cell 3 to 8 (ASCII code for '0')
> # move to cell 2
[- # while the value in cell 2 is not zero
    < # move to cell 1
    + # add the value in cell 2 to the value in cell 1
    > # move to cell 2
    - # decrement the value in cell 2
] # end while loop
< # move to cell 1
. # print the result

