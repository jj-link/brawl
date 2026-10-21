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
    unsigned char padding10[0xAC];
    Resource* resourceBC;
    unsigned char paddingC0[0x34];
    Resource* resourceF4;
    Resource* resourceF8;
};

extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

extern "C" int fn_80163BE4(void* owner, Node* node) {
    Resource* resource = node->resourceF4;
    if (resource) {
        if (--resource->references == 0 && resource->kind == 2) {
            resource->release();
        }
    }

    resource = node->resourceF8;
    if (resource) {
        if (--resource->references == 0 && resource->kind == 2) {
            resource->release();
        }
        node->resourceF8 = 0;
    }

    resource = node->resourceBC;
    if (--resource->references == 0 && resource->kind == 2) {
        resource->release();
    }

    fn_8015C144((char*)owner + 0x24, node);
    fn_8015BFB4((char*)owner + 0x30, node);
    node->state = 3;
    return 1;
}
