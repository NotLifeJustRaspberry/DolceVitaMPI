// 14. Полная победа. Армия сопротивления захватывает города (всего надо захватить 20 городов).
// После захвата каждого города во все города, принадлежащие армии сопротивления, рассылается часть
// секретного шифра, найденная во вновь захваченном городе, через столицу (первый город). 
// Необходимо получить в каждом городе полный шифр.

#include <iostream>
#include <mpi.h>

const int CITY_AMOUNT = 20;

int main(int argc, char** argv) {
	int rank, size, len;
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Status status;
	srand((unsigned int)time(0));
	char sender[5] = { 97 + rand() % 25, 97 + rand() % 25 , 97 + rand() % 25 , 97 + rand() % 25 , 97 + rand() % 25 };

    MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	printf("Proc name %s, Rank %d, Size %d\n\n", proc_name, rank, size);

	if (rank == 0) {
		char crypt[100] = "";
		MPI_Gather(&sender, sizeof(sender), MPI_CHAR, &crypt, sizeof(sender), MPI_CHAR, 0, MPI_COMM_WORLD);
		MPI_Bcast(&crypt, sizeof(crypt), MPI_CHAR, 0, MPI_COMM_WORLD);
		printf("Crypt %s\n\n", crypt);
		}

	if (rank > 0 && rank <= 20) {
		//char sender[5] = { 97 + rand() % 25, 97 + rand() % 25 , 97 + rand() % 25 , 97 + rand() % 25 , 97 + rand() % 25 };
		char recv_crypt[100];
		MPI_Send(&sender, sizeof(sender), MPI_CHAR, 0, 5, MPI_COMM_WORLD);
		printf("Loc Crypt %s\n\n", sender);
		MPI_Recv(&recv_crypt, 100, MPI_CHAR, 0, 5, MPI_COMM_WORLD, &status);
		printf("Recv Crypt %s\n\n", recv_crypt);
	}
    MPI_Finalize();
}

//