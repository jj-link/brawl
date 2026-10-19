#pragma force_active on
extern "C" {
void* fn_105_628C(void* p, short flags);

void* fn_105_18384(void* self, short flags) {
    if (self != 0) {
        fn_105_628C(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
