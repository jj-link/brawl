#pragma force_active on
extern "C" void* fn_41_30090(void* p, short flag);
extern "C" void* fn_41_30018(void* p, short flag);
extern "C" void* fn_41_2FFA0(void* p, short flag);
void operator delete(void* p);

extern "C" void* fn_41_300FC(void* p, short flag) {
    short neg = -1;
    if (p != 0) {
        fn_41_30090((char*)p + 0x23c, neg);
        fn_41_30018((char*)p + 0x120, neg);
        fn_41_2FFA0((char*)p + 0x4, neg);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
