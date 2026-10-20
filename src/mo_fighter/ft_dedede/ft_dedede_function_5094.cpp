#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_117_510C(void*, short);

// Destroys the embedded member at +0x11C with flag -1 (no independent free),
// then runs the object's own cleanup with flag 0. Only a positive deleting
// flag releases the allocation. The pointer is returned in every case.
extern "C" void* fn_117_5094(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x11C, static_cast<short>(-1));
        if (object != 0) {
            fn_117_510C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
