#pragma force_active on
struct Value { int a, b; };
class Container {
public:
    virtual void unused();
    virtual Value* get(int);
};
struct Owner {
    int state;
    char pad[0x30];
    unsigned int x, y, z;
    char pad2[4];
    Container container;
};
struct Out {
    char pad[0x1c];
    Container* container;
    char pad2[5];
    unsigned char flag;
};
extern "C" void fn_27_38730(Owner* self, Out* out) {
    if (self->state == 0) self->state = 1;
    Value* v = self->container.get(0); v->b = 0x22;
    if ((self->y >> 24) & 1) self->container.get(0)->b |= 1;
    if ((self->y >> 21) & 1) self->container.get(0)->b |= 4;
    v = self->container.get(5); v->a = 1;
    if ((self->y >> 20) & 1) {
        self->container.get(0)->b |= 8;
        self->container.get(5)->a |= 2;
    }
    if ((self->y >> 19) & 1) {
        self->container.get(0)->b |= 0x10;
        self->container.get(5)->a |= 4;
    }
    v = self->container.get(1); v->b = (self->x >> 13) & 0x3ff;
    v = self->container.get(2); v->b = (self->x >> 10) & 7;
    v = self->container.get(3); v->b = (self->x >> 5) & 15;
    v = self->container.get(4); v->b = 3;
    if ((self->z >> 13) & 1) self->container.get(4)->b |= 4;
    out->container = &self->container;
    out->flag = 0;
}