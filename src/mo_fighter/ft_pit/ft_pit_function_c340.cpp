#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_C2E0(void* object, short deleting);
extern "C" void fn_112_C1B0(void* object, short deleting);

extern "C" void* fn_112_C340(void* object, short deleting) {
    if (object != 0) {
        fn_112_C2E0((unsigned char*)object + 0x94, -1);
        if (object != 0) {
            fn_112_C1B0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
