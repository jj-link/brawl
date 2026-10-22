#pragma force_active on
typedef int s32;

typedef void (*FnEnter)(void*);
typedef s32 (*FnUpdate)(void*);

struct StateEntry {
    FnEnter enter;
    FnUpdate update;
};

extern "C" void fn_800B9984(void* arg);
extern "C" StateEntry lbl_80407C28[];

struct StateObj {
    char _pad[0x10c];
    s32 state;
    s32 last;
};

extern "C" void fn_800C0960(void* self) {
    StateObj* obj = (StateObj*)self;
    fn_800B9984((char*)self + 0x60);

    if (obj->last != obj->state) {
        FnEnter fe = lbl_80407C28[obj->state].enter;
        if (fe) {
            fe(self);
        }
        obj->last = obj->state;
    }

    FnUpdate fu = lbl_80407C28[obj->state].update;
    if (fu) {
        obj->state = fu(self);
    }
}
