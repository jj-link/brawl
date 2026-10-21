#pragma force_active on
extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);
extern "C" void removeItem__9itManagerFP8BaseItem(void*, void*);

struct StageBase {
    char pad[0x3c];
};

struct Stage : StageBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void setState(int);

    char pad40[0x110];
    unsigned char state;
    char pad151[0x57];
    int itemId;
};

extern "C" void fn_68_105A4(Stage* self) {
    if (self->itemId != 0) {
        void* manager = getInstance__9itManagerFv();
        if (manager != 0) {
            void* item =
                getItemFromInstanceId__9itManagerFi(manager, self->itemId);
            if (item != 0) {
                removeItem__9itManagerFP8BaseItem(manager, item);
                self->itemId = 0;
                self->setState(1);
                self->state = 12;
            }
        }
    }
}
