#include <types.h>
#pragma force_active on

extern "C" void fn_80165768(void*, s32, void*, void*, u16);

struct Class_804652C8;

struct Inner {
    char pad[0x20];
    Class_804652C8* target;
};

struct Class_80465260_base {
    char pad[0xC];
    s32 state;
    s32 count;
    char pad2[0x1C - 0x14];
};

class Class_80465260 : public Class_80465260_base {
public:
    virtual void fn_80163BD4();
    virtual void fn_80163BE0();
    virtual void fn_80163AA0();
    virtual void fn_80164658();
    char pad3[0xC8 - 0x20];
    Inner* inner;
};

struct Class_804652C8_base {
    char pad[0x1C];
};

class Class_804652C8 : public Class_804652C8_base {
public:
    virtual void fn_80164E3C();
    virtual void fn_80164E48();
    virtual void fn_80165370();
    virtual void fn_801654C8(s32, void*, void*, u16);
};

struct Entry {
    u8 type;
    u8 pad1;
    u16 flags;
    s32 data;
    s32 pad2;
    Class_80465260* obj;
    s32 value;
};

extern "C" void fn_801703B8(s32* hdr) {
    Entry* e = (Entry*)(hdr + 1);
    s32 i = 0;
    for (; i < *hdr; e++, i++) {
        switch (e->type) {
        case 0:
            fn_80165768(e->obj->inner->target, e->value, &e->data, e->obj, e->flags);
            {
                Class_80465260* obj = e->obj;
                if (--obj->count == 0 && obj->state == 2) {
                    obj->fn_80163BD4();
                }
            }
            break;
        case 1:
            e->obj->inner->target->fn_801654C8(e->value, &e->data, e->obj, e->flags);
            {
                Class_80465260* obj = e->obj;
                if (--obj->count == 0 && obj->state == 2) {
                    obj->fn_80163BD4();
                }
            }
            break;
        }
    }
    *hdr = 0;
}
