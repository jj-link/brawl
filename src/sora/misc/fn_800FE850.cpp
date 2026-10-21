#pragma force_active on
extern "C" {
extern char lbl_8045C814[];
void fn_800FE88C(void* self, const char* p);

void* fn_800FE850(void* self) {
    *reinterpret_cast<const char**>(static_cast<char*>(self) + 0x124) = lbl_8045C814;
    fn_800FE88C(self, lbl_8045C814);
    return self;
}
}
