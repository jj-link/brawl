#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
int fn_40_139CC(void* p)
{
    char* r3 = (char*)p;
    char* r4 = *(char**)(r3 + 0x90);
    u32 off = 0;
    int i;
    int n = *(u8*)(r4 + 0x66);

    for (i = 0; i < n; i++) {
        char* e = *(char**)(r3 + 0x94) + off;
        if (*(u32*)(e + 0xc) == 3) {
            return 1;
        }
        off += 0x1c;
    }
    return 0;
}
}
