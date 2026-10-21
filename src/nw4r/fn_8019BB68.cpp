#pragma force_active on
extern "C" void fn_8019DA5C(void*, unsigned int, int);

struct Obj {
    char pad[0x10];
    int count;
    unsigned short* data;
};

extern "C" void fn_8019BB68(Obj* self) {
    int off;
    int i = 0;
    unsigned short v = 0x8000;
    off = 0;
    while (i < self->count) {
        i++;
        *(unsigned short*)((char*)self->data + off) = v;
        off += 2;
    }
    fn_8019DA5C(self, 4, 0);
}
