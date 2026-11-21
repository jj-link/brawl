#include <types.h>
#pragma force_active on
extern u8 lbl_80532308[];
extern void *fn_8021A180(int, void *);
extern void fn_8027A2E8(int, int);
extern void fn_8021AEC4(int, int, void *);
#define ENTRY(id) (*(void **)(lbl_80532308 + (id)*4))
static inline void set_byte(int id, int off, int val) { *((u8 *)ENTRY(id) + off) = val; }
static inline void set_ptr(int id, void *p) { *(void **)((char *)ENTRY(id) + 0x2c) = p; }
void fn_8027A1D4(int arg0, int arg1) {
    switch (arg1) {
    case 0:
        if (*(u8 *)((char *)ENTRY(arg0) + 0x40) == 0) {
            set_ptr(arg0, fn_8021A180(arg0, (void *)fn_8027A2E8));
            set_byte(arg0, 0x40, 1);
        }
        fn_8021AEC4(arg0, 0, 0);
        break;
    case -1:
        fn_8021A180(arg0, *(void **)((char *)ENTRY(arg0) + 0x2C));
        set_ptr(arg0, 0);
        set_byte(arg0, 0x40, 0);
        set_byte(arg0, 0x42, 0);
        set_byte(arg0, 0x43, 0);
        break;
    }
    {
        void (*cb)(int, int) = (void (*)(int, int))*(void **)((char *)ENTRY(arg0) + 0x28);
        if (cb != 0) cb(arg0, arg1);
    }
}