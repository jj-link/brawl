#pragma force_active on

extern "C" {

extern unsigned char lbl_80461718[];

struct SwObj {
    int type;
    int pad4;
    void** vt;
    int unkC;
    int unk10;
};

struct SwInst {
    char pad[0x18];
    int unk18;
};

struct Class_80454F64_base { char pad[0x8]; };
class Class_80454F64 : public Class_80454F64_base {
public:
    virtual void fn_800A6A94(int);
};

struct Class_80461670_base { char pad[0x8]; };
class Class_80461670 : public Class_80461670_base {
public:
    virtual void fn_80152F34();
};

struct Class_80461684_base { char pad[0x8]; };
class Class_80461684 : public Class_80461684_base {
public:
    virtual void fn_80152DC8();
};

struct Class_80461698_base { char pad[0x8]; };
class Class_80461698 : public Class_80461698_base {
public:
    virtual void fn_80152BDC();
};

struct Class_804616AC_base { char pad[0x8]; };
class Class_804616AC : public Class_804616AC_base {
public:
    virtual void fn_801529F0();
};

struct Class_80466494_base { char pad[0x8]; };
class Class_80466494 : public Class_80466494_base {
public:
    virtual void fn_801B48D8();
};

struct Class_80466B80_base { char pad[0x8]; };
class Class_80466B80 : public Class_80466B80_base {
public:
    virtual void fn_801C8A68();
};

struct Class_80466D44_base { char pad[0x8]; };
class Class_80466D44 : public Class_80466D44_base {
public:
    virtual void fn_801D03F8();
};

struct Class_80488350_base { char pad[0x8]; };
class Class_80488350 : public Class_80488350_base {
public:
    virtual void fn_802EB3A0();
};

unsigned char fn_801541DC(void*);
void* fn_801541F0(void*, int);
void fn_80153488(void*);
void fn_80153498(void*, int);
int fn_80153504(void*, int);
SwObj* fn_80153818(void*, int);
void* getInstance__8ipSwitchFv(void);
int fn_8004B278(int, void*, int);
void netReport__FPCce(const char*, ...);

int fn_80156164(void* self, void* arg1) {
    char buf[0x10];
    char* base = (char*)lbl_80461718;
    int q;
    SwObj* obj;
    unsigned int ok;
    int v;
    int a;
    int t;

    t = fn_801541DC(arg1);
    if ((unsigned char)t != 1) {
        netReport__FPCce((const char*)(base + 0x484), t);
        return 0;
    }

    fn_80153488(buf);
    v = (int)fn_801541F0(arg1, 0);
    if (fn_80153504(buf, v) == 0) {
        netReport__FPCce((const char*)(base + 0x4C8));
        fn_80153498(buf, -1);
        return 0;
    }

    obj = fn_80153818(buf, *(int*)((char*)self + 0x354));
    if (obj == 0) {
        netReport__FPCce((const char*)(base + 0x500));
        fn_80153498(buf, -1);
        return 0;
    }

    ok = 0;
    t = obj->type;
    if (t != 2) {
        netReport__FPCce((const char*)(base + 0x514), t);
    } else {
        q = obj->unkC + 0x34;
        a = obj->unk10;
        {
            SwInst* inst = (SwInst*)getInstance__8ipSwitchFv();
            if (fn_8004B278(inst->unk18, (void*)q, a) != 0) {
                ok = 1;
            } else {
                netReport__FPCce((const char*)(base + 0x544));
            }
        }

        if (ok == 1) {
            char* s = (char*)self;
            char* p = (char*)q + 0x18;
            unsigned char i;
            s[0x35C] = ((unsigned char)p[0x8] >> 2) & 0x3F;
            s[0x35D] = ((unsigned char)p[0x9] >> 2) & 7;
            *(unsigned short*)&s[0x35E] = *(unsigned short*)&p[0x1A];
            s[0x386] = p[0x13];

            for (i = 0; i < 7; i++) {
                s[0x360 + i] = p[0x98 + i * 0x5C];
                s[0x367 + i] = p[0x9E + i * 0x5C];
                s[0x36E + i] = p[0xA3 + i * 0x5C];
                s[0x375 + i] = p[0x99 + i * 0x5C];
                s[0x37C + i] = p[0x9A + i * 0x5C];
            }

            *(unsigned short*)&s[0x384] = 0;
        }
    }

    if (obj != 0) {
        ((Class_80454F64*)obj)->fn_800A6A94(1);
    }

    fn_80153498(buf, -1);
    return ok;
}

}
