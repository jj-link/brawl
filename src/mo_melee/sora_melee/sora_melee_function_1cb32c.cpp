#pragma force_active on
struct CopyTarget {
    virtual void unused0();
    virtual void* get(void*);
    virtual void unused1();
};

extern "C" void* fn_27_1CB32C(void* object, void* destination, void* source) {
    void* result = static_cast<CopyTarget*>(object)->get(source);
    *static_cast<unsigned int*>(result) = *static_cast<unsigned int*>(destination);
    return result;
}
