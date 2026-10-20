#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad[0x40];
    u8 m_40;
};

extern "C" {
bool fn_27_246AAC(Obj* p) {
    return p->m_40 == 5;
}
}
