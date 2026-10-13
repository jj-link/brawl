#include <so/so_array.h>
#include <so/so_enable.h>

namespace {
// Shared prefix of the dynamic traversal's concrete elements.
class DededeDynamicTraversalElement {
public:
    virtual void reserved08();
    virtual void update(void* argument);
    unsigned char reserved;
    soEnable enabled;
    bool suspended;

    void updateIfActive(void* argument) {
        if (enabled.isEnable() == true && suspended == false) {
            update(argument);
        }
    }
};

inline void visitElement(DededeDynamicTraversalElement* element, void* argument) {
    if (element->enabled.isEnable() == true && element->suspended == false) {
        element->updateIfActive(argument);
    }
}
}

extern "C" void fn_117_21A40(void*, soArrayFixed<DededeDynamicTraversalElement**>* elements,
                              void* argument) {
    for (int i = 0; i < elements->size(); ++i) {
        DededeDynamicTraversalElement* element = *elements->at(i);
        if (!element->enabled.isEnable() || element->suspended == true) {
            continue;
        }
        visitElement(element, argument);
    }
}
