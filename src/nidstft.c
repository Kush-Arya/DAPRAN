#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>
#include<fftw3.h>
#include<getopt.h>
#include<string.h>
#include<ColumnRead.h>
#include<Windows.h>

const char* progname;
const struct option long_options[]={
  { "help", 0, NULL, 'h' },
  { "rectangle", 0, NULL, 'r' },
  { "triangle", 0, NULL, 't' },
  { "hamming", 0, NULL, 'm' },
  { "hann", 0, NULL, 'n' },
  { "genHamming", 1, NULL, 'H' },
  { "blackman", 0, NULL, 'b' },
  { "truncblackman", 0, NULL, 'T' },
  { "genbBlackman", 1, NULL, 'B' },
  { "WindowLength", 1, NULL, 'N' },
  { NULL, 0, NULL, 0}
};

void PrintUsage(FILE* Stream)
{
  fprintf(Stream,"Usage: %s options [ outfile ... ]\n",progname);
  fprintf(Stream,
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"
	  "-%c --%s \n"	  
	  "-%c --%s \n",
	  long_options[0].val,long_options[0].name,
	  long_options[1].val,long_options[1].name,
	  long_options[2].val,long_options[2].name,
	  long_options[3].val,long_options[3].name,
	  long_options[4].val,long_options[4].name,
	  long_options[5].val,long_options[5].name,
	  long_options[6].val,long_options[6].name,
	  long_options[7].val,long_options[7].name,
	  long_options[8].val,long_options[8].name,
	  long_options[9].val,long_options[9].name	  
	  );
  exit(1);
}

const char* const short_options = "hrtmnH:bTB:N:";
int main(int argn,char* args[])
{
  int next_option,Nw=256;
  double window[3]={0,0,0};
  progname = args[0];
  do{
    next_option = getopt_long(argn,args,short_options,long_options,NULL);

    switch(next_option){
    case 'h': PrintUsage(stderr); break;
    case 'r': window[0]=next_option; break;
    case 't': window[0]=next_option; break;
    case 'm': window[0]=next_option; break;
    case 'n': window[0]=next_option; break;
    case 'H': window[0]=next_option;
      sscanf(optarg,"%lf,%lf",&window[1],&window[2]); break;
    case 'b': window[0]=next_option; break;
    case 'T': window[0]=next_option; break;
    case 'B': window[0]=next_option;
      window[1] = atof(optarg); break;      
    case 'N': Nw = atoi(optarg); break;
    }
  }while(next_option!=-1);

  int n;
  for( n=-300;n<300;n++ )
    fprintf(stdout,"%d %f %f %f %f %f %f %f\n",n,(double)Rectangle(n-100,Nw),(double)Triangle(n-100,Nw),Hann(n-100,Nw),Hamming(n-100,Nw),TBlackman(n-100,Nw),EBlackman(n-100,Nw),GBlackman(n-100,Nw,.16));
  return 0;
}
