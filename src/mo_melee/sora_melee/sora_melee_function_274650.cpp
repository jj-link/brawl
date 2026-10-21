#pragma force_active on

struct Obj {
    unsigned char padding[0x3C];

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
    virtual void setParam(short);
};

struct Layout {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x114];
    int field154;
    unsigned char field158;
    unsigned char pad159[3];
    float field15C;
    unsigned char pad160[8];
    int field168;
    int field16C;
    unsigned char pad170[0x28];
    int field198;
    int field19C;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char __vt__17grGimmickCatapult[];
extern "C" const float lbl_27_rodata_4508;

extern "C" void* create__17grGimmickCatapultFsPCc(short param, const char* name)
{
    Layout* obj = (Layout*)__nw__FUlQ25Heaps8HeapType(0x1A4, 15);
    if (obj) {
        __ct__10grYakumonoFPCc(obj, name);
        obj->vtable = __vt__17grGimmickCatapult;
        obj->field154 = 0;
        obj->field158 = 0;
        obj->field15C = lbl_27_rodata_4508;
        obj->field198 = 0;
        obj->field19C = 0;
        obj->field168 = -1;
        obj->field16C = -1;
    }
    if (obj) {
        ((Obj*)obj)->setParam(param);
    }
    return obj;
}
