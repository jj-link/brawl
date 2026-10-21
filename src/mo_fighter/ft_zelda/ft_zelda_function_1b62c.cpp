#pragma force_active on
extern "C" {
extern char lbl_104_data_2DC8[8];
extern char lbl_104_data_2DF4[8];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_33A8B8(void*, int, int, int, int);
}

class OwnerValue {
public:
    virtual void v0();
    virtual void v1();
    virtual int v2();
};

class OwnerNode {
public:
    virtual void v0();
    virtual void v1();
    virtual OwnerValue* v2();
};

class ResourceNode {
public:
    int pad0;
    int pad1;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4();
};

struct Sub {
    int pad[10];
    int taskId;
};

struct Modules {
    ResourceNode* resource;
    int pad[5];
    OwnerNode* owner;
};

struct Input {
    int pad0[2];
    Sub* sub;
    int pad1[51];
    Modules* modules;
};

extern "C" int fn_104_1B62C(void* self, Input* input) {
    int owner;
    Modules* modules = input->modules;
    ResourceNode* resource = modules->resource;
    int taskId = input->sub->taskId;
    owner = modules->owner->v2()->v2();
    void* object = resource->v4();
    int res = fn_27_14DB04(__dynamic_cast(
        object, 0, lbl_104_data_2DC8, lbl_104_data_2DF4, short(1)));
    fn_27_33A8B8(self, taskId, res, owner, 0x1E);
    return 1;
}
