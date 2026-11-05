#pragma force_active on

struct Node {
    char pad[0x10];
    void* value;
};

struct NodeList {
    char pad[0x58];
    Node* nodes[7];
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

struct Class_728_base { char pad[0x3c]; };
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
    unsigned short selection;
    char pad44[0x638 - 0x44];
    int state;
    const void* config;
    int field640;
    int count;
    int field648;
    NodeList* list;
    int field650;
    Loader* loader;
    Class_728* view;
    int field65C;
    int field660;
    int mode;
};

extern "C" {
extern const char lbl_2_data_1AC0[];
extern int lbl_2_data_1B30[];

void fn_18_1C4C(Menu*, int);
int fn_18_1A9C(Menu*);
void fn_18_1D48(Menu*, int, int);

void fn_2_13980(Menu* self, Loader* loader, short arg) {
    int sel = arg;
    unsigned off;
    unsigned cnt;

    self->loader = loader;
    self->config = lbl_2_data_1AC0;
    self->count = 0x16;
    cnt = 0;
    off = 0;

    do {
        loader->attach(
            loader->context,
            (*reinterpret_cast<Node**>(
                reinterpret_cast<char*>(self->list) + 0x58 + off))->value);
        ++cnt;
        off += 4;
    } while (cnt < 7);

    switch (sel) {
    case 0:
        self->mode = 0;
        self->selection = 0;
        self->state = 0;
        fn_18_1C4C(self, 1);
        break;

    case 23:
        self->mode = 1;
        self->selection = 0;
        self->state = 23;
        fn_18_1C4C(self, 1);
        break;

    default:
        self->mode = 2;
        switch (fn_18_1A9C(self)) {
        case 13:
            sel = 1;
            break;
        case 14:
            sel = 4;
            break;
        case 20:
            sel = 3;
            break;
        case 21:
            sel = 2;
            break;
        case 38:
            sel = 5;
            break;
        case 39:
            sel = 6;
            break;
        }
        self->selection = sel;
        fn_18_1D48(self, sel, 1);
        self->state = 0x22;
        break;
    }

    self->view->fn_2_361C4(0xA, lbl_2_data_1B30[self->selection]);
}
}
