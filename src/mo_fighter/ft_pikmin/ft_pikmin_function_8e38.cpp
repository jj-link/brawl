#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void fn_27_1AB96C(void*, u8);

extern "C" void* fn_113_8E38(void* self, short event)
{
    u32 base = (u32)self;
    fn_27_711E4(self, event, (void*)((u32)self + 0x24));
    fn_27_1AB96C((void*)(base + 0x24), 0);
    return (void*)base;
}
