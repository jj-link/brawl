#include <ft/fighter.h>
#include <so/so_external_value_accesser.h>

#pragma force_active on

extern "C" {
extern float lbl_105_rodata_44;
extern float lbl_105_rodata_48;
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];

void fn_105_BD50(void*, int, float, float, unsigned char, unsigned char, int, unsigned char);
void fn_105_13CC4(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct BD50Data {
    int value;
    float first;
    float second;
    unsigned char flags[4];
};

struct V64 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual unsigned long query(unsigned long);
    virtual void v18();
    virtual void set(unsigned long);
};

struct V08 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual float getFloat();
    virtual void v13(); virtual void v14(); virtual void v15();
    virtual bool isActive();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual int statusKind();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void apply(BD50Data*);
};

struct V54 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual unsigned long query(unsigned long);
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
    virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85();
    virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
    virtual void v98();
    virtual void set(unsigned long, bool, bool);
};

struct V10Header {
    int word0;
    int word1;
};

struct V10 : V10Header {
#define DECL_V10(n) virtual void a##n();
    DECL_V10(0) DECL_V10(1) DECL_V10(2) DECL_V10(3) DECL_V10(4)
    DECL_V10(5) DECL_V10(6) DECL_V10(7) DECL_V10(8) DECL_V10(9)
    DECL_V10(10) DECL_V10(11) DECL_V10(12) DECL_V10(13) DECL_V10(14)
    DECL_V10(15) DECL_V10(16) DECL_V10(17) DECL_V10(18) DECL_V10(19)
    DECL_V10(20) DECL_V10(21) DECL_V10(22) DECL_V10(23) DECL_V10(24)
    DECL_V10(25) DECL_V10(26) DECL_V10(27) DECL_V10(28) DECL_V10(29)
    DECL_V10(30) DECL_V10(31) DECL_V10(32) DECL_V10(33) DECL_V10(34)
    DECL_V10(35) DECL_V10(36) DECL_V10(37) DECL_V10(38) DECL_V10(39)
    DECL_V10(40) DECL_V10(41) DECL_V10(42) DECL_V10(43) DECL_V10(44)
    DECL_V10(45) DECL_V10(46) DECL_V10(47) DECL_V10(48) DECL_V10(49)
    DECL_V10(50) DECL_V10(51) DECL_V10(52) DECL_V10(53) DECL_V10(54)
    DECL_V10(55) DECL_V10(56) DECL_V10(57) DECL_V10(58) DECL_V10(59)
    DECL_V10(60) DECL_V10(61) DECL_V10(62) DECL_V10(63) DECL_V10(64)
    DECL_V10(65) DECL_V10(66) DECL_V10(67) DECL_V10(68) DECL_V10(69)
    DECL_V10(70) DECL_V10(71) DECL_V10(72) DECL_V10(73) DECL_V10(74)
    DECL_V10(75) DECL_V10(76) DECL_V10(77) DECL_V10(78) DECL_V10(79)
    DECL_V10(80) DECL_V10(81) DECL_V10(82) DECL_V10(83) DECL_V10(84)
    DECL_V10(85) DECL_V10(86) DECL_V10(87) DECL_V10(88) DECL_V10(89)
    DECL_V10(90) DECL_V10(91) DECL_V10(92) DECL_V10(93) DECL_V10(94)
    DECL_V10(95) DECL_V10(96) DECL_V10(97) DECL_V10(98) DECL_V10(99)
    DECL_V10(100) DECL_V10(101) DECL_V10(102) DECL_V10(103) DECL_V10(104)
    DECL_V10(105) DECL_V10(106) DECL_V10(107) DECL_V10(108) DECL_V10(109)
    DECL_V10(110) DECL_V10(111)
#undef DECL_V10
    virtual bool get(int);
};

struct V14 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5();
    virtual void set(int, bool);
};

struct V70 {
    virtual void a0(); virtual void a1(); virtual void a2();
    virtual void set(int, void*);
};

struct Modules {
    char pad0[8];
    V08* mod08;
    char pad1[4];
    V10* mod10;
    V14* mod14;
    char pad2[0x3C];
    V54* mod54;
    char pad3[0xC];
    V64* mod64;
    char pad4[8];
    V70* mod70;
};

struct Object {
    char pad0[8];
    void* task;
    char pad1[0xCC];
    Modules* modules;
};

extern "C" void fn_105_13870(void*, Object* self) {
    bool zero = false;

    if (self->modules->mod64->query(0x22000010UL) == 1UL) {
        self->modules->mod64->set(0x22000010UL);

        float frame = lbl_105_rodata_44;
        int flag = 0;

        if (self->modules->mod08->statusKind() == 0x1D7) {
            frame = self->modules->mod08->getFloat();
            flag = 1;
        }

        BD50Data data;
        fn_105_BD50(&data, 0x1D6, frame, lbl_105_rodata_48, 0, 0, flag, 0);
        self->modules->mod08->apply(&data);
    } else {
        if (self->modules->mod64->query(0x22000011UL) == 1UL) {
            self->modules->mod64->set(0x22000011UL);

            float frame = lbl_105_rodata_44;
            int flag = 0;

            if (self->modules->mod08->statusKind() == 0x1D6) {
                frame = self->modules->mod08->getFloat();
                flag = 1;
            }

            BD50Data data;
            fn_105_BD50(&data, 0x1D7, frame, lbl_105_rodata_48, 0, 0, flag, 0);
            self->modules->mod08->apply(&data);
        }
    }

    if (self->modules->mod08->isActive() == 1) {
        V54* mod54 = self->modules->mod54;
        if (mod54->query(6) == 1UL) {
            self->modules->mod54->set(6, zero, zero);
        }

        fn_105_13CC4(self);

        Fighter* fighter = (Fighter*)__dynamic_cast(
            self->task, 0x3C, lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter != 0) {
            Fighter* partner = fighter->getPartner();
            if (partner != 0) {
                if (soExternalValueAccesser::getSituationKind(partner) == 0 &&
                    self->modules->mod10->get(0) == 1) {
                    self->modules->mod14->set(zero, zero);
                    self->modules->mod70->set(0, self);
                } else {
                    self->modules->mod14->set(2, zero);
                    self->modules->mod70->set(0x10, self);
                }
            }
        }
    }
}
