#pragma force_active on
struct Sub {
    char pad[0x15c];
    int flag;
};

struct Self {
    char pad[0x174];
    Sub* items[1];
};

struct Arg {
    char pad[0x25];
    unsigned char idx;
};

extern "C" void fn_40_3001C(Self* self, Arg* arg)
{
    Sub* sub = self->items[arg->idx];
    if (sub->flag == 0) {
        sub->flag = 1;
    }
}
