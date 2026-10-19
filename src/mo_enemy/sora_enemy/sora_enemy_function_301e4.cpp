#pragma force_active on
extern "C" {
void* fn_41_30174(void* self, short flag);
void* fn_27_1D81C8(void* self, short flag);

void* fn_41_301E4(void* self, short flag) {
    if (self) {
        fn_41_30174((char*)self + 0xCC, -1);
        fn_27_1D81C8(self, 0);
        if (flag > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
}
