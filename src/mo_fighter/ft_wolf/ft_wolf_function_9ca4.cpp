#pragma force_active on
extern "C" {
extern char lbl_125_data_2934[];

typedef struct {
    void *vtbl;
    int pad[3];
    int a;
    int b;
    int c;
} Obj;

void fn_125_9CA4(Obj *self, int a, int b, int c)
{
    self->vtbl = lbl_125_data_2934;
    self->a = a;
    self->b = b;
    self->c = c;
}
}
