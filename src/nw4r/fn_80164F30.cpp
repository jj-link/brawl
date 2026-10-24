#pragma force_active on

struct Manager {
    virtual void fn0();
    virtual void detach(void*, void*);
};

struct Resource {
    unsigned char padding[0x9C];
    Manager* manager;
};

struct Owner {
    unsigned char padding[0xBC];
    Resource* resource;
};

struct RefData {
    unsigned char p0[0xC];
    int kind;
    int references;
    unsigned char p1[8];
};

struct RefObj : RefData {
    virtual void release();
};

struct Node {
    unsigned char padding[0xC];
    int state;
    unsigned char padding10[0x10];
    RefObj* refObj;
};

extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

extern "C" int fn_80164F30(Owner* owner, Node* node) {
    Resource* resource = owner->resource;
    resource->manager->detach(resource, node);

    RefObj* ref = node->refObj;
    if (--ref->references == 0 && ref->kind == 2) {
        ref->release();
    }

    fn_8015C144((char*)owner + 0xC0, node);
    fn_8015BFB4((char*)owner + 0xCC, node);
    node->state = 3;
    return 1;
}
