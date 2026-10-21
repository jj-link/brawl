#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" s32 fn_41_230F8(s32 x);
extern "C" u8* fn_41_23270(void* self, u32 index);
extern "C" void fn_41_232A4(void* unused, s32 x, u8* out);
extern "C" void fn_41_23328(void* self, u32 index, u8* entry);
extern float lbl_41_rodata_D58;

struct SoraEntry {
    u8 type;
    u8 pad1[3];
    s32 field4;
    s32 field8;
    s32 fieldC;
    float f10;
    float f14;
    float f18;
    float f1C;
};

struct SoraObj {
    char pad[0x50];
    u8* list;
    s32 count54;
    s32 count58;
};

extern "C" void fn_41_2343C(SoraObj* self) {
    u8* list = self->list;
    if (self->count54 != 0) {
        SoraEntry* p = (SoraEntry*)fn_41_23270(self, 0);
        if (p != 0) {
            s32 r = fn_41_230F8(0);
            p->type = 2;
            fn_41_232A4(self, r, (u8*)p);
            p->fieldC = 0;
            float z = lbl_41_rodata_D58;
            p->f10 = z;
            p->f14 = z;
            p->f18 = z;
            p->f1C = z;
        }
        if (list != 0) {
            u32 i = 6;
            while (i < (u32)self->count58) {
                fn_41_23328(self, i, list + (i - 6) * 0x24);
                i++;
            }
        }
    }
}
