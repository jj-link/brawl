#pragma force_active on
extern "C" int fn_1_194A4(void*, int);
extern "C" int fn_1_19968(void*, int);

extern "C" int fn_1_1B668(void* self) {
    *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 0x100) = 0;
    fn_1_194A4(self, 1);
    fn_1_19968(self, 1);
    return 0;
}
