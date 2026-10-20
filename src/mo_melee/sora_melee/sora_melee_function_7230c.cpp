#pragma force_active on
extern "C" const float lbl_27_rodata_9B8[];

struct EntryData {
    char padding[0x24];
    float value;
};

struct Entry {
    EntryData* data;
};

class Manager {
public:
    virtual void unused00();
    virtual void unused01();
    virtual void unused02();
    virtual void unused03();
    virtual void unused04();
    virtual void unused05();
    virtual void unused06();
    virtual void unused07();
    virtual void unused08();
    virtual void unused09();
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
    virtual Entry* getEntry(int);
    virtual void unused21();
    virtual int getIndex();
};

struct Object {
    char padding[0x20];
    Manager* manager;
};

extern "C" float fn_27_7230C(Object* self) {
    int index = self->manager->getIndex();
    Entry* entry = index < 0 ? 0 : self->manager->getEntry(index);
    if (!entry) {
        return lbl_27_rodata_9B8[0];
    }
    return entry->data->value;
}
