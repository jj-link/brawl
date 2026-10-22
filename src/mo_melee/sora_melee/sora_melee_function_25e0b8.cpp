#pragma force_active on

typedef int s32;
typedef unsigned char u8;

extern "C" {
void fn_27_25CEA4(void*, s32);
s32 randi__Fl(s32);
extern u8 lbl_27_data_545C0[];
extern s32 lbl_27_data_545A0;
}

extern "C" void* fn_27_25E0B8(void* arg0) {
    char* self = (char*)arg0;
    s32 off;
    s32 i;
    fn_27_25CEA4(self, 1);
    *(u8*)(self + 0x10) = 0;
    *(u8**)(self + 0x00) = lbl_27_data_545C0;
    *(s32*)(self + 0x28) = lbl_27_data_545A0;
    *(s32*)(self + 0x2C) = 0;
    *(s32*)(self + 0x18) = 1;
    *(s32*)(self + 0x1C) = 2;
    *(s32*)(self + 0x20) = 3;
    *(s32*)(self + 0x24) = 4;
    i = 0;
    off = 0;
    do {
        s32 j = randi__Fl(3) * 4;
        s32* pa = (s32*)(self + off + 0x18);
        s32* pb = (s32*)(self + j + 0x18);
        s32 t = *pa;
        i++;
        off += 4;
        *pa = *pb;
        *pb = t;
    } while (i < 4);
    return arg0;
}
