#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_15260(void*, short);
extern "C" void* fn_112_5958(void*, short);

extern "C" void* fn_112_151F0(void* object, short deleting) {
    if (object != 0) {
        fn_112_15260(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_112_5958(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
