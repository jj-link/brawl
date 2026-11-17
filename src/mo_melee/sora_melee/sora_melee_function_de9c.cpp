#include <types.h>
#pragma force_active on

struct Pad8 {
    u32 first;
    u32 second;
};

class soModelModuleImpl : public Pad8 {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual u32 slot73();
    void switchEnvMap(bool arg0);
    void* resource;
    char pad10[0xB5];
    struct FlagByte { u8 isEnvMap : 1; u8 reserved : 7; } flags;
    char padC6[2];
    void* unkC8;
};

class EnvObject {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60(s32, void*);
};

extern "C" u32 fn_8018F394(void*);
extern "C" void* fn_8018ECCC(void*, const char*);
extern "C" const char* lbl_27_data_4B8[];

void soModelModuleImpl::switchEnvMap(bool arg0) {
    if (slot73() == 1U && flags.isEnvMap != arg0) {
        void* c = resource;
        s32 sp8 = *(s32*)((char*)c + 0xE8);
        const char** np;
        u32 half = fn_8018F394(&sp8) >> 1;
        if (flags.isEnvMap == 1U) {
            np = lbl_27_data_4B8;
            for (u32 i = 0; i < 2U; i++, np++) {
                u8* p = (u8*)fn_8018ECCC(&sp8, *np);
                if (p != 0) {
                    while (p[0] != 1) {
                        u16 raw = (u16)p[2] | ((u16)p[1] << 8);
                        u32 v = raw;
                        v = v - half;
                        p[1] = (u8)(v >> 8);
                        p[2] = (u8)v;
                        p += 8;
                    }
                }
            }
            flags.isEnvMap = 0;
            char* c8 = (char*)unkC8;
            char* d8 = *(char**)(c8 + 0xD8);
            EnvObject* obj = *(EnvObject**)(d8 + 0x54);
            void* a5 = *(void**)(*(char**)(c8 + 0x8) + 0x28);
            obj->slot60(0, a5);
            return;
        }
        u32 j = 0;
        const char** np2 = lbl_27_data_4B8;
        for (; j < 2U; j++, np2++) {
            u8* p = (u8*)fn_8018ECCC(&sp8, *np2);
            if (p != 0) {
                while (p[0] != 1) {
                    u16 raw = (u16)p[2] | ((u16)p[1] << 8);
                    u32 v = raw;
                    v = v + half;
                    p[1] = (u8)(v >> 8);
                    p[2] = (u8)v;
                    p += 8;
                }
            }
        }
        flags.isEnvMap = 1;
        char* c8 = (char*)unkC8;
        char* d8 = *(char**)(c8 + 0xD8);
        EnvObject* obj = *(EnvObject**)(d8 + 0x54);
        void* a5 = *(void**)(*(char**)(c8 + 0x8) + 0x28);
        obj->slot60(1, a5);
    }
}