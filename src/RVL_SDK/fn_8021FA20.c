#pragma force_active on
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef s32 (*fn_ptr)(void*, void*, void*);

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 status);
extern void fn_8021AC3C(void*);
extern void fn_8021AD00(void*);
extern void* lbl_8047C920[];

s32 fn_8021FA20(void* arg0, void* arg1) {
    s32 intState;
    s32 result = 0;
    if (*(u8*)arg1 >= 0x20 && *(u8*)arg1 <= 0x3F) {
        intState = OSDisableInterrupts();
        ((fn_ptr)lbl_8047C920[*(u8*)arg1 - 0x20])(arg0, arg1, lbl_8047C920);
        OSRestoreInterrupts(intState);
        fn_8021AC3C(arg0);
        fn_8021AD00(arg0);
    } else {
        result = -1;
    }
    return result;
}
