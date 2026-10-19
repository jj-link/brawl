#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_99_3F2C(void*, short);

// Destroy the embedded module at 0x10 before its enclosing base.
// The signed low halfword controls deletion; nonpositive values only destruct.
extern "C" void* fn_99_5030(void* object, short deleting) {
    if (object) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_99_3F2C(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
