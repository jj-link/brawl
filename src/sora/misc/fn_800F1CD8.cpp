#pragma force_active on
extern "C" {
extern char lbl_8045B8EC[];
void __dl__FPv(void*);
void __dt__8gfThreadFv(void*, int);
void exit__6gfTaskFv(void*);
void fn_800F20C4(void*);
void free__13gfHeapManagerFPv(void*);
void fn_80153498(void*, int);
void __dt__6gfTaskFv(void*, int);
}

class Thread {
public:
    ~Thread() { __dt__8gfThreadFv(this, 0); }
};

struct Resource {
    char pad[8];
    virtual ~Resource();
};

struct Object {
    char pad0[0x3c];
    void* vptr;
    char pad40[0x44];
    void* buffer84;
    void* buffer88;
    char pad8c[0x10];
    char member9c[0x10];
    void* task;
    char padb0[0xc];
    Resource* resource;
    char padc0[4];
    Thread* thread;
};

extern "C" Object* fn_800F1CD8(Object* self, int flag) {
    if (self) {
        Thread* thread = self->thread;
        self->vptr = lbl_8045B8EC;
        if (thread)
            delete thread;
        if (self->resource)
            delete self->resource;
        if (self->task)
            exit__6gfTaskFv(self->task);
        fn_800F20C4(self);
        if (self->buffer88)
            free__13gfHeapManagerFPv(self->buffer88);
        if (self->buffer84)
            free__13gfHeapManagerFPv(self->buffer84);
        fn_80153498(self->member9c, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
