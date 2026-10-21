#pragma force_active on
extern "C" {

void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CA210(void*, short);
void* fn_27_D0AC0(void*, short);
void* fn_41_2CBC(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_390B0(void* arg0, short arg1) {
    if (arg0) {
        short v = -1;
        fn_27_CB4A0((char*)arg0 + 0x6068, v);
        __destroy_arr((char*)arg0 + 0x5fd8, fn_41_2A480, 8, 0x12);
        __destroy_arr((char*)arg0 + 0x5f90, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CA210((char*)arg0 + 0x5cdc, v);
        fn_27_D0AC0((char*)arg0 + 0x5310, v);
        fn_41_2CBC(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
