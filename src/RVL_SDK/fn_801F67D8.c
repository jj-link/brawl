#pragma force_active on
typedef void (*FuncPtr)(void);

struct Obj {
    int pad[14];
    FuncPtr func;
};

extern void fn_801F67D8(void* arg0, struct Obj* self) {
    if (self->func) {
        self->func();
    }
}
