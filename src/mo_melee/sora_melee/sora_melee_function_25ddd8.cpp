#pragma force_active on
struct FnState {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

extern "C" int fn_27_25DDD8(FnState* self) {
    if (self->m_10 >= 2) {
        self->m_08 = 7;
        self->m_0c = 4;
        return 1;
    }
    return 0;
}
