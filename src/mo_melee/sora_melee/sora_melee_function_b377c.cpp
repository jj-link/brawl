#pragma force_active on
struct Fn27Inner {
    char *items;
};

struct Fn27Outer {
    char pad[0x20];
    Fn27Inner *inner;
};

extern "C" {
char *fn_27_B377C(Fn27Outer *self, int index) {
    return self->inner->items + index * 20;
}
}
