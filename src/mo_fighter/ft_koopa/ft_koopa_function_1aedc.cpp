#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_102_1AF60(void*, short);
void* fn_102_3E54(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_102_1AEDC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x20, destroyMember);
        fn_102_1AF60(storage + 0x10, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_102_3E54(object, destroyBase);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
