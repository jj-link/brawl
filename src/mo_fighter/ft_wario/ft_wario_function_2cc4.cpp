#pragma force_active on
extern "C" {
void* fn_27_5BFA0(void*, short);
void* fn_110_2CC4(void* p1, short p2);
}

void* fn_110_2CC4(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_5BFA0(p1, -1);
        if (p2 > 0) {
            operator delete(p1);
        }
    }
    return p1;
}
