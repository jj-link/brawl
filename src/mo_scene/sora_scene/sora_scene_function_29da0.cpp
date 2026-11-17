#include <types.h>
#pragma force_active on

struct S { char pad[0x11]; u8 m; };
struct Rec {
    char pad[0x34D4];
    union {
        u16 flags;
        struct { u16 top : 1; u16 mid : 7; u16 count : 3; u16 low : 5; } bits;
    };
    char pad2[6];
    u32 value;
    char pad3[0x3528 - 0x34E0];
    u8 k1;
    u8 a2;
    u8 k2;
    u8 a4;
};
struct G { char pad[0x24]; Rec* rec; };

extern "C" {
extern G* g_GameGlobal;
void fn_1_29EB4(S* self);
int exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int c);
}

extern "C" void fn_1_29DA0(S* self, int a1, int a2, int a3, int a4, int a5, u32 a6)
{
    Rec* rec = g_GameGlobal->rec;
    u8 k1 = (u8)exchangeGmCharacterKindToMuCharKind__6muMenuFiii(a1);
    u8 k2 = (u8)exchangeGmCharacterKindToMuCharKind__6muMenuFiii(a3);
    u16 f = rec->flags;
    int set = 0;

    if (!((f >> 15) & 1)) {
        if (a5 != 0) {
            set = 1;
            rec->flags = f | 0x8000;
        } else if (rec->value < a6) {
            set = 1;
        }
    } else if (a5 != 0 && rec->value > a6) {
        set = 1;
    }

    if (a5 != 0) {
        int n = self->m + 1;
        if ((int)rec->bits.count < n) {
            rec->bits.count = n;
        }
        fn_1_29EB4(self);
    }

    if (set != 0) {
        rec->value = a6;
        rec->k1 = k1;
        rec->k2 = k2;
        rec->a2 = a2;
        rec->a4 = a4;
        rec->flags |= 1;
    }
}
