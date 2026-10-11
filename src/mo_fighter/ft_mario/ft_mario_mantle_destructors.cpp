// The two interfaces have no owned teardown work; positive deleting flags
// release storage, while null pointers and nonpositive flags are preserved.
extern "C" void* fn_91_10080(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
extern "C" void* fn_91_100C0(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
