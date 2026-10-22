#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

#define VIRT(n) virtual void vfn##n()

class grGimmick {
public:
    unsigned char m_pad[0x3C];
    virtual ~grGimmick();
    VIRT(0); VIRT(1); VIRT(2); VIRT(3); VIRT(4); VIRT(5); VIRT(6); VIRT(7);
    VIRT(8); VIRT(9); VIRT(10); VIRT(11); VIRT(12); VIRT(13); VIRT(14); VIRT(15);
    VIRT(16); VIRT(17); VIRT(18); VIRT(19); VIRT(20); VIRT(21); VIRT(22); VIRT(23);
    VIRT(24); VIRT(25); VIRT(26); VIRT(27); VIRT(28); VIRT(29); VIRT(30); VIRT(31);
    VIRT(32); VIRT(33); VIRT(34); VIRT(35); VIRT(36); VIRT(37); VIRT(38); VIRT(39);
    VIRT(40); VIRT(41); VIRT(42); VIRT(43); VIRT(44); VIRT(45); VIRT(46); VIRT(47);
    VIRT(48); VIRT(49); VIRT(50); VIRT(51); VIRT(52); VIRT(53); VIRT(54); VIRT(55);
    VIRT(56); VIRT(57); VIRT(58); VIRT(59); VIRT(60); VIRT(61); VIRT(62); VIRT(63);
    VIRT(64); VIRT(65); VIRT(66); VIRT(67); VIRT(68); VIRT(69); VIRT(70); VIRT(71);
    VIRT(72); VIRT(73); VIRT(74); VIRT(75); VIRT(76); VIRT(77); VIRT(78); VIRT(79);
    VIRT(80); VIRT(81); VIRT(82); VIRT(83); VIRT(84); VIRT(85); VIRT(86); VIRT(87);
    VIRT(88); VIRT(89); VIRT(90); VIRT(91); VIRT(92); VIRT(93); VIRT(94); VIRT(95);
    VIRT(96); VIRT(97); VIRT(98); VIRT(99); VIRT(100); VIRT(101); VIRT(102); VIRT(103);
    VIRT(104); VIRT(105); VIRT(106); VIRT(107); VIRT(108); VIRT(109); VIRT(110);
    virtual void call1C8(float);
    virtual void call1CC(float);
    VIRT(111); VIRT(112); VIRT(113); VIRT(114); VIRT(115); VIRT(116); VIRT(117); VIRT(118);
    virtual void call1F0(float);
    virtual void call1F4(float);
    virtual void call1F8(float);

    unsigned char pad_40[0x2C];
    unsigned char m_6C;
    unsigned char pad_6D[0x5B];
    unsigned char m_C8;
};

extern "C" void fn_73_363C(grGimmick* self, float f) {
    update__9grGimmickFf(self, f);
    self->m_6C &= ~2;
    if (self->m_C8 != 0) {
        self->call1C8(f);
        self->call1CC(f);
        self->call1F4(f);
        self->call1F0(f);
        self->call1F8(f);
    }
}
