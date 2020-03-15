#include <iostream>
#include <mpi.h>
#include <chrono>


using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){

	int processRank, processSize;
	auto startTime = high_resolution_clock::now();
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &processRank);
	MPI_Comm_size(MPI_COMM_WORLD, &processSize);
	MPI_Barrier(MPI_COMM_WORLD);
	int firstNumber,lastNumber;
	
	if(processRank == 0){
		cout<<"Enter the first number to sum from: ";
		cin>>firstNumber;
		cout<<"Enter the last number: ";
		cin>>lastNumber;
	}
	
	int sum = 0;
	for(int x=firstNumber; x<=lastNumber; x++){
		sum += x;
	}
	if(processRank == 0){
		cout<<"The sum from "<<firstNumber<<" to "<<lastNumber<<" is = "<<sum<<endl;
	}
	MPI_Barrier(MPI_COMM_WORLD);
	
	MPI_Finalize();
	auto endTime = high_resolution_clock::now();
	auto executionTime = duration_cast<milliseconds>(endTime-startTime);
	if(processRank ==0){
		cout<<"Execution Time is "<<executionTime.count()<<" milliseconds"<<endl;
	}
	
	return 0;
}