#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_131CD0(void*, int, int, void*);

struct CallbackInterface {
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
    virtual void callback(int, int);
};

extern "C" void fn_118_94F8(void* self, int enabled, int arg3, void* arg4) {
    if (enabled != 0) {
        u8* storage = static_cast<u8*>(self);
        void* object = *reinterpret_cast<void**>(storage + 0x60);
        object = *reinterpret_cast<void**>(static_cast<u8*>(object) + 0xD8);
        object = *reinterpret_cast<void**>(static_cast<u8*>(object) + 0x64);
        reinterpret_cast<CallbackInterface*>(object)->callback(1, 0x1200003F);
    }
    fn_27_131CD0(self, enabled, arg3, arg4);
}
