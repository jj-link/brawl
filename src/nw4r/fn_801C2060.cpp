#pragma force_active on
extern "C" {

void fn_801C1120(void *, void *, void *);

struct Struct {
    char pad[0xc0];
    void *field_c0;
};

void fn_801C2060(Struct *self, void *arg)
{
    fn_801C1120(self->field_c0, self, arg);
}

}
