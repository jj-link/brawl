#pragma force_active on

struct Vec {
    float x, y, z, w;
};

struct Pair {
    Vec a, b;
};

struct Face {
    char pad[4];
    unsigned short size;
    char pad2[0x2e];
    unsigned char flag;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Face* slot4(int, int);
};

struct World {
    char pad[0x2c0];
    Vec a, b;
};

struct Self {
    char* vt;
    unsigned short size, state;
    char* v8;
    char* vc;
    World* world;
    Face* faces[6];
    int value;
};

extern char lbl_804882A8[];
extern float lbl_805A4408;
extern Object_vptr_0* lbl_805A0EB8;

extern "C" void fn_802EE65C(World*, void*);
extern "C" Face* fn_802E7988(Face*, Pair*, int);
extern "C" void fn_802E8B20(Face*, void*);
extern "C" void fn_802EDAC8(World*, Face*);

extern "C" Self* fn_802E911C(Self* self, World* world, int value) {
    self->state = 1;
    self->vt = lbl_804882A8;
    self->v8 = lbl_804882A8 + 0x10;
    self->vc = lbl_804882A8 + 0x20;
    self->world = world;
    self->value = value;
    if (self->size)
        self->state = 2;

    void* ptr = self;
    if (self)
        ptr = &self->v8;
    fn_802EE65C(self->world, ptr);

    Vec a __attribute__((aligned(16)));
    Vec b __attribute__((aligned(16)));
    a.x = self->world->a.x;
    a.y = self->world->a.y;
    a.z = self->world->a.z;
    a.w = self->world->a.w;
    b.x = self->world->b.x;
    b.y = self->world->b.y;
    b.z = self->world->b.z;
    b.w = self->world->b.w;

    Pair p __attribute__((aligned(16)));
    Face* f;

    p.a.x = b.x; p.a.y = a.y; p.a.z = a.z; p.a.w = lbl_805A4408;
    p.b.x = b.x; p.b.y = b.y; p.b.z = b.z; p.b.w = lbl_805A4408;
    f = lbl_805A0EB8->slot4(0xa0, 0x2f);
    f->size = 0xa0;
    if (f) f = fn_802E7988(f, &p, 0);
    f->flag = 3;
    ptr = self;
    if (self) ptr = &self->vc;
    fn_802E8B20(f, ptr);
    self->faces[0] = f;
    fn_802EDAC8(world, f);

    float zero, tx, ty, tz, uy, uz;
    tx = a.x; zero = lbl_805A4408; tz = a.z; ty = a.y; uz = b.z; uy = b.y;
    p.a.x = tx; p.a.y = ty; p.a.z = tz; p.a.w = zero;
    p.b.x = tx; p.b.y = uy; p.b.z = uz; p.b.w = zero;
    f = lbl_805A0EB8->slot4(0xa0, 0x2f);
    f->size = 0xa0;
    if (f) f = fn_802E7988(f, &p, 0);
    f->flag = 3;
    ptr = self;
    if (self) ptr = &self->vc;
    fn_802E8B20(f, ptr);
    self->faces[1] = f;
    fn_802EDAC8(world, f);

    ty = b.y; zero = lbl_805A4408; tz = a.z; tx = a.x; uz = b.z; uy = b.x;
    p.a.x = tx; p.a.y = ty; p.a.z = tz; p.a.w = zero;
    p.b.x = uy; p.b.y = ty; p.b.z = uz; p.b.w = zero;
    f = lbl_805A0EB8->slot4(0xa0, 0x2f);
    f->size = 0xa0;
    if (f) f = fn_802E7988(f, &p, 0);
    f->flag = 3;
    ptr = self;
    if (self) ptr = &self->vc;
    fn_802E8B20(f, ptr);
    self->faces[2] = f;
    fn_802EDAC8(world, f);

    ty = a.y; zero = lbl_805A4408; tz = a.z; tx = a.x; uz = b.z; uy = b.x;
    p.a.x = tx; p.a.y = ty; p.a.z = tz; p.a.w = zero;
    p.b.x = uy; p.b.y = ty; p.b.z = uz; p.b.w = zero;
    f = lbl_805A0EB8->slot4(0xa0, 0x2f);
    f->size = 0xa0;
    if (f) f = fn_802E7988(f, &p, 0);
    f->flag = 3;
    ptr = self;
    if (self) ptr = &self->vc;
    fn_802E8B20(f, ptr);
    self->faces[3] = f;
    fn_802EDAC8(world, f);

    tz = b.z; zero = lbl_805A4408; ty = a.y; tx = a.x; uz = b.y; uy = b.x;
    p.a.x = tx; p.a.y = ty; p.a.z = tz; p.a.w = zero;
    p.b.x = uy; p.b.y = uz; p.b.z = tz; p.b.w = zero;
    f = lbl_805A0EB8->slot4(0xa0, 0x2f);
    f->size = 0xa0;
    if (f) f = fn_802E7988(f, &p, 0);
    f->flag = 3;
    ptr = self;
    if (self) ptr = &self->vc;
    fn_802E8B20(f, ptr);
    self->faces[4] = f;
    fn_802EDAC8(world, f);

    tz = a.z; zero = lbl_805A4408; ty = a.y; tx = a.x; uz = b.y; uy = b.x;
    p.a.x = tx; p.a.y = ty; p.a.z = tz; p.a.w = zero;
    p.b.x = uy; p.b.y = uz; p.b.z = tz; p.b.w = zero;
    f = lbl_805A0EB8->slot4(0xa0, 0x2f);
    f->size = 0xa0;
    if (f) f = fn_802E7988(f, &p, 0);
    f->flag = 3;
    ptr = self;
    if (self) ptr = &self->vc;
    fn_802E8B20(f, ptr);
    self->faces[5] = f;
    fn_802EDAC8(world, f);

    return self;
}
