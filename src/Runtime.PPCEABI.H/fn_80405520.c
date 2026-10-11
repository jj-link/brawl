/* Write a MetroTRK console buffer and translate its transport status. */
typedef unsigned long u32;
typedef unsigned char u8;

extern u8 fn_80405EEC(void* handle);
extern void* fn_80402EF0(void);
extern u8 fn_80405190(u32 command, u32 mode, u32* size, void* buffer);

int fn_80405520(void* handle, void* buffer, u32* size, void* unused) {
    u32 count;
    u8 status;

    if (!fn_80405EEC(handle)) {
        return 1;
    }
    if (fn_80402EF0() == 0) {
        return 1;
    }
    count = *size;
    status = fn_80405190(0xd0, 1, &count, buffer);
    *size = count;
    switch (status) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}
