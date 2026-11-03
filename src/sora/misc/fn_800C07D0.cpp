#pragma force_active on
#include <types.h>
#include <gf/gf_file_io_handle.h>

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__20tyFigListDataManagerFb(void*, int);
void loadRequest__20tyFigListDataManagerFv(void*);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void* fn_800AD808(void*, int);
void fn_800AD8F8(void*);
extern const char lbl_80456DD8[];
}

struct Elem {
    s32 id;
    u8 pad[0xC];
};

struct Self {
    u8 pad0[0x10C];
    s32 f10C;        // 0x10C
    u8 pad110[0xC];  // 0x110
    Elem elems[16];  // 0x11C
    s32 count;       // 0x21C
    u8 pad220[8];    // 0x220
    void* figManager; // 0x228
    gfFileIOHandle fh1; // 0x22C
    u8 pad230[0x84];    // 0x230
    u8 isLoaded;        // 0x2B4
    u8 pad2B5[3];
    void* obj2;         // 0x2B8
    gfFileIOHandle fh2; // 0x2BC
    u8 pad2C0[0x84];    // 0x2C0
    gfFileIOHandle fh3; // 0x344
};

static s32 hasId(const Self* s, s32 val) {
    for (s32 i = 0; i < s->count; i++) {
        if (s->elems[i].id == val) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_800C07D0(void* self) {
    const char* base = lbl_80456DD8;
    Self* s = (Self*)self;

    if (hasId(s, 0)) {
        if (s->isLoaded == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x1468, 0x2A);
            if (p != 0) {
                p = __ct__20tyFigListDataManagerFb(p, 0);
            }
            s->figManager = p;
            loadRequest__20tyFigListDataManagerFv(p);
        }
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(&s->fh1, base + 0x88, 0x2B, 0, 0);
    }

    if (hasId(s, 1)) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x3EB4, 0x2A);
        if (p != 0) {
            p = fn_800AD808(p, 0);
        }
        s->obj2 = p;
        fn_800AD8F8(p);
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(&s->fh2, base + 0xA8, 0x2B, 0, 0);
    }

    if (hasId(s, 2)) {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(&s->fh3, base + 0xCC, 0x2B, 0, 0);
    }

    s->f10C = 0;
}
