#pragma force_active on
extern "C" void fn_27_1A18A0(void* object, short deleting);
extern "C" void fn_115_4D60(void* object, short deleting);
extern void operator delete(void*);

extern "C" void* fn_115_4CE8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A18A0(storage + 0x354, -1);
        if (object != 0) {
            fn_115_4D60(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
