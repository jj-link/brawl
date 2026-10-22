#pragma force_active on

typedef signed int s32;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_803CD318(int arg0);

typedef struct {
    s32 pad[0x1B40 / 4];
    s32 field_1B40;
    s32 field_1B44;
    s32 field_1B48;
} Struct_803CE5C4;

extern Struct_803CE5C4* fn_803CD324(void);

void fn_803CE5C4(s32 arg0) {
    s32 state;

    switch (fn_803CD324()->field_1B40) {
    case 0:
    case 6:
        state = OSDisableInterrupts();
        fn_803CD318(0);
        fn_803CD324()->field_1B40 = arg0;
        fn_803CD324()->field_1B48 = 0;
        OSRestoreInterrupts(state);
        break;
    }
}
