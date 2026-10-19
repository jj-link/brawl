#pragma force_active on
class soModuleAccesser;

struct CaptainEventArgs {
    int id;
    unsigned char flag;
    int value;
    unsigned char rest[0x2C];
};

extern "C" {
void fn_100_FB5C(soModuleAccesser*, CaptainEventArgs*);
}

extern "C" void fn_100_E3B4(void* unused, soModuleAccesser* accesser) {
    CaptainEventArgs args;
    args.id = 0x44f;
    args.flag = 0;
    args.value = 0;
    fn_100_FB5C(accesser, &args);
}
