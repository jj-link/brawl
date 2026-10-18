#pragma force_active on
extern "C" void __dl__FPv(void*);

// Deleting-destructor ABI for a leaf object with no member teardown.
extern "C" void* fn_99_3F2C(void* object, short deleting) {
    if (object && deleting > 0) {
        __dl__FPv(object);
    }
    return object;
}
