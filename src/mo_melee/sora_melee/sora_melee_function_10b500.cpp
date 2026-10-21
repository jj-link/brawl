#pragma force_active on
typedef unsigned int u32;

class EntryCallback {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void invoke();
};

struct ftEntry {
    char padding[0x1D4];
    EntryCallback callback;
};

struct Self { char pad[0x154]; u32 id; };

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);

extern "C" void fn_27_10B500(Self* __restrict self) {
    getEntity__14ftEntryManagerFUl(self->id)->callback.invoke();
}
