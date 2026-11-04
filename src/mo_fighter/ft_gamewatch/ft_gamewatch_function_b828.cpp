#pragma force_active on
extern "C" {
extern const char lbl_107_data_3D3C[], lbl_107_data_45B8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
unsigned char fn_27_1119B8(void*);
int fn_27_111364(void*);
void fn_107_18914(void*, unsigned int, int, int, float);
}

#define V8(n) \
    virtual void n##0(); virtual void n##1(); \
    virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); \
    virtual void n##6(); virtual void n##7();

class Fighter {
public:
    char pad0[0x28];
    unsigned int taskId;
    char pad2c[0x10];
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f)
    V8(g) V8(h) V8(i) V8(j) V8(k) V8(l)
    V8(m) V8(n) V8(o) V8(p) V8(q) V8(r)
    V8(s) V8(t) V8(u) V8(v) V8(w)
    virtual void slot184();
    virtual void* getOwner();
};
class ResourceId {
public:
    V8(a)
    virtual void slot8();
    virtual void slot9();
    virtual int getEtcResId();
};
class Resource {
public:
    char pad[8];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual ResourceId* getResourceIdAccesser();
};
#undef V8
struct Modules { Resource* resource; };
struct Accesser {
    char pad[8];
    void* stageObject;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" int fn_107_B828(void* request, Accesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->stageObject, 0x3c, lbl_107_data_3D3C, lbl_107_data_45B8, 1));
    Resource* resource = accesser->modules->resource;
    unsigned int taskId = fighter->taskId;
    float value = fn_27_1119B8(fighter->getOwner());
    int ownerId = fn_27_111364(fighter->getOwner());
    ResourceId* res = resource->getResourceIdAccesser();
    fn_107_18914(request, taskId, res->getEtcResId(), ownerId, value);
    return 1;
}
