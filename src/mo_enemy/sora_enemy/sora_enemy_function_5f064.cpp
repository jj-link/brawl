#pragma force_active on
extern "C" {
void* fn_41_5EFF4(void*, short);
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CA210(void*, short);
void* fn_27_D1120(void*, short);
void* fn_41_2CBC(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_41_5F064(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short v = -1;
        fn_41_5EFF4(members + 0x6358, v);
        fn_27_CB4A0(members + 0x6308, v);
        __destroy_arr(members + 0x6248, fn_41_2A480, 8, 0x18);
        __destroy_arr(members + 0x6200, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CA210(members + 0x5F4C, v);
        fn_27_D1120(members + 0x5310, v);
        fn_41_2CBC(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
