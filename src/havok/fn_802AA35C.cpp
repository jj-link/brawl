#pragma force_active on

typedef int s32;

extern "C" {
extern const float lbl_805A3F00;
void fn_802FEA54(void*, void*, void*);
}

struct Frame {
    s32 a;
    void** b;
    s32 c;
    s32 d;
    s32 e;
};

extern "C" void fn_802AA35C(char* arg0, s32 arg1, void** arg2, s32 arg3) {
    Frame f;
    float z = lbl_805A3F00;
    s32* p = (s32*)*arg2;

    *(float*)(arg0 + 0x1C) = z;
    *(float*)(arg0 + 0x18) = z;
    *(float*)(arg0 + 0x14) = z;
    *(float*)(arg0 + 0x10) = z;
    *(float*)(arg0 + 0x2C) = z;
    *(float*)(arg0 + 0x28) = z;
    *(float*)(arg0 + 0x24) = z;
    *(float*)(arg0 + 0x20) = z;

    s32 t = p[4];
    f.a = arg1;
    f.b = arg2;
    f.d = arg3;
    f.e = *(s32*)(arg0 + 8);
    f.c = t;
    fn_802FEA54(arg0 + 0x30, &f, arg2);
}
