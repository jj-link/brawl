typedef unsigned long u32;

extern void fn_80405B6C(void* payload, u32 size);

int fn_8040123C(void* packet) {
    fn_80405B6C((char*)packet + 16, *(u32*)((char*)packet + 8));
    return 0;
}
