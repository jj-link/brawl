#pragma force_active on
extern "C" void __dt__9grGimmickFv(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_40_27054(void* self, int flags) {
    if (self != 0) {
        __dt__9grGimmickFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
