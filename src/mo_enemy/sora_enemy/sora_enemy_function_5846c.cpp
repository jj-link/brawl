#pragma force_active on
extern "C" void* fn_41_58570(void*, int);
extern "C" void* fn_41_58508(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_5846C(void* p) {
    int i = 0;
    while (i < 1) {
        void* entry = fn_41_58570(static_cast<unsigned char*>(p) + 0x130, i);
        if (fn_27_8D3E4(static_cast<unsigned char*>(entry) + 0x94) == 0) {
            goto done;
        }
        ++i;
    }

    i = 0;
    while (i < 6) {
        void* entry = fn_41_58508(static_cast<unsigned char*>(p) + 0x0C, i);
        if (fn_27_8D3E4(entry) == 0) {
            goto done;
        }
        ++i;
    }

done:
    return;
}
