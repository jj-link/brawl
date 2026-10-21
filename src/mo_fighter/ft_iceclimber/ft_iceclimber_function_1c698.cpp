#pragma force_active on

union Range {
    struct {
        float minimum, maximum;
    } values;
    struct {
        unsigned long minimum, maximum;
    } bits;
};

struct Config {
    const void* vtable;
    unsigned char state;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state2;
    unsigned char pad;
    Range ranges[5];
    bool firstFlag, secondFlag, initialized;
};

extern "C" {
extern const unsigned char lbl_27_data_13608[];

void fn_105_1C698(
    Config* self,
    const Range* a,
    const Range* b,
    const Range* c,
    const Range* d,
    const Range* e,
    bool f,
    bool g
) {
    self->state = 0;
    self->enabled = true;
    self->state2 = 0;
    self->vtable = lbl_27_data_13608;
    self->ranges[0] = *a;
    self->ranges[1] = *b;
    self->ranges[2] = *c;
    self->ranges[3] = *d;
    self->ranges[4] = *e;
    self->firstFlag = f;
    self->secondFlag = g;
    self->initialized = true;
}
}
