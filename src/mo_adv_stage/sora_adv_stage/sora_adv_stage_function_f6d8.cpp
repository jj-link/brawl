#pragma force_active on
struct Fn40F6D8Args
{
    char padding[0x0C];
    char* field;
    unsigned char index;
};

extern "C" void fn_40_26BE4(char* self, unsigned int idx);

extern "C" void fn_40_F6D8(Fn40F6D8Args* self)
{
    fn_40_26BE4(self->field, self->index);
}
