#pragma force_active on
extern "C" {
void* fn_94_15D34(void*, short);
void* fn_94_1614C(void*, short);

void* fn_94_15CC4(void* object, short deleting) {
    if (object != 0) {
        fn_94_15D34(static_cast<unsigned char*>(object) + 0x990C, static_cast<short>(-1));
        fn_94_1614C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
