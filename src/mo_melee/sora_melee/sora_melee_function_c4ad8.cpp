#pragma force_active on
struct Interface {
    virtual void slot0();
    virtual unsigned int* slot1(unsigned int*);
};

extern "C" void fn_27_C4AD8(Interface* object, unsigned int* destination, unsigned int* source) {
    unsigned int* result = object->slot1(source);
    *result = *destination;
}
