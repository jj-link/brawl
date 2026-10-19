#pragma force_active on
extern "C" void* fn_8007EF70(void*, int, int, int, int);

struct Obj3DC9C {
    unsigned char pad0[0x40];
    int f40;
    void* f44;
    void* f48;
    void* f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
};

extern "C" void fn_40_3DC9C(Obj3DC9C* self) {
    switch (self->f40) {
    case 7:
        if (self->f48 != 0) {
            self->f4c = fn_8007EF70(self->f48, self->f58, self->f5c, self->f60, self->f64);
        }
        break;
    }
}
