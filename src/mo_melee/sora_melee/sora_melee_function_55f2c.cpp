#pragma force_active on

typedef unsigned char u8;
typedef int s32;

struct Array {
    virtual void v0();
    virtual s32* at(s32 index);
    virtual void v2();
    virtual s32 size();
};

struct Object {
    Array* array;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7;
    void* data;
};

extern "C" unsigned char lbl_27_data_57E8[];

extern "C" Object* fn_27_55F2C(Object* self, Array* array, u8 value) {
    self->array = array;
    self->data = lbl_27_data_57E8;
    self->unk4 = 0;
    self->unk5 = 0;
    self->unk6 = value;

    for (s32 i = 0; i < self->array->size(); i++) {
        *self->array->at(i) = -1;
    }

    return self;
}
