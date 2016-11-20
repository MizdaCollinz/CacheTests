/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int min(int first,int second){
    if (first < second){
        return first;
    } else {
        return second;
    }
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int M = 1000;
  unsigned int N = 256*1024; 
  unsigned int i,j,k,ii,jj,kk,l;
  double sum;

	
  /* declare variables; examples, adjust for task */
	double **a;
	double **b;
    double **c;
 
  
  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }

    
  /* allocate memory for arrays; examples, adjust for task */
	a = malloc (N * sizeof(double));
	b = malloc (N * sizeof(double));
	c = malloc (N * sizeof(double));
	for(i=0; i<N; i++){
		a[i] = malloc (N * sizeof(double));
		b[i] = malloc (N * sizeof(double));
		c[i] = malloc (N * sizeof(double));
	}

	 /* initialise array elements */
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            a[i][j] = 1.0;
            b[i][j] = 1.0;
            c[i][j] = 0.0;
        }
    }

  l=8; //Block size used for blocking calculation
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
    for (i=0; i<N; i+=l){
        for (j=0; j<N; j+=l){
           for(k=0; k<N; k+=l){
               for(ii=i;ii<min(i+(l),N);ii++){
                   for(jj=j; jj<min(j+(l),N);jj++){
                       for(kk=k; kk<min(k+(l),N);kk++){
                           c[ii][jj]= c[ii][jj] + a[ii][kk] * b[kk][jj];
                       }
                   }
               }
           }
        }
    }

  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",(t2 - t1));


  /* free memory; examples, adjust for task */
  free(a);
  free(b);
  free(c);

  return 0;  
}

