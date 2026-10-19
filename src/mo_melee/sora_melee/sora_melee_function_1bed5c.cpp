#pragma force_active on
struct V {
    virtual void f0();
    virtual void* f(void*);
};

extern "C" void* fn_27_1BED5C(V* a, void* b, void* c, void* d) {
    void* result = a->f(c);
    *(void**)result = *(void**)b;
    return result;
}
