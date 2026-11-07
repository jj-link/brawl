#pragma force_active on
struct Obj {
    char pad0[0x504];
    int result;
    char pad508[4];
    int value;
    char pad510[0xd4c-0x510];
    int target;
    float step;
    char padD54[0x18];
    unsigned int sound1;
    unsigned int sound2;
};
extern "C" void fn_15_1424(Obj*, int);
extern "C" void fn_80075F1C(void*, unsigned int, int);
extern void* g_sndSystem;
extern "C" int fn_15_49C4(Obj* self) {
    int value = self->value;
    int target = self->target;
    if (target != value) {
        if (target > value) {
            int next = (int)((float)value + self->step);
            self->value = next;
            if (next > target) self->value = target;
        } else {
            int next = (int)((float)value - self->step);
            self->value = next;
            if (next < target) self->value = target;
        }
        fn_15_1424(self, self->value);
        return self->result;
    }
    if (self->sound1 != 0xffffffff) {
        fn_80075F1C(g_sndSystem, self->sound1, 0);
        self->sound1 = 0xffffffff;
    }
    if (self->sound2 != 0xffffffff) {
        fn_80075F1C(g_sndSystem, self->sound2, 0);
        self->sound2 = 0xffffffff;
    }
    return 8;
}