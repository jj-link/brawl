#pragma force_active on
extern "C" {
void* fn_27_63EBC(void*, short);

void* fn_122_3C20(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_63EBC(p1, -1);
        if (p2 > 0) {
            operator delete(p1);
        }
    }
    return p1;
}
}
