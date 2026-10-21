#pragma force_active on
extern "C" {

void* fn_27_C9550(void*, short);
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CA7E4(void*, short);
void* fn_27_CF2D8(void*, short);
void* fn_41_2CBC(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_35344(void* arg0, short arg1) {
    if (arg0) {
        short v = -1;
        fn_27_C9550((char*)arg0 + 0x5d0c, v);
        fn_27_CB4A0((char*)arg0 + 0x5cbc, v);
        __destroy_arr((char*)arg0 + 0x5bdc, fn_41_2A480, 8, 0x1c);
        __destroy_arr((char*)arg0 + 0x5b7c, __dt__18emTargetSearchUnitFv, 0x18, 4);
        fn_27_CA7E4((char*)arg0 + 0x57fc, v);
        fn_27_CF2D8((char*)arg0 + 0x5310, v);
        fn_41_2CBC(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
