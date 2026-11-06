#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);
extern unsigned char lbl_27_data_4BEC8[];

struct Object_vptr_4_base {
    char pad[0x4];
};

class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1(int arg);
};

void* fn_27_2334B8(void* self, int deleteFlag) {
    if (self != 0) {
        Object_vptr_4* p18 = *(Object_vptr_4**)((char*)self + 0x18);
        *(void**)((char*)self + 0x30) = lbl_27_data_4BEC8;
        if (p18 && p18) {
            p18->slot1(1);
        }
        Object_vptr_4* p20 = *(Object_vptr_4**)((char*)self + 0x20);
        if (p20 && p20) {
            p20->slot1(1);
        }
        Object_vptr_4* p24 = *(Object_vptr_4**)((char*)self + 0x24);
        if (p24 && p24) {
            p24->slot1(1);
        }
        Object_vptr_4* p28 = *(Object_vptr_4**)((char*)self + 0x28);
        if (p28 && p28) {
            p28->slot1(1);
        }
        *(void**)((char*)self + 0x18) = 0;
        *(void**)((char*)self + 0x20) = 0;
        *(void**)((char*)self + 0x24) = 0;
        *(void**)((char*)self + 0x28) = 0;
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

}
