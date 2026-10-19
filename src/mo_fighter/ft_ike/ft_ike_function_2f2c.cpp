#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_10424(void*, short);
extern "C" void* fn_27_19A97C(void*, short);

extern "C" void* fn_119_2F2C(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 0x7c, -1);
        if (object != 0) {
            fn_27_19A97C(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
