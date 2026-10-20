#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BF54(void*, short);
extern "C" void* fn_118_BE1C(void*, short);

extern "C" void* fn_118_BFB4(void* object, short deleting) {
    if (object != 0) {
        fn_118_BF54(static_cast<unsigned char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_118_BE1C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
