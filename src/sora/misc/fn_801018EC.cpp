#pragma force_active on
extern "C" {

struct Vec3f {
    float x, y, z;
};

struct Base {
    char pad[0x14];
};

struct MuObject : Base {
    virtual void v0();
    virtual MuObject* v1();
};

void fn_800DB360(Vec3f*, const Vec3f*, int);
void fn_800B6838(MuObject*, const Vec3f*);

void fn_801018EC(MuObject** self, const Vec3f* vec) {
    if (*self) {
        Vec3f local;
        fn_800DB360(&local, vec, 0);
        MuObject *obj = *self;
        obj = obj->v1();
        fn_800B6838(obj, &local);
    }
}

}
