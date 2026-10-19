#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_334C(void*, short);
extern "C" void* fn_112_5958(void*, short);

extern "C" void* fn_112_32DC(void* object, short deleting) {
    if (object != 0) {
        fn_112_334C(static_cast<unsigned char*>(object) + 8, -1);
        fn_112_5958(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
