#pragma force_active on
typedef unsigned char u8;
typedef struct {
    char padding[0x1B3C];
    u8 unk1B3C;
} Struct_805A1250;

extern Struct_805A1250 *lbl_805A1250;

void fn_803CD410(int arg0) {
    if (lbl_805A1250 != 0) {
        lbl_805A1250->unk1B3C = lbl_805A1250->unk1B3C | (u8)(1 << arg0);
    }
}
