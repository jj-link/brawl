#pragma force_active on
extern "C" void* fn_41_2FF44(void* p, short flag);
extern "C" void* fn_41_27D8(void* object, short shouldDelete);
void operator delete(void* p);

extern "C" void* fn_41_30090(void* p, short flag) {
    short neg = -1;
    if (p != 0) {
        fn_41_2FF44((char*)p + 0x50, neg);
        fn_41_27D8(p, neg);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
