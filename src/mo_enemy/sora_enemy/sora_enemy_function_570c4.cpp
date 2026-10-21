#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef short s16;

extern "C" char lbl_41_data_16DE4[];
extern "C" char lbl_41_data_3E50[];
extern "C" void fn_41_2D038(void* self, s32 a, s16 b, void* c, void* d);

class emSubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s16 v7();
    virtual void v8();
    virtual void v9();
};

extern "C" void* fn_41_570C4(void* self, char* other) {
    u32 args[4];
    *(void**)self = lbl_41_data_16DE4;
    void* q = *(void**)(*(char**)(other + 0xd8) + 0xc0);
    args[0] = 1;
    args[1] = 0x2a;
    args[2] = (u32)&args[0];
    args[3] = (u32)q;
    emSubObj* sub = reinterpret_cast<emSubObj*>(*(char**)(*(char**)(other + 0xd8) + 0x80) + 8);
    s16 v = sub->v7();
    fn_41_2D038((char*)self + 4, 1, v, &args[2], lbl_41_data_3E50);
    return self;
}
