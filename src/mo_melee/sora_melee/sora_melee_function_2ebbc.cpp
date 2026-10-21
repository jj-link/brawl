#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" const float lbl_27_rodata_400;
extern "C" void fn_80133E14(void*);

struct Vec2 {
    float x, y;

    Vec2& operator=(const Vec2& other) {
        float ny = other.y, nx = other.x;
        x = nx;
        y = ny;
        return *this;
    }
};

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

    void* ptr4;
    Vec2 position2;
    u8 pad10[0x10];
    Vec3 position;
    u32 id;
    u8 pad30[6];
    u16 value36;
    u32 upper : 16;
    u32 kind : 4;
    u32 lower : 8;
    u32 flag : 1;
    u32 bottom : 3;
};

extern "C" void fn_27_2EBBC(State* self, const Vec2* position) {
    if (self->data != 0) {
        self->kind = self->getData()->getType();

        switch (self->getData()->getType()) {
        case 0:
            self->position.x = lbl_27_rodata_400;
            self->position.y = lbl_27_rodata_400;
            self->position.z = lbl_27_rodata_400;
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

    if (self->ptr4 != 0)
        fn_80133E14(self->ptr4);

    self->value36 = 0;
    self->flag = 0;
    self->position2 = *position;
}
