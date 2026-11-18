#pragma force_active on
#pragma push
#pragma use_lmw_stmw on

class Class_80487298 {
public:
    virtual void fn_802CAD00();
    virtual void fn_80080A64();
    virtual int fn_802CACF8();
};

struct Value {
    Class_80487298* object;
};
struct State {
    unsigned char* data;
    unsigned char pad[8];
    signed char flag;
};
typedef int (*Operation)(Value*, Value*, State*, void*);
struct OperationEntry {
    Operation operation;
    unsigned char pad[16];
};
struct Table {
    unsigned char pad[0x990];
    OperationEntry entries[1];
};
struct Context {
    Value* left;
    Value* right;
    State* state;
    void* extra;
};
struct Result {
    unsigned char type;
    unsigned char pad;
    unsigned char tag;
    unsigned char pad2;
    int value;
};

extern "C" int fn_802CAB20(const Context* self, Result* result, int next) {
    unsigned char* data;
    Value* left;
    Value* right;
    void* extra;
    State* state;
    state = self->state;
    data = state->data;
    left = self->left;
    extra = self->extra;
    right = self->right;
    int leftType = left->object->fn_802CACF8();
    int rightType = right->object->fn_802CACF8();
    unsigned char* map = ((unsigned int)(-state->flag | state->flag) >> 31) ? data + 0x590 : data + 0x190;
    int value = reinterpret_cast<Table*>(data)->entries[(reinterpret_cast<unsigned char*>(rightType) + reinterpret_cast<unsigned int>(map))[leftType << 5]].operation(left, right, state, extra);
    result->value = value;
    result->type = 6;
    result->tag = 0xFF;
    return next;
}

#pragma pop
