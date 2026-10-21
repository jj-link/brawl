#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_80286D74(void*, void*, void*);

void fn_802E444C(void* self, void* arg) {
    fn_80286D74(arg, reinterpret_cast<u8*>(self) + 0x10, self);
}
}
