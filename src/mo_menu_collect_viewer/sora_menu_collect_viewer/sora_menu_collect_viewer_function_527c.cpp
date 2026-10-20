#pragma force_active on
struct Target {
    char pad[0x350];
    int field350;
    int field354;
};

struct Context {
    char pad[0x1BF4];
    int state;
    char pad2[0x1CE4 - 0x1BF8];
    Target* target;
};

struct Viewer {
    char pad[0x1AC];
    Context* context;
};

extern "C" void fn_800C6E64(Target*, int, int);

extern "C" void fn_6_527C(Viewer* self, int a, int b, int flag) {
    Context* context = self->context;
    Target* target = context->target;
    if (target->field350 == 0) {
        if (flag == 0 && target->field354 != 0) {
            context->state = 0;
        } else {
            fn_800C6E64(target, a, b);
            self->context->state = 6;
        }
    }
}
