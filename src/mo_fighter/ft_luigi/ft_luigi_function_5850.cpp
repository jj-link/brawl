#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_99_58C8(void*, short);
extern "C" void* fn_99_5928(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_5850(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_99_58C8(storage + 0x18, destroyMember);
        fn_99_5928(storage + 0x4, destroyMember);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
