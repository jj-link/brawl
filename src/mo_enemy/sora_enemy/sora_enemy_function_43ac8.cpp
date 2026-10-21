#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_41_43C3C(void*, int);
extern "C" void* fn_41_43C04(void*, int);
extern "C" void* fn_41_43BEC(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_43AC8(void* p) {
    int i = 0;
    while (i < 1) {
        if (fn_27_8D3E4(fn_41_43C3C((u8*)p + 0xD4, i)) == 0) return;
        i++;
    }

    i = 0;
    while (i < 3) {
        if (fn_27_8D3E4(fn_41_43C04((u8*)p + 0x40, i)) == 0) return;
        i++;
    }

    i = 0;
    while (i < 1) {
        if (fn_27_8D3E4(fn_41_43BEC((u8*)p + 0xC, i)) == 0) return;
        i++;
    }
}
