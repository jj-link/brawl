#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad[0x1e7];
    u8 flags;
    void* f1e8;
    void* f1ec;
};

extern "C" {
void* getGround__5StageFi(void*, int);
void startEntityAutoLoop__8grMadeinFv(void*);
void fn_8011097C(void*);

void fn_27_230D0C(Obj* self, int flag) {
    if (!(self->flags & 1)) {
        void* ground = getGround__5StageFi(self, 0);
        startEntityAutoLoop__8grMadeinFv(ground);
        self->flags |= 1;
    }
    if (flag != 0 && self->f1e8 != 0 && !(self->flags & 2)) {
        startEntityAutoLoop__8grMadeinFv(self->f1e8);
        if (self->f1ec != 0) {
            fn_8011097C(self->f1ec);
        }
        self->flags |= 2;
    }
}
}
