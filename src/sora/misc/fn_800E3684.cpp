#pragma force_active on
extern "C" {

struct StateEntry {
    void (*enter)(void*, int);
    void* unk4;
    void (*exit)(void*);
};

extern const StateEntry lbl_80408840[];

struct Obj {
    char pad[0x14];
    int state;
};

void fn_800E3684(void* arg0, int arg1) {
    Obj* self = (Obj*)arg0;
    void (*exitFn)(void*) = lbl_80408840[self->state].exit;
    if (exitFn != 0) {
        exitFn(arg0);
    }

    int old = self->state;
    self->state = arg1;
    if (lbl_80408840[arg1].enter != 0) {
        lbl_80408840[arg1].enter(arg0, old);
    }
}

}
