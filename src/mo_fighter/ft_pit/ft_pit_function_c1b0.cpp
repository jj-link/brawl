#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_C150(void*, short);
extern "C" void* fn_112_C030(void*, short);

extern "C" void* fn_112_C1B0(void* object, short deleting) {
    if (object != 0) {
        fn_112_C150(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_112_C030(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
