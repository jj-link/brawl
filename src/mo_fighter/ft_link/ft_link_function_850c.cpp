#pragma force_active on
extern "C" {
void* fn_27_5BFA0(void*, short);

void* fn_93_850C(void* p, short flag) {
    if (p != 0) {
        fn_27_5BFA0(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
