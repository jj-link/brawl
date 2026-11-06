#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_144;
extern char lbl_27_bss_148[];
extern char lbl_27_bss_138[];
void fn_27_7B5B0(void* p);
void* fn_27_7B5D0(void* p, int n);
void fn_27_7B38C(void* p);
void fn_27_7B3AC(void* p);
void __register_global_object(void* object, void* destructor, void* chain);
}

struct Flagged {
    char pad[0x8];
    unsigned int flags;
};

struct ShortSlot {
    short v;
    short pad;
};

class ObjC;

class Object_vptr_0 {
public:
    virtual int slot0(void* a, int* b, int c, short* d, void* e);
    virtual ObjC** slot1(int i);
    virtual void slot2();
    virtual int slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12();
    virtual Flagged* slot13();
    virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37();
    virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41();
    virtual void slot42(); virtual void slot43();
    virtual void slot44(int i);
    virtual void slot45();
    virtual int slot46();
};

class ObjC {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12();
    virtual unsigned int slot13(void* a, Flagged* b, int c);
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18(); virtual void slot19(); virtual void slot20();
    virtual void init();
    virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37();
    virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41();
    virtual int slot42(int sp);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_73C90();
    virtual void fn_27_73D24();
    virtual void fn_27_74B94(int a, void* b);
    virtual void fn_27_75684();
    virtual void fn_27_758E4();
    virtual void fn_27_73DA4();
    virtual void fn_27_73E50();
    virtual void fn_27_73EFC();
    virtual void fn_27_73FA8();
    virtual void fn_27_74054();
    virtual void fn_27_74100();
    virtual void fn_27_741AC();
    virtual void fn_27_74274();
    virtual void fn_27_74334();
    virtual void fn_27_7440C();
    virtual void fn_27_75498();
    virtual void fn_27_75E04();
    virtual void fn_27_75A48();
    virtual void fn_27_75DF8();
    virtual void fn_27_75DF0();
    virtual void fn_27_746B0();
    virtual void fn_27_75DDC();
    virtual void fn_27_75DC8();
    virtual void fn_27_75DB4();
    virtual void fn_27_75DA0();
    virtual void fn_27_75D8C();
    virtual void fn_27_75D78();
    virtual void fn_27_74B08();
    virtual void fn_27_749F8();
    virtual void fn_27_74A04();
    virtual void fn_27_74A7C();
    virtual void fn_27_758F0();
    virtual void fn_27_75C9C();
    virtual void fn_27_74E9C();
    virtual void fn_27_75B18();
    virtual void fn_27_75B2C();
    virtual void fn_27_75B6C();
    virtual void fn_27_74FB0();
    char pad4[0x28];
    Object_vptr_0* unk2C;
    Object_vptr_0* unk30;
    int unk34;
};

struct Inner {
    char pad[0x5c];
    Object_vptr_0* x;
};

struct Arg1 {
    char pad0[8];
    Object_vptr_3c* task;
    char pad1[0xcc];
    Inner* unkD8;
};

extern "C" int fn_27_746B0(soNullable* arg0, Arg1* arg1) {
    int sp10;
    ShortSlot spC;
    ShortSlot sp8;

    sp10 = -1;
    arg1->unkD8->x->slot44(0);
    if (!lbl_27_bss_144) {
        fn_27_7B5B0(lbl_27_bss_148);
        __register_global_object(lbl_27_bss_148, (void*)fn_27_7B5D0, lbl_27_bss_138);
        lbl_27_bss_144 = 1;
    }
    char* blk = lbl_27_bss_148;
    int r27;
    fn_27_7B38C(blk);
    spC.v = 0;
    bool ok = arg0->unk2C->slot0(arg1, &sp10, -1, (short*)&spC, blk) == 1;
    if (ok) {
        if (sp10 <= -1) {
            return 0;
        }
        if (arg1->task->slot42(sp10) == 0) {
            return 0;
        }
        if (arg0->unk2C->slot13()->flags & 1) {
            arg1->unkD8->x->slot45();
        }
        arg0->fn_27_74B94(sp10, arg1);
        return 1;
    }
    int count = arg1->unkD8->x->slot46();
    if (count > 0) {
        int r26 = count;
        sp10 = -1;
        while (r26 > 0) {
            fn_27_7B3AC(blk);
            arg1->unkD8->x->slot44(r26);
            sp8.v = 1;
            bool ok2 = arg0->unk2C->slot0(arg1, &sp10, -1, (short*)&sp8, blk) == 1;
            if (ok2) {
                unsigned int r25 = 1;
                if (sp10 <= -1) {
                    return 0;
                }
                r27 = arg0->unk34;
                if (r27 >= 0) {
                    if (r27 < arg0->unk30->slot3()) {
                        ObjC* obj = *arg0->unk30->slot1(r27);
                        if (obj != 0) {
                            Flagged* t = arg0->unk2C->slot13();
                            r25 = obj->slot13(arg1, t, sp10);
                        }
                    }
                }
                if (r25 == 1) {
                    if (arg1->task->slot42(sp10) == 0) {
                        return 0;
                    }
                    arg1->unkD8->x->slot45();
                    arg0->fn_27_74B94(sp10, arg1);
                    return 1;
                }
            }
            r26--;
        }
        arg1->unkD8->x->slot44(0);
    }
    return 0;
}
