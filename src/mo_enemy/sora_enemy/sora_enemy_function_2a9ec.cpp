#pragma force_active on
extern "C" void* fn_41_15FD4(char* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1F060(void* p);

struct Obj {
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
};

extern "C" void fn_41_2A9EC(void* unused, void* self, void* obj) {
    ((Obj*)obj)->v11();
    for (int i = 0; i < 8; i++) {
        if (i != 0) {
            void* p = fn_41_15FD4((char*)self, i);
            if (!fn_41_1AE7C(p)) {
                fn_41_1F060(p);
            }
        }
    }
}
