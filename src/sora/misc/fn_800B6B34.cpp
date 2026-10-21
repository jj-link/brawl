#pragma force_active on

struct Vec3f {
    float x, y, z;
    Vec3f() {}
};

struct Matrix {
    float m[3][4];
    void setSRT(const Vec3f&, const Vec3f&, const Vec3f&);
};

struct Node {
    char pad[0x20];
    float sx, sy, sz;
    float rx, ry, rz;
    float tx, ty, tz;
};

struct Model {
    char pad[0xe8];
    void* resource;
};

struct Object {
    char pad[0x10];
    Model* model;
};

extern "C" Node* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(
    const void*, const char*);

extern "C" void fn_800B6B34(Matrix* out, Object* self, const char* name)
{
    Matrix m;
    void* resource = self->model->resource;
    Node* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&resource, name);

    Vec3f translate;
    translate.x = node->tx;
    translate.y = node->ty;
    translate.z = node->tz;

    Vec3f rotate;
    rotate.x = node->rx;
    rotate.y = node->ry;
    rotate.z = node->rz;

    Vec3f scale;
    scale.x = node->sx;
    scale.y = node->sy;
    scale.z = node->sz;

    m.setSRT(scale, rotate, translate);
    *out = m;
}
