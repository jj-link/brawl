#pragma force_active on
struct HealObj {
    char pad[0x184];
    char m_184;
    int m_188;
    float m_18c;
};

extern "C" void fn_87_D70(HealObj* self, char a, int b, float c) {
    self->m_184 = a;
    self->m_188 = b;
    self->m_18c = c;
}
