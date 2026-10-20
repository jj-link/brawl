#include <types.h>

extern "C" void fn_27_135EDC(void*, void*, void*);

namespace {

struct KindObj {
    virtual int unk00();
    virtual int unk01();
    virtual int unk02();
    virtual int unk03();
    virtual int unk04();
    virtual int unk05();
    virtual int unk06();
    virtual int unk07();
    virtual int unk08();
    virtual int unk09();
    virtual int unk10();
    virtual int unk11();
    virtual int unk12();
    virtual int unk13();
    virtual int unk14();
    virtual int unk15();
    virtual int getKind(); // 0x48
};

struct NotifyObj {
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void notify(u32); // 0x50
};

} // namespace

#pragma force_active on
extern "C" void fn_103_95A4(void* self, void* params) {
    fn_27_135EDC(self, params, *(void**)((u8*)self + 0x60));
    if (params == nullptr) {
        return;
    }
    KindObj* kindObj = *reinterpret_cast<KindObj**>(reinterpret_cast<u8*>(*(void**)(*(u8**)((u8*)self + 0x60) + 0xd8)) + 0x70);
    if (kindObj->getKind() != 0x117) {
        return;
    }
    u8* p = (u8*)params;
    if (p[0x21] == 2 && p[0x23] == 0 && p[0x22] == 0xa && p[0x24] == 0) {
        return;
    }
    NotifyObj* notifyObj = *reinterpret_cast<NotifyObj**>(reinterpret_cast<u8*>(*(void**)(*(u8**)((u8*)self + 0x60) + 0xd8)) + 0x64);
    notifyObj->notify(0x22000011);
}
