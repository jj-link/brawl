#pragma force_active on
typedef unsigned char u8;

struct Color {
    u8 r, g, b, a;
};

struct Scene {
    u8 pad[0x2880];
    Color* colors;
};

struct SceneRoot {
    u8 pad[0x40];
    Scene* scene;
};

struct Object {
    u8 pad[0x3C];
    void* vtable;
    u8 pad40[4];
    u8 handle[4];
};

extern "C" {
extern u8 lbl_25_data_AB4[];
extern Color lbl_25_rodata_30;
extern SceneRoot* g_gfSceneRoot;

void fn_8000E708(SceneRoot*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_25_2010(Object* self, int flag) {
    if (self) {
        self->vtable = lbl_25_data_AB4;
        Color color = lbl_25_rodata_30;
        SceneRoot* root = g_gfSceneRoot;
        Scene* scene = root->scene;
        fn_8000E708(root);

        Color* colors = scene->colors;
        colors[0] = color;
        colors[1] = color;
        colors[2] = color;
        colors[3] = color;

        __dt__14gfFileIOHandleFv(self->handle, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
