#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){
	unsigned *nums;
	unsigned result = 0;
	char flags = 0b00000000;
	posix_memalign((void*)&nums, 64, 1000*sizeof(unsigned short));
	memset((void*)nums, 0x0, 1000*sizeof(unsigned short));
	for(unsigned short i = 0; !(flags | 0b00000000); ++i){
		scanf("%u", &nums[i]);
		if(nums[i] == 1){flags |= 0b00000001;}
	} 
	flags &= 0b00000000;
	for(unsigned short i = 0; (!(flags | 0b00000000)) && (i < 1000); ++i){
		for(unsigned short j = i+1; (nums[j] != 0) && (!(flags | 0b00000000)); ++j){
			for(unsigned short k = j+1; nums[k] != 0; ++k){
				if(nums[i] + nums[j] + nums[k] == 2020){
					result = nums[i] * nums[j] * nums[k];
					flags |= 0b00000001;
					break;
				}
			}
		}
	}
	printf("Result: %u\n", result);  
	free(nums);
}
