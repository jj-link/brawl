#pragma force_active on
typedef signed short s16;

extern "C" void fn_27_3190A4(s16* out, const s16* in);
extern "C" void fn_27_319B4C(char* obj, s16* v, void* p);
extern "C" void fn_27_319AAC(char* obj, s16* v, void* p);

extern "C" void fn_27_318F24(char* self, void* p, const s16* src) {
    s16 b[2];
    s16 a[2];
    s16 d[2];
    s16 c[2];
    a[0] = *src;
    fn_27_3190A4(&b[0], &a[0]);
    c[0] = b[0];
    fn_27_319B4C(self + 0x48, &c[0], p);
    d[0] = b[0];
    fn_27_319AAC(self + 0x8, &d[0], p);
}
