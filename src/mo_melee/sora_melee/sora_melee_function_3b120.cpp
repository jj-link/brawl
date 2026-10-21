#pragma force_active on

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct S {
    u32 a;
    u32 b;
};

struct A : S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void* v32(void*);
};

class B {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(s32, s32, s32, s32, s32);
};

extern "C" void fn_27_3B120(u8* self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    u32 r9 = *(u32*)(self + 0x28);
    A* obj = (A*)(*(u32*)(*(u32*)(r9 + 0xd8) + 4));
    s32 res = (s32)obj->v32((void*)arg2);
    ((B*)self)->v11(arg1, res, arg3, arg4, arg5);
}
