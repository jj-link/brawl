#pragma force_active on
class Child {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void*, void*);
};

class Owner {
public:
    char pad[0x50];
    unsigned int flags;
    char pad2[0x9c - 0x54];
    Child* child;
};

extern "C" {
void fn_80164398(Owner* self, void* arg) {
    if (self->flags & 2) return;
    self->child->v2(self, arg);
}
}
