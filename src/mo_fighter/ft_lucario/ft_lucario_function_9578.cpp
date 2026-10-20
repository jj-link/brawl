#pragma force_active on
extern "C" void fn_27_13604C(void*, void*, void*, void*);

namespace {
struct Handler {
    virtual void unk_0();
    virtual void unk_4();
    virtual void unk_8();
    virtual void unk_C();
    virtual void unk_10();
    virtual void unk_14();
    virtual void unk_18();
    virtual void unk_1C();
    virtual void unk_20();
    virtual void unk_24();
    virtual void unk_28();
    virtual void unk_2C();
    virtual void unk_30();
    virtual void unk_34();
    virtual void unk_38();
    virtual void unk_3C();
    virtual void unk_40();
    virtual void unk_44();
    virtual void unk_48();
    virtual void unk_4C();
    virtual void call(int, int);
};
} // namespace

extern "C" void fn_118_9578(void* self, void* a, void* b, void* c) {
    void* module = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(self) + 0x60)) + 0xD8);
    Handler* handler = *reinterpret_cast<Handler**>(reinterpret_cast<unsigned char*>(module) + 0x64);
    handler->call(1, 0x1200003F);
    fn_27_13604C(self, a, b, c);
}
