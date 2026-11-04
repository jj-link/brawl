#include <types.h>
#pragma force_active on

extern "C" {

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int heapType);
void* fn_801AC370(void* allocator, void* out, s32 a, s32 b, s32 c, s32 d);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
s32 fn_80015DB4(s32 a, s32 b, s32 c, s32 d, u16 e);
void fn_800B0254(void* self, s32 a);
void fn_800AFF00(void* self);

extern void* g_GameGlobal;
extern char lbl_80455C9C[];

void* fn_800AFDE4(void* self, const char* name, s32 arg2, s32 arg3, s32 arg4) {
    u8* s = (u8*)self;
    void* sp8;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, name, 8, 0xF, 8, true);
    *(char**)(s + 0x3C) = lbl_80455C9C;
    *(s32*)(s + 0x40) = 1;
    *(s32*)(s + 0x44) = 0;
    *(s32*)(s + 0x48) = 0;
    *(s32*)(s + 0x4C) = 0;
    *(s32*)(s + 0x50) = 0;
    *(s32*)(s + 0x54) = 0;
    s[0x1A4] = 0;
    *(s32*)(s + 0x1A8) = 0;
    *(void**)(s + 0x48) = fn_801AC370(getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A), &sp8, arg2, arg2, 0x80, 0x80);
    *(const char**)(s + 0x0) = name;
    s[0x2C] &= 0xFFFFFFFD;
    if (arg3 != 0 && arg4 >= 0) {
        if (((*((u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28)) >> 7) & 1) {
            arg4 += 1;
        }
        fn_800B0254(self, fn_80015DB4(arg3, 0, 1, arg4, (u16)0xFFFE));
    }
    fn_800AFF00(self);
    return self;
}

}