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
			printf("Master sends %d\n",outgoing);
			MPI_Send(&outgoing,1,MPI_INT,1,1,MPI_COMM_WORLD);
		}
		if(rank==1){
			MPI_Recv(&incoming,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
			printf("%d received by slave",incoming);
		}
	MPI_Finalize();
	
}
