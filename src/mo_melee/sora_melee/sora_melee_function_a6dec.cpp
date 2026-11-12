#include <types.h>

#pragma force_active on

struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}
    Vec2(const Vec2& other) {
        __memcpy(this, &other, sizeof(Vec2));
    }

    void set(float px, float py) {
        x = px;
        y = py;
    }
};

struct Vec3 {
    float x, y, z;
};

struct Matrix {
    float m[3][4];
};

struct FlagBits {
    u8 active : 1;
    u8 reserved : 2;
    u8 initialized : 1;
    u8 other : 4;
};

#define V8(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3(); \
    virtual void p##4(); \
    virtual void p##5(); \
    virtual void p##6(); \
    virtual void p##7();

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Vec3 slot14(int);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
};

class Model {
public:
    char pad[8];

    V8(a)
    V8(b)
    V8(c)
    V8(d)
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual Vec3 slot36(void*, int);
    virtual Vec3 slot37(void*, Vec3*, int, int);
    virtual void slot38();
    virtual void slot39();
    virtual void slot40(void*, Matrix*, int);
};

class Graphics {
public:
    char pad[8];

    V8(a)
    V8(b)
    V8(c)
    V8(d)
    V8(e)
    V8(f)
    V8(g)
    V8(h)
    V8(i)
    V8(j)
    V8(k)
    V8(l)
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101(float*, float*, int);
};

struct Shape {
    u8 pad0[2];
    u16 flags;
    u8 pad1[8];
    void* resource;
    u8 pad2[8];
    float width, height;
};

struct Destination {
    u8 pad[0x1c];
    u8 flags;
    u8 pad1[3];
    float x, y;

    void setPosition(float px, float py) {
        x = px;
        y = py;
        flags |= 0x20;
    }
};

struct Object {
    Shape* shape;
    Destination* destination;
    int count;
    float x, y;
    Vec2 size;
    u8 state, flags;
};

struct Modules {
    u8 pad0[4];
    Model* model;
    u8 pad1[4];
    Object_vptr_0* posture;
    Graphics* graphics;
};

struct Fighter {
    u8 pad[0xd8];
    Modules* modules;
};

extern "C" {
    void* __dynamic_cast(void*, long, const void*, const void*, long);
    void fn_80010ED4(void*);
    void fn_8001133C(void*, Vec2*, Vec2*);
    void fn_80011528(void*, float, Vec2*);
    void fn_8003DC64(Vec2*, Vec2*, float);
    void fn_8003E6DC(Matrix*, Vec3*);

    extern float lbl_27_rodata_D18[];
    extern char lbl_27_data_157A0[];
    extern char lbl_27_data_157C8[];
    extern char lbl_27_data_157D8[];
}

extern "C" void fn_27_A6DEC(Object* self, Fighter* fighter, int enabled) {
    u16 bits;
    float* constants = lbl_27_rodata_D18;
    int count = self->count;

    if (count >= 0) {
        count--;
        self->count = count;
        if (count < 0) {
            ((FlagBits*)&self->destination->flags)->active = 0;
            ((FlagBits*)&self->flags)->active = 0;
            self->count = -1;
            return;
        }
    }

    bits = self->shape->flags;
    if (!(bits & 2)) {
        int hasTarget = bits & 1;
        Vec3 pos;

        if (hasTarget) {
            pos = fighter->modules->model->slot36(self->shape->resource, 0);
        } else {
            pos = fighter->modules->posture->slot4();
        }

        self->destination->setPosition(pos.x, pos.y);

        switch (self->state) {
        case 0: {
            Vec2 v(self->x, self->y);
            Vec2 p = self->size;

            if ((u32)((self->flags >> 4) & 1) == 1) {
                v.x = constants[1];
            } else if (bits & 4) {
                v.x *= fighter->modules->posture->slot9();
            }

            if (bits & 0x200) {
                if (hasTarget) {
                    Vec3 point = {v.x, v.y, constants[1]};
                    point = fighter->modules->model->slot37(
                        self->shape->resource, &point, 0, 0);
                    v.set(point.x - pos.x, point.y - pos.y);
                } else {
                    const Vec3& rotation =
                        fighter->modules->posture->slot14(0);
                    fn_8003DC64(&v, &v, constants[2] * rotation.x);
                }
            }

            if (!(bits & 0x40)) {
                if (hasTarget) {
                    Matrix matrix;
                    Vec3 scale;
                    fighter->modules->model->slot40(
                        self->shape->resource, &matrix, 0);
                    fn_8003E6DC(&matrix, &scale);
                    if (constants[0] != scale.x) {
                        p.x *= scale.x;
                        p.y *= scale.x;
                        v.x *= scale.x;
                        v.y *= scale.x;
                    }
                } else {
                    float scale = fighter->modules->posture->slot22();
                    if (constants[0] != scale) {
                        p.x *= scale;
                        p.y *= scale;
                        v.x *= scale;
                        v.y *= scale;
                    }
                }
            }

            fn_8001133C(
                __dynamic_cast(self->destination, 0x44,
                               lbl_27_data_157C8, lbl_27_data_157D8, 0),
                &v, &p);
            break;
        }

        case 1: {
            Vec2 v(self->x, self->y);
            float radius = self->size.x;

            if ((u32)((self->flags >> 4) & 1) == 1) {
                v.x = constants[1];
            } else if (bits & 4) {
                v.x *= fighter->modules->posture->slot9();
            }

            if (bits & 0x200) {
                if (hasTarget) {
                    Vec3 point = {v.x, v.y, constants[1]};
                    point = fighter->modules->model->slot37(
                        self->shape->resource, &point, 0, 0);
                    v.set(point.x - pos.x, point.y - pos.y);
                } else {
                    const Vec3& rotation =
                        fighter->modules->posture->slot14(0);
                    fn_8003DC64(&v, &v, constants[2] * rotation.x);
                }
            }

            if (!(bits & 0x40)) {
                if (hasTarget) {
                    Matrix matrix;
                    Vec3 scale;
                    fighter->modules->model->slot40(
                        self->shape->resource, &matrix, 0);
                    fn_8003E6DC(&matrix, &scale);
                    if (constants[0] != scale.x) {
                        radius *= scale.x;
                        v.x *= scale.x;
                        v.y *= scale.x;
                    }
                } else {
                    float scale = fighter->modules->posture->slot22();
                    if (constants[0] != scale) {
                        radius *= scale;
                        v.x *= scale;
                        v.y *= scale;
                    }
                }
            }

            fn_80011528(
                __dynamic_cast(self->destination, 0x44,
                               lbl_27_data_157A0, lbl_27_data_157D8, 0),
                radius, &v);
            break;
        }

        case 2:
        case 3:
        case 4: {
            float first[14];
            float bounds[14];
            Vec2 p;
            Vec2 v;

            fighter->modules->graphics->slot101(first, bounds, 0);

            if (self->state == 2) {
                p.set(self->shape->width + (bounds[8] - bounds[6]),
                      self->shape->height + (bounds[3] - bounds[5]));
                v.set(constants[3] * (bounds[8] + bounds[6]) - pos.x,
                      constants[3] * (bounds[3] + bounds[5]) - pos.y);
            } else if (self->state == 3) {
                float height =
                    self->shape->height + (bounds[3] - bounds[7]);
                p.set(self->shape->width + (bounds[8] - bounds[6]), height);
                v.set(constants[3] * (bounds[8] + bounds[6]) - pos.x,
                      bounds[7] + constants[3] * height - pos.y);
            } else if (self->state == 4) {
                float height =
                    self->shape->height + (bounds[7] - bounds[5]);
                p.set(self->shape->width + (bounds[8] - bounds[6]), height);
                v.set(constants[3] * (bounds[8] + bounds[6]) - pos.x,
                      bounds[7] - constants[3] * height - pos.y);
            }

            fn_8001133C(
                __dynamic_cast(self->destination, 0x44,
                               lbl_27_data_157C8, lbl_27_data_157D8, 0),
                &v, &p);
            break;
        }
        }
    }

    if (enabled && ((FlagBits*)&self->flags)->active) {
        if (!((FlagBits*)&self->destination->flags)->initialized) {
            fn_80010ED4(self->destination);
        }
        self->destination->flags |= 0x80;
    } else {
        ((FlagBits*)&self->destination->flags)->active = 0;
    }
}
