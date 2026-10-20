#pragma force_active on
struct FnStore {
    char pad[0x14];
    void *a;
    void *b;
    float c;
};

extern "C" void fn_27_64E78(FnStore *self, void *a, void *b, float c)
{
    self->a = a;
    self->b = b;
    self->c = c;
}
