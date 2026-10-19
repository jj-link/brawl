#pragma force_active on
struct FZeroObject;

extern "C" void fn_61_2384(FZeroObject*, int);

extern "C" FZeroObject* fn_61_CBC8(FZeroObject* self, int del) {
    if (self != 0) {
        fn_61_2384(self, 0);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
