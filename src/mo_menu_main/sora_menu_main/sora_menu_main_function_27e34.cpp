#pragma force_active on

typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern "C" {
extern double lbl_2_rodata_E48;

int exchangeMuCharKindToMuStockchkind__6muMenuFiii(int);
int exchangeGmCharacterKind2Something__6muMenuFi(int);
void setFrameTex__8MuObjectFf(void*, f32);
void setFrameVisible__8MuObjectFf(void*, f32);
void fn_2_28004(void*, s32, s32, void*);

void fn_2_27E34(void* self, s32 param) {
    s32 row;
    s32 col;
    s32 i;
    s32 k;
    s32* ent;
    s32 lim;
    void* ob;

    k = *(u8*)((char*)self + 0x67c);
    for (i = 0; i < 5 && k < (s32)*(u8*)(*(char**)((char*)self + 0x678) + 0x8c); i++, k++) {
        ent = *(s32**)((char*)self + 0x678);
        int kind = ent[k];
        int stock = exchangeMuCharKindToMuStockchkind__6muMenuFiii(kind);
        int gm = exchangeGmCharacterKind2Something__6muMenuFi(stock);
        ob = *(void**)((char*)self + 0x64c);
        void* obj = *(void**)((char*)ob + 0x250 + i * 4);
        setFrameTex__8MuObjectFf(obj, (f32)(gm * 10 + 1));
    }

    row = (s32)*(u8*)((char*)self + 0x67d);
    for (col = 0; col < 6 && row < (s32)*(u8*)(*(char**)((char*)self + 0x678) + 0x8c); col++, row++) {
        ent = *(s32**)((char*)self + 0x678);
        fn_2_28004(self, col, row, (void*)((char*)ent + 0x90 + row * 12));
    }

    s32 flag = 0;
    if (param != 0) {
        if ((s32)*(u8*)((char*)self + 0x67d) != 0)
            flag |= 2;
        lim = (s32)*(u8*)(*(char**)((char*)self + 0x678) + 0x8c);
        if ((s32)*(u8*)((char*)self + 0x67d) + 6 < lim)
            flag |= 1;
    }
    ob = *(void**)((char*)self + 0x64c);
    setFrameVisible__8MuObjectFf(*(void**)((char*)ob + 0x230), (f32)flag);

    s32 flag2 = 0;
    if (param != 0) {
        if ((s32)*(u8*)((char*)self + 0x67c) != 0)
            flag2 |= 1;
        ent = *(s32**)((char*)self + 0x678);
        lim = (s32)*(u8*)((char*)ent + 0x8c);
        if ((s32)*(u8*)((char*)self + 0x67c) + 5 < lim)
            flag2 |= 2;
    }
    ob = *(void**)((char*)self + 0x64c);
    setFrameVisible__8MuObjectFf(*(void**)((char*)ob + 0x234), (f32)flag2);
}
}
