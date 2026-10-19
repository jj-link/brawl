#pragma force_active on
extern "C" {
void* fn_94_4D20(void* p, short flag);
void* fn_94_1CAF0(void* p, short flag);
}
void operator delete(void* p);

extern "C" void* fn_94_1CAF0(void* p, short flag) {
    if (p != 0) {
        fn_94_4D20(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
