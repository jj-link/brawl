#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);

struct X {
    virtual void foo();
};

extern "C" void* fn_126_2E1C(void* p, short s) {
    if (p) {
        fn_27_A0C34(p, -1);
        if (s > 0) {
            X* obj = (X*)p;
            delete obj;
        }
    }
    return p;
}
