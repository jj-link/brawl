#pragma force_active on
struct Fn27Object {
    virtual void slot0();
    virtual void* call(void*);
};

extern "C" void* fn_27_1BBBE8(Fn27Object* object, void* value, void* argument) {
    void* result = object->call(argument);
    *(void**)result = *(void**)value;
    return result;
}
