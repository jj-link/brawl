#include "types.h"
#pragma force_active on

struct Struct_B4 {
    char pad[0xB4];
    unsigned int unkB4;
};

struct Struct_40 {
    char pad[0x40];
    Struct_B4* unk40;
};

extern "C" {
void fn_2_31A5C(Struct_40*, unsigned int, int);
void fn_2_31EB8(Struct_40*, int, int);

void fn_2_34A9C(Struct_40* arg0) {
    fn_2_31A5C(arg0, arg0->unk40->unkB4, -1);
    fn_2_31EB8(arg0, 2, 0x1f);
}
}
