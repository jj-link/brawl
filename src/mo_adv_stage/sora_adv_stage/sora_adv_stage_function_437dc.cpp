#pragma force_active on
extern "C" void __dl__FPv(void*);

class Object {
    char padding[0x5c];

public:
    virtual ~Object();
};

struct Wrapper {
    Object* object;
};

extern "C" Wrapper* fn_40_437DC(Wrapper* self, int flag)
{
    if (self) {
        delete self->object;
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
