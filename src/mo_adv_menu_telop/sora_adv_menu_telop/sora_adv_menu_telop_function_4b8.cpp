#pragma force_active on
struct gfTask;

extern "C" void setPaused__6gfTaskFb(gfTask*, bool);

struct fn_38_4B8_Task {
    char pad[0x4C];
    int field_4C;
};

extern "C" void fn_38_4B8(fn_38_4B8_Task* task) {
    if (task->field_4C < 4)
        task->field_4C = 4;
    setPaused__6gfTaskFb(reinterpret_cast<gfTask*>(task), false);
}
