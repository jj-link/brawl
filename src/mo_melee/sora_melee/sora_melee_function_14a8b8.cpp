#pragma force_active on

class Obj {
public:
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4(int a);
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual float s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16(int a);
    virtual int s17();
    virtual int s18();
    virtual int s19();
    virtual int s20();
    virtual int s21();
    virtual int s22();
    virtual int s23();
    virtual int s24();
    virtual int s25();
    virtual int s26();
    virtual int s27();
    virtual int s28();
    virtual int s29();
    virtual int s30();
    virtual int s31();
    virtual int s32();
    virtual int s33();
    virtual int s34();
    virtual int s35();
    virtual int s36();
    virtual int s37();
    virtual int s38();
    virtual int s39(int a);
    virtual int s40(int a);
};

class IpHuman {
public:
    unsigned int isWinPoseIndicate() const;
    int getWinPose() const;
};

struct OwnerRec {
    int f0;
    void* f4;
};

class ftManager {
public:
    OwnerRec* getOwner(int id);
};

extern ftManager* g_ftManager;
extern char lbl_27_data_2BDE0[];
extern char lbl_27_data_350[];
extern float lbl_27_rodata_18B8;

extern "C" {
int fn_27_8BC8C(void);
int fn_27_1959BC(void* self);
int fn_27_195A78(void* self);
unsigned int fn_27_11139C(void);
int fn_27_111364(void);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
int randi(long);

static inline void* subOf(void* self) { return *(void**)((char*)self + 0xd8); }
static inline Obj* objAt(void* p, int off) { return *(Obj**)((char*)p + off); }

extern "C" int fn_27_14A8B8(void* a, void* self, int id) {
    if (id <= 0x5207) {
        return fn_27_8BC8C();
    }
    switch (id) {
    case 0x5209:
        return (unsigned char)objAt(subOf(self), 0x5c)->s23();
    case 0x520B:
        return (unsigned char)objAt(subOf(self), 0x5c)->s27();
    case 0x520D:
        return (unsigned char)objAt(subOf(self), 0x5c)->s29();
    case 0x520F:
        return (signed char)objAt(subOf(self), 0x5c)->s24();
    case 0x520A:
        return (unsigned char)objAt(subOf(self), 0x5c)->s25();
    case 0x520C:
        return (unsigned char)objAt(subOf(self), 0x5c)->s28();
    case 0x520E:
        return (unsigned char)objAt(subOf(self), 0x5c)->s31();
    case 0x5210:
        return (signed char)objAt(subOf(self), 0x5c)->s26();
    case 0x5208:
        return objAt(subOf(self), 0x8c)->s5();
    case 0x5211:
        return (unsigned char)objAt(subOf(self), 0x5c)->s39(0);
    case 0x5212:
        return (unsigned char)objAt(subOf(self), 0x5c)->s40(0);
    case 0x5213:
        return (unsigned char)objAt(subOf(self), 0x5c)->s39(1);
    case 0x5214:
        return (unsigned char)objAt(subOf(self), 0x5c)->s40(1);
    case 0x5215:
        return (unsigned char)objAt(subOf(self), 0x5c)->s39(2);
    case 0x5216:
        return (unsigned char)objAt(subOf(self), 0x5c)->s40(2);
    case 0x5217:
        return (unsigned char)objAt(subOf(self), 0x5c)->s39(3);
    case 0x5218:
        return (unsigned char)objAt(subOf(self), 0x5c)->s40(3);
    case 0x5219:
        return (unsigned char)objAt(subOf(self), 0x5c)->s39(4);
    case 0x521A:
        return (unsigned char)objAt(subOf(self), 0x5c)->s40(4);
    case 0x521E:
        switch (objAt(subOf(self), 0xa8)->s16(0)) {
        case 0x4:  return 0x121;
        case 0x21: return 0x128;
        case 0x3a: return 0x133;
        case 0x2e: return 0x13a;
        case 0x1f: return 0x12c;
        default:   return 0x121;
        }
    case 0x521F:
        switch (objAt(subOf(self), 0xa8)->s16(0)) {
        case 0x4:  return 0x122;
        case 0x21: return 0x129;
        case 0x3a: return 0x134;
        case 0x2e: return 0x13b;
        case 0x1f: return 0x12d;
        default:   return 0x122;
        }
    case 0x5220:
        switch (objAt(subOf(self), 0xa8)->s16(0)) {
        case 0x4:  return 0x124;
        case 0x21: return 0x12a;
        case 0x3a: return 0x136;
        case 0x2e: return 0x13d;
        case 0x1f: return 0x12f;
        default:   return 0x124;
        }
    case 0x5221:
        switch (objAt(subOf(self), 0xa8)->s16(0)) {
        case 0x4:  return 0x127;
        case 0x21: return 0x12b;
        case 0x3a: return 0x139;
        case 0x2e: return 0x140;
        case 0x1f: return 0x132;
        default:   return 0x127;
        }
    case 0x521B: {
        Obj* c = objAt(subOf(self), 0x0c);
        if (lbl_27_rodata_18B8 == c->s9()) {
            int r = (signed char)objAt(subOf(self), 0x5c)->s24();
            if (r > 0) {
                return (unsigned char)objAt(subOf(self), 0x5c)->s23();
            }
            goto fallback_521b;
        }
        int r = (signed char)objAt(subOf(self), 0x5c)->s24();
        if (r < 0) {
            return (unsigned char)objAt(subOf(self), 0x5c)->s23();
        }
    fallback_521b:
        return 0xfe;
    }
    case 0x521C: {
        Obj* c = objAt(subOf(self), 0x0c);
        if (lbl_27_rodata_18B8 == c->s9()) {
            int r = (signed char)objAt(subOf(self), 0x5c)->s24();
            if (r < 0) {
                return (unsigned char)objAt(subOf(self), 0x5c)->s23();
            }
            goto fallback_521c;
        }
        int r = (signed char)objAt(subOf(self), 0x5c)->s24();
        if (r > 0) {
            return (unsigned char)objAt(subOf(self), 0x5c)->s23();
        }
    fallback_521c:
        return 0xfe;
    }
    case 0x521D: {
        Obj* c = objAt(subOf(self), 0x0c);
        if (lbl_27_rodata_18B8 == c->s9()) {
            int r = (signed char)objAt(subOf(self), 0x5c)->s30();
            if (r < 0) {
                return (unsigned char)objAt(subOf(self), 0x5c)->s29();
            }
            goto fallback_521d;
        }
        int r = (signed char)objAt(subOf(self), 0x5c)->s30();
        if (r > 0) {
            return (unsigned char)objAt(subOf(self), 0x5c)->s29();
        }
    fallback_521d:
        return 0xfe;
    }
    case 0x5222:
        return fn_27_1959BC(self);
    case 0x5223:
        return fn_27_195A78(self);
    case 0x5224: {
        int r = objAt(subOf(self), 0x64)->s4(0x10000000);
        IpHuman* h = (IpHuman*)__dynamic_cast(g_ftManager->getOwner(r)->f4, 4, lbl_27_data_2BDE0, lbl_27_data_350, 1);
        if (h->isWinPoseIndicate() == 1U) {
            return h->getWinPose() - 1;
        }
        return randi(3);
    }
    case 0x5225: {
        int r = objAt(subOf(self), 0x64)->s4(0x10000000);
        g_ftManager->getOwner(r);
        if (fn_27_11139C() == 1U) {
            return 4;
        }
        g_ftManager->getOwner(r);
        return fn_27_111364();
    }
    default:
        return 0;
    }
}
