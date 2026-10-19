#pragma force_active on
extern "C" {
void fn_105_327C(void* p, short n);

void* fn_105_3220(void* self, short flag) {
    if (self != 0) {
        fn_105_327C(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
