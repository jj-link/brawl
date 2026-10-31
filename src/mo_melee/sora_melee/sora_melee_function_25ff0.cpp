#pragma force_active on
struct Object {
    unsigned char pad[0x2C];
    void* field2C;
    void* field30;
    unsigned char pad34[4];
    unsigned char high : 3;
    unsigned char flag : 1;
    unsigned char low : 4;
};

extern "C" void fn_801109AC(void*);

extern "C" void fn_27_25FF0(Object* self, bool value)
{
    if (self->field2C == 0 || self->field30 == 0)
        return;
    self->flag = value;
    if (!value)
        fn_801109AC(self->field30);
}
