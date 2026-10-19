#pragma force_active on
extern "C" {
    void fn_27_35E54(void*);
    void fn_27_36354(void*);
    void fn_27_366BC(void*, int);
}

extern "C" void fn_27_4B720(void* obj) {
    char* p = (char*)obj;
    if (*(unsigned char*)(p + 0xE3) == 0) {
        fn_27_35E54(p + 0xC0);
    } else {
        fn_27_36354(p + 0xC0);
        fn_27_366BC(p + 0xC0, 0);
    }
    *(int*)(p + 0xCC) = -1;
}
