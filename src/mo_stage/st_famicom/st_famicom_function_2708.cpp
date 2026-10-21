#pragma force_active on

#define VIRTUAL_SLOT(n) virtual void slot##n();
#define VIRTUAL_TEN(n) \
    VIRTUAL_SLOT(n##0) VIRTUAL_SLOT(n##1) VIRTUAL_SLOT(n##2) \
    VIRTUAL_SLOT(n##3) VIRTUAL_SLOT(n##4) VIRTUAL_SLOT(n##5) \
    VIRTUAL_SLOT(n##6) VIRTUAL_SLOT(n##7) VIRTUAL_SLOT(n##8) \
    VIRTUAL_SLOT(n##9)

struct Base {
    char pad[0x3C];
};

struct Obj : Base {
    VIRTUAL_TEN(0)
    VIRTUAL_TEN(1)
    VIRTUAL_TEN(2)
    VIRTUAL_TEN(3)
    VIRTUAL_TEN(4)
    VIRTUAL_TEN(5)
    VIRTUAL_TEN(6)
    VIRTUAL_TEN(7)
    VIRTUAL_TEN(8)
    VIRTUAL_TEN(9)
    VIRTUAL_TEN(10)
    VIRTUAL_TEN(11)
    VIRTUAL_TEN(12)
    VIRTUAL_SLOT(130)
    VIRTUAL_SLOT(131)
    VIRTUAL_SLOT(132)
    virtual void release(void*);
};

#undef VIRTUAL_TEN
#undef VIRTUAL_SLOT

extern "C" {

extern char lbl_68_data_8E8[];

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8015C238(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void* fn_68_23FC(void*, int);
void __dl__FPv(void*);

void* fn_68_2708(void* self, int flag) {
    if (self != 0) {
        char* obj = (char*)self;
        void* ptr = *(void**)(obj + 0x9B8);
        *(void**)(obj + 0x3C) = lbl_68_data_8E8;

        if (ptr != 0)
            Destroy__Q34nw4r3g3d6G3dObjFv(ptr);

        ((Obj*)self)->release(obj + 0x1EC);

        if ((char*)self + 0x1EC)
            fn_8015C238((char*)self + 0x1EC, 0);

        __dt__14snd3DGeneratorFv((char*)self + 0x1E4, -1);
        fn_68_23FC(self, 0);

        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}

}
