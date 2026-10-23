#pragma force_active on
extern "C" {
extern char lbl_80488D38[];
}

extern "C" void __ct__14Class_8032BBE8Fv(char* self) {
    *(short*)(self + 0x6) = 1;
    *(void**)(self + 0x0) = lbl_80488D38;
    *(unsigned int*)(self + 0x8) = 0x20000;
}
