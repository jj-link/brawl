#pragma force_active on
extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
}

struct ResourceBase {
    char pad[0x5c];
};

struct Resource : ResourceBase {
    virtual ~Resource();
};

struct Menu {
    char pad0[8];
    void* object;
    char padC[8];
    Resource* resource;
    char pad18[0x20];
    unsigned int handle;
    void* buffer;
};

extern "C" Menu* fn_2_3BC0(Menu* self, int flag) {
    if (self) {
        if (self->object) {
            Destroy__Q34nw4r3g3d6G3dObjFv(self->object);
            self->object = 0;
        }
        if (self->resource) {
            Resource* resource = self->resource;
            delete resource;
            self->resource = 0;
        }
        cancelRequest__14gfFileIOHandleFv(&self->handle);
        if (self->buffer) {
            free__13gfHeapManagerFPv(self->buffer);
            self->buffer = 0;
        }
        __dt__14gfFileIOHandleFv(&self->handle, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
