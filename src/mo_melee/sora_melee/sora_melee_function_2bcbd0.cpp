#include <types.h>
#pragma force_active on

struct Resource {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual u8 getGroup(u32);
    virtual void setGroup(u8, u16);
    virtual void v7();
    virtual s32 getFile(s32, u32);
};

struct Accessor {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual u32 getId();
};

struct Provider {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Accessor* getAccessor();
};

struct Owner {
    Resource base;
    Provider provider;
    u8 pad[0xC];
    Resource* resource;
};

extern "C" s32 fn_27_2BCBD0(Owner* self, s32 index, u32 id) {
    u8 oldGroup = self->resource->getGroup(0);
    Resource* resource = self->resource;
    resource->setGroup(self->base.getGroup(0), 0xFF);

    if (id == 0xFFFF) {
        id = self->provider.getAccessor()->getId();
    }

    s32 result = self->resource->getFile(index, id);
    self->resource->setGroup(oldGroup, 0xFF);
    return result;
}
