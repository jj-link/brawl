#pragma force_active on
typedef unsigned int u32;

struct Object;

struct Holder {
    virtual void slot0();
    virtual Object** get(u32 index);
    virtual void slot2();
    virtual u32 count();
};

struct Outer {
    unsigned char pad[0x6d8];
    Holder holder;
};

extern "C" int fn_27_28DDA0(Object* object);

extern "C" Object* fn_27_2A8A00(Outer* self, u32 index) {
    if (index >= self->holder.count()) {
        return 0;
    }

    Object* obj = *self->holder.get(index);
    if (obj == 0 || fn_27_28DDA0(obj) == 0) {
        return 0;
    }

    return obj;
}
