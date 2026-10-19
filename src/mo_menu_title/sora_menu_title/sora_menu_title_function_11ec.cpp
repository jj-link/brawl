#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void* self, int flag);
void __dl__FPv(void* p);

void* fn_24_11EC(void* self, int flag) {
    if (self != 0) {
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
