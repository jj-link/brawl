#pragma force_active on
extern "C" void fn_801AB038(void*, int);
extern "C" void fn_801AB078(void*, int);
extern "C" void fn_801AB0B8(void*, int);
extern "C" void fn_801AB0CC(void*, int);

extern "C" void fn_8006526C(void* arg0, int arg1) {
    void* temp_r5 = *(void**)((char*)arg0 + 0x4);
    if (temp_r5 != 0) {
        if (arg1 != 0) {
            *(void**)((char*)temp_r5 + 0xD4) = arg0;
            fn_801AB038(*(void**)((char*)arg0 + 0x4), 1);
            fn_801AB038(*(void**)((char*)arg0 + 0x4), 4);
            fn_801AB0B8(*(void**)((char*)arg0 + 0x4), 4);
            return;
        }
        *(void**)((char*)temp_r5 + 0xD4) = 0;
        fn_801AB078(*(void**)((char*)arg0 + 0x4), 1);
        fn_801AB078(*(void**)((char*)arg0 + 0x4), 4);
        fn_801AB0CC(*(void**)((char*)arg0 + 0x4), 4);
    }
}
