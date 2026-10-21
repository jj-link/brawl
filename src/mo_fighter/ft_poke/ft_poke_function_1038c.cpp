#pragma force_active on

class PokeStorageArray {
public:
    virtual void fn08();
    virtual void fn0C();
    virtual void fn10();
    virtual void fn14();
    virtual void fn18();
    virtual void fn1C();
    virtual void fn20();
    virtual void fn24();
    virtual void fn28();
    virtual void fn2C();
    virtual void append(void*);
};

extern "C" {
void fn_27_CD8C8(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
extern char lbl_27_data_8E80[];
}

extern "C" void* fn_116_1038C(unsigned char* arg0) {
    struct { int field; unsigned char data[0x14]; } locals;

    fn_27_CD8C8(arg0, 0);
    fn_27_1A154C(arg0 + 0x20, 0);

    *(void**)(arg0 + 0x3C) = lbl_27_data_8E80;
    *(void**)(arg0 + 0x40) = arg0;
    *(int*)(arg0 + 0x44) = 0;
    locals.field = 0;
    *(int*)(arg0 + 0x48) = -1;
    *(int*)(arg0 + 0x4C) = -1;
    *(int*)(arg0 + 0x50) = 0;

    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(locals.data, i == 0 ? (void*)(arg0 + 0x20) : 0);
        reinterpret_cast<PokeStorageArray*>(arg0)->append(locals.data);
        fn_27_AB18C(locals.data, -1);
    }

    return arg0;
}
