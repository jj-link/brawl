#include <so/so_value_accesser.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);

    char pad[0x18];
    soModuleAccesser* accesser;
    int kind;
    int count;
    int value;
    int status;
};

extern "C" void fn_27_14FEAC(Object* self, int kind) {
    if (self->kind != kind) {
        self->slot4(kind);
    }

    unsigned int same;
    if (self->value >= 0 &&
        self->status == self->accesser->m_enumerationStart->m_statusModule->getStatusKind()) {
        same = 1;
    } else {
        same = 0;
    }

    if (same == 1) {
        self->count++;
    } else {
        self->count = 1;
    }

    switch (kind) {
    case 1:
        switch (self->count) {
        case 1:
            self->value = (int)soValueAccesser::getConstantFloat(self->accesser, 0xbda, 0);
            break;
        case 2:
            self->value = (int)soValueAccesser::getConstantFloat(self->accesser, 0xbdb, 0);
            break;
        case 3:
            break;
        }
        break;

    case 2:
        switch (self->count) {
        case 1:
            self->value = (int)soValueAccesser::getConstantFloat(self->accesser, 0xbdc, 0);
            break;
        case 2:
            self->value = (int)soValueAccesser::getConstantFloat(self->accesser, 0xbdd, 0);
            break;
        case 3:
            break;
        }
        if (self->value == 0) {
            self->value = -1;
        }
        break;

    case 3:
        switch (self->count) {
        case 1:
            self->value = (int)soValueAccesser::getConstantFloat(self->accesser, 0xbde, 0);
            break;
        case 2:
            break;
        }
        if (self->value == 0) {
            self->value = -1;
        }
        break;
    }

    self->status = self->accesser->m_enumerationStart->m_statusModule->getStatusKind();
    self->kind = kind;
}
