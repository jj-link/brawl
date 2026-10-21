#pragma force_active on

extern "C" void fn_68_17C8(void);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);

struct Data {
    char pad[0x28];
    unsigned char count;
};

struct Elem {
    char pad[0x28];
};

#define D10(x)                                                                        \
    virtual void v##x##0(); virtual void v##x##1(); virtual void v##x##2();          \
    virtual void v##x##3(); virtual void v##x##4(); virtual void v##x##5();          \
    virtual void v##x##6(); virtual void v##x##7(); virtual void v##x##8();          \
    virtual void v##x##9();

class Self {
public:
    char pad[0x3c];
    D10(0) D10(1) D10(2) D10(3) D10(4) D10(5) D10(6) D10(7)
    D10(8) D10(9) D10(10) D10(11) D10(12) D10(13)
    virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143();
    virtual void v144(); virtual void v145(); virtual void v146();
    virtual void call(Elem*);
    char pad2[0x5c];
    Data* data;
    char pad3[0x388];
    Elem* array;
};
#undef D10

extern "C" void fn_68_170C(Self* self) {
    Data* data = self->data;
    if (data != 0) {
        self->array = (Elem*)__construct_new_array(
            __nwa__FUlQ25Heaps8HeapType(data->count * 0x28 + 0x10, 0x11),
            fn_68_17C8, 0, 0x28, data->count);
        if (self->array != 0) {
            unsigned char i;
            unsigned char n = data->count;
            for (i = 0; i != n; i++) {
                self->call(&self->array[i]);
            }
        }
    }
}
