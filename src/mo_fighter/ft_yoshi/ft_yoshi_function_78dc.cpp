#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_95_5800(void*, short);
void* fn_95_7990(void*, short);
void* fn_95_79FC(void*, short);
void* fn_95_7A58(void*, short);
void* fn_95_7AB4(void*, short);
void* fn_95_7B10(void*, short);

void* fn_95_78DC(void* object, short deleting)
{
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;

        fn_27_13C90(storage + 0x2B4, destroy);
        fn_95_7990(storage + 0x278, destroy);
        fn_27_21038(storage + 0x268, destroy);
        fn_95_79FC(storage + 0x248, destroy);
        fn_95_7A58(storage + 0x228, destroy);
        fn_95_5800(storage + 0x1F0, destroy);
        fn_95_7AB4(storage + 0xC4, destroy);
        fn_95_7B10(object, destroy);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
