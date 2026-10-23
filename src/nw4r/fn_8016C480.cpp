#pragma force_active on

struct ResourceData {
    unsigned char padding[0xC];
    int kind;
    int references;
    unsigned char padding14[8];
};

struct Resource : ResourceData {
    virtual void release();
};

struct Node {
    unsigned char padding[0xC];
    int state;
    unsigned char padding10[0xB8];
    Resource* resource;
};

extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

extern "C" int fn_8016C480(void* owner, Node* node) {
    Resource* resource = node->resource;
    if (--resource->references == 0 && resource->kind == 2) {
        resource->release();
    }

    fn_8015C144((char*)owner + 0x38, node);
    fn_8015BFB4((char*)owner + 0x44, node);
    node->state = 3;
    return 1;
}
