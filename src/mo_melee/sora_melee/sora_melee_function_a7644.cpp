#pragma force_active on
struct Inner {
    char pad[0x14];
    void* m_14;
};
struct Outer {
    char pad[4];
    Inner* m_4;
};

extern "C" void fn_27_A7644(Outer* self, void* arg) {
    self->m_4->m_14 = arg;
}
