#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char __vt__8NtBuffer[];
extern char lbl_80460CF0[];
extern char* lbl_805A0434;
extern char lbl_8059E7C0;
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* create__12gfMemoryPoolFPvUlPCc(void*, unsigned long, const char*);

void* fn_80149AA0(void* arg0) {
    char* p = (char*)arg0;
    *(s32*)(p + 0x04) = 0;
    *(void**)(p + 0x00) = lbl_80460CF0;
    *(u8*)(p + 0x11) = 0;
    *(s32*)(p + 0x94) = 0;
    *(s32*)(p + 0x98) = 0;
    *(void**)(p + 0x33b8) = __vt__8NtBuffer;
    *(s32*)(p + 0x33bc) = 0;
    *(s32*)(p + 0x33c0) = 0;
    *(u8*)(p + 0x33c4) = 0;
    *(s32*)(p + 0x33c8) = 0;
    *(u8*)(p + 0x33cc) = 0;
    *(u8*)(p + 0x33cd) = 1;
    *(u8*)(p + 0x33ce) = 0;
    *(u8*)(p + 0x33f4) = 0;
    *(u8*)(p + 0x33f5) = 0;
    *(u8*)(p + 0x33f6) = 0;
    *(s32*)(p + 0x3404) = 0;
    *(s32*)(p + 0x3408) = 0;
    *(s32*)(p + 0x340c) = 0;
    *(u8*)(p + 0x3410) = 0;
    *(u8*)(p + 0x3411) = 0;
    *(u8*)(p + 0x3412) = 0;
    *(u8*)(p + 0x3413) = 0;
    *(s32*)(p + 0x341c) = 0;
    *(s32*)(p + 0x3418) = 0;
    *(s8*)(p + 0x3420) = -1;
    *(s8*)(p + 0x3421) = -1;
    *(u16*)(p + 0x3422) = 0x1c20;
    *(u16*)(p + 0x3424) = 0;
    *(s32*)(p + 0x3428) = 0;
    *(s32*)(p + 0x342c) = 0;
    *(s32*)(p + 0x3430) = 0;
    *(s32*)(p + 0x3434) = 0;
    *(u8*)(p + 0x343c) = 0;
    *(s32*)(p + 0x3444) = 0;
    *(s32*)(p + 0x3440) = 0;
    *(s32*)(p + 0x3448) = 0;
    *(s32*)(p + 0x3498) = 0;
    *(s32*)(p + 0x349c) = 0;
    *(s32*)(p + 0x34a0) = 0;
    *(s32*)(p + 0x34a4) = 0;
    *(u8*)(p + 0x34ac) &= 0xFFFFFF00;

    lbl_805A0434 = p;

    void* heap = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(6, 0x20000);
    *(void**)(p + 0x3538) = heap;
    *(void**)(p + 0x353c) = create__12gfMemoryPoolFPvUlPCc(heap, 0x20000, &lbl_8059E7C0);

    return arg0;
}
}
