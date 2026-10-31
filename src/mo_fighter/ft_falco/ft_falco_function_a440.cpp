#pragma force_active on

struct Local {
    int first;
    int second;
    Local(const Local&);
};

extern "C" {
extern const char lbl_108_data_2E6C[], lbl_108_data_2E98[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_317604(void*, int, int, int, Local*, float, float, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
}

class Node {
public:
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual Local n6();
    virtual void n7();
    virtual void n8();
    virtual void n9();
    virtual void n10();
    virtual float n11();
};

class Inner {
public:
    virtual void i0();
    virtual void i1();
    virtual int i4();
};

class OwnerNode {
public:
    virtual void o0();
    virtual void o1();
    virtual Inner* o4();
};

class ResBase {
public:
    int pad[2];
};

class ResObj : public ResBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s4();
    virtual void s5();
    virtual void* s6();
};

class Other {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m6(int, int);
};

struct Sub {
    int pad[10];
    int taskId;
};

struct Modules {
    ResObj* resource;
    int pad[2];
    Node* node;
    int pad1[2];
    OwnerNode* owner;
    int pad2[14];
    Other* other;
};

struct Accesser {
    char pad0[0x8];
    Sub* sub;
    char pad1[0xCC];
    Modules* modules;
};

struct Owner2 {
    char pad0[0x28];
    int val;
};

extern "C" int fn_108_A440(Owner2* self, Accesser* accesser, unsigned int arg2) {
    int iv;
    void* ptr;
    OwnerNode* owner;
    ResObj* resource;
    int taskId;
    Node* node;
    float vf;
    float cf;
    Modules* modules = accesser->modules;
    node = modules->node;
    owner = modules->owner;
    resource = modules->resource;
    taskId = accesser->sub->taskId;

    cf = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xDB2, 0);
    vf = node->n11();
    Local local = node->n6();
    iv = owner->o4()->i4();
    ptr = resource->s6();
    void* dc = __dynamic_cast(
        ptr, 0, lbl_108_data_2E6C, lbl_108_data_2E98, 1);
    int res = fn_27_14DB04(dc);
    fn_27_317604(self, taskId, res, iv, &local, vf, cf, 0x1F);
    (*(Modules**)((char*)accesser + 0xD8))->other->m6(6, self->val);
    return 1;
}
