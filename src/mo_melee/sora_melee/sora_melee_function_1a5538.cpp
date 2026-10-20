#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FlagHolder {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_1A5538(FlagHolder* p) {
    p->flags |= 0x00080000;
}
}
