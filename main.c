/*
	You can find the theory of the calculating results in this on work article.
	https://medium.com/@tp4460/theory-developed-on-the-collatz-conjecture-on-work-79442e447240
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2000

int main(void)
{

	int e16=0;
	int tot_print = 0;
	int enter_point;
	int great_s = 0;
	int sep = 0;
	int bound = 2;
	int delta;
	int sr;	//succesor.
	int l, h, w;
	int p, q; // p = L(n), q = H(n).
	int tmp;
	int sigma;
	int diff;
	printf("n\tl(n)\tT(n)\tLTn\tW\tDelta\tSigma\t   \tEntryPoint\n");
	int sr_b = 0;

	for (int i = 5; i < N; i+=2) {
	//for (int i = 3; i < N; i+=2) {
		sigma = 0;	
		sr = 3*i+1;	
		tmp = i;

		while(tmp != 1) {
		
			if(tmp%2) {
				tmp = 3*tmp+1;
			/*	Storing the entry point in the power of two series of a number */
				for(int h = 16; h <= tmp; h*=2) {
				
					if(h==tmp) {
						enter_point = tmp;

						if(enter_point == 16)
							e16++;	
						break;
					}
				}
			}	
			else {
				tmp /=2;
			
						
			}
			sigma++;
		}

		for(p = 2; p < i; p*=2)	
			;
		if(p>i)
			p = p/2;
	
		for(q = 2; q < sr ; q*=2)	
			;	
		if( q == sr)
			;
		else if(q> sr)
			q = q/2;
	
		w = sr -q;		
	
		delta = w - p;
		diff = (delta - sr_b )/2;
		sr_b = delta;
		printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", i, p, sr, q, w, delta, sigma, diff, enter_point);
		tot_print++;
			
		sep++;
		

		if(sigma > great_s) {
			great_s = sigma;
		}	
		if(sep == bound ) {
			putchar('\n');	
			bound = bound * 2;
			sep = 0;
		}	
	}
	printf("Greater Sigma value: %d\n",great_s);
	printf("Total printed: %d\n",tot_print);
	printf("Entered at 16: %d  \t%4.2f%\n",e16,( (double)e16/(double)tot_print) * 100);
	return (0);
}
