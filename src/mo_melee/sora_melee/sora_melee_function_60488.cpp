#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_27_60A90(void*, void*);

void fn_27_60488(void* self, void* arg) {
    fn_27_60A90(arg, reinterpret_cast<u8*>(self) + 0x64);
}
}
