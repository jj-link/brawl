#include <types.h>
#pragma force_active on

class Obj2AAC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual f32 v12();
};

class Object_vptr_4_base {
public:
    char pad[0x4];
};

class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual f32 slot2(char* a, s32 id, s32 idx) = 0;
    virtual s32 slot3(char* a, s32 id, s32 idx) = 0;
    virtual void slot4() = 0;
    virtual f32 slot5(char* a, s32 id, s32 idx) = 0;
    virtual s32 slot6(char* a, s32 id, s32 idx) = 0;
};

extern Object_vptr_4_base lbl_27_bss_71C8;
extern double lbl_27_rodata_4648;

extern "C" s32 fn_27_28CCF0(char* self, s32 id) {
    s32 kind = (s32)((u32)id >> 28);
    s32 flag = 0;
    f32 f;

    if (kind > 0 && kind < 3) {
        flag = 1;
    }
    if (flag != 0) {
        if ((s32)(((u32)id >> 24) & 0xF) == 1) {
            f = ((Obj2AAC*)(self + 0x2AAC))->v12();
            return (s32)f;
        }
        return ((Obj2AAC*)(self + 0x2AAC))->v4();
    }

    if (id < 0x4E1F) {
        s32 flag2 = 0;
        if (kind > 0 && kind < 3) {
            flag2 = 1;
        }
        if (flag2 != 0) {
            if ((((u32)id >> 24) & 0xF) == 0) {
                f = (f32)((Obj2AAC*)(self + 0x2AAC))->v4();
            } else {
                f = ((Obj2AAC*)(self + 0x2AAC))->v12();
            }
        } else if (id > 0x4E1F) {
            s32 flag3 = 0;
            s32 r3v;
            if (kind > 0 && kind < 3) {
                flag3 = 1;
            }
            if (flag3 != 0) {
                if ((s32)(((u32)id >> 24) & 0xF) == 1) {
                    r3v = (s32)((Obj2AAC*)(self + 0x2AAC))->v12();
                } else {
                    r3v = ((Obj2AAC*)(self + 0x2AAC))->v4();
                }
            } else if (id < 0x4E1F) {
                s32 flag4 = 0;
                f32 f4;
                if (kind > 0 && kind < 3) {
                    flag4 = 1;
                }
                if (flag4 != 0) {
                    if ((((u32)id >> 24) & 0xF) == 0) {
                        f4 = (f32)((Obj2AAC*)(self + 0x2AAC))->v4();
                    } else {
                        f4 = ((Obj2AAC*)(self + 0x2AAC))->v12();
                    }
                } else if (id > 0x4E1F) {
                    f4 = (f32)fn_27_28CCF0(self, id);
                } else if (id < 0x7CF) {
                    f4 = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot2(self + 0xCC, id, 0);
                } else {
                    f4 = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot5(self + 0xCC, id, 0);
                }
                r3v = (s32)f4;
            } else if (id < 0x55EF) {
                r3v = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot3(self + 0xCC, id, 0);
            } else {
                r3v = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot6(self + 0xCC, id, 0);
            }
            f = (f32)r3v;
        } else if (id < 0x7CF) {
            f = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot2(self + 0xCC, id, 0);
        } else {
            f = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot5(self + 0xCC, id, 0);
        }
        return (s32)f;
    }

    if (id < 0x55EF) {
        return ((Object_vptr_4*)&lbl_27_bss_71C8)->slot3(self + 0xCC, id, 0);
    }
    return ((Object_vptr_4*)&lbl_27_bss_71C8)->slot6(self + 0xCC, id, 0);
}
