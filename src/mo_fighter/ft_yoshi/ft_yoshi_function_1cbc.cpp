#pragma force_active on
extern "C" {
void fn_95_1C58(void* self, short flags);
void __dl__FPv(void* p);

void* fn_95_1CBC(void* self, short flags) {
    if (self != 0) {
        fn_95_1C58(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
