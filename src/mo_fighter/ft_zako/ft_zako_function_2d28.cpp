#pragma force_active on
extern "C" void* fn_27_14FCF4(void*, short);

void operator delete(void* p);

extern "C" {
void* fn_126_2D28(void* self, short flags);
}

void* fn_126_2D28(void* self, short flags) {
    if (self != 0) {
        fn_27_14FCF4(self, -1);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
