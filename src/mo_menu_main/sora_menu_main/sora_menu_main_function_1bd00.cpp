#pragma force_active on

extern "C" void fn_18_1C4C(void*, int);
extern char lbl_2_data_2680[];
extern const unsigned char lbl_2_rodata_6B8[];
extern const unsigned short lbl_2_rodata_6BC[];

struct Node {
    char pad[0x10];
    void* value;
};

struct Loader {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void attach(void*, void*);
    char pad[0xE0];
    void* context;
};

struct Class_728_base {
    char pad[0x3C];
};

class Class_728 : public Class_728_base {
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
    virtual void fn_2_36914();
    virtual void fn_2_36908();
    virtual void fn_2_361C4(int, int);
};

struct Menu {
    char pad0[0x42];
    unsigned short sel;
    char pad44[0x638 - 0x44];
    int state;
    const void* config;
    int field640;
    int count;
    int field648;
    void* list;
    int field650;
    Loader* loader;
    Class_728* view;
    int field65C;
    int field660;
    int mode;
};

extern "C" void fn_2_1BD00(Menu* self, Loader* loader, unsigned int mode) {
    unsigned int off;
    unsigned int i;
    unsigned short idx;

    self->loader = loader;
    self->config = lbl_2_data_2680;
    self->count = 0x6C;
    i = 0;
    off = 0;

    do {
        loader->attach(
            loader->context,
            (*reinterpret_cast<Node**>(
                reinterpret_cast<char*>(self->list) + 0x1B0 + off))->value);
        i++;
        off += 4;
    } while (i < 3);

    if (mode == 6) {
        self->mode = 0;
    } else {
        self->mode = 1;
    }

    if (mode == 6) {
        idx = 0;
    } else {
        for (idx = 0; idx < 3; idx++) {
            if (mode == lbl_2_rodata_6B8[idx]) {
                break;
            }
        }
    }

    self->sel = idx;
    Class_728* view = self->view;
    view->fn_2_361C4(0x1C, lbl_2_rodata_6BC[idx]);
    fn_18_1C4C(self, 1);
}
