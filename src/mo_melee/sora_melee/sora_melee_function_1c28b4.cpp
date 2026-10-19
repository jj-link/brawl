#pragma force_active on
struct V {
    virtual void* f0();
    virtual void* f1(void*);
};

extern "C" void* fn_27_1C28B4(V* a, void* b, void* c) {
    void* result = a->f1(c);
    *(void**)result = *(void**)b;
    return result;
}
