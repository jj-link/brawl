#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual s32 getCount();
};

struct Handler {
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
    virtual void finish(s32, s32, void*);
    virtual void v18();
    virtual void v19();
    virtual s32 start(s32, s32, void*);
    virtual void v21();
    virtual void v22();
};

struct Base {
    u8 pad[8];
};

struct Main : Base {
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual Handler* getHandler();

    u8 pad0[0x3C - 0xC];
    s32 field3C;
    Inner* inner;
    u8 pad44[0xBC - 0x44];
    u8 sub[0x101 - 0xBC];
    u8 flags;
};

extern "C" s32 fn_27_616D8(Main* self) {
    s32 count = self->inner->getCount();
    self->flags |= 0x20;
    s32 result = self->getHandler()->start(self->field3C, count, self->sub);
    self->getHandler()->finish(self->field3C, count, self->sub);
    return result;
}
