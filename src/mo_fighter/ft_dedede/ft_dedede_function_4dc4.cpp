#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_1A1FE4(void*, short);
void fn_117_4E3C(void*, short);
}

// Destroy the embedded member at +0x244 (flag -1), then the base object (flag 0);
// only a positive deleting flag releases the allocation.
extern "C" void* fn_117_4DC4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<unsigned char*>(object) + 0x244, static_cast<short>(-1));
        if (object != 0) {
            fn_117_4E3C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
