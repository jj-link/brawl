#pragma force_active on
typedef int s32;

typedef struct { char pad[0x98]; s32 field_98; } Struct_803CE468;

extern s32 fn_803CD270(void);
extern Struct_803CE468* fn_803CD2E0(void);
extern void fn_803CD598(void);
extern void fn_803CE5C4(s32 arg0);
extern s32 fn_803CEEFC(s32 arg0, s32 arg1, void* arg2);
extern void fn_803CD9C4(void);

s32 fn_803CDA34(void) {
    Struct_803CE468* ptr;
    s32 var;

    if (fn_803CD2E0() == 0) {
        fn_803CE5C4(5);
        return 5;
    }
    if (fn_803CD270() == 0) {
        var = 0;
    } else {
        ptr = fn_803CD2E0();
        if (ptr == 0) {
            var = 0;
        } else {
            var = ptr->field_98;
        }
    }
    if (var != 0) {
        fn_803CD598();
        fn_803CE5C4(0);
        return 6;
    }
    return fn_803CEEFC(1, 1, fn_803CD9C4);
}
