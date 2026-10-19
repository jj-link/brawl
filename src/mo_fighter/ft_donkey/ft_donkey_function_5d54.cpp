#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_92_4114(void*, short);

extern "C" void* fn_92_5D54(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_92_4114(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
