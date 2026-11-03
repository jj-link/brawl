#include <types.h>
#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

extern "C" {
int fn_800393C0(void*, int, int, int, void*, int);
int fn_8003A210(int);
void fn_8014FC44(u16, u8, u8);
void fn_8014FD1C(void);
void fn_80150494(int);
u64 fn_801504AC(int);
void fn_80153488(int*);
void fn_80153498(int*, int);
int fn_80153504(int*, int);
int fn_80153810(int*);
int fn_80153CF4(int*);
char* fn_80153D50(int*);
u8 fn_801541DC(int);
void* fn_801541F0(int, u8);
void fn_801E1D80(u64, void*);
}

struct Fn80157Target {
    u8 pad5c[0x5c];
    u8 busy;
    u8 pad5d[3];
    int result;
};

struct Fn80157Object {
    u8 pad[0x370];
    Fn80157Target* target;
};

extern "C" int fn_80157FD4(Fn80157Object* self, int arg1, int arg2) {
    int entry[2];
    int timeData[8];
    u32 success;
    u8 count;
    int index;
    char* value;
    u8 i;
    int type;

    if (self->target == 0) {
        return 0;
    }

    success = 0;
    count = fn_801541DC(arg1);
    i = 0;

    while ((u8)i < count) {
        fn_80153488(entry);
        if (fn_80153504(entry, (int)fn_801541F0(arg1, (u8)i)) == 0) {
            fn_80153498(entry, -1);
        } else if (fn_80153D50(entry) == 0) {
            fn_80153498(entry, -1);
        } else {
            type = 0;
            switch (fn_80153CF4(entry)) {
            case 1:
                type = 1;
                break;
            case 2:
                type = 2;
                break;
            case 3:
                type = 3;
                break;
            }

            if (type != 0) {
                value = fn_80153D50(entry);
                index = fn_80153810(entry);

                if (fn_800393C0(self->target, type, fn_8003A210(type),
                                index, value, 1) != 0) {
                    while (self->target->busy == 0) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                    if (self->target->result == 0) {
                        success = 1;
                    }
                }
            }

            if (type == 1) {
                fn_80150494(2);
            }
            if (type == 2) {
                fn_80150494(1);
            }
            if (type == 3) {
                fn_80150494(4);
            }
            fn_80153498(entry, -1);
        }

        i++;
    }

    if (success == 1) {
        OSGetTime();
        fn_8014FD1C();
        fn_801E1D80(fn_801504AC(0), timeData);
        fn_8014FC44((u16)timeData[5], (u8)(timeData[4] + 1),
                    (u8)timeData[3]);
    }

    return success;
}