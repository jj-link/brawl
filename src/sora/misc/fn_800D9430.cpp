#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" u8 fn_800C8548();
extern "C" s32 exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int kind);
extern "C" s32 getNumCharColor__6muMenuFiii(int kind);
extern "C" void netReport__FPCce(const char*, ...);

extern char lbl_804599B8[];
extern char lbl_804599D8[];

static s32 countCharColors(s32 kind) {
    s32 k = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
    if (k == 0x28) {
        return 1;
    }
    return getNumCharColor__6muMenuFiii(k);
}

extern "C" u8 fn_800D9430(char* self, s32 kind, s32 count) {
    u8 idx = fn_800C8548();
    char* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = self + idx * 0x218 + 0x70;
    }
    if (p == 0) {
        netReport__FPCce(lbl_804599B8);
        return 0;
    }
    char* base = p + 0xE4;
    u8 cur = 0;
    while ((s32)cur < countCharColors(kind)) {
        char* ptr = base;
        s32 i;
        for (i = 0; i < count; i++) {
            if (kind == (s32)(u8)ptr[3] && cur == (u8)ptr[4]) {
                break;
            }
            ptr += 0xA;
        }
        if (i == count) {
            return (u8)cur;
        }
        cur++;
    }
    netReport__FPCce(lbl_804599D8, kind);
    return 0;
}
