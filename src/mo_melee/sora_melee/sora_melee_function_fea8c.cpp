#pragma force_active on
struct Node {
    int field0;
    int field4;
    int field8;
};

extern "C" Node *fn_27_FEA8C(Node *object, int index)
{
    int shift = object->field8 >> 29;
    int adjusted = shift + index;
    if (adjusted >= 2)
        adjusted -= 2;
    return object + adjusted + 1;
}
