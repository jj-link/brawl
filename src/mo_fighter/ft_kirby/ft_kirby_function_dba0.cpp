#pragma force_active on
extern "C" unsigned int fn_96_1DB84(void* self);
extern "C" void fn_27_135468(void* self, unsigned int arg);

extern "C" int fn_96_DBA0(void* self, unsigned int arg) {
    unsigned char* base = static_cast<unsigned char*>(self);
    if (fn_96_1DB84(base + 0x1B72C) == 1) {
        return 1;
    }
    fn_27_135468(self, arg);
}
