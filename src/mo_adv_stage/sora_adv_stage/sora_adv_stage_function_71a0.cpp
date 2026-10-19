#pragma force_active on
extern "C" {
extern unsigned char* g_GameGlobal;

struct Flags {
    unsigned char bit : 1;
    unsigned char pad : 7;
};

bool fn_40_71A0(void) {
    unsigned char* base = *(unsigned char**)(g_GameGlobal + 0x30);
    Flags* f = (Flags*)(base + 0x4924);
    return f->bit;
}
}
