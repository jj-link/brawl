#pragma force_active on
struct Obj;

extern "C" void fn_95_1C58(Obj* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" {
Obj* fn_95_1E88(Obj* self, short flag) {
    if (self != 0) {
        fn_95_1C58(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
