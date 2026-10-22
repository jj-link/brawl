#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

extern u8 fn_80405EEC(void);
extern void* fn_80402EF0(void);
extern u8 fn_80405190(u32 command, u32 mode, u32* size, void* buffer);

int fn_804055DC(void* arg0, void* arg1, u32* arg2) {
    u32 count;
    u8 status;

    if (!fn_80405EEC()) {
        return 1;
    }
    if (fn_80402EF0() == 0) {
        return 1;
    }
    count = *arg2;
    status = fn_80405190(0xd1, 0, &count, arg1);
    *arg2 = count;
    switch (status) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}
