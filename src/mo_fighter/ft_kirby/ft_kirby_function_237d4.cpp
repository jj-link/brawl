#pragma force_active on
extern "C" void fn_27_1DAF80(void*);

extern "C" int fn_96_237D4(void* self, unsigned int flags) {
    if (flags & 2) return 0;
    fn_27_1DAF80(self);
    return 0;
}
