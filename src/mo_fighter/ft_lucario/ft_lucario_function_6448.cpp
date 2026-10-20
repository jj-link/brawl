#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_118_64C0(void*, short);
extern "C" void* fn_118_6520(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_6448(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x30, -1);
        fn_118_64C0(storage + 0x18, -1);
        fn_118_6520(storage + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
