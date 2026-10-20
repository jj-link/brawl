#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_DD98(void* object, short deleting);
extern "C" void fn_95_DC64(void* object, short deleting);

extern "C" void* fn_95_DDF8(void* object, short deleting) {
    if (object != 0) {
        fn_95_DD98(static_cast<unsigned char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_95_DC64(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
