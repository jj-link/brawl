#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct FlagHolder {
    u8 pad[8];
    u32 flags;
};

extern "C" void fn_27_19ED90(FlagHolder* p) {
    p->flags &= 0xFFFEFFFF;
}
