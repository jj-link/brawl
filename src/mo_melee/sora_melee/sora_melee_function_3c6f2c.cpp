#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" s32 fn_27_30FACC(void*, u32, s32, void*, u32);
extern "C" s32 fn_27_1922CC(void*, u32);
extern f32 lbl_27_rodata_8084;

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
    virtual void v4();
    virtual void v5(s32, u32, void*);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(s32, u32);
    virtual void v11();
    virtual void v12(u32, void*);
    virtual void v13(u32, void*, f32);
};

class VObjC {
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
};

class VObj1c {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" s32 fn_27_3C6F2C(void* arg0) {
    char* s = (char*)arg0;
    VObj70* obj70 = *(VObj70**)(*(char**)(s + 0xd8) + 0x70);
    s32 status = fn_27_30FACC(
        lbl_27_bss_7B0C, 0, obj70->v16(), arg0, 1);

    VObj64* obj64 = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
    obj64->v5(0, 0x20000003, *(void**)(s + 0xd8));

    switch (status) {
    case 0x119:
    case 0x11a:
    case 0x11b: {
        VObj64* o64 = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
        s32 val = fn_27_1922CC(arg0, 0x5dc1);
        o64->v10(val, 0x20000000);

        VObj64* o64b = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
        VObjC* objC = *(VObjC**)(*(char**)(s + 0xd8) + 0xc);
        o64b->v12(0x2100000a, *(void**)(s + 0xd8));
        objC->v10();

        VObjC* objC2 = *(VObjC**)(*(char**)(s + 0xd8) + 0xc);
        objC2->v19();

        ((PlayerTask*)(*(char**)(s + 0x8)))->v43();

        VObj1c* obj1c = *(VObj1c**)(*(char**)(s + 0xd8) + 0x1c);
        obj1c->v4();

        s32 ret = ((PlayerTask*)(*(char**)(s + 0x8)))->v40();
        if (ret == 5) {
            VObj70* o70a = *(VObj70**)(*(char**)(s + 0xd8) + 0x70);
            o70a->v3(0x18b, arg0);
        } else {
            VObj70* o70b = *(VObj70**)(*(char**)(s + 0xd8) + 0x70);
            o70b->v3(0x11d, arg0);
        }

        f32 f = lbl_27_rodata_8084;
        VObj64* o64c = *(VObj64**)(*(char**)(s + 0xd8) + 0x64);
        o64c->v13(0x21000009, *(void**)(s + 0xd8), f);
        return 1;
    }
    default:
        return 0;
    }
}
