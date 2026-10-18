#pragma force_active on
typedef unsigned char u8;

struct FlagStruct {
    u8 pad[0xc];
    u8 flag : 1;
    u8 rest : 7;
};

extern "C" bool fn_27_A7C84(FlagStruct* p) {
    return p->flag != 0;
}
