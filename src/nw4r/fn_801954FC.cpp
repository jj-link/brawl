#pragma force_active on
typedef float f32;
typedef int s32;

extern "C" int fn_80193E88(void*, void*, void*);
extern "C" void fn_801EC158(void*);
extern "C" void fn_80194FF8(f32*, void*, int, f32);

extern "C" void fn_801954FC(char* self, int unused, char* arg2, f32 f) {
    f32 out[3];
    int r;
    r = fn_80193E88(self + 4, arg2, arg2 + 8);
    fn_801EC158(self + 0x1c);
    fn_80194FF8(out, arg2, r, f);
    *(f32*)(self + 0x28) = out[0];
    *(f32*)(self + 0x38) = out[1];
    *(f32*)(self + 0x48) = out[2];
}
