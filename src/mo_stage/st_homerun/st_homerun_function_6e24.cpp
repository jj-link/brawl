#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Base {
    char pad0[0x3C];
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
    virtual void setVisible(bool);
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void setDigit(u8);
    virtual void v115();
    virtual void reset();
};

struct Object : Base {
    char pad40[0x6C - 0x40];
    u8 visible : 1;
    u8 unusedFlags : 7;
    char pad6D[0x150 - 0x6D];
    u8 step;
    char pad151[0x15C - 0x151];
    u32* value;
    u32 previous;
    u8 kind;
};

extern "C" {
extern char lbl_88_data_1D80[];
char* strcpy(char*, const char*);
char* itoa(int, char*, int);
u32 strlen(const char*);
char* strncpy(char*, const char*, u32);
int atoi(const char*);

void fn_88_6E24(Object* self) {
    char digit[8];
    char number[64];

    switch (self->step) {
    case 0:
        self->reset();
        self->setDigit(0);
        self->step = 1;
    case 1:
        self->step = 2;
    case 2:
        if (*self->value == 0) {
            self->setVisible(false);
            self->step = 8;
            break;
        }
        if (*self->value != self->previous) {
            if (!self->visible)
                self->setVisible(true);
            self->previous = *self->value;
            self->reset();
            strcpy(digit, lbl_88_data_1D80);
            itoa(*self->value, number, 10);
            u32 length = strlen(number);

            switch (self->kind) {
            case 18:
                if (length < 1)
                    self->setDigit(0);
                else {
                    strncpy(digit, &number[length - 1], 1);
                    self->setDigit((u8)atoi(digit));
                }
                break;
            case 19:
                if (length < 2)
                    self->setDigit(0);
                else {
                    strncpy(digit, &number[length - 2], 1);
                    self->setDigit((u8)atoi(digit));
                }
                break;
            case 20:
                if (length < 3)
                    self->setDigit(0);
                else {
                    strncpy(digit, &number[length - 3], 1);
                    self->setDigit((u8)atoi(digit));
                }
                break;
            case 21:
                if (length < 4)
                    self->setDigit(0);
                else {
                    strncpy(digit, &number[length - 4], 1);
                    self->setDigit((u8)atoi(digit));
                }
                break;
            }
        }
        break;
    case 8:
        if (*self->value != 0)
            self->step = 2;
        break;
    }
}
}
