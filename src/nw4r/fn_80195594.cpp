#pragma force_active on
typedef float f32;
typedef int s32;

extern "C" s32 fn_80193E88(void*, void*, void*);
extern "C" s32 fn_8019459C(void*, void*, s32, void*, s32, f32);
extern "C" void fn_80194FF8(f32*, void*, s32, f32);

extern "C" void fn_80195594(void* self, s32 arg1, void* arg2, f32 f) {
    char* p = (char*)self;
    char* q = (char*)arg2;
    f32 out[3];
    s32 r = fn_80193E88(p + 4, q, q + 8);
    s32 r2 = fn_8019459C((void*)(p + 0x1c), (void*)(p + 0x10), arg1, (void*)q, r, f);
    fn_80194FF8(out, (void*)q, r2, f);
    *(s32*)p |= 0x80000000;
    *(f32*)(p + 0x28) = out[0];
    *(f32*)(p + 0x38) = out[1];
    *(f32*)(p + 0x48) = out[2];
}
