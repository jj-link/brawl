#pragma force_active on

struct Task {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x50];
    void* object;
    char pad94[4];
    unsigned char active;
    char pad99[0x37B];
    int sound414;
    int group;
    int sound;
    float value;
};

extern "C" {
void fn_80075F1C(void*, int, int);
void fn_8006C6DC();
void fn_800F5284(Task*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void freeGroup__9sndSystemFii(void*, int, int);
void* __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern void* g_sndSystem;
extern char lbl_8045BD28[0x98];
extern char lbl_8045BDF0[0x98];
extern const float lbl_805A2610;

extern "C" Task* fn_800F6280(Task* self, int flags) {
    if (self != 0) {
        self->vtable = &lbl_8045BD28;
        if (self->sound >= 0) {
            fn_80075F1C(g_sndSystem, self->sound, 0);
            self->sound = -1;
        }
        fn_8006C6DC();

        if (self != 0) {
            self->vtable = &lbl_8045BDF0;
            if (self->object != 0) {
                fn_800F5284(self);
                Destroy__Q34nw4r3g3d6G3dObjFv(self->object);
                self->active = 0;
                if (self->group >= 0) {
                    freeGroup__9sndSystemFii(g_sndSystem, self->group, 0);
                    self->group = -1;
                    self->sound414 = -1;
                    self->sound = -1;
                    self->value = lbl_805A2610;
                }
            }
            __dt__6gfTaskFv(self, 0);
        }

        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
