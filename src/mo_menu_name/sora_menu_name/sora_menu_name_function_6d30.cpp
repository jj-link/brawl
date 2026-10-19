#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void* fn_16_6D30(void* self, int flag);
}

void* fn_16_6D30(void* self, int flag) {
    if (self) {
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
