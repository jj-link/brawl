#pragma force_active on

extern "C" {

extern void* lbl_80465978[];
extern int lbl_805A0508;
void fn_80204E6C(int, void*);
void fn_8015C238(void*, int);
void __dl__FPv(void* p);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__Q34nw4r2ut5ColorFv(void* ptr, int destroyFlag);

class Object {
public:
    char padding[0];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};

void* fn_801890EC(void* arg0, int arg1) {
    if (arg0 != 0) {
        Object* self = (Object*)arg0;
        *(void***)self = lbl_80465978;
        self->v4();
        int field = *(int*)((char*)arg0 + 0x40);
        if (field != 0) {
            fn_80204E6C(lbl_805A0508, (void*)field);
            *(int*)((char*)arg0 + 0x40) = 0;
        }
        __destroy_arr((char*)arg0 + 0x28, __dt__Q34nw4r2ut5ColorFv, 4, 4);
        if ((char*)arg0 + 4) {
            fn_8015C238((char*)arg0 + 4, 0);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
