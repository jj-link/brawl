#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Rect {
    float left, right, top, bottom;

    Rect(const Rect& r)
        : left(r.left), right(r.right), top(r.top), bottom(r.bottom) {}
};

struct Data {
    char pad[0x10];
    Vec3 position;
    char pad2[0x20];
    Rect bounds;
};

struct Object {
    void* vtable;
    Data* data;
};

extern "C" void fn_27_B1E6C(Object* self, Rect* out) {
    Rect bounds = self->data->bounds;
    Vec3 position = self->data->position;

    out->top = bounds.top + position.y;
    out->bottom = bounds.bottom + position.y;
    out->left = bounds.left + position.x;
    out->right = bounds.right + position.x;
}
