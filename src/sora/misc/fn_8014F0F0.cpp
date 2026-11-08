#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
extern "C" {
void fn_80153488(int*);
void fn_80153498(int*, int);
int fn_80153504(int*, int);
int fn_80153810(int*);
int fn_80153CF4(int*);
int fn_80153D50(int*);
u8 fn_801541DC(void*);
void* fn_801541F0(void*, u8);
int fn_80039180(void*, int);
int fn_800393C0(void*, int, void*, int, int, int);
}
extern unsigned char lbl_80423690[];
extern "C" int fn_8014F0F0(void* arg0, void* collection, void* arg2, u8* target) {
    int entry[2];
    int value;
    u8 count;
    int success;
    u8 i;
    int type;
    unsigned char* status;
    count = fn_801541DC(collection);
    status = lbl_80423690;
    success = 0;
    i = 0;
    while ((u8)i < count) {
        fn_80153488(entry);
        if (fn_80153504(entry, (int)fn_801541F0(collection, i)) == 0) {
            fn_80153498(entry, -1);
        } else if (fn_80153D50(entry) == 0) {
            fn_80153498(entry, -1);
        } else {
            type = 0;
            if (fn_80153CF4(entry) == 1) {
                type = 1;
            } else if (fn_80153CF4(entry) == 2) {
                type = 2;
            } else if (fn_80153CF4(entry) == 3) {
                type = 3;
            }
            if (type != 0) {
                value = fn_80153D50(entry);
                while (status[0] == 0) {
                    OSSleepTicks(((*(u32*)0x800000F8) / 4) / 1000);
                }
                if ((u32)value > (u32)(*(u32*)(status + 0xC) << 17)) {
                    success = 1;
                    fn_80153498(entry, -1);
                    goto done;
                }
                if (fn_80039180(target, type) != 0) {
                    while (target[0x5C] == 0) {
                        OSSleepTicks(((*(u32*)0x800000F8) / 4) / 1000);
                    }
                    if (*(int*)(target + 0x60) == 0) {
                        if (fn_800393C0(target, type, target + 0x64, fn_80153810(entry), fn_80153D50(entry), 0) != 0) {
                            while (target[0x5C] == 0) {
                                OSSleepTicks(((*(u32*)0x800000F8) / 4) / 1000);
                            }
                        }
                    }
                }
            }
            fn_80153498(entry, -1);
        }
        i++;
    }
done:
    return success;
}