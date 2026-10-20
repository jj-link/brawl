#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_C0E8(void*, short);
extern "C" void* fn_118_BFB4(void*, short);

extern "C" void* fn_118_C148(void* object, short deleting) {
    if (object != 0) {
        fn_118_C0E8(static_cast<unsigned char*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_118_BFB4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
