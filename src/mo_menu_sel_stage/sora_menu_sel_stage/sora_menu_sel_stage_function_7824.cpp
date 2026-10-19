#pragma force_active on
extern "C" {
void exit__6gfTaskFv(void*);

struct SelTaskObj {
    char pad[0x68];
    void* task68;
};

void fn_11_7824(SelTaskObj* self) {
    if (self->task68 != 0) {
        exit__6gfTaskFv((char*)self->task68 + 4);
        self->task68 = 0;
    }
    exit__6gfTaskFv(self);
}
}
