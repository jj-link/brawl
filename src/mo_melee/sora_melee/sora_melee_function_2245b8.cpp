#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Rect2D {
    float left, right, top, bottom;
    char pad10[0x10];
    Vec3f center;
};

struct stPositions;

struct StageParam {
    char pad0[0x18];
    float x, y, z;
    char pad24[0x2C];
    float top, bottom, right, left;
};

struct SceneRoot {
    char pad0[0x47C];
    float x, y, z;
};

struct Stage {
    char pad0[0x78];
    Rect2D* camera;
    char pad7C[0x14];
    stPositions* positions;
    char pad94[4];
    StageParam* param;
};

extern "C" {
void fn_27_2263D8(stPositions*);
void getCameraRange__11stPositionsFP6Rect2D(stPositions*, Rect2D*);
void getCameraCenter__11stPositionsFP5Vec3f(stPositions*, Vec3f*);

extern SceneRoot* g_gfSceneRoot;

void updateStagePositions__5StageFv(Stage* self) {
    if (self->positions) {
        fn_27_2263D8(self->positions);
        getCameraRange__11stPositionsFP6Rect2D(self->positions, self->camera);
        getCameraCenter__11stPositionsFP5Vec3f(self->positions, &self->camera->center);

        if (self->param) {
            self->camera->right *= self->param->right;
            self->camera->left *= self->param->left;
            self->camera->top *= self->param->top;
            self->camera->bottom *= self->param->bottom;
            g_gfSceneRoot->x = self->param->x;
            g_gfSceneRoot->y = self->param->y;
            g_gfSceneRoot->z = self->param->z;
        }
    }
}
}
