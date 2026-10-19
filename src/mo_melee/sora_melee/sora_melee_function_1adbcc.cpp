#pragma force_active on
class fn_27_1ADBCC_VTable {
public:
    virtual void method0();
    virtual void* method1(void*);
};

extern "C" void* fn_27_1ADBCC(fn_27_1ADBCC_VTable* a, void* b, void* c) {
    void* result = a->method1(c);
    *(void**)result = *(void**)b;
    return result;
}
