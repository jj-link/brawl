#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_96_2758(void*, short);
extern "C" void* fn_96_26BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_37A8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_96_2758(storage + 0x18, destroyMember);
        fn_96_26BC(storage + 0x4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
