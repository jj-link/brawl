#pragma force_active on
struct Base {
    virtual void unused0();
    virtual void* call(void*);
};

extern "C" void* fn_27_1E6B5C(Base* arg0, void* arg1, void* arg2) {
    void* result = arg0->call(arg2);
    *static_cast<void**>(result) = *static_cast<void**>(arg1);
    return result;
}
