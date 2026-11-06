#pragma force_active on
extern "C" int fn_800B61C0(void*);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(void*);
};

struct Resource {
    char pad[0x10];
    void* value;
};

struct Self {
    char pad0[0x40];
    Resource* resource;
    Object_vptr_0* object;
    char pad1[0xbc];
    int fallback;
};

extern "C" int fn_800BFFBC(Self* self) {
    if (fn_800B61C0(self->resource)) {
        self->object->slot13(self->resource->value);
        return 3;
    }
    return self->fallback;
}
