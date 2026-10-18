#pragma force_active on
extern "C" void* fn_110_3F20(void*, short);
extern "C" void* fn_110_3FA4(void*, short);
extern "C" void* fn_110_FB28(void*, short);
extern "C" void* fn_110_4004(void*, short);
extern "C" void* fn_110_FB84(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

void operator delete(void*);

extern "C" void* fn_110_FA8C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_110_3F20(p + 0x190, -1);
        fn_110_3FA4(p + 0x17C, -1);
        fn_110_FB28(p + 0x124, -1);
        fn_110_4004(p + 0x80, -1);
        fn_110_FB84(p + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
