#pragma force_active on
struct Fn27Base {
    virtual ~Fn27Base();
    virtual void* call(void* source);
};

struct Fn27Object : Fn27Base {};

extern "C" void* fn_27_1C0B08(Fn27Object* object, void* destination, void* source) {
    void* result = object->call(source);
    *static_cast<void**>(result) = *static_cast<void**>(destination);
    return result;
}
