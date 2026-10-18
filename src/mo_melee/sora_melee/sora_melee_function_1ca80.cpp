#pragma force_active on
typedef unsigned char u8;

struct FnObj15C {
    char pad[0x164];
    u8 a : 4;
    u8 flag : 1;
    u8 b : 3;
};

extern "C" {
bool fn_27_1CA80(FnObj15C* p) {
    return p->flag != 0;
}
}
