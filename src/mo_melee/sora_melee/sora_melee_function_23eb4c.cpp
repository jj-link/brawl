#pragma force_active on
#pragma peephole on

struct SomeObj {
    unsigned char pad[0x5D];
    unsigned char flags;
};

extern "C" int fn_27_23ABA0();

extern "C" int fn_27_23EB4C(SomeObj* obj) {
    if ((unsigned int)((obj->flags >> 3) & 1) == 1U) {
        return 1;
    }
    fn_27_23ABA0();
}
