#pragma force_active on
extern "C" {
void fn_27_CB4A0(void*, short);
void fn_27_CAE44(void*, short);
void fn_27_CE2E8(void*, short);
void fn_41_2CBC(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_41_5023C(void* arg0, short arg1) {
    if (arg0 != 0) {
        char* p = static_cast<char*>(arg0);
        short d = -1;
        fn_27_CB4A0(p + 0x58E0, d);
        __destroy_arr(p + 0x57B8, fn_41_2A480, 8, 0x25);
        __destroy_arr(p + 0x5788, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CAE44(p + 0x555C, d);
        fn_27_CE2E8(p + 0x5310, d);
        fn_41_2CBC(arg0, static_cast<short>(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
