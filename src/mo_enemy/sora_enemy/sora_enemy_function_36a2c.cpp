#pragma force_active on
typedef int s32;
extern "C" void* fn_41_36B00(char*, s32);
extern "C" void* fn_41_36AD8(char*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_36A2C(void* p) {
    int i;
    for (i = 0; i < 2; ++i) {
        if (fn_27_8D3E4((char*)fn_41_36B00((char*)p + 0x70, i) + 0x94) == 0)
            return;
    }
    for (i = 0; i < 2; ++i) {
        if (fn_27_8D3E4(fn_41_36AD8((char*)p + 0x0C, i)) == 0)
            return;
    }
}
