#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct muAdvDifficultyTaskParam {
    u32 f0;
    u32 f4;
    u32 f8;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_32_94(void* p);
extern "C" void fn_800B96E8(void* p, int v);

extern "C" void* create__19muAdvDifficultyTaskFPC24muAdvDifficultyTaskParam(const muAdvDifficultyTaskParam* p) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x350, 0x2a);
    if (obj != 0) {
        obj = fn_32_94(obj);
    }
    u8* base = (u8*)obj;
    *(u32*)(base + 0x44) = p->f4;
    *(u32*)(base + 0x48) = p->f8;
    *(u32*)(base + 0x4c) = p->f0;
    fn_800B96E8(base + 0x54, p->f4 & 0xff);
    if ((s32)*(u32*)(base + 0x48) >= 0) {
        fn_800B96E8(base + 0xfc, p->f8 & 0xff);
    }
    return obj;
}
