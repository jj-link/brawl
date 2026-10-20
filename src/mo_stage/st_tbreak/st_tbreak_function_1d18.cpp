#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct State {
    char pad[0x18];
    Vec3 position;
    float pad24;
    float a;
    float b;
    float c;
    float d;
    int id;

    void setPosition(float x, float y, float z) {
        position.x = x;
        position.y = y;
        position.z = z;
    }

    void setPair(float x, float y) {
        c = x;
        d = y;
    }
};

struct Object {
    char pad[0x160];
    State* state;
    char pad164[8];
    unsigned char flags;
};

struct Input {
    char pad[4];
    float a;
    char pad8[0x74];
    float b;
    Vec3 position;
    float c, d;
};

extern "C" void fn_89_1D18(Object* self, int, const Input* input) {
    float d = input->d;
    float c = input->c;
    float z = input->position.z;
    float y = input->position.y;
    float x = input->position.x;
    float b = input->b;
    float a = input->a;

    self->state->id = -1;
    self->state->a = a;
    self->state->b = b;
    self->state->setPosition(x, y, z);
    self->state->setPair(c, d);
    self->flags |= 0x10;
}
