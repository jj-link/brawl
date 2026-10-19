#pragma force_active on
extern "C" void* fn_27_10424(void*, short);
extern "C" void* fn_27_19A97C(void*, short);
void operator delete(void*);

extern "C" void* fn_113_1B18(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 0x7C, -1);
        if (object != 0) {
            fn_27_19A97C(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
