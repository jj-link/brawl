#pragma force_active on
struct fn_27_EFFA8_Interface {
    virtual void* slot0();
    virtual void* function(void*);
};

extern "C" void* fn_27_EFFA8(fn_27_EFFA8_Interface* self, void* source, void* arg, void* unused) {
    void* result = self->function(arg);
    *static_cast<void**>(result) = *static_cast<void**>(source);
    return result;
}
