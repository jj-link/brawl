#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_3440(void*, short);
extern "C" void* fn_95_6138(void*, short);

extern "C" void* fn_95_33D0(void* object, short deleting) {
    if (object != 0) {
        fn_95_3440(static_cast<unsigned char*>(object) + 8, -1);
        fn_95_6138(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
