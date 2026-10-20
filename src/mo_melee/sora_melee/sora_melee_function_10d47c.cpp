#pragma force_active on
typedef unsigned int u32;

extern "C" void* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_1158AC();

extern "C" void fn_27_10D47C(void* self) {
    getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_1158AC();
}
