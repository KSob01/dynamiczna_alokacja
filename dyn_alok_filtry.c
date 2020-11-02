#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX (10 + 90)

void print(const size_t N, const int tab[]){
	for(int i = 0;i < N;++i){
		printf("%d%c", tab[i], i != N - 1? '\t' : '\n');
	}
}

void rand_fill(const size_t N, int* tab){
	for(int i = 0;i < N;++i)
		tab[i] = MIN + rand() / ((RAND_MAX + 1u) / (MAX-MIN+1));
}

int read(unsigned int* value){
	return scanf("%zu", value);
}

int main(){
	unsigned int seed;
	size_t N;
	

	if(!read(&seed)) return EXIT_FAILURE;

	srand(seed);

	if(!read(&N)) return EXIT_FAILURE;

	//if(scanf("%zu", &N) != 1) return EXIT_FAILURE;

	int *tab;

	tab = (int*) calloc(N, sizeof(*tab));

	if(tab == NULL) return EXIT_FAILURE;
	
	print(N, tab);
	
	rand_fill(N, tab);

	print(N, tab);

	free(tab);

	return 0;
}
