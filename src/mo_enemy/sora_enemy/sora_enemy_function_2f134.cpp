#pragma force_active on
extern "C" void* fn_41_2AC4(void* ptr, short flag);
extern "C" void* fn_41_2F0D8(void* object, short flag);
extern "C" void* fn_27_CD934(void* object, short flag);
void operator delete(void* p);

extern "C" void* fn_41_2F134(void* p, short flag) {
    if (p) {
        fn_41_2AC4((char*)p + 0x6c, -1);
        fn_41_2F0D8((char*)p + 0x20, -1);
        fn_27_CD934(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
