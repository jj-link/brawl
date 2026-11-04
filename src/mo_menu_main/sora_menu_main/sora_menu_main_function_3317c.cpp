#pragma force_active on
#include <types.h>

struct Inner {
    char pad0[0x68];
    void* unk68;
    char pad1[4];
    void* unk70;
    char pad2[0xB4 - 0x74];
    unsigned int unkB4;
    char pad3[0x1AC - 0xB8];
    int unk1AC;
    char pad4[4];
    unsigned char unk1B4;
};

struct Struct_40 {
    char pad[0x40];
    Inner* unk40;
};

extern "C" {
void fn_2_31A5C(Struct_40*, unsigned int, int);
void fn_2_3204C(Struct_40*, int);
int fn_2_31C6C(Struct_40*, unsigned int, unsigned int*);
void fn_2_31D14(Struct_40*, int, unsigned int, unsigned int*, int);
void setFrameVisible__8MuObjectFf(void*, float);
void setFrameTex__8MuObjectFf(void*, float);
}

extern const float lbl_2_rodata_13FC;

extern "C" void fn_2_3317C(Struct_40* self)
{
    unsigned int buf[6];

    unsigned int b4 = self->unk40->unkB4;
    int id = self->unk40->unk1AC;
    fn_2_31A5C(self, b4, id);
    fn_2_3204C(self, id);
    setFrameVisible__8MuObjectFf(self->unk40->unk68, lbl_2_rodata_13FC);
    int id2 = self->unk40->unk1AC;
    if ((unsigned int)(id2 - 0x17) <= 1u) {
        int n = fn_2_31C6C(self, b4, buf);
        if (n > 0) {
            Inner* in = self->unk40;
            unsigned int d1 = (unsigned int)(0x17 - id2);
            unsigned int d2 = (unsigned int)(id2 - 0x17);
            int flag = (int)((d1 | d2) >> 31);
            if (in->unk1B4 == 0) {
                fn_2_31D14(self, 0x1d, flag, buf, n);
            }
            else {
                setFrameTex__8MuObjectFf(in->unk70, (float)flag);
            }
        }
    }
}
