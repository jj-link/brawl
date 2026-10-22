#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct FtRegBlock {
    unsigned char head[0xC];
    unsigned char rest[0x174];
};

extern "C" {
extern FtRegBlock lbl_110_bss_450;
void* fn_110_20E14(void* self);
void* fn_110_1FA28(void* object, short deleting);
void fn_110_C79C(void* a0, int a1, int a2);
void* fn_110_20E5C(void* info);
void* fn_110_20EB4(void* object, short deleting);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_110_20D90() {
    unsigned char (FtRegBlock::*h)[0xC] = &FtRegBlock::head;
    unsigned char* base = reinterpret_cast<unsigned char*>(&lbl_110_bss_450);
    fn_110_20E14(base + 0xC);
    __register_global_object(base + 0xC, (void*)fn_110_1FA28, &(lbl_110_bss_450.*h));
    fn_110_C79C(base + 0x14C, 0xFF, 0);
    fn_110_C79C(base + 0x154, 0xFF, 1);
    fn_110_20E5C(base + 0x168);
    __register_global_object(base + 0x168, (void*)fn_110_20EB4, base + 0x15C);
}

__declspec(section ".ctors") extern void* const fn_110_20D90_ctor = (void*)fn_110_20D90;
