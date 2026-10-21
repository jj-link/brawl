#pragma force_active on

struct Obj {
    char pad0[4];
    int m_4;
    char m_8;
    char m_9;
};

extern "C" void fn_801C6B94(Obj* obj) {
    obj->m_4 = 0;
    obj->m_8 = 0x2f;
    obj->m_9 = 0;
}
