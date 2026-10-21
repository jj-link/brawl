#pragma force_active on

extern "C" {
extern char lbl_100_data_2098[8];
extern char lbl_100_data_20C4[8];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_100_15644(void*, int, int, void*);
}

class FighterNode {
public:
    int pad[2];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* getNode();
};

class ValueNode {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* getNext();
};

extern "C" int fn_100_9028(void* self, char* accesser) {
    void* owner;
    int taskId;
    FighterNode* fighter = *(FighterNode**)(*(char**)(accesser + 0xd8));
    void* obj = fighter->getNode();
    void* dyn = __dynamic_cast(
        obj, 0, lbl_100_data_2098, lbl_100_data_20C4, (short)1);
    taskId = *(int*)(*(char**)(accesser + 8) + 0x28);
    ValueNode* p = *(ValueNode**)(*(char**)(accesser + 0xd8) + 0x18);
    ValueNode* q = (ValueNode*)p->getNext();
    owner = q->getNext();
    int resource = fn_27_14DB04(dyn);
    fn_100_15644(self, taskId, resource, owner);
    return 1;
}
