#pragma force_active on
class FZeroObject;

extern "C" {
void fn_61_2384(FZeroObject*, int);
void __dl__FPv(void*);
FZeroObject* fn_61_3C98(FZeroObject* self, int flag) {
    if (self) {
        fn_61_2384(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
