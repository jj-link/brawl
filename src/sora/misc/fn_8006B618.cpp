#pragma force_active on
extern "C" void fn_801AB0CC(void* p, unsigned int flag);
extern "C" void fn_801AB078(void* p, unsigned int flag);

extern "C" void fn_8006B618(void*, void* self) {
    *(unsigned int*)((char*)self + 0xD4) = 0;
    fn_801AB0CC(self, 0x20);
    fn_801AB078(self, 4);
}
