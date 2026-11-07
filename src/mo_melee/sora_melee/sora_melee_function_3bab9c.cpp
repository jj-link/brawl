#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* a, int b);
};

struct Inner { char pad[0x64]; Object_vptr_0* obj; };
struct Acc { char pad[0xd8]; Inner* inner; };

extern unsigned char lbl_27_bss_7B0C[];
extern "C" void* fn_27_30FA2C(void*, int, int, Acc*, int);
extern "C" void fn_27_17DE50(Acc*, void*, void*);

extern "C" void fn_27_3BAB9C(void* self, Acc* a) {
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x122, a, 0), 0x20000001);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x123, a, 0), 0x20000002);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x125, a, 0), 0x20000003);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x124, a, 0), 0x20000004);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x126, a, 0), 0x20000005);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x127, a, 0), 0x20000006);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x128, a, 0), 0x20000007);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x12b, a, 0), 0x20000008);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x12a, a, 0), 0x20000009);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x129, a, 0), 0x2000000a);
    a->inner->obj->slot5(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x12c, a, 0), 0x2000000b);
    void* x = fn_27_30FA2C(lbl_27_bss_7B0C, 3, 0x1dc, a, 0);
    fn_27_17DE50(a, x, fn_27_30FA2C(lbl_27_bss_7B0C, 3, 0x1e2, a, 0));
}
