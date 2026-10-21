#pragma force_active on

extern "C" void renderOpa__6gfTaskFv();
extern "C" const float lbl_71_rodata_0;
extern "C" void* fn_801AC554(void*, int);
extern "C" void fn_801A7750(void*, void*);

struct SceneRoot {
    char pad[0x40];
    void* child;
};

extern "C" SceneRoot* g_gfSceneRoot;

struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Params {
    int n;
    int pad[3];
    Vec3 v;
    int pad2[3];
    float f;
};

struct Self {
    char pad[0x1f8];
    float x, y, z;
};

extern "C" void fn_71_1D08(Self* self) {
    renderOpa__6gfTaskFv();
    if (g_gfSceneRoot != 0) {
        void* obj = g_gfSceneRoot->child;
        if (obj != 0) {
            struct ParamsRaw {
                int n;
                int pad[3];
                float x, y, z;
                int pad2[3];
                float f;
            } p;

            p.n = 2;
            Vec3 v(self->x, self->y, self->z);
            p.x = v.x;
            p.y = v.y;
            p.z = v.z;
            p.f = lbl_71_rodata_0;

            void* h = fn_801AC554(obj, 1);
            fn_801A7750(&h, &p);
        }
    }
}
