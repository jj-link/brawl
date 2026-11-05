#pragma force_active on
typedef int s32;

typedef struct {
    char pad[0x90];
    s32 field_90;
    s32 field_94;
    s32 field_98;
} Struct_803CE3FC;

extern s32 fn_803CD270(void);
extern s32 fn_803CE570(void);
extern Struct_803CE3FC* fn_803CD2E0(void);

s32 fn_803CE3FC(void) {
    Struct_803CE3FC* p;

    if (fn_803CD270() == 0) {
        return 1;
    }
    if (fn_803CE570() != 0) {
        return 1;
    }
    p = fn_803CD2E0();
    if (p == 0) {
        return 1;
    }
    p->field_98 = 0;
    p->field_94 = 0;
    p->field_90 = 0;
    return 0;
}