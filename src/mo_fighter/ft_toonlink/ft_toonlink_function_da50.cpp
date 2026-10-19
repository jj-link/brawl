#pragma force_active on
extern "C" {

void fn_121_D9D8(void*, short);
void __dl__FPv(void*);

void* fn_121_DA50(void* arg1, short arg2) {
    if (arg1) {
        fn_121_D9D8(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}

}
