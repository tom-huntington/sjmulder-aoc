#!/usr/bin/env cbmbasic
1OPEN1,1,0,"data/01-input.txt"
2INPUT#1,A:N=N+1:IFST>0THENGOTO6
3IFN>1ANDA>BTHENP1=P1+1
4IFN>3ANDA+B+C>B+C+DTHENP2=P2+1
5D=C:C=B:B=A:GOTO2
6PRINTP1,P2
