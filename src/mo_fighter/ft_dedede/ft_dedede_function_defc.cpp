#pragma force_active on
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

struct DededeEventMask {
    unsigned char data[8];
};

struct soModuleAccesser;
}

extern "C" {
void fn_117_DEAC(DededeTraversalElement*, void*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
bool fn_117_DF8C(void*, const DededeEventMask*, soModuleAccesser*);
}

extern "C" void fn_117_DEFC(void* object, const DededeTraversalIndex* index, soModuleAccesser* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DededeTraversalElement* element =
        reinterpret_cast<DededeTraversalElement*>(composite + 0xC);

    if (index->value & 4) {
        if (static_cast<unsigned int>(element->enabled != 0) == 1 &&
            element->state == 0) {
            fn_117_DEAC(element, argument);
        }
    }

    DededeEventMask next;
    fn_117_DF94(&next, reinterpret_cast<const DededeEventMask*>(index));
    fn_117_DF8C(composite + 4, &next, argument);
}
