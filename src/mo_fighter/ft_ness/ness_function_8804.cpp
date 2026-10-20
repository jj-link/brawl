#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_47CCC(void*, short);
extern "C" void* fn_27_19958C(void*, short);
extern "C" void* fn_27_19FCBC(void*, short);
extern "C" void* fn_27_19D830(void*, short);

extern "C" void* fn_101_8804(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_48BE8(members + 0x844, memberDeleting);
        fn_27_47CCC(members + 0x834, memberDeleting);
        fn_27_19958C(members + 0x6C0, memberDeleting);
        fn_27_19FCBC(members + 0x48C, memberDeleting);
        fn_27_19D830(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
