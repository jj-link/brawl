extern "C" void* fn_99_EE3C(void*, short);
extern "C" void* fn_99_F168(void*, short);

// Destroy the embedded module at 0x1958 before its enclosing base.
// The signed low halfword controls deletion; nonpositive values only destruct.
extern "C" void* fn_99_EDCC(void* object, short deleting) {
    if (object) {
        fn_99_EE3C(static_cast<unsigned char*>(object) + 0x1958, -1);
        fn_99_F168(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
