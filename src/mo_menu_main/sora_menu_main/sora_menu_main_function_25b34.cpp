#pragma force_active on
extern "C" void* fn_2_25B34(int index, void* arg);
extern "C" unsigned char lbl_2_rodata_B40[];

extern "C" void* fn_2_25B34(int index, void* arg) {
    typedef void* (*Fn)(void*);
    Fn callback = *(Fn*)((unsigned char*)lbl_2_rodata_B40 + index * 20);
    if (callback != 0) {
        return callback(arg);
    }
    return 0;
}
