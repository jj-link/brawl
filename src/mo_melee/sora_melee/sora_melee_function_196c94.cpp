#pragma force_active on
struct FnStruct {
    void *data;
    int zero;
    int a;
    int c;
};

extern char lbl_27_data_3AC18[];

extern "C" void fn_27_196C94(FnStruct *s, int a, int c) {
    s->zero = 0;
    s->data = lbl_27_data_3AC18;
    s->a = a;
    s->c = c;
    if (a == 0) {
        s->c = 0;
    }
}
