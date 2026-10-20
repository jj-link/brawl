#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_D2F88(void *ptr) {
    u32 val = *(u32 *)((char *)ptr + 0x8);
    return (val >> 22) & 1;
}
