#pragma force_active on
extern "C" void fn_8018E808(void*);
extern "C" void exit__6gfTaskFv(void*);

struct TitleObjectBase {
    unsigned char reserved[0x5C];
};

struct TitleObject : TitleObjectBase {
    virtual ~TitleObject();
};

struct TitleMenu {
    unsigned char reserved[0x40];
    unsigned int resource;
    void* task;
    TitleObject* object;
};

extern "C" void fn_24_8B8(TitleMenu* self) {
    fn_8018E808(&self->resource);
    exit__6gfTaskFv(self->task);
    self->task = 0;
    delete self->object;
    self->object = 0;
}
