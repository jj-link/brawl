#pragma force_active on
extern "C" void* fn_115_4118(void*, short);
extern "C" void* fn_115_44E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_447C(void* object, short deleting) {
    if (object != 0) {
        fn_115_4118(static_cast<unsigned char*>(object) + 0x1FC4, -1);
        fn_115_44E8(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
