#pragma force_active on

typedef unsigned short u16;

struct S0 {
    u16 pad0;
    u16 pad2;
    u16 unk4;
    u16 unk6;
};

extern "C" {
extern void* fn_802DA104(int);
extern void fn_802DA190(void*, void*);
extern void fn_802DA2B4(void*);
extern void fn_80281D64(int, int, int, int);

void* fn_802DA2C8(void* arg0) {
    S0* ptr = (S0*)arg0;
    int val = ptr->unk4 + 1;
    ptr->unk4 = val;

    if ((u16)val > ptr->unk6) {
        ptr = (S0*)fn_802DA104((val * 2) & 0x1FFFE);
        fn_802DA190(ptr, arg0);
        fn_802DA2B4(arg0);
    }

    int aligned = ((int)ptr + 0x37) & 0xFFFFFFF0;
    int offset = aligned + (ptr->unk6 << 5);
    fn_80281D64((ptr->unk4 - 1) * 0x14 + offset, 0, 0x14, aligned);
    return ptr;
}
}
