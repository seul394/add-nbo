#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	printf("[bob11]add-nbo[%s%s]\n", "이슬", "1509");

	uint32_t op1;
	uint32_t op2;
	
	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");

	fread(&op1, sizeof(uint32_t), 1, fp1);
	fread(&op2, sizeof(uint32_t), 1, fp2);
	
	fclose(fp1);
	fclose(fp2);

	op1 = ntohl(op1);
	op2 = ntohl(op2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", op1, op1, op2, op2, op1 + op2, op1 + op2);

}
