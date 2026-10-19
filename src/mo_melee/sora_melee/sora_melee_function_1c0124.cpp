#pragma force_active on
struct Interface {
    virtual void reserved();
    virtual void* call(void*);
};

extern "C" void* fn_27_1C0124(void* obj, void* out, void* arg) {
    void* result = static_cast<Interface*>(obj)->call(arg);
    *static_cast<void**>(result) = *static_cast<void**>(out);
    return result;
}
