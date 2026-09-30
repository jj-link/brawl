typedef unsigned long u32;

extern int fn_80404D98(void* destination, u32 address, u32* size, int translate, int read);

int fn_80404D4C(void* destination, u32 address) {
    u32 size = 4;
    int result = fn_80404D98(destination, address, &size, 0, 1);
    if (result == 0 && size != 4) {
        result = 0x700;
    }
    return result;
}
