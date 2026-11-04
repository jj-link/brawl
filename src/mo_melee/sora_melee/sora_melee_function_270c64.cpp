#pragma force_active on
struct Object {
    char pad[4];
    int state;
    char pad8[12];
    float end;
    float time;
    float step;
    float value;
    int mode;
};
extern "C" void fn_27_270D18(Object*);
extern int lbl_27_data_57C2C;
extern "C" void fn_27_270C64(Object* self, float delta) {
    fn_27_270D18(self);
    self->time += delta;
    if (self->mode == 0) {
        self->value -= self->step;
    } else if (self->mode == 1) {
        self->value += self->step;
    }
    if (self->end <= self->time) {
        self->state = lbl_27_data_57C2C;
    }
}