#pragma force_active on
extern "C" void fn_52_363C(void* self, int flag);
extern "C" char lbl_52_data_44B8[];

struct Obj {
    char pad1[0x3c];
    void* f3c;
    char pad2[0x15c];
    void* f19c;
};

extern "C" void* fn_52_12714(void* self, int flag) {
    if (self != 0) {
        Obj* obj = (Obj*)self;
        void* ptr = obj->f19c;
        obj->f3c = &lbl_52_data_44B8;
        if (ptr != 0) {
            operator delete(ptr);
        }
        obj->f19c = 0;
        fn_52_363C(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
