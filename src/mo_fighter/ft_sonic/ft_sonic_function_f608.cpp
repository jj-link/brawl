#pragma force_active on
class UnkClass {
public:
    int x;
};

extern "C" {
    void fn_123_FCC8(UnkClass* self, short param);

    UnkClass* fn_123_F608(UnkClass* self, short param) {
        if (self != 0) {
            fn_123_FCC8(self, (short)-1);
            if (param > 0) {
                delete self;
            }
        }
        return self;
    }
}
