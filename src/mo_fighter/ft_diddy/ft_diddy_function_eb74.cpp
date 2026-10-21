#pragma force_active on
struct Work {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int getInt(int);
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual int isFlag(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);
extern "C" void removeItem__9itManagerFP8BaseItem(void*, void*);

extern "C" void fn_115_EB74(void*, Accesser* accesser) {
    if (accesser->modules->work->isFlag(0x22000014)) {
        int id = accesser->modules->work->getInt(0x20000000);
        void* item = getItemFromInstanceId__9itManagerFi(
            getInstance__9itManagerFv(), id);
        removeItem__9itManagerFP8BaseItem(
            getInstance__9itManagerFv(), item);
    }
}
