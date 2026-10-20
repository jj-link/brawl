#pragma force_active on
extern "C" void fn_52_363C(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_52_data_44B8[];

struct Obj {
    char pad0[0x3c];
    void* f3c;
    char pad1[0x15c];
    void* f19c;
};

extern "C" void* fn_52_132AC(void* self, int flags) {
    if (self != 0) {
        Obj* obj = (Obj*)self;
        if (self != 0) {
            void* p = obj->f19c;
            obj->f3c = &lbl_52_data_44B8;
            if (p != 0)
                __dl__FPv(p);
            obj->f19c = 0;
            fn_52_363C(self, 0);
        }
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
