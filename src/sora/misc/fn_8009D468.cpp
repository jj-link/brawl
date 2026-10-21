#pragma force_active on

extern "C" const float lbl_805A1DC8;
extern "C" const float lbl_805A1DCC;

struct Entry {
    float x, y, z;
    unsigned int value;
};

struct State {
    float x, y, z, w;
    struct {
        unsigned int high : 8;
        unsigned int low : 24;
    } flags;
    unsigned int values[6];
    Entry a[16];
    Entry b[16];
    char pad[0x2c];
    float tail[6];
    unsigned int last;
};

extern "C" void fn_8009D468(State* p) {
    p->flags.high = 0;
    p->values[0] = 0;
    p->values[1] = 0;
    p->values[2] = 0;
    p->values[3] = 0;
    p->values[4] = 0;
    p->values[5] = 0;
    p->x = p->y = lbl_805A1DC8;
    p->z = lbl_805A1DCC;
    p->w = lbl_805A1DCC;

    for (int i = 0; i < 16; ++i) {
        p->a[i].x = p->a[i].y = p->a[i].z = lbl_805A1DC8;
        p->a[i].value = 0;
        p->b[i].x = p->b[i].y = p->b[i].z = lbl_805A1DC8;
        p->b[i].value = 0;
    }

    p->last = 0;
    p->tail[0] = lbl_805A1DC8;
    p->tail[1] = lbl_805A1DC8;
    p->tail[2] = lbl_805A1DC8;
    p->tail[3] = lbl_805A1DC8;
    p->tail[4] = lbl_805A1DC8;
    p->tail[5] = lbl_805A1DC8;
}
