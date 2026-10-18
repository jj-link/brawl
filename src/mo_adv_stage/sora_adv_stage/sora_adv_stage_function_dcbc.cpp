#pragma force_active on
extern "C" bool fn_27_2340A0(int);

struct Fn40_DCBC {
    unsigned char pad[8];
    unsigned char* flag;
    unsigned char pad2[4];
    int state;
};

extern "C" void fn_40_DCBC(Fn40_DCBC* self)
{
    if (self->state == 0) {
        *self->flag = 1;
    } else if (fn_27_2340A0(self->state)) {
        *self->flag = 1;
    }
}
