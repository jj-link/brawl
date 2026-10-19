#pragma force_active on
extern "C" void fn_27_689B0(void* p, short v);
extern "C" void* fn_27_1985B4(void* p, short v);
void operator delete(void*);

extern "C" void* fn_95_72BC(void* object, short deleting) {
    if (object != 0) {
        fn_27_689B0(static_cast<unsigned char*>(object) + 0x7C, -1);
        if (object != 0) {
            fn_27_1985B4(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
