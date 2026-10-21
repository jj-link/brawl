#pragma force_active on
extern "C" void fn_802870F8(void*, void*);

extern "C" void fn_802E4408(char* self, void* arg) {
    fn_802870F8(arg, self + 0x10);
}
