#pragma force_active on
extern "C" {
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void freeResource__16gfResourceLoaderFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);

struct ScSelf {
    int a;
    int b;
    void* task;
    int unk;
    void* archive;
    void* loader;
};

int fn_1_1BF3C(ScSelf* self) {
    if (self->task) {
        exit__6gfTaskFv(self->task);
        self->task = 0;
    }
    if (self->archive) {
        __dt__9gfArchiveFv(self->archive, 1);
        self->archive = 0;
    }
    void* loader = self->loader;
    if (loader) {
        if (loader) {
            freeResource__16gfResourceLoaderFv(loader);
            __dt__14gfFileIOHandleFv(loader, -1);
            __dl__FPv(loader);
        }
        self->loader = 0;
    }
    return 0;
}
}
