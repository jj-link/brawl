#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_3_data_0[];
extern const float lbl_3_rodata_812C;
extern const float lbl_3_rodata_8120;
extern const double lbl_3_rodata_8148;
extern char* g_GameGlobal;

void fn_800B92D8(void*, unsigned long, char*, unsigned long);
void fn_800B7224(void*, void*, char*, void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setFrameVisible__8MuObjectFf(void*, float);
int exchangeMuSelchkind2MuStockchkind__6muMenuFi(int);
int exchangeGmCharacterKind2Something__6muMenuFi(int);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
unsigned int __cvt_fp2unsigned(float);
}

struct Entry {
    unsigned char type;
    unsigned char pad1;
    char name[0x18];
    unsigned char kind;
    unsigned char pad1b;
    unsigned char sub;
    unsigned char pad1d[3];
    int idx;
    int pad24;
};

struct Data {
    unsigned char count;
    char pad[7];
    Entry e[1];
};

struct Slot {
    int v;
    char pad[0x18];
};

extern "C" void fn_3_14F0(char* self) {
    char buf[64];
    char* str = lbl_3_data_0;
    char* matName;
    Data* d;
    Entry* e;
    unsigned int i;

    i = 0;
    d = *(Data**)(g_GameGlobal + 0x2c);
    if (d->count == 0)
        return;

    matName = str + 0x70;
    e = d->e;
    for (; i < d->count; i++, e++) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            *(void**)self,
            *(void**)(((char**)(self + 0xf50))[e->idx] + 0xc),
            str + 0x40);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            *(void**)self,
            *(void**)(((char**)(self + 0xfd0))[e->idx] + 0xc),
            str + 0x40);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            *(void**)self,
            *(void**)(((char**)(self + 0x1050))[e->idx] + 0xc),
            str + 0x40);

        fn_800B92D8(*(void**)(self + 0x10d4), e->idx, e->name, strlen(e->name));

        if (e->type == 2) {
            setFrameVisible__8MuObjectFf(
                ((void**)(self + 0x1050))[e->idx], lbl_3_rodata_812C);
        } else {
            setFrameVisible__8MuObjectFf(
                ((void**)(self + 0x1050))[e->idx], lbl_3_rodata_8120);
        }

        unsigned int a;
        unsigned int b;

        if (e->kind == 0x29) {
            a = 0;
            b = 0;
        } else {
            int kind = exchangeMuSelchkind2MuStockchkind__6muMenuFi(e->kind);
            int value = exchangeGmCharacterKind2Something__6muMenuFi(kind) * 10 + 1;
            a = __cvt_fp2unsigned((float)value);
            b = e->sub;
        }

        sprintf(buf, str + 0x80, a + b);

        char* mdl = ((char**)(self + 0xfd0))[e->idx];
        void* extra = *(void**)(self + 0x10d8);
        void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(mdl + 8, matName);

        fn_800B7224(mdl, *(void**)((char*)mat + 0xc), buf, extra);
        ((Slot*)(self + 0xbac))[e->idx].v = i;
    }
}
