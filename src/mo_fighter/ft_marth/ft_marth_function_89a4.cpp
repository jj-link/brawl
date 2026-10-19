#pragma force_active on
extern "C" {
void fn_106_815C(void*, short);

void* fn_106_89A4(void* self, short flag)
{
    if (self != 0) {
        fn_106_815C(self, 0);
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
}
