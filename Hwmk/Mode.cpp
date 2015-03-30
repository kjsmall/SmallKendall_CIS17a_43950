// Kendall Small

using namespace std;
#include<iostream>
#include<iomanip>
#include<ctime>

int mean(int *, int);
int median(int *, int);
int *mode(int *, int);
int *sort(int *, int);
void *printAry(int *, int);
int *fillAry(int *, int);

int main()
{
    int me, med, mod;
    const int SIZE = 28;
    int *set = new int[SIZE]; 
    int *getsize = new int[1];
    
    set=fillAry(set, SIZE);
    printAry(set, SIZE);
    cout<<endl<<endl;
    set=sort(set, SIZE);
    printAry(set, SIZE);
    cout<<endl<<endl;
    
    me = mean(set, SIZE);
    
    med = median(set, SIZE);

    int *modes = mode(set, SIZE);
    cout<<"The number of modes is: "<<modes[0]<<endl;
    cout<<"The max frequency of modes is: "<<modes[1]<<endl;
    for(int i=2;i<(modes[0] + 2);i++)
    {
    	cout<<modes[i]<<" ";
	}
	cout<<endl;
    system("PAUSE");
    return 0;
}

int *fillAry(int *set, int SIZE)
{
    for(int i=0;i<SIZE;i++)
            set[i] = i % 10;
    return set;
}

int *sort(int *set, int SIZE)
{
    bool swap;
    do
    {
        swap = false;             
        for(int i=0;i<(SIZE - 1);i++)
        {
            if(set[i] > set[i + 1])
            {
                int temp = set[i];
                set[i] = set[i + 1];
                set[i + 1] = temp;
                swap = true;
            }
        }
        
    }while (swap);
    return set;
}

void *printAry(int *set, int SIZE)
{
     for(int i=0;i<SIZE;i++)
     {
             cout<<set[i]<<" ";
             if((i + 1) % 10 == 0)
                  cout<<endl;
     }
}

int mean(int *set , int SIZE)
{
    int count = 0;
    for(int i=0;i<SIZE;i++)
            count += set[i];
            
    count = count / (SIZE - 1);
    return count;
}

int median(int *set , int SIZE)
{
    bool swap;
    do
    {
        swap = false;             
        for(int i=0;i<(SIZE - 1);i++)
        {
            if(set[i] > set[i + 1])
            {
                int temp = set[i];
                set[i] = set[i + 1];
                set[i + 1] = temp;
                swap = true;
            }
        }
        
    }while (swap);
    
    
    return set[SIZE / 2];
}

int *mode(int *set, int SIZE)
{
    int freq = 0, max = 0;
    for(int i=0;i<SIZE;i++)
    {
            if(set[i] == set[i + 1])
            {
                freq++;
                if(freq>max)
                  max = freq;}
            else{
                freq = 0;
            }
    }
    
    // Mode counter
    int modeC = 0;
    freq = 0;
    for(int j=0;j<SIZE;j++)
    {
        if(set[j] == set[j + 1])
        {
            freq++;
            if(freq==max)
               modeC++;
        }    
        else
            freq = 0;
    }
    
    int* modes = new int [modeC + 2];
	int start = 2;
	modes[0] = modeC;
	freq = 0;
	for(int k=0; k<SIZE;k++) 
	{
		if(set[k] == set[k+1])
		{
			freq++;
			if(freq==max)modes[start++] = set[k]; }
		else freq=0;
	}
    modes[1] = ++max;    
    
    return modes;
}
                       
    
            
            
