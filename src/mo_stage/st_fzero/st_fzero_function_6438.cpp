#pragma force_active on
extern "C" {
void fn_61_2384(void*, int);
void __dl__FPv(void*);
void* fn_61_6438(void* self, int doDelete);
}

extern "C" {
void* fn_61_6438(void* self, int doDelete) {
    if (self != 0) {
        fn_61_2384(self, 0);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
