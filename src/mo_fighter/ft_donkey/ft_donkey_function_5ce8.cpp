#pragma force_active on
extern "C" void fn_92_5D54(void*, short);
extern "C" void fn_92_4154(void*, short);
void operator delete(void*);

extern "C" void* fn_92_5CE8(void* object, short deleting) {
    if (object != 0) {
        fn_92_5D54((char*)object + 0x24, (short)-1);
        fn_92_4154(object, (short)-1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
