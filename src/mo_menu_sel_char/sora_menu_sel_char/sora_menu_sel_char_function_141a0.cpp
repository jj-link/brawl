#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void fn_10_14414(void* a, const void* b, int c, void* d, void* e);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
extern const char lbl_10_rodata_5C0[];
extern const char lbl_10_rodata_630[];
extern char lbl_10_data_7C8[];
}

struct SelSub {
    char pad[0x5cc];
    int m_5cc;
    unsigned char m_5d0;
};

struct SelSelf {
    char pad0[0xb0];
    char* m_b0;
    char pad1[0xec - 0xb4];
    char* m_ec;
    char pad2[0x1f4 - 0xf0];
    SelSub* m_1f4;
    char pad3[0x404 - 0x1f8];
    void* m_404;
    void* m_408;
};

extern "C" void fn_10_141A0(SelSelf* self, void* a, void* b, void* c) {
    char* base = lbl_10_data_7C8;
    fn_10_14414(self, lbl_10_rodata_5C0, 0xe, a, b);
    fn_10_14414(self, lbl_10_rodata_630, 3, a, c);

    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    int r2;
    if (result == 1) {
        r2 = 0;
    } else {
        SelSub* s = self->m_1f4;
        if (s->m_5d0 != 0) {
            r2 = 2;
        } else {
            r2 = s->m_5cc == 2;
        }
    }
    char* p = base + 0x1ac;
    if (r2 == 2) p = base + 0x198;
    *(char**)(base + 0x190) = p;
    fn_10_14414(self, base + 0x190, 1, a, b);

    void* heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a);
    self->m_404 = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 0xf, *(void**)(self->m_b0 + 0x10));
    self->m_408 = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 0xa, *(void**)(self->m_ec + 0x10));
}
