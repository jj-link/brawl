#pragma force_active on
extern "C" void* fn_99_323C(void*, short);
extern "C" void* fn_99_41E0(void*, short);

// Destroy the embedded module at 0x8 before its enclosing base.
// The signed low halfword controls deletion; nonpositive values only destruct.
extern "C" void* fn_99_31CC(void* object, short deleting) {
    if (object) {
        fn_99_323C(static_cast<unsigned char*>(object) + 8, -1);
        fn_99_41E0(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
