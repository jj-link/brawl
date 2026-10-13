void operator delete(void*);
extern "C" void* fn_117_A614(void*, short);

// The original lifetime wrapper invokes the nondeleting base operation on the
// same receiver. Its complete layout and concrete hierarchy remain opaque.
extern "C" void* fn_117_C58C(void* object, short deleting) {
    if (object != 0) {
        fn_117_A614(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
