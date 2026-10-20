#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1FAA0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct Obj;
Obj* fn_27_CA34C(Obj* self);
}

struct Obj {
    char* p0;
    char* p4;
    u32 f8;
};

extern "C" Obj* fn_27_CA34C(Obj* self) {
    self->p0 = lbl_27_data_1FAA0;
    self->p4 = lbl_27_data_1FAA0 + 0x48;
    self->f8 &= 0xFFFF;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 0xb);
    return self;
}
