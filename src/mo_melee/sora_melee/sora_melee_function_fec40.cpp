#pragma force_active on
struct Fn27FEC40Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags : 7;
    unsigned int remaining : 25;
};

extern "C" void fn_27_FEC40(Fn27FEC40Data* self, unsigned int value)
{
    self->flags = value;
}
