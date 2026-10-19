#pragma force_active on
extern "C" {
void* fn_120_9940(void* self, short flags);

void* fn_120_11F04(void* self, short flags) {
    if (self != 0) {
        fn_120_9940(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
