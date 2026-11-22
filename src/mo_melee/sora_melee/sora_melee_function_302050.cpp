// Module-aggregate constructor for sora_melee.
#pragma force_active on

typedef unsigned char Byte;
typedef unsigned int Word;

class Array0 {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void append(void*);
};

class EventManager {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual Word getManageId();
};

class Resource {
public:
    virtual void slot08();
};

union Flags {
    unsigned int raw;
    struct {
        unsigned int rest : 4;
        unsigned int value : 2;
        unsigned int flag : 1;
        unsigned int rest2 : 25;
    } bits;
};

extern "C" {
extern Byte lbl_27_data_1D4E8[];
extern Byte lbl_27_data_1A3D8[];
extern Byte lbl_27_data_8E80[];
extern Byte lbl_27_data_20248[];
extern Byte lbl_27_data_2490[];
extern Byte lbl_27_data_11740[];
extern Byte lbl_27_data_12380[];
extern Byte lbl_27_bss_DBC[];
extern Byte lbl_27_bss_9BC[];
extern Byte lbl_27_bss_7690[];
extern Byte lbl_27_bss_7684[];
extern Byte lbl_27_bss_520C[];
extern Byte lbl_27_bss_5204[];
extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_5200;

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void fn_27_137B4(void*);
void fn_27_137EC(void*, short);
void fn_27_82794(void*, short);
void fn_27_82A14(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void*, void*);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
}

static inline Byte* pointer(void* p, int offset) { return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset); }

static inline Byte* part(Byte* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

static inline short eventId(Byte* modules) {
    Byte* events = pointer(modules, 0x80) + 8;
    return static_cast<short>(reinterpret_cast<EventManager*>(events)->getManageId());
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        *(void**)lbl_27_bss_520C = 0;
        *(void**)lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(lbl_27_bss_520C, reinterpret_cast<void*>(fn_27_82794), lbl_27_bss_7690);
        lbl_27_bss_5208 = 1;
    }
    return lbl_27_bss_520C;
}

extern "C" Byte* fn_27_302050(Byte* self, Byte* accesser, int count) {
    *(void**)(self + 0x00) = lbl_27_data_1D4E8;
    *(void**)(self + 0x04) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(self + 0x08) &= 0x01FFFFFF;
    __construct_array(self + 0x0C, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);

    *(void**)(self + 0x20) = lbl_27_data_1A3D8;
    *(void**)(self + 0x24) = lbl_27_data_1A3D8 + 0x48;
    *(unsigned int*)(self + 0x28) &= 0x0007FFFF;
    __construct_array(self + 0x2C, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 4);

    *(void**)(self + 0x6C) = lbl_27_data_8E80;
    *(void**)(self + 0x70) = self;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = -1;
    *(int*)(self + 0x7C) = -1;
    *(int*)(self + 0x80) = 0;

    Word motionEntry[5];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(motionEntry, i == 0 ? self + 0x20 : 0);
        reinterpret_cast<Array0*>(self)->append(motionEntry);
        fn_27_AB18C(motionEntry, -1);
    }

    *(void**)(self + 0x88) = lbl_27_data_20248;
    *(void**)(self + 0x8C) = lbl_27_data_20248 + 0x48;
    Flags f;
    f.raw = *(unsigned int*)(self + 0x90);
    f.raw &= 0x0FFFFFFF;
    f.bits.value = 1;
    f.bits.flag = 0;
    *(unsigned int*)(self + 0x90) = f.raw;
    __construct_array(self + 0x94, (void (*)(void*))fn_27_137B4, (void (*)(void*))fn_27_137EC, 0x2C, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(self + 0x8C, 1, 1);

    *(int*)(self + 0xC8) = 0;
    *(void**)(self + 0xC4) = lbl_27_data_2490;
    *(int*)(self + 0xCC) = count;
    *(int*)(self + 0xD0) = 0x14;
    if (count == 0) {
        *(int*)(self + 0xD0) = 0;
    }

    void* globalA = global1();
    if (lbl_27_bss_5200 == 0) {
        *(void**)lbl_27_bss_5204 = 0;
        *(void**)lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(lbl_27_bss_5204, reinterpret_cast<void*>(fn_27_82A14), lbl_27_bss_7684);
        lbl_27_bss_5200 = 1;
    }
    Byte* modules = pointer(accesser, 0xD8);
    Byte* calcArray = part(self, 0x88);
    Byte* transition = part(self, 0x6C);
    short id = eventId(modules);
    Byte* dbc = lbl_27_bss_DBC;

    fn_27_13844(self + 0xD8, accesser, self + 0xC4, transition,
        globalA, calcArray, lbl_27_bss_9BC, lbl_27_bss_5204,
        id, 0, dbc);
    reinterpret_cast<Resource*>(pointer(pointer(accesser, 0xD8), 4))->slot08();
    return self;
}
