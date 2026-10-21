#pragma force_active on
extern void fn_8035E00C(void* p);

typedef struct Obj {
    void* unk0;
    int unk4;
    int unk8;
    int unkC;
} Obj;

int fn_8037D2AC(void* arg0, Obj* arg1) {
    if (arg1 != 0) {
        if (arg1->unk0 != 0) {
            fn_8035E00C(arg1->unk0);
            arg1->unk0 = 0;
        }
        arg1->unk8 = 0;
        arg1->unkC = 0;
    }
    return 1;
}
