#pragma force_active on
struct Obj {
    char pad[0x40];
    unsigned char m_40;
};

extern "C" {
bool fn_27_243D48(Obj* obj) {
    return obj->m_40 == 7;
}
}
