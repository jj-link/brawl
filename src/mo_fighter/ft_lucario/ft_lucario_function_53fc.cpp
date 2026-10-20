#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void* fn_118_5474(void*, short);

extern "C" void* fn_118_53FC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, -1);
        if (object != 0) {
            fn_118_5474(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
