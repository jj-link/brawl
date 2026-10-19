#pragma force_active on
struct FZeroObject;

extern "C" {
void fn_61_2384(FZeroObject*, int);
void __dl__FPv(void*);

FZeroObject* fn_61_84FC(FZeroObject* self, int deleteFlag) {
    if (self) {
        fn_61_2384(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
