#pragma force_active on

typedef unsigned char u8;

struct Anim {
    void* resource;
    float frame;
    u8 pad[0x14];
    int id;
};

struct Array {
    virtual void dummy0();
    virtual Anim* at(int);
    virtual void dummy1();
    virtual int size();
};

struct Target {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void apply(void*, short*, float, float);
};

struct Modules {
    u8 pad[0x6C];
    Target* target;
};

struct Owner {
    u8 pad[0xD8];
    Modules* modules;
};

struct Self {
    u8 pad0[0x8C];
    Array* array;
    u8 pad1[0x168 - 0x90];
    Owner* owner;
};

extern "C" unsigned int isEnd__9soAnimChrCFv(Anim*);
extern "C" float getEndFrame__9soAnimChrCFPQ34nw4r3g3d12AnmObjChrRes(
    Anim*, void*);
extern "C" void fn_27_1BFE4(Self*, short*, int);

extern "C" void fn_27_1C1DC(Self* self, short* arg)
{
    int count = self->array->size();
    Anim* anim;

    for (int i = 0; i < count; ++i) {
        anim = self->array->at(i);
        if (anim->id != -1) {
            if (isEnd__9soAnimChrCFv(anim) == 1) {
                struct {
                    short value;
                    short pad;
                } id;
                id.value = *arg;
                fn_27_1BFE4(self, &id.value, 0);
                return;
            }

            if (anim->resource) {
                getEndFrame__9soAnimChrCFPQ34nw4r3g3d12AnmObjChrRes(
                    anim, anim->resource);
            }

            struct {
                short value;
                short pad;
            } id;
            id.value = *arg;

            float end =
                getEndFrame__9soAnimChrCFPQ34nw4r3g3d12AnmObjChrRes(
                    anim, anim->resource);
            float frame = anim->frame;
            self->owner->modules->target->apply(
                self->owner, &id.value, frame, end);
            return;
        }
    }
}
