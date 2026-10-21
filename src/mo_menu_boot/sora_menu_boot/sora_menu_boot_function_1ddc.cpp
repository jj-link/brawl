#pragma force_active on
struct BootObject {
    char padding[0x5C];
    virtual ~BootObject();
};

struct MenuBoot {
    char padding[0x150];
    int state;
    unsigned int file154;
    unsigned int file158;
    void* task;
    BootObject* object;
    void* resource;
};

extern "C" void fn_8018E808(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void fn_800B8A0C(void*, int);

extern "C" void fn_22_1DDC(MenuBoot* self) {
    self->state = 0;
    fn_8018E808(&self->file154);
    fn_8018E808(&self->file158);
    exit__6gfTaskFv(self->task);
    self->task = 0;
    delete self->object;
    self->object = 0;
    fn_800B8A0C(self->resource, 1);
    self->resource = 0;
}
