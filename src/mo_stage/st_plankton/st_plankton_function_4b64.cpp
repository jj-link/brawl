#include <gr/gr_gimmick.h>

#pragma force_active on

extern "C" char lbl_74_data_D60[];

extern "C" int fn_74_4B64(grGimmick* self) {
    const char* base = lbl_74_data_D60;
    int result = self->grGimmick::setNode();
    switch (*(u8*)(*(char**)((char*)self + 0x158) + 0x24)) {
    case 0:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x10);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x1C);
        break;
    case 1:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x30);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x3C);
        break;
    case 2:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x50);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x5C);
        break;
    case 3:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x70);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x7C);
        break;
    case 4:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x90);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x9C);
        break;
    case 5:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0xB0);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0xBC);
        break;
    case 6:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0xD0);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0xDC);
        break;
    case 7:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0xF0);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0xFC);
        break;
    case 8:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x110);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x11C);
        break;
    case 9:
        self->getNodeIndex((u32*)((char*)self + 0x15C), 0, base + 0x130);
        self->getNodeIndex((u32*)((char*)self + 0x160), 0, base + 0x13C);
        break;
    }
    return result;
}
