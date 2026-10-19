#pragma force_active on
extern "C" {
void* fn_100_3380(void* object, short shouldDelete);
void* fn_100_4850(char* object, short flag);
}

void operator delete(void* p);

extern "C" void* fn_100_3310(char* object, short shouldDelete) {
    if (object != 0) {
        fn_100_3380(object + 0x1F38, -1);
        fn_100_4850(object, 0);
        if (shouldDelete > 0) {
            operator delete(object);
        }
    }
    return object;
}
