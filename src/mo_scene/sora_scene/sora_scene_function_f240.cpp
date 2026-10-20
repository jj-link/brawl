#pragma force_active on
struct Task {
    char padding[0x200];
    virtual void exit(int);
};

struct Scene {
    char padding[0x390];
    Task* task;
};

extern "C" int fn_1_F240(Scene* scene) {
    if (scene->task) {
        scene->task->exit(1);
    }
    scene->task = 0;
    return 0;
}
