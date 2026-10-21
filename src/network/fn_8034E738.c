#pragma force_active on
typedef unsigned char u8;

u8 fn_8033AC84(void *p);
extern void *lbl_805A0FB0;

void fn_8034E738(void *a, void *b) {
    if (*(void (**)(void *, u8))((char *)lbl_805A0FB0 + 0x90c) != 0) {
        (*(void (**)(void *, u8))((char *)lbl_805A0FB0 + 0x90c))(b, fn_8033AC84(a));
    }
}
