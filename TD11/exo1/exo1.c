#include "trajet.h"

/*
				    THE CAKE IS A LIE

					,:/+/-
					/M/              .,-=;//;-
			.:/= ;MH/,    ,=/+%$XH@MM#@:
			-$##@+$###@H@MMM#######H:.    -/H#
		.,H@H@ X######@ -H#####@+-     -+H###@X
		.,@##H;      +XM##M/,     =%@###@X;-
		X%-  :M##########$.    .:%M###@%:
		M##H,   +H@@@$/-.  ,;$M###@%,          -
		M####M=,,---,.-%%H####M$:          ,+@##
		@##################@/.         :%H##@$-
		M###############H,         ;HM##M$=
		#################.    .=$M##M$=
		################H..;XM##M$=          .:+
		M###################@%=           =+@MH%
		@#################M/.         =+H#X%=
		=+M###############M,      ,/X#H+:,
		.;XM###########H=   ,/X#H+:;
			.=+HM#######M+/+HM@+=.
				,:/%XM####H/.
					,.:=-.
*/

int main(int argc, char **argv)
{
	Liste *l = initListe();

	/*
	promptTrajet(l);
	promptTrajet(l);
	promptTrajet(l);
	*/

	importTrajet(l, "trajet.txt");

	printf("%lf", distance(l));

	return 0;
}
