#pragma force_active on
struct Target {
    char pad[0xe];
    unsigned short field;
};

struct Source {
    char pad[4];
    Target* target;
};

extern "C" void fn_27_2EF54(Source* self, unsigned short val) {
    self->target->field = val;
}
