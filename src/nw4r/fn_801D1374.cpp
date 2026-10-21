#pragma force_active on
struct SomeObj {
    char pad[0xb1];
    unsigned char flags;
    char pad2[0x6e];
    int m_unk;
};

extern "C" void fn_801D1374(SomeObj* obj, int value) {
    if (value == obj->m_unk)
        return;
    obj->m_unk = value;
    obj->flags |= 0x10;
}
