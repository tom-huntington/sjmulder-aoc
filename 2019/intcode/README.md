intcode
=======

**intcode** [**-v**] *code* [*input*]

AoC intcode interpreter. **-v** causes instructions, inputs and outputs
to be printed. *code* and *input* must be files or `-` for standard
input. Standard input is also used if *input* is omitted.

Example
-------

    $ echo 5 | ./intcode -v input.day05
       0: 00003 in    [225]                 ;                 ->       5
       2: 00001 add   [225],  [  6],  [  6] ;       5,   1100 ->    1105
       6: 01105 jt        1,    238         ;       1,    238
     238: 01105 jt        0,  99999         ;       0,  99999
     241: 01105 jt      227,    247         ;     227,    247
     247: 01005 jt    [227],  99999         ;       0,  99999
     250: 01005 jt    [  0],    256         ;       3,    256
     256: 01106 jf      227,  99999         ;     227,  99999
     259: 01106 jf        0,    265         ;       0,    265
     265: 01006 jf    [  0],  99999         ;       3,  99999
     268: 01006 jf    [227],    274         ;       0,    274
     274: 01105 jt        1,    280         ;       1,    280
     280: 00001 add   [225],  [225],  [225] ;       5,      5 ->      10
     284: 01101 add     294,      0,  [  0] ;     294,      0 ->     294
     288: 00105 jt        1,  [  0]         ;       1,    294
     294: 01106 jf        0,    300         ;       0,    300
     300: 00001 add   [225],  [225],  [225] ;      10,     10 ->      20
     304: 01101 add     314,      0,  [  0] ;     314,      0 ->     314
     308: 00106 jf        0,  [  0]         ;       0,    314
     314: 01007 jt    [226],    226,  [224] ;     677,    226 ->       0
     318: 01002 mul   [223],      2,  [223] ;       0,      2 ->       0
     322: 01006 jf    [224],    329         ;       0,    329
     329: 00008 eq    [226],  [677],  [224] ;     677,    226 ->       0
     333: 01002 mul   [223],      2,  [223] ;       0,      2 ->       0
     337: 01005 jt    [224],    344         ;       0,    344
     340: 01001 add   [223],      1,  [223] ;       0,      1 ->       1
     344: 00107 jt      226,  [677],  [224] ;     226,    226 ->       0
     348: 01002 mul   [223],      2,  [223] ;       1,      2 ->       2
     352: 01006 jf    [224],    359         ;       0,    359
     359: 00008 eq    [677],  [677],  [224] ;     226,    226 ->       1
     363: 01002 mul   [223],      2,  [223] ;       2,      2 ->       4
     367: 01005 jt    [224],    374         ;       1,    374
     374: 01108 eq      226,    226,  [224] ;     226,    226 ->       1
     378: 01002 mul   [223],      2,  [223] ;       4,      2 ->       8
     382: 01005 jt    [224],    389         ;       1,    389
     389: 00007 jt    [677],  [226],  [224] ;     226,    677 ->       1
     393: 01002 mul   [223],      2,  [223] ;       8,      2 ->      16
     397: 01005 jt    [224],    404         ;       1,    404
     404: 00007 jt    [226],  [226],  [224] ;     677,    677 ->       0
     408: 00102 mul       2,  [223],  [223] ;       2,     16 ->      32
     412: 01006 jf    [224],    419         ;       0,    419
     419: 01108 eq      226,    677,  [224] ;     226,    677 ->       0
     423: 00102 mul       2,  [223],  [223] ;       2,     32 ->      64
     427: 01005 jt    [224],    434         ;       0,    434
     430: 01001 add   [223],      1,  [223] ;      64,      1 ->      65
     434: 01107 jt      226,    226,  [224] ;     226,    226 ->       0
     438: 01002 mul   [223],      2,  [223] ;      65,      2 ->     130
     442: 01006 jf    [224],    449         ;       0,    449
     449: 01007 jt    [677],    677,  [224] ;     226,    677 ->       1
     453: 00102 mul       2,  [223],  [223] ;       2,    130 ->     260
     457: 01006 jf    [224],    464         ;       1,    464
     460: 01001 add   [223],      1,  [223] ;     260,      1 ->     261
     464: 00107 jt      226,  [226],  [224] ;     226,    677 ->       1
     468: 01002 mul   [223],      2,  [223] ;     261,      2 ->     522
     472: 01005 jt    [224],    479         ;       1,    479
     479: 01107 jt      677,    226,  [224] ;     677,    226 ->       0
     483: 01002 mul   [223],      2,  [223] ;     522,      2 ->    1044
     487: 01005 jt    [224],    494         ;       0,    494
     490: 01001 add   [223],      1,  [223] ;    1044,      1 ->    1045
     494: 01008 eq    [677],    677,  [224] ;     226,    677 ->       0
     498: 00102 mul       2,  [223],  [223] ;       2,   1045 ->    2090
     502: 01005 jt    [224],    509         ;       0,    509
     505: 00101 add       1,  [223],  [223] ;       1,   2090 ->    2091
     509: 00107 jt      677,  [677],  [224] ;     677,    226 ->       0
     513: 00102 mul       2,  [223],  [223] ;       2,   2091 ->    4182
     517: 01005 jt    [224],    524         ;       0,    524
     520: 01001 add   [223],      1,  [223] ;    4182,      1 ->    4183
     524: 01108 eq      677,    226,  [224] ;     677,    226 ->       0
     528: 01002 mul   [223],      2,  [223] ;    4183,      2 ->    8366
     532: 01005 jt    [224],    539         ;       0,    539
     535: 01001 add   [223],      1,  [223] ;    8366,      1 ->    8367
     539: 00007 jt    [226],  [677],  [224] ;     677,    226 ->       0
     543: 00102 mul       2,  [223],  [223] ;       2,   8367 ->   16734
     547: 01006 jf    [224],    554         ;       0,    554
     554: 00008 eq    [677],  [226],  [224] ;     226,    677 ->       0
     558: 01002 mul   [223],      2,  [223] ;   16734,      2 ->   33468
     562: 01006 jf    [224],    569         ;       0,    569
     569: 00108 eq      226,  [226],  [224] ;     226,    677 ->       0
     573: 01002 mul   [223],      2,  [223] ;   33468,      2 ->   66936
     577: 01006 jf    [224],    584         ;       0,    584
     584: 01107 jt      226,    677,  [224] ;     226,    677 ->       1
     588: 01002 mul   [223],      2,  [223] ;   66936,      2 ->  133872
     592: 01006 jf    [224],    599         ;       1,    599
     595: 00101 add       1,  [223],  [223] ;       1, 133872 ->  133873
     599: 01008 eq    [226],    226,  [224] ;     677,    226 ->       0
     603: 00102 mul       2,  [223],  [223] ;       2, 133873 ->  267746
     607: 01005 jt    [224],    614         ;       0,    614
     610: 01001 add   [223],      1,  [223] ;  267746,      1 ->  267747
     614: 01007 jt    [226],    677,  [224] ;     677,    677 ->       0
     618: 01002 mul   [223],      2,  [223] ;  267747,      2 ->  535494
     622: 01006 jf    [224],    629         ;       0,    629
     629: 00108 eq      677,  [226],  [224] ;     677,    677 ->       1
     633: 00102 mul       2,  [223],  [223] ;       2, 535494 -> 1070988
     637: 01005 jt    [224],    644         ;       1,    644
     644: 01008 eq    [226],    677,  [224] ;     677,    677 ->       1
     648: 01002 mul   [223],      2,  [223] ; 1070988,      2 -> 2141976
     652: 01005 jt    [224],    659         ;       1,    659
     659: 00108 eq      677,  [677],  [224] ;     677,    226 ->       0
     663: 01002 mul   [223],      2,  [223] ; 2141976,      2 -> 4283952
     667: 01006 jf    [224],    674         ;       0,    674
     674: 00004 out   [223]                 ; 4283952        
     676: 00099 hlt                                                
    4283952