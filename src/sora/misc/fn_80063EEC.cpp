#pragma force_active on
extern "C" void fn_80064FA0(void*, void*, void*, int, void*, void*, int);

extern "C" void fn_80063EEC(void* entry, int arg2, void* arg3, void* arg4, int arg5) {
    unsigned* base = (unsigned*)entry;
    unsigned val = base[0x44 / 4];
    if (val != 0) {
        fn_80064FA0((void*)base[0x30 / 4], (void*)val, (void*)base[0x2c / 4], arg2, arg3, arg4, arg5);
    }
}
