#pragma force_active on
struct FnObject {
    virtual void unused();
    virtual void* call(void*);
};

extern "C" void* fn_27_1BA820(FnObject* object, void** output, void* argument) {
    void* result = object->call(argument);
    *static_cast<void**>(result) = *output;
    return result;
}
