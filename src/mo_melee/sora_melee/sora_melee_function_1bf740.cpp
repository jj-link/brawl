#pragma force_active on
struct Obj {
    virtual void* fn0(int);
    virtual void* fn1(int);
};

extern "C" void fn_27_1BF740(Obj* obj, unsigned int* src, int arg) {
    void* result = obj->fn1(arg);
    *(unsigned int*)result = *src;
}
