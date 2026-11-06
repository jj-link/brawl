#pragma force_active on
#include <gf/gf_file_io_handle.h>
#include <nw4r/g3d/g3d_resfile.h>

extern "C" int fn_800B61C0(void*);

class Object_vptr_0 {
public:
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
    virtual void slot13(void* p);
};

struct IOPair {
    gfFileIOHandle handle;
    void* buffer;
};

struct Entry {
    int type;
    char pad[0xC];
};

struct Self {
    char pad0[0x40];
    void* p40;
    char pad44[0x10];
    void* p54;
    Object_vptr_0* obj58;
    char pad5C[0x10C - 0x5C];
    int f10C;
    char pad110[0x11C - 0x110];
    Entry entries[16];
    int count21C;
    int index220;
    char pad224[0x22C - 0x224];
    IOPair single22C;
    IOPair arr234[17];
    IOPair single2BC;
    IOPair arr2C4[16];
    IOPair single344;
    IOPair arr34C[4];
};

extern "C" int fn_800C1890(Self* self) {
    IOPair* p;
    int r0;

    if (fn_800B61C0(self->p40) != 0) {
        self->obj58->slot13(self->p54);
        int idx = self->index220 + 1;
        self->index220 = idx;
        if (idx < self->count21C) {
            switch (self->entries[idx].type) {
            case 0:
                p = &self->arr234[idx];
                if (self->single22C.buffer == 0) {
                    if (!self->single22C.handle.isReady()) {
                        r0 = 0;
                        goto done;
                    }
                    self->single22C.buffer = self->single22C.handle.getBuffer();
                    self->single22C.handle.release();
                }
                if (p->buffer == 0) {
                    if (!p->handle.isReady()) {
                        r0 = 0;
                        goto done;
                    }
                    p->buffer = p->handle.getBuffer();
                    nw4r::g3d::ResFile::Init(&p->buffer);
                    p->handle.release();
                }
                r0 = 1;
                break;
            case 1:
                p = &self->arr2C4[idx];
                if (self->single2BC.buffer == 0) {
                    if (!self->single2BC.handle.isReady()) {
                        r0 = 0;
                        goto done;
                    }
                    self->single2BC.buffer = self->single2BC.handle.getBuffer();
                    self->single2BC.handle.release();
                }
                if (p->buffer == 0) {
                    if (!p->handle.isReady()) {
                        r0 = 0;
                        goto done;
                    }
                    p->buffer = p->handle.getBuffer();
                    nw4r::g3d::ResFile::Init(&p->buffer);
                    p->handle.release();
                }
                r0 = 1;
                break;
            case 2:
                if (self->single344.buffer == 0) {
                    if (!self->single344.handle.isReady()) {
                        r0 = 0;
                        goto done;
                    }
                    self->single344.buffer = self->single344.handle.getBuffer();
                    self->single344.handle.release();
                }
                r0 = 1;
                break;
            case 3:
                p = &self->arr34C[idx];
                if (p->buffer == 0) {
                    if (!p->handle.isReady()) {
                        r0 = 0;
                        goto done;
                    }
                    p->buffer = p->handle.getBuffer();
                    nw4r::g3d::ResFile::Init(&p->buffer);
                    p->handle.release();
                }
                r0 = 1;
                break;
            default:
                r0 = 1;
                break;
            }
done:
            int ret = 1;
            if (r0 != 0) {
                ret = 2;
            }
            return ret;
        } else {
            return 5;
        }
    } else {
        return self->f10C;
    }
}
