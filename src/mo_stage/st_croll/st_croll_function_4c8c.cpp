#pragma force_active on
struct Obj90 {
    char pad[0xf0];
    void *field_f0;
};

extern "C" {
void *fn_90_4CA0(void *a, void *b, void *c);

void *fn_90_4C8C(Obj90 *self, void *arg)
{
    return fn_90_4CA0(self->field_f0, self, arg);
}
}
