#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

struct Camera {
    char pad0[0x60];
    float x, y, z;
    char pad6C[0x54];
    float a, b, c, d, e;
    char padD4[0x24];
    u16 mode;
    u16 flags;
};

struct Node {
    Node* next;
};

typedef void (Node::*Callback)(u8*);
extern Callback lbl_80454F10;

struct Scene {
    char pad[0x465];
    u8 flags;
};

extern Scene* g_gfSceneRoot;

struct Self {
    Camera* camera;
    char pad4[0xA8];
    Node* nodes;
    char padB0[8];
    u8 state;
    char padB9[3];
    float values[8];
};

extern "C" void fn_80018778(Camera*);

extern "C" void fn_800A6BF0(Self* self) {
    Camera* camera = self->camera;
    camera->e = self->values[0];
    camera->x = self->values[1];
    camera->y = self->values[2];
    camera->z = self->values[3];
    camera->flags |= 2;
    camera->a = self->values[4];
    camera->b = self->values[5];
    camera->d = self->values[6];
    camera->flags |= 0x80;
    camera->c = self->values[7];
    camera->flags |= 0x40;
    camera->mode = 0xE1;
    fn_80018778(camera);

    u8 state = self->state;
    Callback callback = lbl_80454F10;
    for (Node* node = self->nodes; node; node = node->next)
        (node->*callback)(&state);

    self->state = 0;
    g_gfSceneRoot->flags &= ~0x20;
}
