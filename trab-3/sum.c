#include <stdio.h>
#include <stdlib.h>

#define MAX 20010

int main(){
	int i, n, aux, global_begin = -1, global_end = -1, begin = -1, end = -1, min = 0, actual_sum = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &aux);
		end = i;
		if(actual_sum + aux >= 0){
			actual_sum = 0;
			begin = i;
			continue;
		}
		if(actual_sum + aux < min){
			min = actual_sum + aux;
			global_begin = begin;
			global_end = end;
		}
		actual_sum += aux;
	}
	printf("min=%d, inicio%d, fim=%d\n", min, global_begin+1, global_end);
	return 0;
}