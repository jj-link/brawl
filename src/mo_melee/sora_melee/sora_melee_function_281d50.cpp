#pragma force_active on
extern "C" {
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_5BC58[];
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_282964(void*);
void fn_27_1A1B88(void*);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*);
};

extern "C" void* fn_27_281D50(void* self) {
    char* c = (char*)self;
    char* a = c + 0x18;
    *(void**)(c + 0x4) = a;
    *(int*)(c + 0x8) = 0;
    *(int*)(c + 0xc) = -1;
    *(int*)(c + 0x10) = -1;
    *(int*)(c + 0x14) = 0;
    *(void**)(c + 0x0) = lbl_27_data_5BC58;

    *(void**)(a + 0x0) = lbl_27_data_1D4E8;
    *(void**)(a + 0x4) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(a + 0x8) &= 0x01ffffff;

    __construct_array(a + 0xc, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);
    __construct_array(c + 0x38, fn_27_282964, fn_27_1A1B88, 0x2c, 1);

    char entry[0x14];
    fn_27_AB15C(entry, c + 0x38);
    ((Object_vptr_0*)a)->slot10(entry);
    fn_27_AB18C(entry, -1);
    return self;
}