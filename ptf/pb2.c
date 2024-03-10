#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define path "cuvinte.txt"

int nrvoc(char *s)
{
  int voc = 0, i;
  for (i = 0; i < strlen (s); i++)
	{
	  if ((strchr ("aeiouAEIOU", s[i])) != NULL)
		{
		  voc++;
		}

	}
  return voc;
}

int lungime (char *s)
{
  return strlen(s);
}

int litere (char *s)
{
  int litMari = 0;
  for (int i = 0; i < strlen (s); i++)
	{
	  if (isupper (s[i]))
		litMari++;
	}
  return litMari;
}

int diferenta (char *s)
{
  return s[0] - s[strlen (s) - 1];
}



int main (int argc, char **argv)
{
  int (*pf[]) (char *) = { lungime, nrvoc, litere, diferenta };
  
  FILE *fout=NULL;
  if((fout=fopen(path,"w"))==NULL)
  {
      printf("Eroare la deschidere\n");
      perror(NULL);
  }

  for (int i = 1; i < argc; i++)
	{
	    //printf("%s\n", argv[i]);
	  fprintf (fout,"%d %d %d %d\n", pf[0] (argv[i]),pf[1] (argv[i]),pf[2] (argv[i]),pf[3] (argv[i]));
	  
	}
  fclose(fout);
  return 0;
}
