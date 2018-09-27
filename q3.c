#include<mpi.h>
#include<stdio.h>
int main(int argc,char** argv){
	
int rank,size,outgoing,incoming;
	
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
		if(rank==0){
			scanf("%d",&outgoing);
			printf("Root node sends %d to all others\n",outgoing);

		}
	
	MPI_Bcast(&outgoing,1,MPI_INT,0,MPI_COMM_WORLD);
	printf("\n %d is the value received by process %d",outgoing,rank);
	
	MPI_Finalize();
}
