#pragma force_active on

typedef signed int s32;

extern s32 fn_803CD2A8(void);

typedef struct {
    s32 pad[0x1B40 / 4];
    s32 field_1B40;
} Struct_803D48E0;

extern Struct_803D48E0* fn_803CD324(void);
extern void fn_803CD410(s32 arg0);
extern void fn_803CFBE4(s32 a, s32 b);

void fn_803D48E0(s32 arg0) {
    s32 result;

    result = fn_803CD2A8();
    if (arg0 != 0) {
        fn_803CD324()->field_1B40 = 3;
        fn_803CD410(1);
    } else {
        fn_803CD324()->field_1B40 = 0;
    }
    fn_803CFBE4(0, *(s32 *)(result + 0xC));
}