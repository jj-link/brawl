#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
extern char lbl_27_data_3DC08[];
void fn_27_CDA70(void*, int);
void fn_27_CDCC4(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 6;
        u32 value : 3;
        u32 flag : 1;
        u32 rest : 22;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
    u8 arr[0x20];
};

extern "C" Obj* fn_27_19EF6C(Obj* self, u32 value) {
    self->vtable = lbl_27_data_3DC08;
    self->calc = lbl_27_data_3DC08 + 0x48;
    self->flags.raw &= 0x03FFFFFF;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array(self->arr, (void (*)(void*))fn_27_CDCC4, (void (*)(void*))fn_27_CDA70, 0x10, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 2);
    return self;
}
