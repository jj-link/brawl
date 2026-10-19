#include <types.h>
#pragma force_active on

extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(u32);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, s32, s32, void*);
void changeNodeAnimN__8MuObjectFPCc(void*, const char*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, const char*);
void fn_11_118C(u8* self, const char* name, s32 count, s32 a, s32 b, s32 c);
void fn_800B672C(void* obj, float* out, const char* name);
extern char lbl_11_rodata_0[];
extern char lbl_11_data_0[];
}

extern "C" void fn_11_1018(u8* self, s32 a2, s32 flag, s32 a4, s32 a5, s32 a6) {
    float pos[3];
    u8* rodata = (u8*)lbl_11_rodata_0;
    u8* data = (u8*)lbl_11_data_0;
    void* heap;
    void* mdl;
    const char* name;

    fn_11_118C(self, (const char*)(rodata + 0xc8), 8, a2, 0, a6);
    heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a);
    mdl = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 0x51, *(void**)(*(u8**)(self + 0x84) + 0x10));
    name = (const char*)(data + 0x250);
    *(void**)(self + 0x214) = mdl;
    if (*(s32*)(self + 0x40) == 2) {
        name = (const char*)(data + 0x268);
    }
    changeNodeAnimN__8MuObjectFPCc(*(void**)(self + 0x84), name);
    if (flag != 0) {
        fn_11_118C(self, (const char*)(rodata + 0x20), 0x15, flag, a4, a6);
        fn_11_118C(self, (const char*)(rodata + 0x108), 1, a5, 0, a6);
        *(void**)(self + 0x220) = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 1, *(void**)(*(u8**)(self + 0x58) + 0x10));
        *(void**)(self + 0x218) = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 0xa, *(void**)(*(u8**)(self + 0x88) + 0x10));
        mdl = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 1, *(void**)(*(u8**)(self + 0x1ec) + 0x10));
        *(void**)(self + 0x21c) = mdl;
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, *(void**)(*(u8**)(self + 0x1f0) + 0x10), (const char*)(data + 0x280));
        fn_800B672C(*(void**)(self + 0x88), pos, (const char*)(data + 0x280));
        *(float*)(self + 0x6050) = pos[1];
    }
    {
        u8* p = *(u8**)(self + 0x48);
        *(u8**)(p + 0x40) = self + 0x54;
        *(s32*)(p + 0x44) = 0x70;
    }
}
