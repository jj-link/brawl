#pragma force_active on
struct QueryBase {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual int query();
};

struct QueryObject {
    char pad[0xD8];
    struct QueryNode* node;
};

struct QueryNode {
    char pad[0x70];
    QueryBase* target;
};

extern "C" bool fn_27_155B3C(void*, QueryObject* object) {
    QueryNode* node = reinterpret_cast<QueryNode*>(object->node);
    return node->target->query() != 0xC2;
}
