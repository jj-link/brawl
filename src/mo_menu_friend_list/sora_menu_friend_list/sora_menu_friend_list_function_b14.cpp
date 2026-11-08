#include <types.h>
#include <ut/ut_relocate.h>
#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
extern char lbl_14_data_50[];
void* fn_8004E5C4(void*);
int exchangeMuCharKindToMuStockchkind__6muMenuFiii(int);
int fn_800AF6F0(int);
int isCharUsable__6muMenuFiii(int);
u16 fn_80034278(void*);
}
static inline bool usable(int want) {
    for (int k = 0; k < 0x23; ++k) {
        if (fn_800AF6F0(exchangeMuCharKindToMuStockchkind__6muMenuFiii(k)) == want && isCharUsable__6muMenuFiii(k))
            return true;
    }
    return false;
}
extern "C" int fn_14_B14(char* base, u8* out, int max, u8* fileBuf, u32 fileSz) {
    int count = 0;
    char* mgr = (char*)fn_8004E5C4(g_GameGlobal);
    utRelocate rel(fileBuf, fileSz);
    u8* tbl = (u8*)rel.getPublicAddress(lbl_14_data_50);
    int i = 0;
    u8* p = tbl;
    for (; *p != 0xff && i < 0x80; p += 3)
        base[0x2a39 + i++] = *p;
    for (; i < 0x80; ++i)
        base[0x2a39 + i] = 0;
    int idx = 0;
    int zero = 0;
    for (p = tbl; *p != 0xff && count < max; p += 3, ++idx) {
        int ok = 0;
        switch (p[1]) {
        case 1:
            if (usable(p[2])) ok = 1;
            break;
        case 2:
            if (isCharUsable__6muMenuFiii(p[2])) ok = 1;
            break;
        case 3:
            if (*(u32*)(mgr + 0x804) >> 31) ok = 1;
            break;
        case 0:
        default:
            ok = 1;
            break;
        }
        if (ok) {
            out[0] = idx;
            ++count;
            *(u16*)(out + 2) = zero;
            out += 4;
        }
    }
    u16 extra;
    if (*(void**)(base + 0x2a2c) == 0)
        extra = 0;
    else
        extra = fn_80034278(*(void**)(base + 0x2a2c));
    for (u16 j = 0; j < extra && count < max; ++j) {
        out[0] = (u8)0xff;
        ++count;
        *(u16*)(out + 2) = j;
        out += 4;
    }
    return count;
}