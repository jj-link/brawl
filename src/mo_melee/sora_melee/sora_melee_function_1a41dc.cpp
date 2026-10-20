#pragma force_active on
struct FTThing {
    int m_0;
    int m_4;
    int m_8;
    int m_c[1];
};

extern "C" int* fn_27_1A41DC(FTThing* self, int index) {
    return &self->m_c[index];
}
