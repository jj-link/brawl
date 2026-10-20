#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_116_5F9C(void*, short);
void operator delete(void*);

extern "C" void* fn_116_5F24(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xF0, -1);
        if (object != 0) {
            fn_116_5F9C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
