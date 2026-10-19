#pragma force_active on
extern "C" void fn_27_199F1C(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_125_8C74(void* self, void* accesser) {
    fn_27_199F1C(self, 7, 0);
    fn_27_6A244((char*)self + 0x178, accesser, self);
    return self;
}
