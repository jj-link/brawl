#pragma force_active on

extern "C" {

extern void* lbl_80465738[];
extern int lbl_805A0508;
void fn_80204E6C(int, void*);
void fn_8018C1B0(void*);
void fn_80182894(void*, int);
void __dl__FPv(void* p);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__Q34nw4r2ut5ColorFv(void* ptr, int destroyFlag);

class Elem {
public:
    virtual void v0(int);
};

class Other {
public:
    virtual void v0(int);
    char pad[0x55];
    unsigned char flag;
};

struct Obj {
    void* vtable;
    char pad4[0x28 - 0x4];
    Other* field28;
    char pad2c[0xD4 - 0x2C];
    unsigned char colors[0xE4 - 0xD4];
};

extern "C" void* fn_801846F8(void* arg0, int arg1) {
    if (arg0 != 0) {
        Obj* self = (Obj*)arg0;
        self->vtable = lbl_80465738;
        Other* o = self->field28;
        if (o != 0 && o->flag == 0) {
            o->v0(-1);
            fn_80204E6C(lbl_805A0508, self->field28);
            self->field28 = 0;
        }
        fn_8018C1B0((char*)arg0 + 0xE4);
        __destroy_arr((char*)arg0 + 0xD4, __dt__Q34nw4r2ut5ColorFv, 4, 4);
        fn_80182894(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
