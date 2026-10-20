#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_C0F8(void* object, short deleting);
extern "C" void fn_115_BFC0(void* object, short deleting);

extern "C" void* fn_115_C158(void* object, short deleting) {
    if (object != 0) {
        fn_115_C0F8(static_cast<unsigned char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_115_BFC0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
