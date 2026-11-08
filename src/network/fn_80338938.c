#pragma force_active on
extern void *lbl_805A0F80;
extern void fn_8033524C(void);
void fn_80338938(int arg0) {
    void *obj;
    void (*callback)(int, int, int);
    if (lbl_805A0F80 == 0 || arg0 == 0) {
        return;
    }
    fn_8033524C();
    obj = lbl_805A0F80;
    callback = *(void (**)(int, int, int))((char *)obj + 0x14);
    if (callback != 0) callback(arg0, 0, *(int *)((char *)obj + 0x18));
    obj = lbl_805A0F80;
    if (obj != 0) {
        *(int *)((char *)obj + 0x04) = 0;
        obj = lbl_805A0F80;
        *(int *)((char *)obj + 0x30) = 0;
    }
}