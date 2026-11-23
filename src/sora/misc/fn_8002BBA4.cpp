#include <gf/gf_archive.h>
#include <string.h>
#include <types.h>
#pragma force_active on

extern void* lbl_805A0058;
extern s32 lbl_805A005C;

extern "C" void fn_8002BD2C(void* a, void* b, void* data, s32 size);

extern "C" void fn_8002BBA4(u8* self, const char* name) {
    *(s32*)(self + 0xF0) = 0;
    *(s32*)(self + 0xF4) = 0;
    gfArchive arc;
    int size;
    u8* tbl;
    s32 off;
    u32 count;
    u32 i;

    arc.setFileImage(lbl_805A0058, lbl_805A005C, (HeapType)7);
    void* data = arc.getData(ARCNodeType(1), 0, &size, 0xFFFE);
    fn_8002BD2C(self, self, data, size);

    i = 0;
    count = *(u32*)(self + 0xC);
    off = 0;
    while (i < count) {
        tbl = *(u8**)(self + 0x28);
        if (strcmp(*(char**)(self + 0x30) + *(u32*)(tbl + off + 4), name) == 0) {
            *(s32*)(self + 0xF0) = *(s32*)(self + 0x20) + *(s32*)(tbl + i * 8);
            break;
        }
        off += 8;
        i++;
    }

    data = arc.getData(ARCNodeType(1), 1, &size, 0xFFFE);
    fn_8002BD2C(self, self + 0x40, data, size);

    count = *(u32*)(self + 0x4C);
    for (u32 j = 0; j < count; j++) {
        tbl = *(u8**)(self + 0x68);
        if (strcmp(*(char**)(self + 0x70) + *(u32*)(tbl + j * 8 + 4), name) == 0) {
            *(s32*)(self + 0xF4) = *(s32*)(self + 0x60) + *(s32*)(tbl + j * 8);
            break;
        }
    }
}
