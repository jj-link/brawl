#pragma force_active on
extern "C" int fn_1_194A4(void*, int);
extern "C" int fn_1_19968(void*, int);
extern "C" void GXSetMisc(unsigned int, unsigned int);

extern "C" int fn_1_1BBE0(void* self) {
    fn_1_194A4(self, 0);
    fn_1_19968(self, 1);
    GXSetMisc(1, 0);
    return 0;
}
