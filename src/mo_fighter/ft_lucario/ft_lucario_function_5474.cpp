#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_118_54EC(void*, short);

extern "C" void* fn_118_5474(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x318, -1);
        if (object != 0) {
            fn_118_54EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
