#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void* fn_27_6A3D8();
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
};
class Module {
public:
    int a, b;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(void*);
    virtual void v35(); virtual void v36(void*);
};
extern "C" void fn_27_605AC(void*);
extern "C" void fn_27_60824(void*, u32, void*);
extern "C" void* fn_27_6F30C(void*);
extern "C" void fn_27_6D138(void* self, void* unused, void* arg) {
    soNullable* obj = *(soNullable**)((char*)self + 0x48);
    char* p = (char*)obj->fn_27_6A3D8();
    char data[0x28];
    fn_27_605AC(data);
    void* q = fn_27_6F30C(p + 0x1c);
    q = *(void**)((char*)q + 0x44);
    q = *(void**)((char*)q + 0xd8);
    Module* m = *(Module**)((char*)q + 0x38);
    m->v34(data);
    fn_27_60824(data, *(u32*)(p + 0x24), arg);
    q = fn_27_6F30C(p + 0x1c);
    q = *(void**)((char*)q + 0x44);
    q = *(void**)((char*)q + 0xd8);
    m = *(Module**)((char*)q + 0x38);
    m->v36(data);
}