#pragma force_active on
extern "C" {
void fn_119_B5BC(void* p, short n);
void* fn_119_B634(void* p, short flag) {
    if (p != 0) {
        short zero = 0;
        fn_119_B5BC(p, zero);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
