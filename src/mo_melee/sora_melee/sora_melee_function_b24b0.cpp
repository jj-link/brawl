#pragma force_active on
extern "C" void fn_27_B1774(int);

struct Arr {
    virtual void v0() = 0;
    virtual int get(int i) = 0;
    virtual void v2() = 0;
    virtual int size() = 0;
};

struct Holder {
    char pad[0x18];
    Arr* m_arr;
};

extern "C" void fn_27_B24B0(Holder* self) {
    int n = self->m_arr->size();
    for (int i = 0; i < n; i++) {
        fn_27_B1774(self->m_arr->get(i));
    }
}
