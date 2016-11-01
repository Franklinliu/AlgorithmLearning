#include<iostream>
#include<cmath>
#include <sys/time.h>  
#include <iomanip>
#define LEFT(I) (2*I)
#define RIGHT(I) (2*I)+1
long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
} 
void gen(int A[],int len,int range)//exclude A[0],index 1,...,len; A[1],A[2],...,A[len]
{
	srand((int)getCurrentTime());
	for(int i=1;i<=len;i++)
	{
		A[i] = rand()%(range);
	}
}  
int heapsize; 
void gen(int A[], int len);
void print(int A[],int len);
void swap(int& a, int& b);
void MAX_HEAPIFY(int A[],int heapsize,int i);
void BUILD_MAX_HEAP(int A[],int len);
void HEAPSORT(int A[],int len);
void MAX_HEAPIFY(int A[],int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	if(l<=heapsize and A[l] > A[i])
		 largest = l;
	else
		 largest = i;
	 if(r<=heapsize and A[r] > A[largest])
	 {
		 largest = r;
	 }
	 if(largest!=i)
	 {
		 swap(A[i],A[largest]);
		 MAX_HEAPIFY(A,largest);
	 }
}
void BUILD_MAX_HEAP(int A[],int len)
{
	heapsize = len;
	for(int i=(len/2);i>=1;i--)
	{
		MAX_HEAPIFY(A,i);
	}
}
void HEAPSORT(int A[],int len)
{
	BUILD_MAX_HEAP(A,len);
	for(int i=len; i>=2;i--)
	{
		swap(A[1],A[i]);
		heapsize = heapsize -1;
		MAX_HEAPIFY(A,1);
	}
}
void swap(int&a, int&b)
{
	int temp = b;
	b = a;
	a = temp;
}

void print(int A[], int len)
{
	for(int i=1;i<=len;i++)
	{
		std::cout<<A[i]<<std::setw(3);
	}
	std::cout<<std::endl;
}
int main()
{
	int len = 10;
	int A[len+1];
	int range = len*5;
	gen(A,len,range);
	print(A,len);
    HEAPSORT(A,len);
	print(A,len);
}