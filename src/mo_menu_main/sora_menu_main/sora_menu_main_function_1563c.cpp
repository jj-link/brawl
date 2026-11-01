#pragma force_active on

struct Node {
    char pad[0x10];
    void* value;
};

struct NodeList {
    char pad[0x18];
    Node* nodes[6];
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

struct ViewBase {
    char pad[0x3C];
};

struct View : ViewBase {
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
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void reserved22();
    virtual void reserved23();
    virtual void reserved24();
    virtual void reserved25();
    virtual void reserved26();
    virtual void select(int, int);
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
    View* view;
    int field65C;
    int field660;
    int mode;
};

extern "C" {
extern const char lbl_2_data_1E58[];

void fn_18_1C4C(Menu*, int);
int fn_18_1A9C(Menu*);
void fn_18_1D48(Menu*, int, int);
int fn_800557D8();
void fn_8005A0E4(int);
void fn_800557C0();

void fn_2_1563C(Menu* self, Loader& loader, short arg) {
    int sel = arg;
    unsigned off;
    unsigned cnt;

    self->loader = &loader;
    self->config = lbl_2_data_1E58;
    self->count = 6;
    cnt = 0;
    off = 0;

    do {
        loader.attach(
            loader.context,
            (*reinterpret_cast<Node**>(
                reinterpret_cast<char*>(self->list) + 0x18 + off))->value);
        ++cnt;
        off += 4;
    } while (cnt < 6);

    switch (sel) {
    case 0:
        self->mode = 0;
        self->selection = 0;
        self->state = 0;
        fn_18_1C4C(self, 1);
        break;

    case 24:
        self->mode = 1;
        self->selection = 1;
        self->state = 24;
        fn_18_1C4C(self, 1);
        break;

    case 30:
        self->mode = 1;
        self->selection = 4;
        self->state = 30;
        fn_18_1C4C(self, 1);
        break;

    case 22:
        if (fn_800557D8() != 0) {
            fn_8005A0E4(0x2E);
            fn_800557C0();
        }
        self->mode = 1;
        self->selection = 5;
        self->state = 22;
        fn_18_1C4C(self, 1);
        break;

    default:
        self->mode = 2;
        switch (fn_18_1A9C(self)) {
        case 1:
            sel = 0;
            break;
        case 2:
            sel = 2;
            break;
        case 37:
            sel = 3;
            break;
        case 3:
            sel = 1;
            break;
        }
        self->selection = sel;
        fn_18_1D48(self, sel, 1);
        self->state = 0x22;
        break;
    }

    self->view->select(7, self->selection + 6);
}
}
