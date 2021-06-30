#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	char* line;
	u_int8_t flags = 0b00000000;
	posix_memalign((void*)&line, 64, 256*sizeof(char));
	memset(line, 0x0, 256);
	unsigned pos = 0, trees = 0, slopes = 0, trees_product = 1, high = 30, incr = 1;
	FILE* data;
	data = fopen("data", "r");
	if(!data){printf("ERROR OPENING FILE\n"); return -1;}
	l1:
	while(line[0] != 'a'){
		memset(line, 0x0, 256);
		fgets(line, 33, data);
		if(flags & 0b00000001){
			if(!(flags & 0b00000010)) { flags ^= 0b00000010;}
			else {flags ^= 0b00000010; continue;}
		}
		if(line[pos] == '#'){++trees;}
		(pos < high) ? (pos += incr) : (pos -= high);
	}
	++slopes;
	rewind(data);
	trees_product *= trees;
	trees = 0; pos = 0;
	memset(line, 0x0, 256);
	if(slopes < 5){
		switch(slopes){
			case 1:{high = 28; incr = 3; break;}
			case 2:{high = 26; incr = 5; break;}
			case 3:{high = 24; incr = 7; break;}
			case 4:{high = 30; incr = 1; flags |= 0b00000001; break;}
			default: break;
		}
		goto l1;
	}
	free(line);
	fclose(data);
	printf("Trees multiplied: %u\n", trees_product);
	return 0;
}
