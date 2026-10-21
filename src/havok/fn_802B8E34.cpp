#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern "C" {
void fn_802FEA54(void*, void*, void*);
}

struct Frame {
    s32 a;
    s32* b;
    s32 c;
    s32 d;
    s32 e;
};

extern "C" {
void fn_802B8E34(void* arg0, s32 arg1, s32* arg2, s32 arg3) {
    Frame f;
    s32 t = *arg2;

    f.a = arg1;
    f.b = arg2;
    f.d = arg3;
    f.e = *(s32*)((u8*)arg0 + 8);
    f.c = t;
    fn_802FEA54((u8*)arg0 + 0x10, &f, (void*)f.e);
}
}
