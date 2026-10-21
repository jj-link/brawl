#pragma force_active on
// fn_801505B0

typedef unsigned char u8;

extern "C" {

struct Unknown {
    u8 _0[0x1C];
};

extern Unknown* g_GameGlobal;

void fn_801505B0(int value) {
    Unknown* ptr = *(Unknown**)((char*)g_GameGlobal + 0x38);
    ptr->_0[0x18] = (u8)value;
}

} // extern "C"
