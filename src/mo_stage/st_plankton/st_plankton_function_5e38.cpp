#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_74_data_2118[];

void fn_74_5F3C(void*);
void* fn_74_5F4C(void*, int);
void __construct_array(void*, void (*)(void*), void* (*)(void*, int),
                       unsigned long, int);
}

struct Module {
    void* vt;
    void* vt2;
    void* owner;
    char module[0x1c];
    void* av;
    void* calc;
    u32 flags;
    char entries[0x30];
};

extern "C" Module* fn_74_5E38(Module* self) {
    self->av = lbl_74_data_2118;
    self->calc = lbl_74_data_2118 + 0x48;
    self->flags &= 0x7FFFF;
    __construct_array(self->entries, fn_74_5F3C, fn_74_5F4C, 8, 6);
    return self;
}
