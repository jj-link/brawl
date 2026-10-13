void operator delete(void*);
extern "C" void* fn_117_228C(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void* fn_117_17F04(void*, short);
extern "C" void* fn_117_1F1B8(void*, short);

// Destroy embedded members in reverse construction order. Only the outer
// object's positive deleting flag releases its allocation.
extern "C" void* fn_117_1F234(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_228C(storage + 0x279C, -1);
        fn_27_C7770(storage + 0x278C, -1);
        fn_117_228C(storage + 0x2770, -1);
        fn_27_C7770(storage + 0x2760, -1);
        fn_117_228C(storage + 0x2744, -1);
        fn_27_C7770(storage + 0x2734, -1);
        fn_117_17F04(storage + 0x2650, -1);
        fn_117_1F1B8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
