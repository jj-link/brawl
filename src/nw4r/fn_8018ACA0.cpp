#pragma force_active on

struct Target {
    char pad[0xe];
    char m_flag;
};

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Target* v6();
};

extern "C" void fn_8018ACA0(Inner* self, int unused, int arg2) {
    Target* result = self->v6();
    if (result != 0) {
        int tmp = (arg2 == 0);
        result->m_flag = (char)tmp;
    }
}
