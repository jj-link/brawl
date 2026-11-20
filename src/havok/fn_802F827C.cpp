#include <types.h>
#pragma force_active on

class SoAlloc {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* alloc(u32 size);
    virtual void reset();
    virtual void f();
    u32 m_04;
    u32 m_08;
    u32 m_0C;
    u32 m_10;
    u32 m_14;
    u32 m_18;
    u32 m_1C;
    void release(u32 saved) {
        m_10 = saved;
        if (saved == m_18) reset();
    }
    u32 take(u32 size) {
        u32 top = m_10;
        u32 end = top + size;
        if (end <= m_1C) {
            m_10 = end;
            return top;
        }
        return (u32)alloc(size);
    }
};

class Writer {
public:
    virtual void a();
    virtual void b();
    virtual void write(void* sub, void* out, void* buf);
};

class Visitor {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void get(void* out);
};

extern "C" void fn_8027EABC(void* alloc, void* ptr, u32 size, s32 align);
extern SoAlloc* lbl_805A0EC8;

struct Buf {
    u32 ptr;
    u32 count;
    u32 flags;
    u32 saved;
    Buf(u32 n) {
        ptr = 0;
        count = 0;
        flags = 0x80000000;
    }
    u32 isUnowned() const { return flags & 0x80000000; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, (void*)ptr, flags << 3, 0x15); }
};

struct Ctx {
    u8 m_00[0x54];
    Writer* m_54;
    void* m_58;
    u8 m_5C[0x10];
    void* m_6C;
    u8 m_70[0x274];
    s32 m_2E4;
};

extern "C" void fn_802CAEE8(void* table, void* data, s32 count, void* test);
extern "C" void fn_8027EABC(void* alloc, void* ptr, u32 size, s32 align);
extern SoAlloc* lbl_805A0EC8;

extern "C" void fn_802F827C(Ctx* self, Visitor* obj) {
    u32 out[8] __attribute__((aligned(16)));
    u32 count = self->m_2E4;
    Buf buf __attribute__((aligned(16)))(count);
    u32 size = ((count * 8) + 0x10) & 0xFFFFFFF0;
    SoAlloc* alloc = lbl_805A0EC8;
    u32 base = alloc->take(size);
    buf.ptr = base;
    buf.flags = count | 0x80000000;
    buf.saved = base;
    obj->get(out);
    self->m_54->write((u8*)obj + 0x30, out, &buf);
    if (buf.count != 0) {
        void* test = self->m_6C;
        if (test != 0) {
            test = (u8*)test + 8;
        }
        s32 n = (s32)buf.count;
        void* data = (void*)buf.ptr;
        void* table = self->m_58;
        fn_802CAEE8(table, data, n, test);
    }
    lbl_805A0EC8->release(buf.saved);
    if (!buf.isUnowned()) {
        buf.dealloc();
    }
}