#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* __dt__18soTargetSearchUnitFv(void* self, int flag) {
    if (self != 0 && flag > 0)
        __dl__FPv(self);
    return self;
}
