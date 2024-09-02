#include <iostream>
#include <vector>

using namespace std;

int power(int base, int exponent) {
    int result = 1;

    // Handle negative exponents
    if (exponent < 0) {
        std::cout << "Negative exponents are not supported." << std::endl;
        return 0; // Returning 0 to indicate an error; handle appropriately
    }

    // Compute the power using a loop
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}

int* convert(int number)
{

    int* arr = new int[8];

    for(int i = 0 ; i < 8 ; i ++)
    {
        arr[7-i] = number%2;
        number = number /2;
        
    }

    return arr;




}

int main() {
    
int number_of_char;
number_of_char = 16;
int size = number_of_char+1;

int number_of_table;

if((size - 1)%8 == 0)
{
    number_of_table = (size - 1)/8;
}
else
number_of_table = (size - 1)/8+1;


unsigned char c[17] = {210,208,222,157,64,190,223,0,8,1,6,2,1,15,7,0};

unsigned char* a=   c;


int count =0 ; 

  int *p[8][number_of_table];

for(int j = 0; j < number_of_table ; j ++){
   for(int i =0 ; i < 8 ; i++)
   {
    p[i][j]= convert(a[count]);
    count ++; 
    
   }
}

for(int k = 0 ; k < number_of_table ; k ++ ){

   for(int i = 0 ; i < 8 ; i ++)
   {

    for(int j = 0 ; j < 8 ; j ++)
    {
        cout<<*(p[i][k]+j)<<" ";


    }
    cout<<endl;

   }
   cout<<"--------------"<<endl;
   }
    cout<<endl<<endl;

int q[8][8][number_of_table];

for(int k = 0 ; k < number_of_table ; k ++)
    {
        for(int i = 0; i < 8 ; i++)
    {
        for(int j =0 ; j < 8 ; j++)
        {
            q[7-j][7-i][k] = *(p[i][k]+j);
        }
    }
    }



for(int k = 0 ; k < number_of_table ; k ++)
{
    for(int i = 0; i < 8 ; i++)
    {
        for(int j =0 ; j < 8 ; j++)
        {
            cout<< q[i][j][k]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}


cout<<endl;

int final[8][8][number_of_table];

//convert to int 

for(int k = 0 ;k < number_of_table ; k ++)
{
for(int i = 0 ; i < 8 ; i ++)
{
    for (int j =0 ; j < 8 ;j ++)
    {

final[i][j][k] = q[i][j][k] - '0'+48;
    }
}
}
int final2[8][number_of_table] ;

for(int k = 0 ; k < number_of_table ; k ++)
{
    for(int i = 0 ; i < 8 ; i ++)
    {
        final2[i][k] =0;
    }
}

for(int k = 0 ; k < number_of_table ; k ++)
{
    for(int i = 0 ; i < 8 ; i ++)
    {
        for (int j =0 ; j < 8 ;j ++)
    {

        final2[i][k] +=(final[i][j][k] * power(2,7-j));


    }
    }
}

for(int k = 0 ; k < number_of_table ; k ++)
{
    for(int i = 0 ; i < 8 ; i ++)
    {
        cout<<final2[i][k] <<endl;
    }
}


char final3[8][number_of_table];

for(int k = 0 ; k < number_of_table ; k++)
{
    for(int i =0 ; i < 8 ; i ++)
    {
        final3[i][k] = static_cast<char>(final2[i][k]);
        cout<<final3[i][k]; //display the results, could be deleted
    }
}

}
