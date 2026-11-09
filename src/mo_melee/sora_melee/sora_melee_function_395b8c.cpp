#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" s32 fn_27_30FACC(void*, u32, s32, void*, u32);

class VObj70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32, void*);
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
    virtual s32 v16();
};

class VObj64 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(u32, void*);
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
    virtual s32 v17(u32);
    virtual void v18(u32);
    virtual void v19(u32, void*);
};

class VObj54 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(u32, void*, void*);
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
    virtual void v15(u32, void*);
};

struct PlayerTaskBase {
    char pad[0x3c];
};

class PlayerTask : public PlayerTaskBase {
public:
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
    virtual void v39();
    virtual s32 v40();
};

struct SpillBlock {
    s32 word;
    u8 byte;
};

extern "C" s32 fn_27_395B8C(void* a, void* self) {
    char* s = (char*)self;
    VObj70* o70 = *(VObj70**)(*(char**)(s + 0xd8) + 0x70);
    s32 r = o70->v16();
    s32 status = fn_27_30FACC(lbl_27_bss_7B0C, 0, r, self, 1);

    if (status == 0x112 || status == 0x117) {
        VObj64* o64 = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
        if (o64->v17(0x22000019) != 0) {
            VObj64* a64 = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
            void* p = a64->v4(0x20000006, *(void**)(s + 0xd8));
            VObj54* b = *(VObj54**)(*(char**)(s + 0xd8) + 0x54);
            b->v4(6, p, *(void**)(s + 0xd8));

            SpillBlock loc;
            loc.word = 0x835;
            loc.byte = 0;
            VObj54* c = *(VObj54**)(*(char**)(s + 0xd8) + 0x54);
            c->v15(6, &loc);

            VObj64* d = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
            d->v18(0x2200001A);

            PlayerTask* pt = *(PlayerTask**)(s + 0x8);
            if (pt->v40() == 5) {
                VObj70* e = *(VObj70**)(*(char**)(s + 0xd8) + 0x70);
                e->v3(0x1A3, self);
            } else {
                VObj70* f = *(VObj70**)(*(char**)(s + 0xd8) + 0x70);
                f->v3(0x127, self);
            }

            VObj64* g = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
            g->v19(0x22000019, *(void**)(s + 0xd8));
            return 1;
        }
    }
    return 0;
}
