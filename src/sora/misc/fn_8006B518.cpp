#pragma force_active on

struct Message;
struct ScnMdlSimple;

struct MsgCallback {
    void* vtable;
    unsigned long index;
    float scale;
    Message* owner;
    unsigned char flag;
    char pad11[3];
    int value;
    MsgCallback* next;
    ScnMdlSimple* model;
    unsigned long node;
};

struct MsgBuffer {
    char pad0[0x20];
    MsgCallback callback;
};

struct Message {
    char pad0[0x1D8];
    MsgBuffer** buffers;
};

struct ScnMdlSimple {
    char pad0[0xD4];
    MsgCallback* callback;
    char padD8[0x10];
    void* resource;
};

struct ResNode {
    char pad0[0xC];
    unsigned long id;
};

extern "C" void fn_801AB0B8(ScnMdlSimple*, int);
extern "C" void fn_801AB038(ScnMdlSimple*, int);
extern "C" ResNode* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);

extern "C" int attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(
    Message* self, unsigned long index, ScnMdlSimple* model,
    const char* name, unsigned char flag, int value, float scale)
{
    MsgCallback* callback = &self->buffers[index]->callback;
    MsgCallback* old = model->callback;

    if (callback->next) {
        callback->next = 0;
    }
    if (old) {
        callback->next = old;
    }
    model->callback = callback;

    fn_801AB0B8(model, 0x20);
    fn_801AB038(model, 4);

    callback->owner = self;
    callback->index = index;
    callback->scale = scale;
    callback->flag = flag;
    callback->value = value;
    callback->model = model;

    if (*name) {
        void* resource = model->resource;
        ResNode* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&resource, name);
        callback->node = node ? node->id : 0;
    } else {
        callback->node = 0;
    }

    return 1;
}
