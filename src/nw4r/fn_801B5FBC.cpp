#pragma force_active on
extern "C" void fn_8019DFAC(void*, void*, int);

extern "C" void* fn_801B5FBC(void* arg0, void* arg1) {
    if (arg0 != arg1) {
        *(int*)arg0 = *(int*)arg1;
        fn_8019DFAC((char*)arg0 + 4, (char*)arg1 + 4, 0x40);
    }
    return arg0;
}
