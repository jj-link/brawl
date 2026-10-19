#pragma force_active on
extern "C" {
void* fn_8007EF70(void*, int, int, int, int);
}

struct SimpleEndingState {
    char pad[0x9AC];
    void* m9AC;
    void* m9B0;
    void* m9B4;
    int m9B8;
};

extern "C" void fn_19_D98(SimpleEndingState* self) {
    switch (self->m9B8) {
    case 3:
        self->m9B4 = fn_8007EF70(self->m9AC, 0, 0, -1, -1);
        break;
    }
}
