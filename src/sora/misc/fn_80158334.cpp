#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8014E478(void*, int);
}

struct Obj {
    char pad0[0x44];
    int m44;
    void* m48;
    unsigned char m4c;
    char pad4d[0xf];
    int m5c;
};

extern "C" void fn_80158334(Obj* self) {
    if (self->m48 == 0) {
        void* r = __nw__FUlQ25Heaps8HeapType(0x98, self->m44);
        if (r != 0) {
            r = fn_8014E478(r, self->m44);
        }
        self->m48 = r;
        if (r == 0) {
            self->m4c = 1;
        } else {
            self->m5c = 1;
            self->m4c = 0;
        }
    }
}