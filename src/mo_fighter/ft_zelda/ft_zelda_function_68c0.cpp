#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_150488(void*, short);
void* fn_104_6940(void*, short);
void* fn_27_199A54(void*, short);

void* fn_104_68C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_150488((unsigned char*)object + 0x5B8, -1);
        fn_104_6940((unsigned char*)object + 0x584, -1);
        if (object != 0) {
            fn_27_199A54(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
