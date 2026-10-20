#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_120_3244(void*, short);
void* fn_27_19F32C(void*, short);
void* fn_27_1A54AC(void*, short);
}

extern "C" void* fn_120_31BC(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_27_93100(self + 0x9F28, memberDeleting);
        fn_120_3244(self + 0x68, memberDeleting);
        fn_27_19F32C(self + 0x1C, memberDeleting);
        fn_27_1A54AC(self, memberDeleting);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
