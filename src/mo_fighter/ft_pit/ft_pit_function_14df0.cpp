#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_14E64(void*, short);
extern "C" void* fn_112_14F80(void*, short);

extern "C" void* fn_112_14DF0(void* object, short deleting) {
    if (object != 0) {
        fn_112_14E64(static_cast<unsigned char*>(object) + 0x17958, -1);
        fn_112_14F80(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
