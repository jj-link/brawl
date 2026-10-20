#pragma force_active on
struct fn_27_Obj {
    char pad[0x40];
    unsigned char m_40;
};

extern "C" {
int fn_27_2498C8(fn_27_Obj* p) {
    return p->m_40 == 5;
}
}
