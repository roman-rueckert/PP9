/*gauss.h*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE *output_stream){



	double x1, x2, w, y1, rnd_number;
	static double y2;
	static int use_last = 0;

	if (use_last)
	{
		y1 = y2;
		use_last = 0;
	}
	else
	{
		do
		{
	     		x1 = 2.0 * ((double)rand() / (RAND_MAX)) - 1.0;
	     		x2 = 2.0 * ((double)rand() / (RAND_MAX)) - 1.0;
	     		w = x1 * x1 + x2 * x2;
	     	}
		while (w >= 1.0);

		w = sqrt((-2.0 * log(w)) / w);
		y1 = x1 * w;
		y2 = x2 * w;
		use_last = 1;
	}
	rnd_number=expected_value + y1 * std_deviation;
	printf("%f \n",rnd_number);
	output_stream=fopen("zufall.txt","a+");
	fprintf(output_stream, "%f \n",rnd_number);
	fclose(output_stream);
	return;
}
