#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on
struct S { char pad[0x11]; u8 m; };
struct Record { char pad[0x9c]; union { u16 flags; struct { u16 a : 11; u16 count : 3; u16 b : 2; } bits; }; char pad2[0xa]; u32 value; };
extern "C" int exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int);
extern "C" Record* fn_8004E5D8(GameGlobal*, int);
extern "C" void fn_1_29EB4(S*);
extern "C" void fn_1_29CC0(S* self, int character, int flag, u32 value) {
    u8 kind = exchangeGmCharacterKindToMuCharKind__6muMenuFiii(character);
    if (kind < 0x23) {
        Record* record = fn_8004E5D8(g_GameGlobal, kind);
        u16 flags = record->flags;
        if (!((flags >> 15) & 1)) {
            if (flag) {
                record->flags = flags | 0x8000;
                record->value = value;
            } else if (record->value < value) {
                record->value = value;
            }
        } else if (flag && record->value > value) {
            record->value = value;
        }
        if (flag) {
            int count = self->m + 1;
            u16 f = record->flags;
            if (((f >> 2) & 7) < count) {
                record->bits.count = count;
            }
            fn_1_29EB4(self);
        }
    }
}