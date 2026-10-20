#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_92_5528(void*, short);

extern "C" void* fn_92_54B0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x470, -1);
        if (object != 0) {
            fn_92_5528(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
