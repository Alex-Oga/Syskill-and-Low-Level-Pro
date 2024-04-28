#include "cacheSim.h"

// In this question, we will assume DRAM will take a 4-byte values starting from 0 to 
void init_DRAM()
{
	unsigned int i=0;
	DRAM = malloc(sizeof(char) * DRAM_SIZE);
	for(i=0;i<DRAM_SIZE/4;i++)
	{
		*((unsigned int*)DRAM+i) = i;
	}
}

void printCache()
{
	int i,j,k;
	printf("===== L1 Cache Content =====\n");
	for(i=0;i<2;i++)
	{
		printf("Set %d :", i);
		for(j=0;j<2;j++)
		{
			printf(" {(TAG: 0x%x)", (unsigned int)(L1_cache[i][j].tag));
			for(k=0;k<16;k++)
				printf(" 0x%x,", (unsigned int)(L1_cache[i][j].data[k]));
			printf(" |");
		}
		printf("\n");
	}
	printf("===== L2 Cache Content =====\n");
	for(i=0;i<4;i++)
	{
		printf("Set %d :", i);
		for(j=0;j<4;j++)
		{
			printf(" {(TAG: 0x%x)", (unsigned int)(L2_cache[i][j].tag));
			for(k=0;k<16;k++)
				printf(" 0x%x,", (unsigned int)(L2_cache[i][j].data[k]));
			printf(" |");
		}
		printf("\n");
	}
}


int L1lookup(u_int32_t address)
{
	u_int32_t tag = getL1Tag(address);
	u_int32_t set = getL1SetID(address);
	for(int i=0;i<2;i++)
	{
		if(L1_cache[set][i].tag == tag) return 1;
	}
	return 0;
}

int L2lookup(u_int32_t address)
{
	u_int32_t tag = getL2Tag(address);
	u_int32_t set = getL2SetID(address);
	for(int i=0;i<4;i++)
	{
		if(L2_cache[set][i].tag == tag) return 1;
	}
	return 0;

}

// This function performs a read to an address.
u_int32_t read(u_int32_t address)
{
	L1access(address, 0, 0);
	return 0;
}

// This function access the L1 cache for the address. Type is 0 for a read and 1 for a write.
int L1access(u_int32_t address, int type, u_int32_t data)
{
	// TODO
	return 0;
}

// This function access the L2 cache for the address. Type is 0 for a read and 1 for a write.
int L2access(u_int32_t address, int type, u_int32_t data)
{
	// TODO
	return 0;
}

// This functions replace the LRU block in the L1 with the input block
void L1replace(cacheBlock block, int setID)
{
	// TODO
}

// This functions replace the LRU block in the L2 with the input block
void L2replace(cacheBlock block, int setID)
{
	// TODO
}

unsigned int getL1SetID(u_int32_t address)
{
	return 0; // TODO
}

unsigned int getL2SetID(u_int32_t address)
{
	return 0; // TODO
}

unsigned int getL1Tag(u_int32_t address)
{
	return 0; // TODO
}

unsigned int getL2Tag(u_int32_t address)
{
	return 0; // TODO
}


void write(u_int32_t address, u_int32_t data)
{
	L1access(address, 1, data);
}


int main()
{
	init_DRAM();
	cacheAccess buffer;
	int timeTaken=0;
	FILE *trace = fopen("input.trace","r");
	int L1hit = 0;
	int L2hit = 0;
	cycles = 0;
	while(!feof(trace))
	{
		fscanf(trace,"%d %x %x", &buffer.readWrite, &buffer.address, &buffer.data);
		printf("Processing the request for [R/W] = %d, Address = %x, data = %x\n", buffer.readWrite, buffer.address, buffer.data);

		// Checking whether the current access is a hit or miss so that we can advance time correctly
		if(L1lookup(buffer.address))// Cache hit
		{
			timeTaken = 1;
			L1hit++;
		}
		else if(L2lookup(buffer.address))// L2 Cache Hit
		{
			L2hit++;
			timeTaken = 5;
		}
		else timeTaken = 50;
		if (buffer.readWrite) write(buffer.address, buffer.data);
		else read(buffer.address);
		cycles+=timeTaken;
	}
	printCache();
	printf("Total cycles used = %ld\nL1 hits = %d, L2 hits = %d", cycles, L1hit, L2hit);
	fclose(trace);
	free(DRAM);
	return 0;
}




