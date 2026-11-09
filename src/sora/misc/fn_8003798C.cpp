#include <types.h>
#include <gf/gf_archive.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

extern "C" void fn_80228154(int arg0);
extern "C" void fn_8026F4EC(void* p, void* s);
extern "C" void fn_8026F698();
extern "C" int fn_8026F854(int arg0);
extern "C" void fn_8026F868(void* a, int b, int c);
extern "C" void* fn_80023AC8();

extern "C" void fn_8003623C();
extern "C" void fn_8003626C();
extern u8 lbl_804954D8[];
extern u8 lbl_804954E0[];

struct Self {
    u8 pad[0x10];
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1C;
    u8 pad2[0x38 - 0x20];
    int m_38;
    u8 pad3[0x98 - 0x3C];
    int m_98;
    int m_9C;
    u8 pad4[0xAC - 0xA0];
    gfFileIOHandle m_AC;
    union {
        u32 raw;
        struct {
            u32 state : 4;
            u32 rest : 28;
        } f;
    } m_B0;
};

struct B1Bits {
    u8 f0 : 1;
    u8 f1 : 1;
    u8 rest : 6;
};

extern "C" int fn_8003798C(Self* self) {
    u8* b1 = (u8*)self + 0xB1;
    int state = (int)self->m_B0.raw >> 28;
    if (state == 2)
        return 1;
    if (state == 0)
        return 0;
    if ((*b1 >> 5) & 1)
        return 0;
    if (!self->m_AC.isReady())
        return 0;
    self->m_B0.f.state = 2;

    int sz;
    void* data4;
    {
        gfArchive arc;
        int size = self->m_AC.getSize();
        arc.setFileImage(self->m_AC.getBuffer(), size, (HeapType)6);

        self->m_10 = arc.getData((ARCNodeType)1, 0, &sz, 0xFFFE);
        self->m_14 = arc.getData((ARCNodeType)1, 1, &sz, 0xFFFE);
        self->m_18 = arc.getData((ARCNodeType)1, 2, &sz, 0xFFFE);
        self->m_1C = arc.getData((ARCNodeType)1, 3, &sz, 0xFFFE);
        self->m_38 = sz;
        data4 = arc.getData((ARCNodeType)1, 4, &sz, 0xFFFE);
    }

    fn_80228154(0);
    fn_80228154(1);
    fn_80228154(2);
    fn_80228154(3);

    if ((s8)lbl_804954D8[0] == 0) {
        *(void**)(lbl_804954E0 + 0x10) = (void*)fn_8003623C;
        *(void**)(lbl_804954E0 + 0x14) = (void*)fn_8003626C;
        *(void**)(lbl_804954E0 + 0x00) = (void*)(lbl_804954E0 + 0x10);
        *(u32*)(lbl_804954E0 + 0x08) = 0;
        *(u32*)(lbl_804954E0 + 0x0C) = 0;
        *(u32*)(lbl_804954E0 + 0x1C) = 0;
        *(u32*)(lbl_804954E0 + 0x04) = 0;
        *(u32*)(lbl_804954E0 + 0x18) = 0;
        lbl_804954D8[0] = 1;
    }
    *(u32*)(lbl_804954E0 + 0x18) = *(u32*)(lbl_804954E0 + 0x04);

    fn_8026F4EC(&self->m_10, lbl_804954E0);
    fn_8026F698();
    fn_8026F854(1);
    self->m_9C = 1;
    fn_8026F868(data4, self->m_98, 0x1D000);

    u8* t = (u8*)fn_80023AC8();
    ((B1Bits*)b1)->f1 = (t[0x74] >> 3) & 1;
    t[0x74] = t[0x74] | 8;
    return 1;
}
