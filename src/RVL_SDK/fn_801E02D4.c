#pragma force_active on

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32 status);
void fn_801E0704(void* p);

void fn_801E02D4(s32* self, s32 val) {
    s32 status = OSDisableInterrupts();
    fn_801E0704(self + 1);
    *self = val;
    OSRestoreInterrupts(status);
}
