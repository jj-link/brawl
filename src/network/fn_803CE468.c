#pragma force_active on
typedef int s32;

typedef struct { char pad[0x98]; s32 field_98; } Struct_803CE468;

extern s32 fn_803CD270(void);
extern Struct_803CE468* fn_803CD2E0(void);

s32 fn_803CE468(void) {
    Struct_803CE468* p;

    if (fn_803CD270() == 0) {
        return 0;
    }
    p = fn_803CD2E0();
    if (p == 0) {
        return 0;
    }
    return p->field_98;
}
