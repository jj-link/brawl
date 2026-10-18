#pragma force_active on
typedef struct {
    int pad[3];
    int *data;
} fn_118_A510_Obj;

extern "C" void fn_118_A510(fn_118_A510_Obj *self, int scale, int index) {
    self->data[index] *= scale;
}
