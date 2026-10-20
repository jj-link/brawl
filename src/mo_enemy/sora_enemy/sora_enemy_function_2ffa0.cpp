#pragma force_active on
extern "C" void* fn_41_27D8(void* object, short shouldDelete);
extern "C" void* fn_41_2890(void* p, short flag);
extern "C" void* fn_41_2FF44(void* p, short flag);
void operator delete(void* p);

extern "C" void* fn_41_2FFA0(void* p, short flag) {
    short neg = -1;
    if (p != 0) {
        fn_41_27D8((char*)p + 0xCC, neg);
        fn_41_2890((char*)p + 0xB0, neg);
        fn_41_2FF44((char*)p + 4, neg);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
