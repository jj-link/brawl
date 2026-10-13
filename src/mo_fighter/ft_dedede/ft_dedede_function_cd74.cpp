void operator delete(void*);
extern "C" void* fn_117_A614(void*, short);

// Run the nondeleting base lifetime operation on the unchanged receiver.
// Only a positive signed destructor flag releases the allocation.
extern "C" void* fn_117_CD74(void* object, short deleting) {
    if (object != 0) {
        fn_117_A614(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
