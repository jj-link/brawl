#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

struct Fn6_9770 {
    unsigned char pad0[0x124];
    int result;
    unsigned char pad128[0x628];
    void* task;
};

extern "C" int fn_6_9770(Fn6_9770* self) {
    void* task = self->task;
    if (*reinterpret_cast<int*>(static_cast<char*>(task) + 0x104) == 3) {
        exit__6gfTaskFv(task);
        self->task = 0;
        return 14;
    }
    return self->result;
}
