#pragma force_active on

class Object {
public:
    char padding[0x3C];

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
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void set(int);
};

struct Vec2 {
    float x;
    float y;
};

struct GimmickWarpZone {
    char pad[0x3C];
    void* vtable;
    char pad2[0x118];
    unsigned int i0;
    unsigned int i1;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_272D8C(void*, const char*);
extern "C" char lbl_40_data_F73C[];

extern "C" void* fn_40_334A8(int value, const char* name)
{
    GimmickWarpZone* obj = (GimmickWarpZone*)__nw__FUlQ25Heaps8HeapType(0x160, 15);
    if (obj) {
        fn_27_272D8C(obj, name);
        obj->vtable = (void*)lbl_40_data_F73C;
        Vec2 t;
        t.x = 0.0f;
        t.y = 0.0f;
        unsigned int* p = (unsigned int*)&t;
        obj->i0 = p[0];
        obj->i1 = p[1];
    }
    if (obj) {
        ((Object*)obj)->set(value);
    }
    return (void*)obj;
}
