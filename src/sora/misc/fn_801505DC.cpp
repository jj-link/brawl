#pragma force_active on

struct GameGlobal {
    unsigned char padding[0x38];
    int* field38;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_801505DC(unsigned char val) {
    int* p = g_GameGlobal->field38;
    unsigned char* dst = (unsigned char*)p;
    dst[0x19] = val;
}
