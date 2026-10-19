#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_126_4228(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_41BC(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_126_4228(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
