#pragma force_active on

extern "C" {
extern signed char lbl_27_bss_85A4;
extern char lbl_27_bss_8508[];
extern char lbl_27_data_3A8D8[];
extern void* __vt__10soNullable;
void fn_27_197E54(void*, int);
void* __register_global_object(void* object, void (*destructor)(void*, int), void* chain);
}

struct GlobalBase {
    void* vtbl;
};

class soNullable {
public:
    virtual unsigned int isNull();
    virtual int* slot1(int index);
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
    virtual int slot13();
};

struct Entry {
    int index;
    int value;
};

extern GlobalBase lbl_27_bss_85A8;

static inline soNullable* getGlobal() {
    if (lbl_27_bss_85A4 == 0) {
        lbl_27_bss_85A8.vtbl = &__vt__10soNullable;
        lbl_27_bss_85A8.vtbl = lbl_27_data_3A8D8;
        __register_global_object(&lbl_27_bss_85A8, fn_27_197E54, lbl_27_bss_8508);
        lbl_27_bss_85A4 = 1;
    }
    return (soNullable*)&lbl_27_bss_85A8;
}

extern "C" void fn_27_380148(char* arg0, int arg1, Entry* arg2) {
    soNullable* obj;
    Entry* entries = arg2;
    int i;

    switch (arg1) {
    case 0:
        obj = (soNullable*)arg0;
        break;
    case 1:
        obj = (soNullable*)(arg0 + 0x4B8);
        break;
    case 2:
        obj = getGlobal();
        break;
    default:
        obj = getGlobal();
        break;
    }

    if (obj->isNull() != 1 && entries != 0) {
        for (i = 0;; i++) {
            int value;
            if (i >= obj->slot13()) {
                break;
            }
            if (entries->index < 0) {
                break;
            }
            value = entries->value;
            *obj->slot1(entries->index) = value;
            entries++;
        }
    }
}
