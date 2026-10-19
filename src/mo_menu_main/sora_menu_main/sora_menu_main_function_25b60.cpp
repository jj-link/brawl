#pragma force_active on
typedef int (*Fn)(void*);

struct Fn2Entry {
    unsigned char storage[4];
    Fn callback;
};

extern "C" const Fn2Entry lbl_2_rodata_B40[];

extern "C" int fn_2_25B60(int index, void* arg) {
    Fn callback = *(Fn*)((unsigned char*)lbl_2_rodata_B40 + index * 20 + 4);
    if (callback != 0)
        return callback(arg);
    return 0;
}
