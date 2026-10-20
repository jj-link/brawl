#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_C27C(void*, short);
extern "C" void* fn_118_C148(void*, short);

extern "C" void* fn_118_C2DC(void* object, short deleting) {
    if (object != 0) {
        fn_118_C27C(static_cast<unsigned char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_118_C148(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
