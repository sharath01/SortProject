#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<vector>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;
static const int num_threads = 4;
std::mutex m;

void quick(vector<int> &data,int left,int right);
int partition(vector<int> &a,int left,int right);
void exch(vector<int> &data,int i,int j);

void sort(vector<int> & bar);
void mergeSort(vector<int>&left, vector<int>& right, vector<int>& bars);

void sort(vector<int> & bar)
{
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    vector<int> left;
    vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left);
    sort(right);
    mergeSort(left, right, bar);
}

void mergeSort(vector<int>&left, vector<int>& right, vector<int>& bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k])
        {
           bars[i] = left[j];
           j++;
        }
        else
        {
           bars[i] = right[k];
           k++;
        }
        i++;
    }

    while (j < nL)
    {
       bars[i] = left[j];
       j++; i++;
    }

    while (k < nR)
    {
       bars[i] = right[k];
       k++; i++;
   }
}

void quick(vector<int> &data,int left,int right)
{
    if (right <= left) return ;
    int pivot=partition(data,left,right);
    quick(data,left,pivot-1);
    quick(data,pivot+1,right);
}

int partition(vector<int> &a,int low,int high)
{
    int left=low;
    int right=high;
    int v=a[left];
    while(left<right)
    {
        while( a[left]<=v) left++;
        while(a[right]>v) right--;
        if (left<right)
              exch(a,left,right);
    }
    exch(a,low,right);
    return right;
}

void exch(vector<int> &data,int i,int j)
{
    int s=data[i];
    data[i]=data[j];
    data[j]=s;
}

vector<vector<string>> readInputFile(string inputFileName)
{
   vector<vector<string>> items;
   string item;

   ifstream inputFile(inputFileName);
   if(inputFile.is_open())
   {
       while(getline(inputFile,item))
       {
          vector<string> tempVec;
          for(auto it : item)
          {
             string s;s.clear();s.push_back(it);
             tempVec.push_back(s);
          }
          items.push_back(tempVec);
       }
       inputFile.close();
    }
    else
       cout<<"unable to input open";
   return items;
}

void writeToOutputFile(string alg,string outputfileName, vector<string> item)
{
    vector<int> tempVec;
    for(auto it : item)
    {
       if(it != " ")
       {
          tempVec.push_back(stoi(it));
       }
       else
       {
           this_thread::sleep_for (std::chrono::seconds(1));
       }
    }
   // sort
   if(alg == "quicksort")
   {
        quick(tempVec,0,tempVec.size()-1);
   }
   else if(alg == "mergesort")
   {
        sort(tempVec);
   }
   else
   {
      cout<<"invalid algorithm";
   }

   ofstream outputfile(outputfileName,std::ios_base::app);
   if(outputfile.is_open())
   {
      for(auto it:tempVec)
      {
         outputfile <<it<<",";
      }
      outputfile <<endl;
   }
   else
      cout<<"unable to open outputfile"<<endl;
}

int main(int argc, char* argv[])
{
   if(argc < 4)
   {
      cout<<"insufficient arguments passed"<<endl;
      return -1;
   }

   string inputFileName = argv[1];
   string outputFileName = argv[2];
   string alg = argv[3];

   vector<vector<string>> inputStreamVec = readInputFile(inputFileName);
   thread t[num_threads];
   int itemCount = inputStreamVec.size();
   int rotateCount = (itemCount/num_threads)+1;

   for(int i=0;i<rotateCount;++i)
   {
      if(!inputStreamVec[(i*4)].empty()) t[0] = thread(writeToOutputFile,alg,outputFileName,inputStreamVec[(i*4)]);
      if(!inputStreamVec[(i*4)+1].empty()) t[1] = thread(writeToOutputFile,alg,outputFileName,inputStreamVec[(i*4)+1]);
      if(!inputStreamVec[(i*4)+2].empty()) t[2] = thread(writeToOutputFile,alg,outputFileName,inputStreamVec[(i*4)+2]);
      if(!inputStreamVec[(i*4)+3].empty()) t[3] = thread(writeToOutputFile,alg,outputFileName,inputStreamVec[(i*4)+3]);

      for(int i=0;i<num_threads;++i)
      {
         if(t[i].joinable()) t[i].join();
      }
   }

   return 0;
}