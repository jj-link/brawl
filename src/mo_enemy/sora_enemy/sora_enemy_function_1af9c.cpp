#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_41_1AE94(u8* p);

extern "C" void fn_41_1AF9C(u8* self) {
    fn_41_1AE94(self + 8);
    float* f = (float*)(self + 0x68);
    *f = -*f;
}
