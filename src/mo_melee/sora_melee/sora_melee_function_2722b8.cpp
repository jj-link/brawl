#include <types.h>
#pragma force_active on

struct Inner {
    int pad0[7];
    u8 unk1C;
};
struct Node {
    int unk0;
    Node* unk4;
    Inner* unk8;
};
struct Ctx {
    int pad0;
    Node* unk4;
    int pad8;
    Node* unkC;
    u32 unk10;
    int pad14;
    u8 unk18;
};

extern "C" void fn_27_2722B8(Ctx* arg0, u8 arg1) {
    u32 count = arg0->unk10;
    u32 i;
    arg0->unkC = arg0->unk4;
    for (i = 0; i < count; ++i) {
        arg0->unkC->unk8->unk1C = arg1;
        arg0->unkC = arg0->unkC->unk4;
    }
    arg0->unk18 = arg1;
}
