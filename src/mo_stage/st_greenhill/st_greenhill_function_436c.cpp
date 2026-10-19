#pragma force_active on
typedef void (*DtorFn)(void*);

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_72_45FC(void*);
void fn_72_460C(void*);
extern unsigned char lbl_72_data_1DB0[];
}

struct StObj {
    unsigned char pad[0x28];
    unsigned char* m28;
    unsigned char* m2c;
    unsigned long m30;
};

extern "C" void* fn_72_436C(StObj* self) {
    unsigned char* base = lbl_72_data_1DB0;
    self->m28 = base;
    self->m2c = base + 0x48;
    self->m30 &= 0x7FFFF;
    __construct_array((unsigned char*)self + 0x34, (void (*)(void*))fn_72_45FC,
                      (void (*)(void*))fn_72_460C, 8, 6);
    return self;
}
