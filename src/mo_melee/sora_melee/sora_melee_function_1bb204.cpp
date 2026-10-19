#pragma force_active on
struct Base {
    virtual void* unused0();
    virtual void* unused1(void*);
};

extern "C" void* fn_27_1BB204(Base* object, void* destination, void* source) {
    void* result = object->unused1(source);
    *(unsigned int*)result = *(unsigned int*)destination;
    return result;
}
