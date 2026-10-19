#pragma force_active on
extern "C" void fn_41_51BBC(void*, short);

extern "C" char* fn_41_51C88(char* p, short flag) {
    if (p) {
        if (p) {
            fn_41_51BBC(p + 4, -1);
        }
        if (flag > 0) {
            delete p;
        }
    }
    return p;
}
