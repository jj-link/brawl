#pragma force_active on
extern "C" char* fn_41_51C88(char* p, short flag);
extern "C" void* fn_41_33D4C(void* p, short n);

extern "C" char* fn_41_51CEC(char* p, short flag) {
    if (p) {
        fn_41_51C88(p + 8, -1);
        fn_41_33D4C(p, 0);
        if (flag > 0) {
            delete p;
        }
    }
    return p;
}
