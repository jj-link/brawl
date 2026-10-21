#pragma force_active on
typedef unsigned int u32;
extern "C" void* getTask__6gfTaskFi(int);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" u32 lbl_27_data_4A000[];
extern "C" u32 __RTTI__6gfTask[];

struct Object {
    char padding[0x8C8];
    u32 taskId;
};

inline void* resolve(const u32& id) {
    if (id == 0xFFFFFFFF)
        return 0;
    void* task = getTask__6gfTaskFi(id);
    if (task)
        return __dynamic_cast(task, 0x3C, lbl_27_data_4A000, __RTTI__6gfTask, 0);
    return 0;
}

extern "C" void* fn_27_288618(Object* self) {
    if (self->taskId == 0xFFFFFFFF)
        return 0;
    return resolve(self->taskId);
}
