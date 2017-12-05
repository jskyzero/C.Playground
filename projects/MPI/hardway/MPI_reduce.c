// 对于数据做同一种操作，并将结果返回到指定的进程中，这个过程称为集合通信。

#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	int myid, numprocs;
	double local_num = 3.0; 

	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    
    double global_num;
    
    // 强烈安利使用linux 毕竟有补全
    MPI_Reduce(&local_num, &global_num, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    
    if(myid == 0) {
    	printf("Total sum = %f, avg = %f\n", global_num, global_num / numprocs);
	}

	MPI_Finalize();
	return 0;
}
