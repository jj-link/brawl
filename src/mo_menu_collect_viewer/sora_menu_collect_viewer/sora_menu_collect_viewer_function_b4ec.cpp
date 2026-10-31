#pragma force_active on
extern "C" {
extern char lbl_6_data_8E0[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
}

extern "C" void fn_6_B4EC(void* self) {
    unsigned char* s = (unsigned char*)self;
    if (s[0x261] == 0) {
        return;
    }
    void* a = *(void**)(s + 0x70);
    void* b = *(void**)(*(unsigned char**)(s + 0x48) + 0x10);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(a, b, lbl_6_data_8E0);
}
