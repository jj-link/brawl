#pragma force_active on
extern "C" {
void* fn_108_2050(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_108_2908(void*, short);
void operator delete(void*);
}

extern "C" void* fn_108_1FCC(char* fighter, short deleting) {
    if (fighter != 0) {
        short memberDeleting = -1;
        fn_108_2050(fighter + 0x1B380, memberDeleting);
        fn_27_C74E8(fighter + 0x1B370, memberDeleting);
        fn_108_2908(fighter, static_cast<short>(0));
        if (deleting > 0) operator delete(fighter);
    }
    return fighter;
}
