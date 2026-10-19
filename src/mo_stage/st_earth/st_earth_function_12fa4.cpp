#pragma force_active on
extern "C" {
void fn_66_2C60(void* self, int flag);
void operator delete(void* p);

void* fn_66_12FA4(void* self, int size) {
    if (self != 0) {
        fn_66_2C60(self, 0);
        if (size > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
