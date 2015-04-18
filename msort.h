#include <iostream>
#include <vector>
using namespace std;

template<class T,class Comparator>
void msort(vector<T>& mylist,vector<T>& output,int start, int end,Comparator comp)
{
    if(start>=end)return;
    int mid=(start+end)/2;
    msort(mylist,output,start,mid,comp);
    msort(mylist,output,mid+1,end,comp);
    cout<<"merging "<<start<<"  "<<mid<<"  "<<end<<endl;
    merge(mylist,output,start,mid+1,end,comp);
	for(int i=start;i<=end;i++)
	mylist[i]=output[i];
}

template<class T,class Comparator>
void mergeSort(vector<T>& myArray,Comparator comp)
{
    vector<T> other(myArray);
    msort(other, myArray, 0, (int)myArray.size()-1,comp);
}



template<class T,class Comparator>
void merge(vector<T>& mylist,vector<T>& output,int start, int mid,int end,Comparator comp)
{
    int temp=0,temp1=0,temp2=0;
    while(temp<=end-start)
    {

        //if (comp(mylist[start+temp1],mylist[mid+temp2]))
        while((start+temp1<=mid-1)&&(mid+temp2<=end))
    	{
        //if (mylist[start+temp1]<mylist[mid+temp2])
    		if (comp(mylist[start+temp1],mylist[mid+temp2]))
            {
                cout<<"swapped "<<start+temp<<" "<<start+temp1<<endl;
                output[start+temp]=mylist[start+temp1];
                temp1++;
                temp++;
            }
            else
            {
                cout<<"swapped "<<start+temp<<" "<<mid+temp2<<endl;
                output[start+temp]=mylist[mid+temp2];
                temp2++;
                temp++;
            }
        }

        while(start+temp1<=mid-1)
        	 {
                cout<<"swapped "<<start+temp<<" "<<start+temp1<<endl;
                output[start+temp]=mylist[start+temp1];
                temp1++;
                temp++;
            }
         while(mid+temp2<=end)
         {
         	cout<<"swapped "<<start+temp<<" "<<mid+temp2<<endl;
                output[start+temp]=mylist[mid+temp2];
                temp2++;
                temp++;
         }


    }

}
/*template<class T,class Comparator>
bool compare(T obj1,T obj2,Comparator comp)
{
	return comp(obj1,obj2);
}
*/

