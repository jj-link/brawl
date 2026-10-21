#pragma force_active on

typedef signed int s32;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32);
extern void fn_803CD318(int arg0);

typedef struct {
    s32 pad[0x1B40 / 4];
    s32 field_1B40;
} Struct_803CE574;

extern Struct_803CE574* fn_803CD324(void);

void fn_803CE574(void) {
    s32 state = OSDisableInterrupts();
    fn_803CD318(1);
    fn_803CD324()->field_1B40 = 6;
    OSRestoreInterrupts(state);
}
