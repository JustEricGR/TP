#include<stdio.h>
#include<string.h>

typedef enum{
    ADUNARE,
    SCADERE,
    INMULTIRE,
    IMPARTIRE
}operatie;

int main(int argc,char **argv)
{
    int opt=0;
    float rez=0;
    operatie o;
    for(int i=1;i<argc;i++)
    {
        int n=0;

        if(i%2!=0)
        {
            sscanf(argv[i],"%d",&n);
            switch(o)
            {
                case ADUNARE:
                {
                    rez+=n;
                    break;
                }
                case SCADERE:
                {
                    rez-=n;
                    break;
                }
                case INMULTIRE:
                {
                    rez*=n;
                    break;
                }
                case IMPARTIRE:
                {
                    rez/=n;
                    break;
                }
            }
        }
        
        else
        {
            if(!strcasecmp(argv[i],"add"))opt=0;
            else if(!strcasecmp(argv[i],"sub"))opt=1;
            else if(!strcasecmp(argv[i],"mult"))opt=2;
            else if(!strcasecmp(argv[i],"div"))opt=3;
            o=opt;
            
            
        }

        
    }

    printf("rezultatul este:%f\n",rez);

}

