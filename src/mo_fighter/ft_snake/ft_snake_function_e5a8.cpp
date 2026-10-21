#pragma force_active on

extern "C" {
extern const char lbl_122_data_8B84[], lbl_122_data_8BB0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_3BA478(void*, int, int, int);
}

struct InnerObj {
    virtual void f0();
    virtual void f1();
    virtual int f2();
};

struct NodeObj {
    virtual void f0();
    virtual void f1();
    virtual InnerObj* f2();
};

struct PreBase {
    int a;
    int b;
};

struct ObjTarget : PreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* f4();
};

struct Modules {
    ObjTarget* obj;
    char pad[0x14];
    NodeObj* node;
};

extern "C" int fn_122_E5A8(void* owner, char* ctx) {
    int val;
    char* modules = *(char**)(ctx + 0xd8);
    ObjTarget* obj = *(ObjTarget**)modules;
    int taskId = *(int*)(*(char**)(ctx + 8) + 0x28);
    NodeObj* node = *(NodeObj**)(modules + 0x18);
    val = node->f2()->f2();
    void* ptr = obj->f4();
    int resource = fn_27_14DB04(__dynamic_cast(
        ptr, 0, lbl_122_data_8B84, lbl_122_data_8BB0, short(1)));
    fn_27_3BA478(owner, taskId, resource, val);
    return 1;
}
