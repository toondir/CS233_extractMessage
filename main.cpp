#include <stdio.h>
#include<iostream>

using namespace std;



int main ()
{


    unsigned char* b = new unsigned char[16];

    b[0] = 210;
    b[1] = 208;
    b[2] = 222;
    b[3] = 157 ;
    b[4] = 64 ;
    b[5] = 190;
    b[6] = 223;
    b[7] = 0 ;
    b[8] = 8;
    b[9] = 1;
    b[10] = 6;
    b[11] =2 ;
    b[12] =1 ;
    b[13] = 15; 
    b[14] = 7 ;
    b[15] = 0;


    unsigned char* out  = new unsigned char[16];


for (int block = 0; block < 16; block += 8)
    {
        unsigned char *a = new unsigned char[8];
        for (int i = 0; i < 8; i++)
            a[i] = 0;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                a[j] = (b[j+block]>>i)<<(7);
                out[i+block] |= a[j]>>(7-j);
            }
        }
    }
  

  for(int i = 0 ; i < 16 ; i++)
  {
    cout<<out[i] ;
  }
  cout<<endl;

  return 0;

}