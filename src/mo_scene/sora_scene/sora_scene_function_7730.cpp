#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);
extern "C" void __dt__20tyFigListDataManagerFv(void*, int);

struct Fig {
    char pad[8];
    void* task;
    char pad2[4];
    void* manager;
};

extern "C" int fn_1_7730(Fig* self) {
    exit__6gfTaskFv(self->task);
    self->task = 0;
    if (self->manager)
        __dt__20tyFigListDataManagerFv(self->manager, 1);
    return 0;
}
