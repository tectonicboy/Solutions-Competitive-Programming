#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	unsigned valid_count = 0, low = 0, high = 0, char_index = 0;
	char curr[256], testing = '0';
	for(unsigned i = 0; curr[0] != 'a'; ++i){
		memset(curr, '\0', 256);
		scanf("%u-%u %c: %[^\r\n]", &low, &high, &testing, curr);
		if(curr[0] != 'a'){
			if(((curr[low-1] == testing) && (curr[high-1] != testing)) || ((curr[low-1] != testing) && (curr[high-1] == testing))){
				++valid_count;
			}
		}
	}
	printf("Result: %u\n", valid_count);
}
