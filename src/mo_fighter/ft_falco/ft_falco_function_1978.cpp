#pragma force_active on
extern "C" {
void* fn_108_1A18(char*, short);
void* fn_108_1DF8(char*, short);
void* fn_108_1E94(char*, short);
void* fn_108_1FCC(char*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_108_1978(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_108_1A18(self + 0x1CFD4, memberDeleting);
        fn_108_1DF8(self + 0x1CB1C, memberDeleting);
        fn_108_1E94(self + 0x1CAE0, memberDeleting);
        fn_108_1FCC(self + 0x194, memberDeleting);
        fn_27_125E20(self, 0);
        if (deleting > 0) __dl__FPv(self);
    }
    return self;
}
}
