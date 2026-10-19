#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_22_8C(void* self, int n) {
    if (self != 0) {
        __dt__6gfTaskFv(self, 0);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
