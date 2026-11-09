#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_27C070(void* self, const char* name);
void setPos__9grGimmickFfff(void* self, float x, float y, float z);
void setRot__9grGimmickFfff(void* self, float x, float y, float z);
void setScale__9grGimmickFfff(void* self, float x, float y, float z);
extern const u8 lbl_27_data_5A028[];
extern const float lbl_27_rodata_4520;
extern const float lbl_27_rodata_4524;
}

struct Madein {
    unsigned char _0[0x16C];
    signed char field16C : 8;
    unsigned char _16D[3];
    float f170;
    unsigned char _174[0x1A4 - 0x178];
};

extern "C" void* __ct__8grMadeinFPCc(void* arg0, const char* arg1) {
    char* self = (char*)arg0;
    fn_27_27C070(self, arg1);
    *(void**)(self + 0x3C) = (void*)lbl_27_data_5A028;
    *(u32*)(self + 0x1A0) = 0;
    setPos__9grGimmickFfff(self, lbl_27_rodata_4520, lbl_27_rodata_4520, lbl_27_rodata_4520);
    setRot__9grGimmickFfff(self, lbl_27_rodata_4520, lbl_27_rodata_4520, lbl_27_rodata_4520);
    setScale__9grGimmickFfff(self, lbl_27_rodata_4524, lbl_27_rodata_4524, lbl_27_rodata_4524);
    u32 flags = *(u8*)(self + 0x16C);
    *(u8*)(self + 0x16C) = (u8)(flags & 0xFFFFFF00);
    Madein* m = (Madein*)self;
    *(u32*)(self + 0x168) = 0;
    m->f170 = lbl_27_rodata_4520;
    *(u32*)(self + 0x174) = 0xA;
    *(u32*)(self + 0x17C) = 1;
    *(u32*)(self + 0x180) = 1;
    *(u32*)(self + 0x184) = 1;
    *(u32*)(self + 0x188) = 1;
    *(u32*)(self + 0x18C) = 1;
    *(u32*)(self + 0x190) = 1;
    *(u32*)(self + 0x194) = 1;
    *(u32*)(self + 0x198) = 1;
    *(u32*)(self + 0x19C) = 0;
    *(u32*)(self + 0x164) = 0;
    *(u32*)(self + 0x15C) = 0;
    *(u32*)(self + 0x160) = 0;
    return self;
}
