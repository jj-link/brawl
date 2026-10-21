#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct FnDdadSub {
    u8 pad0[2];
    u16 unk2;
};

struct FnDdadObj {
    u8 pad0[0x2C];
    FnDdadSub *unk2C;
};

extern "C" {
void fn_802DE264(void *, u16, s32);

void fn_802DDAD4(FnDdadObj *arg0, s32 arg1) {
    FnDdadSub *temp_r3 = arg0->unk2C;
    fn_802DE264(temp_r3, temp_r3->unk2, arg1);
}
}
