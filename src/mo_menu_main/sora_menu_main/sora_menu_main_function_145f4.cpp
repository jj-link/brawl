#pragma force_active on

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void call(int);
};

struct Outer {
    char pad[0x64C];
    char* m_arr;
    int unk;
    Target* m_target;
};

extern "C" void fn_2_145F4(Outer* self) {
    for (unsigned i = 0; i < 3; i++) {
        int q = *(int*)(self->m_arr + i * 4 + 0x90);
        self->m_target->call(*(int*)(q + 0x10));
    }
}
