#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_4AD0(void* object, short deleting);

extern "C" void* fn_110_4A0C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_110_4AD0((unsigned char*)object + 4, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
