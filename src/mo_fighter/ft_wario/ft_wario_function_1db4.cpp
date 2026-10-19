#pragma force_active on
extern "C" {

void fn_110_1BE0(void* obj, short flag);
void __dl__FPv(void* ptr);

void* fn_110_1DB4(void* obj, short mode) {
    if (obj) {
        fn_110_1BE0(obj, (short)0);
        if (mode > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

}
