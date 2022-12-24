// 14. ������ ������. ����� ������������� ����������� ������ (����� ���� ��������� 20 �������).
// ����� ������� ������� ������ �� ��� ������, ������������� ����� �������������, ����������� �����
// ���������� �����, ��������� �� ����� ����������� ������, ����� ������� (������ �����). 
// ���������� �������� � ������ ������ ������ ����.

#include <iostream>
#include <mpi.h>
#include <windows.h>

int main(int argc, char** argv) {

	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	srand((unsigned int)time(0) * rank);

	int crypt_shard = rand();
	int* crypt;
	crypt = (int*)malloc(size * sizeof(int));

	printf("Rank %d, Size %d, Crypt shard %d\n", rank, size, crypt_shard);
	
	MPI_Comm_spawn("a.out", MPI_ARGV_NULL, np, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &intercomm, errcodes);
	MPI_Bcast(&crypt_shard, 1, MPI_INT, crypt, 1, MPI_INT, MPI_COMM_WORLD);
	//MPI_Allgather(&crypt_shard, 1, MPI_INT, crypt, 1, MPI_INT, MPI_COMM_WORLD);
	
	printf("Local Crypt: ");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", crypt[i]);
	}
	printf("\n\n");
	MPI_Finalize();
}