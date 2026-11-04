#pragma force_active on

struct Node {
    char pad[0x10];
    void* value;
};

struct NodeList {
    char pad[0x2BC];
    Node* nodes[5];
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

struct Class_728_base { char pad[0x3C]; };
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
extern const char lbl_2_data_3780[];
void fn_18_1C4C(Menu*, int);
int fn_18_1A9C(Menu*);
void fn_18_1D48(Menu*, int, int);

void fn_2_2B5E8(Menu* self, Loader& loader, short arg) {
    int sel = arg;
    unsigned off;
    unsigned cnt;

    self->config = lbl_2_data_3780;
    self->loader = &loader;
    self->mode = 0;
    self->count = 0xAF;
    cnt = 0;
    off = 0;

    do {
        loader.attach(
            loader.context,
            (*reinterpret_cast<Node**>(
                reinterpret_cast<char*>(self->list) + 0x2BC + off))->value);
        ++cnt;
        off += 4;
    } while (cnt < 5);

    switch (sel) {
    case 4:
        self->selection = 0;
        self->state = 4;
        fn_18_1C4C(self, 1);
        break;
    default:
        self->mode = 1;
        switch (fn_18_1A9C(self)) {
        case 15:
            sel = 4;
            break;
        case 16:
            sel = 3;
            break;
        case 17:
            sel = 0;
            break;
        case 18:
            sel = 1;
            break;
        case 19:
            sel = 2;
            break;
        }
        self->selection = sel;
        fn_18_1D48(self, sel, 1);
        self->state = 0x22;
        break;
    }
    self->view->fn_2_361C4(0x13, self->selection + 0x37);
}
}
