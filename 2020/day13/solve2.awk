#!/usr/bin/awk -f

BEGIN		{ RS="[,\n]"; step=1 }
NR>1 && /[^x]/	{ while ((t+NR-2) % $1) t += step;
		  step *= $1; }
		{ print NR, $1, t, step }
END		{ print t }
