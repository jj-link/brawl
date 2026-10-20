#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Vec3 {
    float x, y, z;

    Vec3& operator=(const Vec3& other) {
        float nz = other.z, ny = other.y, nx = other.x;
        x = nx;
        y = ny;
        z = nz;
        return *this;
    }
};

struct Data {
    u8 type;

    int getType() const { return type; }

    u8 pad[3];
    union {
        Vec3 position;
        struct {
            u32 id;
            Vec3 position;
        } attached;
    } data;
};

struct State {
    Data* data;

    Data* getData() const { return data; }

    u8 pad04[0x1c];
    Vec3 position;
    u32 id;
    u8 pad30[8];
    u32 upper : 16;
    u32 kind : 4;
    u32 lower : 12;
};

extern "C" void fn_27_2EB40(State* self) {
    if (self->data == 0)
        return;

    self->kind = self->getData()->getType();

    switch (self->getData()->getType()) {
    case 0:
    default:
        break;
    case 1:
        self->position = self->data->data.position;
        break;
    case 2: {
        u32 id = self->data->data.attached.id;
        self->position = self->data->data.attached.position;
        self->id = id;
        break;
    }
    }
}
