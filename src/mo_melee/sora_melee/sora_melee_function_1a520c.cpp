#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 hi : 3;
    u32 mid : 3;
    u32 lo : 26;
};

struct FieldHolder {
    u32 unk0;
    u32 unk4;
    FieldWord word;
};

extern "C" void fn_27_1A520C(FieldHolder* p, u32 v)
{
    p->word.mid = v;
}
