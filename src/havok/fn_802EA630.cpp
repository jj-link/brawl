#pragma force_active on

struct ArrayElem;

struct ThresholdStruct {
    unsigned char pad[0xB8];
    float threshold1, threshold2;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned int slot2(ArrayElem*);
    virtual unsigned int slot3(ArrayElem*);
};

struct ArrayElem {
    unsigned char pad[0x68];
    Object_vptr_0* obj;
};

struct MainStruct {
    unsigned char pad0[0x18];
    ThresholdStruct* field_18;
    unsigned char pad1C[8];
    unsigned char counter1, counter2;
    unsigned char pad26[10];
    float field_30, field_34;
    ArrayElem** array;
    int count;
};

struct OffsetStruct {
    unsigned char pad[8];
    float offset;
};

extern "C" unsigned int fn_802EA630(MainStruct* arg0, OffsetStruct* arg1) {
    float offset = arg1->offset;
    float x = arg0->field_30 + offset;
    float y = arg0->field_34 + offset;
    arg0->field_30 = x;
    arg0->field_34 = y;
    ThresholdStruct* t = arg0->field_18;
    float threshold1 = t->threshold1;
    int a = x > threshold1;
    float threshold2 = t->threshold2;
    signed char b = y > threshold2;
    int found;
    int flag;
    int idx;
    int i;
    int i2;
    int idx2;
    int flag2;
    int found2;

    if ((signed char)a) {
        arg0->field_30 -= threshold1;
        flag = 1;
        for (i = 0, idx = 0; i < arg0->count; idx += 4, i++) {
            found = 1;
            ArrayElem* elem = *reinterpret_cast<ArrayElem**>(
                reinterpret_cast<char*>(arg0->array) + idx);
            Object_vptr_0* obj = elem->obj;
            if (obj != 0 && (signed char)(obj->slot2(elem) >> 24) != 0)
                found = 0;
            if (found)
                flag = 0;
        }
        if (flag != 0) {
            arg0->counter1++;
            if (arg0->counter1 >= 5) {
                arg0->counter1 = 0;
                return 0x01000000;
            }
        } else {
            arg0->counter1 = 0;
        }
    } else if (b) {
        arg0->field_34 -= threshold2;
        flag2 = 1;
        for (i2 = 0, idx2 = 0; i2 < arg0->count; idx2 += 4, i2++) {
            found2 = 1;
            ArrayElem* elem = *reinterpret_cast<ArrayElem**>(
                reinterpret_cast<char*>(arg0->array) + idx2);
            Object_vptr_0* obj = elem->obj;
            if (obj != 0 && (signed char)(obj->slot3(elem) >> 24) != 0)
                found2 = 0;
            if (found2)
                flag2 = 0;
        }
        if (flag2 != 0) {
            arg0->counter2++;
            if (arg0->counter2 >= 5) {
                arg0->counter2 = 0;
                return 0x01000000;
            }
        } else {
            arg0->counter2 = 0;
        }
    }
    return 0;
}
