#pragma force_active on
class grTenganEvent {
public:
    unsigned char padding[0xA4];
    unsigned int unkA4;

    bool isReadyEnd() const;
};

bool grTenganEvent::isReadyEnd() const {
    return unkA4 == 2;
}
