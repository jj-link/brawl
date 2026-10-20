#pragma force_active on
struct StageEditObj {
    char pad[0x184];
    unsigned char m_184;
    int m_188;
    float m_18c;
};

extern "C" void fn_85_538C(StageEditObj* obj, unsigned char a, int b, float c) {
    obj->m_184 = a;
    obj->m_188 = b;
    obj->m_18c = c;
}
