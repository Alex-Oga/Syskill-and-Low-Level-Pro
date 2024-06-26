#include<stdlib.h>
#include<stdio.h>
#define DRAM_SIZE 1048576

typedef struct cb_struct {
    unsigned char data[16]; // One cache block is 16 bytes.
    u_int32_t tag;
    u_int32_t timeStamp;   /// This is used to determine what to evict. You can update the timestamp using cycles.
}cacheBlock;

// Feel free to use this struct
typedef struct access {
    int readWrite; // 0 for read, 1 for write
    u_int32_t address;
    u_int32_t data; // If this is a read access, value here is 0
}cacheAccess;


cacheBlock getBlockFromDRAM(u_int64_t address, int level, int type, u_int32_t data);

// This is our dummy DRAM. You can initialize this in anyway you want to test.
unsigned char * DRAM; 

cacheBlock L1_cache[2][2]; // Our 2-way, 64 byte cache
cacheBlock L2_cache[4][4]; // Our 4-way, 256 byte cache

// Trace points to a series of cache accesses.
FILE *trace;

long cycles;

void init_DRAM();


// This function print the content of the cache in the following format for an N-way cache with M Sets
// Set 0   : CB1 | CB2 | CB 3 | ... | CB N
// Set 1   : CB1 | CB2 | CB 3 | ... | CB N
// ...
// Set M-1 : CB1 | CB2 | CB 3 | ... | CB N
void printCache();

// These functions perform a cache lookup (i.e., checking if the data is in the respective cache or not) and this is used in the main function to count the number of hits/misses. You do not need to implement this but it is a good example of how you can check the cache hit/miss status for the actual access.
int L1lookup(u_int32_t address);
int L2lookup(u_int32_t address);

////// Part 1: Checking if the address is in the cache /////

// These functions perform a cache access to the associated cache levels. Return 0 if the address is not in the cache (cache miss) and 1 if the address is in the cache (cache hit)
int L1access(u_int32_t address, int type, u_int32_t data);
int L2access(u_int32_t address, int type, u_int32_t data);

// These functions perform a cache replacement by evicting LRU block from the cache and replace this block with the input cache block.
void L1replace(cacheBlock block, int setID);
void L2replace(cacheBlock block, int setID);

// This function returns a setID given an address
unsigned int getL1SetID(u_int32_t address);
unsigned int getL2SetID(u_int32_t address);

// This function returns a tag given an address
unsigned int getL1Tag(u_int32_t address);
unsigned int getL2Tag(u_int32_t address);

////// Part 2: FIFO cache //////
// This function performs a read to a cache content. Return the 4-byte data content given by the address. Please note that the read access MUST evict existing cache block correctly based on the LRU policy and insert the new cache block correctly into the cache.
u_int32_t read(u_int32_t address);

// EPart 3: handle write. Assuming a write-through cache. This is the only place you actually modify the data in the cache and DRAM
void write(u_int32_t address, u_int32_t data);

