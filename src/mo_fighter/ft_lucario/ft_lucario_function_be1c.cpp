#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BDBC(void*, short);
extern "C" void* fn_118_BC88(void*, short);

extern "C" void* fn_118_BE1C(void* object, short deleting) {
    if (object != 0) {
        fn_118_BDBC(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_118_BC88(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
