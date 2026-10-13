namespace {
struct DededeTraversalIndex {
    short value;
};

struct DededeTraversalElement {
    unsigned char unknown[5];
    unsigned char enabled : 1;
    unsigned char remaining : 7;
    unsigned char state;
};
}

extern "C" {
void fn_117_21E18(DededeTraversalElement*, void*);
void fn_117_21FE8(DededeTraversalIndex*, const DededeTraversalIndex*);
int fn_117_21EF8(void*, const DededeTraversalIndex*, void*);
}

extern "C" void fn_117_21E68(void* object, const DededeTraversalIndex* index, void* argument) {
    unsigned char* traversal = static_cast<unsigned char*>(object);
    DededeTraversalElement* element = reinterpret_cast<DededeTraversalElement*>(traversal + 0xC);
    if ((index->value & 8) && static_cast<unsigned int>(element->enabled != 0) == 1 && element->state == 0) {
        fn_117_21E18(element, argument);
    }

    DededeTraversalIndex next;
    fn_117_21FE8(&next, index);
    fn_117_21EF8(traversal + 4, &next, argument);
}
