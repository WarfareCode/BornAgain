#!/usr/bin/env python3

import glob, sys

fworst = ""
lworst = 0
totlin = 0
totbad = 0
nftot = 0
nfbad = 0

flist = sys.argv[1:]
for fn in flist:
    # read in
    fd = open( fn, 'r' )
    txt = fd.read().split( '\n' )
    fd.close

    n = len(txt)
    maxlen = 0
    maxwhere = -1
    nbadlin = 0
    for i in range(n):
        l = len(txt[i])
        if l>maxlen:
            maxlen = l
            maxwhere = i
        if l>85:
            nbadlin += 1

    if nbadlin>0:
        print( "%s: %i/%i lines too long, line %i longest with %i chars" %
               (fn, nbadlin, n, maxwhere, maxlen) )

        totbad += nbadlin
        nfbad += 1
    totlin += n
    nftot += 1
    if maxlen>lworst:
        lworst = maxlen
        fworst = fn

if nftot>0:
    print( "total: %i/%i lines too long, in %i/%i files, longest in %s with %i chars" %
           (totbad, totlin, nfbad, nftot, fworst, lworst) )
    sys.exit(1)
sys.exit(0)
