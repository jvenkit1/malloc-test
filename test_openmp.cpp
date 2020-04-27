#include<iostream>
#include<omp.h>
#include<numeric>
#include<chrono>
using namespace std;

int requestSize[] = {16, 32, 64, 128};
int tid;
double startTime, endTime;

void runParallelRequests(int total_calls){
    int num_threads=4;
    int call_per_thread=total_calls/num_threads;
    startTime=omp_get_wtime();
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<num_threads;i++){
        #pragma parallel num_threads(calls_per_thread) private(tid)
        {
            tid=omp_get_thread_num();
            int reqSize = requestSize[tid%num_threads];
            auto ptr = malloc(reqSize);
            #pragma omp barrier
            free(ptr);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto time_taken = std::chrono::duration<double, std::milli>(end-start).count();
    cout<<"Total Time taken is "<<time_taken<<endl;

}

int main(){
    runParallelRequests(100000);
    return 0;
}