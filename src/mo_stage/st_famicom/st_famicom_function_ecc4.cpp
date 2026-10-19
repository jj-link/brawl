#pragma force_active on
struct StageHeader {
    unsigned char pad0[0x3C];
};

struct StageDispatch : StageHeader {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void setState(int);
};

struct Stage : StageDispatch {
    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[0x17];
    float timer;
    unsigned char pad16C[0x3C];
    int itemId;
};

extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);
extern "C" void removeItem__9itManagerFP8BaseItem(void*, void*);
extern "C" const float lbl_68_rodata_148[];

extern "C" void fn_68_ECC4(Stage* self) {
    if (self->itemId != 0) {
        void* manager = getInstance__9itManagerFv();
        if (manager != 0) {
            void* item = getItemFromInstanceId__9itManagerFi(manager, self->itemId);
            if (item != 0) {
                removeItem__9itManagerFP8BaseItem(manager, item);
                self->itemId = 0;
                self->setState(1);
                self->state = 12;
                self->timer = lbl_68_rodata_148[0];
            }
        }
    }
}
