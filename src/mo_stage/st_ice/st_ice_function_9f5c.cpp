#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_62_data_2E58[];
void fn_62_5714(void*);
void fn_62_5724(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, unsigned long);
}

struct Obj {
    char pad[0x28];
    void* vt;
    void* calc;
    u32 flags;
    char entries[6][8];
};

extern "C" void* fn_62_9F5C(Obj* self) {
    self->vt = lbl_62_data_2E58;
    self->calc = lbl_62_data_2E58 + 0x48;
    self->flags = self->flags & 0x7FFFF;

    __construct_array(self->entries, fn_62_5714,
                      (void (*)(void*))fn_62_5724, 8, 6);

    return self;
}
