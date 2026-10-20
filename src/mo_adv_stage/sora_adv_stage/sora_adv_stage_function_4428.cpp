#pragma force_active on
extern "C" void __dl__FPv(void*);

struct Object {
    void* data;
    unsigned size;
};

extern "C" Object* fn_40_4428(Object* self, int flag)
{
    if (self) {
        if (self) {
            if (self) {
                if (self->data) {
                    self->size -= (int)self->size;
                    __dl__FPv(self->data);
                }
            }
        }
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
