#pragma force_active on
extern "C" {
    void fn_27_35E54(void*);
    void fn_27_36354(void*);
    void fn_27_366BC(void*, int);
}

extern "C" void fn_27_39C34(void* obj) {
    char* p = (char*)obj;
    int val = *(int*)(p + 0x9C);
    if (((val >> 26) & 1) == 0) {
        fn_27_35E54(p + 0x68);
    } else {
        fn_27_36354(p + 0x68);
        fn_27_366BC(p + 0x68, 0);
    }
    *(int*)(p + 0x74) = -1;
}
