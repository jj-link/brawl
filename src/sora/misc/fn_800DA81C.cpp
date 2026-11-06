#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
int sprintf(char* s, const char* fmt, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
extern char lbl_8059E188[8];
}

struct NumDisp {
    char pad0[0x40];
    MuObject* objs[5];
    void* scn;
    char pad1[0x8];
    int count;
};

extern "C" int fn_800DA81C(NumDisp* self, int value, int digits, int skipZeros, int base, int idx) {
    MuObject* obj;
    MuObject** p;
    int j;
    int n;
    void* scn;
    int max;
    char buf[8];
    int i;
    int mul;
    mul = 1;
    n = 0;
    i = 0;
    for (; i < digits; i++) {
        mul *= 10;
    }
    max = mul - 1;
    int v = value > 0 ? value : 0;
    if (v < max) {
        max = v;
    }
    scn = *(void**)((char*)self + 0x54);
    p = (MuObject**)((char*)self + idx * 4);
    j = 0;
    while (j < self->count && (skipZeros == 0 || max > 0 || j == 0)) {
        obj = p[0x40 / 4];
        obj->setFrameTex((float)(max % 10));
        sprintf(buf, lbl_8059E188, base + j);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scn, *(void**)((char*)obj + 0x10), buf);
        p++;
        j++;
        n++;
        max /= 10;
    }
    return n;
}
