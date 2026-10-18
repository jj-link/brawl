#pragma force_active on
extern "C" {
void operator delete(void* p);
}

extern "C" void* fn_112_1E8C(void* self, short flag) {
    if (self != 0 && flag > 0) {
        operator delete(self);
    }
    return self;
}
