#pragma force_active on
extern "C" {
void exit__6gfTaskFv(void*);
void fn_8003354C();
}

struct SoraMenuFriendObj {
    char pad0[0x24EC];
    void* f24EC;
    char pad1[0x2A2C - 0x24F0];
    void* f2A2C;
};

extern "C" {
void fn_14_294(SoraMenuFriendObj* self);
}

void fn_14_294(SoraMenuFriendObj* self) {
    if (self->f24EC != 0) {
        exit__6gfTaskFv(self->f24EC);
    }
    if (self->f2A2C != 0) {
        fn_8003354C();
    }
    exit__6gfTaskFv(self);
}
