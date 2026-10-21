#pragma force_active on
struct Obj {
    char pad[0xc];
    void *field_c;
};

extern struct Obj *lbl_805A1250;
extern void fn_80204768(void *, int, int);

void fn_803CD284(int arg0) {
    fn_80204768(lbl_805A1250->field_c, arg0, 0x20);
}
