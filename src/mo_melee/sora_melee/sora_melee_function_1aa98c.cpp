#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, int);
void fn_27_EF144(void*);
void fn_27_844D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned int, unsigned int);

extern char lbl_27_data_260C8[];
extern char lbl_27_data_3D9C8[];
extern char lbl_27_data_423D0[];
extern char lbl_27_data_424C0[];
}

struct Manager {
    virtual short add(void*);
};

struct Sub {
    void* vtable;
    unsigned char active;
    char pad[3];
    void* v8;
    void* vC;
    void* v10;
    void* v14;
    unsigned int flags;
    char items[60];
    unsigned char end;
};

class soArticleEventObserver;

template <class T, int N>
struct soEventUnitWithWorkArea {
    void* vtable;
    short manager;
    short event;
    Sub* list;
    Sub sub;

    soEventUnitWithWorkArea(short, short);
};

template <>
soEventUnitWithWorkArea<soArticleEventObserver, 5>::soEventUnitWithWorkArea(
    short manager, short event)
{
    this->manager = manager;
    this->vtable = lbl_27_data_260C8;
    this->event = event;

    if (manager != -1) {
        short id = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->manager))->add(this);
        if (id > -1) {
            this->event = id;
        }
    }

    Sub* sub = &this->sub;
    this->list = sub;
    this->vtable = lbl_27_data_3D9C8;
    sub->active = 0;
    sub->vtable = lbl_27_data_423D0;
    sub->v8 = lbl_27_data_423D0 + 0x34;
    sub->vC = lbl_27_data_423D0 + 0x40;
    sub->v10 = lbl_27_data_424C0;
    sub->v14 = lbl_27_data_424C0 + 0x48;
    sub->flags &= 0x0007FFFF;
    __construct_array(sub->items, fn_27_EF144, fn_27_844D8, 12, 5);
    sub->end = 0;
}
