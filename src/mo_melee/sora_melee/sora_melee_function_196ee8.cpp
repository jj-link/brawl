#pragma force_active on
typedef int s32;

struct Callback {
    virtual void f0();
    virtual s32* at(s32);
};

struct Array {
    int pad;
    Callback* callback;
    s32* data;
    s32 count;
};

extern "C" s32* fn_27_196EE8(Array* self, s32 index) {
    if (index >= self->count && self->callback != 0)
        return self->callback->at(index - self->count);
    return self->data + index;
}
