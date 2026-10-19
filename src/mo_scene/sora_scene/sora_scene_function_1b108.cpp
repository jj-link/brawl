#pragma force_active on
struct SceneTask {
    unsigned char pad[8];
    void* task;
};

struct gfTask {
    void exit();
};

extern "C" int fn_1_1B108(SceneTask* self) {
    static_cast<gfTask*>(self->task)->exit();
    self->task = 0;
    return 0;
}
