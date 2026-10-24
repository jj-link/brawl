#pragma force_active on
class gfArchive;
enum ARCNodeType { ARCNODE_TYPE_DUMMY = 0 };

class gfArchive {
public:
    void* getData(ARCNodeType type, int id, unsigned short index);
};

class Obj9 {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void setSlot(int n, void* p);
};

class GroundBase {
public:
    char pad0[0x3C];
};

class Ground : public GroundBase {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void method68(void* data, unsigned long a, unsigned long b);
    virtual void method6C();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void methodA0();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void method124();

    char pad40[4];
    Obj9** unk44;
    char pad48[0x14];
    short unk5C;
    char pad5E[0xE];
    unsigned char unk6C;
    unsigned char unk6D;
    char pad6E[6];
    void* unk74[9];
};

extern "C" {
    extern char* lbl_27_bss_5668;
    void fn_27_228C74(int, Ground* self);
    void fn_27_261C7C(Ground* self);

    void startup__6GroundFP9gfArchiveUlUl(Ground* self, gfArchive* arg0, unsigned long arg1, unsigned long arg2) {
        if (self->unk5C >= 0) {
            self->method6C();
            void* data = arg0->getData((ARCNodeType)2, (int)self->unk5C, 0xFFFE);
            self->method68(data, arg1, arg2);
            fn_27_228C74(*(int*)(lbl_27_bss_5668 + 0xC4), self);
        }
        self->methodA0();

        Obj9* obj = *self->unk44;
        if (obj != 0) {
            obj->setSlot(1, &self->unk74[0]);
            obj->setSlot(2, &self->unk74[1]);
            obj->setSlot(3, &self->unk74[2]);
            obj->setSlot(4, &self->unk74[3]);
            obj->setSlot(5, &self->unk74[4]);
            obj->setSlot(6, &self->unk74[5]);
            obj->setSlot(7, &self->unk74[6]);
            obj->setSlot(8, &self->unk74[7]);
            obj->setSlot(9, &self->unk74[8]);
        }

        self->unk6C &= 0xFFFFFFFD;
        self->method124();
        unsigned int flag = self->unk6D;
        self->unk6C &= 0xFFFFFFFD;
        if ((flag & 1) == 1) {
            fn_27_261C7C(self);
        }
    }
}
