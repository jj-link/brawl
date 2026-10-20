#pragma force_active on
extern "C" {
extern char lbl_27_bss_D8C[];
extern char lbl_105_data_2B10[];
extern char lbl_105_data_2B58[];

void* fn_105_A9F4();
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_C7744(void*, void*, int);
void* fn_27_C77B0(void*, const void*);
void* fn_27_C7770(void*, short);
}

struct ParameterTemporary {
    unsigned char storage[0x10];
};

struct ParameterObject {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
};

extern "C" void fn_105_A7F0(char* object, int kind, int index,
                           void* data, int size) {
    void* selected;

    switch (kind) {
    case 1:
        switch (index) {
        case 0: selected = object + 0x1ECEC; goto selected_done;
        case 1: selected = lbl_27_bss_D8C; goto selected_done;
        case 2: selected = lbl_27_bss_D8C; goto selected_done;
        default: selected = fn_105_A9F4(); goto selected_done;
        }
    case 2:
        switch (index) {
        case 0: selected = object + 0x1EE18; goto selected_done;
        case 1: selected = lbl_27_bss_D8C; goto selected_done;
        case 2: selected = lbl_27_bss_D8C; goto selected_done;
        default: selected = fn_105_A9F4(); goto selected_done;
        }
    case 3:
        switch (index) {
        case 0: selected = object + 0x1EF44; goto selected_done;
        case 1: selected = lbl_27_bss_D8C; goto selected_done;
        case 2: selected = lbl_27_bss_D8C; goto selected_done;
        default: selected = fn_105_A9F4(); goto selected_done;
        }
    case 4:
        switch (index) {
        case 0: selected = object + 0x1F070; goto selected_done;
        case 1: selected = lbl_27_bss_D8C; goto selected_done;
        case 2: selected = lbl_27_bss_D8C; goto selected_done;
        default: selected = fn_105_A9F4(); goto selected_done;
        }
    default:
        selected = fn_105_A9F4();
        goto selected_done;
    }

selected_done:
    ParameterObject* parameter = static_cast<ParameterObject*>(
        __dynamic_cast(selected, 0, lbl_105_data_2B10,
                       lbl_105_data_2B58, 0));

    if (parameter) {
        parameter->slot28();
        ParameterTemporary temporary;
        fn_27_C7744(&temporary, data, size);
        fn_27_C77B0(parameter, &temporary);
        fn_27_C7770(&temporary, static_cast<short>(-1));
    }
}
