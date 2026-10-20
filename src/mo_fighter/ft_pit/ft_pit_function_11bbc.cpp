#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_11B5C(void* object, short deleting);
extern "C" void* fn_112_11A8C(void* object, short deleting);

extern "C" void* fn_112_11BBC(void* object, short deleting) {
    if (object != 0) {
        fn_112_11B5C(static_cast<unsigned char*>(object) + 0xA8, -1);
        if (object != 0) {
            fn_112_11A8C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
