#pragma force_active on
extern void fn_8035D254(void *);

struct lbl_805348E0_struct {
    int pad[4];
    int field;
};
extern struct lbl_805348E0_struct lbl_805348E0;

void fn_8035E380(void) {
    fn_8035D254(&lbl_805348E0.field);
}
