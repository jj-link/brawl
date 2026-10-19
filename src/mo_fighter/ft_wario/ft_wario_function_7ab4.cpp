#pragma force_active on
extern "C" void fn_27_19A19C(void*, unsigned int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_110_7AB4(void* self, void* arg) {
    fn_27_19A19C(self, 9, 0);
    fn_27_6A244((char*)self + 0x1E0, arg, self);
    return self;
}
