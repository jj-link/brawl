#pragma force_active on

struct CaptainGlobals {
    unsigned char chain1[0xC];
    unsigned char object1[4];
    unsigned char chain2[0xC];
    unsigned char object2[4];
    unsigned char chain3[0xC];
    unsigned char object3[4];
    unsigned char chain4[0xC];
    unsigned char object4[4];
    unsigned char chain5[0xC];
    unsigned char object5[4];
    unsigned char chain6[0xC];
    unsigned char object6[4];
    unsigned char chain7[0xC];
    unsigned char object7[4];
};

#pragma push
#pragma opt_propagation off
#pragma scheduling off

extern "C" {
extern CaptainGlobals lbl_100_bss_1E8;

void* fn_100_F6CC(void*);
void* fn_100_F6DC(void*);
void* fn_100_F6EC(void*);
void* fn_100_F6FC(void*);
void* fn_100_F70C(void*);
void* fn_100_F71C(void*);
void* fn_100_F72C(void*);

void* fn_100_F59C(void*, short);
void* fn_100_F55C(void*, short);
void* fn_100_F51C(void*, short);
void* fn_100_F4DC(void*, short);
void* fn_100_F49C(void*, short);
void* fn_100_F45C(void*, short);
void* fn_100_F41C(void*, short);

void* __register_global_object(void*, void* (*)(void*, short), void*);

void fn_100_F5DC() {
    CaptainGlobals* base = &lbl_100_bss_1E8;
    unsigned char (CaptainGlobals::*chain)[0xC] = &CaptainGlobals::chain1;

    fn_100_F6CC(base->object1);
    __register_global_object(base->object1, fn_100_F59C, &(base->*chain));
    fn_100_F6DC(base->object2);
    __register_global_object(base->object2, fn_100_F55C, base->chain2);
    fn_100_F6EC(base->object3);
    __register_global_object(base->object3, fn_100_F51C, base->chain3);
    fn_100_F6FC(base->object4);
    __register_global_object(base->object4, fn_100_F4DC, base->chain4);
    fn_100_F70C(base->object5);
    __register_global_object(base->object5, fn_100_F49C, base->chain5);
    fn_100_F71C(base->object6);
    __register_global_object(base->object6, fn_100_F45C, base->chain6);
    fn_100_F72C(base->object7);
    __register_global_object(base->object7, fn_100_F41C, base->chain7);
}
}

#pragma pop

extern void* const fn_100_F5DC_ctor;

__declspec(section ".ctors") extern void* const fn_100_F5DC_ctor = (void*)fn_100_F5DC;
