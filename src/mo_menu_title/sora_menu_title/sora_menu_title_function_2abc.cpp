#pragma force_active on
extern "C" void* fn_8007EF70(void*, int, int, int, int);

struct Obj24 {
    char pad0[0x54];
    void* m54;
    int m58;
    void* m5c;
    int m60;
};

extern "C" {
void fn_24_2ABC(Obj24* self) {
    switch (self->m60) {
    case 2:
        self->m5c = fn_8007EF70(self->m54, 0, 0, -1, -1);
        break;
    }
}
}
