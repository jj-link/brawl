#pragma force_active on
struct grMadein {
};

extern "C" void __dt__8grMadeinFv(grMadein* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" {
grMadein* fn_69_27F0(grMadein* self, int flags) {
    if (self) {
        __dt__8grMadeinFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
