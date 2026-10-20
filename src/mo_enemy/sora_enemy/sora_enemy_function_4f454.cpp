#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" void* fn_41_4F508(char* p, u32 flag);
extern "C" void* fn_41_4F4F0(u8* p, s32 n);
extern "C" int fn_27_8D3E4(void* p);

extern "C" void fn_41_4F454(char* p) {
    s32 i;
    for (i = 0; i < 1; i++) {
        if (fn_27_8D3E4((char*)fn_41_4F508(p + 0x40, i) + 0x94) == 0) {
            goto done;
        }
    }
    for (i = 0; i < 1; i++) {
        if (fn_27_8D3E4(fn_41_4F4F0((u8*)(p + 0xc), i)) == 0) {
            goto done;
        }
    }
done:
    return;
}
