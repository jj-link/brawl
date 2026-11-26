#include <types.h>

struct Flags {
    signed int state : 8;
    unsigned int rest : 24;
    inline int get() const { return state; }
    inline void set(int v) { state = v; }
};
struct Obj {
    u8 pad[12];
    Flags flags;
    u8 pad2[0x3C];
    u8 sub[1];
    inline int cur() const { return flags.get(); }
    inline void change(int v) { flags.set(v); }
    inline void update() {
        if (cur() == 4) {
            change(2);
        }
    }
};
extern "C" {
int fn_8016FBC8(void*);
void* fn_8016FBF4(void*);
void fn_80163E50(void);
}

#pragma force_active on
extern "C" void fn_8005C9B4(Obj* self) {
    if (fn_8016FBC8(self->sub) != 0) {
        self->update();
        fn_8016FBF4(self->sub);
        fn_80163E50();
    }
}
