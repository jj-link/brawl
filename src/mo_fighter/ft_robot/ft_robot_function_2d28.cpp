#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);

extern "C" {
void* fn_120_2D28(void* p, short flag);
}

void* fn_120_2D28(void* p, short flag) {
    if (p != 0) {
        fn_27_BED74(p, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
