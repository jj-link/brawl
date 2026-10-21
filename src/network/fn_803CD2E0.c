#pragma force_active on
typedef struct { char pad[0xC0]; char f; } Block;

extern Block* lbl_805A1250;

char* fn_803CD2E0(void) {
    if (lbl_805A1250 == 0) {
        return 0;
    }
    return &lbl_805A1250->f;
}
