#pragma force_active on
extern "C" int fn_800B61C0(void*);

class Obj {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf0A() = 0;
    virtual void vf0B() = 0;
    virtual void vf0C() = 0;
    virtual void process(void*) = 0;
};

struct Resource {
    void* pad[4];
    void* field_10;
};

struct Self {
    void* pad0;
    int field_4;
    Obj* field_8;
    char padC[0x40 - 0xC];
    Resource* field_40;
    Resource* field_44;
    char pad48[0x16C - 0x48];
    unsigned char field_16C;
};

extern "C" int fn_800DE6F8(Self* self) {
    Resource* res = self->field_44;
    if (!fn_800B61C0(res)) {
        return self->field_4;
    }
    self->field_8->process(res->field_10);
    self->field_8->process(self->field_40->field_10);
    int result = 0;
    if (self->field_16C) {
        result = 3;
    }
    return result;
}
