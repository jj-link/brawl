#pragma force_active on
struct Target {
    char pad[0xe];
    unsigned short field;
};

struct Source {
    char pad[0x10];
    Target* target;
};

extern "C" void fn_8015DC58(Source* self, unsigned short val) {
    self->target->field = val;
}
