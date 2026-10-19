#pragma force_active on

typedef int s32;

extern "C" void* fn_41_5DFD0(char* p, s32 k);
extern "C" s32 fn_27_8D3E4(void*);

extern "C" s32 fn_41_5DF64(char* self) {
    s32 r;
    for (s32 i = 0; i < 5; i++) {
        r = fn_27_8D3E4(fn_41_5DFD0(self + 0xc, i));
        if (r == 0) {
            break;
        }
    }
    return r;
}
