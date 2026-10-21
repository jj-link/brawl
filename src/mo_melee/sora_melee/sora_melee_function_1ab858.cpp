#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);

extern char lbl_27_data_25F10[];
extern char lbl_27_data_439F8[];
extern char lbl_27_data_43AF0[];
extern char lbl_27_data_3F560[];

void fn_27_EF21C(void*);
void* fn_27_84318(void*, int);
void __construct_array(void*, void (*)(void*), void* (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual short addUnit(void*);
};

struct Inner {
    void* vtable;
    unsigned char byte;
    char pad[3];
    void* v14;
    void* v18;
    void* v1C;
    void* v20;
    unsigned int flags;
    char array[48];
    unsigned char end;
};

class soCollisionReflectorEventObserver;

template<class T, int N>
struct soEventUnitWithWorkArea {
    void* vtable;
    short id;
    short index;
    Inner* ptr;
    Inner inner;

    soEventUnitWithWorkArea(short, short);
};

template<>
soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>::soEventUnitWithWorkArea(
    short id, short index)
{
    this->id = id;
    this->vtable = lbl_27_data_25F10;
    this->index = index;

    if (id != -1) {
        short result = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->id))->addUnit(this);
        if (result > -1) {
            this->index = result;
        }
    }

    Inner* inner = &this->inner;
    this->ptr = inner;
    this->vtable = lbl_27_data_3F560;

    inner->byte = 0;
    inner->vtable = lbl_27_data_439F8;
    inner->v14 = lbl_27_data_439F8 + 0x34;
    inner->v18 = lbl_27_data_439F8 + 0x40;
    inner->v1C = lbl_27_data_43AF0;
    inner->v20 = lbl_27_data_43AF0 + 0x48;
    inner->flags &= 0x0007FFFF;

    __construct_array(inner->array, fn_27_EF21C, fn_27_84318, 12, 4);
    inner->end = 0;
}
