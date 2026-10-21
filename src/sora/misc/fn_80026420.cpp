#pragma force_active on
typedef unsigned char u8;

typedef struct gfMemoryPool {
    u8 pad0[0x10];
    u8 unk10;
} gfMemoryPool;

extern "C" void* alloc__12gfMemoryPoolFPvUli(void*, unsigned long, int);

extern "C" void fn_80026420(unsigned char* self, unsigned long size) {
    u8 saved;
    gfMemoryPool* pool;
    pool = *(gfMemoryPool**)(self + 4);
    saved = pool->unk10;
    pool->unk10 = 0xFE;
    alloc__12gfMemoryPoolFPvUli(pool, size, 0x20);
    pool->unk10 = saved;
}
