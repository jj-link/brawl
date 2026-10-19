#pragma force_active on
struct FZeroObject;

extern "C" {
void fn_61_2384(FZeroObject*, int);
}

extern "C" FZeroObject* fn_61_6120(FZeroObject* self, int flag) {
    if (self != 0) {
        fn_61_2384(self, 0);
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
