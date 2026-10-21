#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Color {
    u8 r, g, b, a;
};

struct Entry {
    u32 x0;
    u8 r, g, b, a;
    u8 pad[12];
};

extern "C" void fn_80191AA4(Entry** arg0, u32 arg1, const Color* arg2) {
    Entry* p = *arg0 + (arg1 & 1);

    if (!(arg1 & 2)) {
        p->r = arg2->r;
        p->g = arg2->g;
        p->b = arg2->b;

        if (arg1 - 4 > 1) {
            return;
        }

        p->a = arg2->a;
        return;
    }

    p->a = arg2->a;
}
