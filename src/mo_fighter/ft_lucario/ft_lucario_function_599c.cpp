#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_118_5A14(void*, short);

extern "C" void* fn_118_599C(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_118_5A14(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
