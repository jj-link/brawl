#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_117_5274(void*, short);

// Destroy the member at +0x88 with flag -1, then run the base cleanup with
// flag 0. Only a positive deleting flag releases the allocation.
extern "C" void* fn_117_51FC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x88, static_cast<short>(-1));
        if (object != 0) {
            fn_117_5274(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
