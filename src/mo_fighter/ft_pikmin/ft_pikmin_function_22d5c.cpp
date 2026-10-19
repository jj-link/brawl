#include <so/so_module_accesser.h>
#include <StaticAssert.h>
#pragma force_active on

// Preserve the original virtual function table layout of the Pikmin article
// integer selector (slot08, slot0C, getParameters at offset 0x10).
class PikminArticleIntegerSelector {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual const int* getParameters(int kind);
};

struct PikminArticleIntegerAccesser {
    u8 prefix[0x158];
    PikminArticleIntegerSelector selector;
};
static_assert(sizeof(PikminArticleIntegerAccesser) == 0x15c, "Selector ABI layout");

extern "C" int fn_113_22E18(PikminArticleIntegerAccesser*, soModuleAccesser*, int, int);

extern "C" int fn_113_22D5C(PikminArticleIntegerAccesser* self, soModuleAccesser* accesser, int index, int element) {
    if (index < 0x5dc8) {
        return fn_113_22E18(self, accesser, index, element);
    }
    int kind = accesser->getWorkManageModule().getInt(0x10000005);
    switch (index) {
    case 0x5dc9: return self->selector.getParameters(kind)[0];
    case 0x5dca: return self->selector.getParameters(kind)[19];
    default: return 0;
    }
}
