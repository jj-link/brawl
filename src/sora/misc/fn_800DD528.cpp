#pragma force_active on
extern "C" {
extern char lbl_8045A000[];

void fn_800DD564(void* self, const char* data);

void* fn_800DD528(void* self) {
    *reinterpret_cast<const char**>(static_cast<char*>(self) + 0x1E0) = lbl_8045A000;
    fn_800DD564(self, lbl_8045A000);
    return self;
}
}
