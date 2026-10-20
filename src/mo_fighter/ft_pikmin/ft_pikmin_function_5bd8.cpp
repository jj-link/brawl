#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_113_5C50(void*, short);
void* fn_113_5CB0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_113_5BD8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_113_5C50(storage + 0x18, destroyMember);
        fn_113_5CB0(storage + 0x4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
