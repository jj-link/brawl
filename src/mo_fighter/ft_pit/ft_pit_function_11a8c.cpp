#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_11A2C(void*, short);
extern "C" void* fn_112_11968(void*, short);

extern "C" void* fn_112_11A8C(void* object, short deleting) {
    if (object != 0) {
        fn_112_11A2C(static_cast<unsigned char*>(object) + 0x58, -1);
        fn_112_11968(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
