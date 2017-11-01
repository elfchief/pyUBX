// File lang/cpp/src/deserializer.h
// Auto-generated by pyUBX generateCpp.py v0.1 on 2017-11-01T09:14:04.975986
// See https://github.com/mayeranalytics/pyUBX
#ifndef __DESERIALIZER_H__
#define __DESERIALIZER_H__

#include "messages/ACK.h"
#include "messages/CFG.h"
#include "messages/MON.h"
#include "messages/TEST.h"

class Deserializer : public ParseUBX
{
public:
    void onUBX(uint8_t cls, uint8_t id, size_t len, char buf[]) {
        switch(cls) {
        case 0x05: // Message class ACK
            switch(id) {
            case 0x01: // Message ACK-ACK_
                onACK_ACK_(*((ACK::ACK_*)buf));
                break;
            case 0x00: // Message ACK-NAK
                onACK_NAK(*((ACK::NAK*)buf));
                break;
            default:
                onUBXerr(cls, id, len, NotImplemented);
            }
            break;
        case 0x06: // Message class CFG
            switch(id) {
            case 0x3E: // Message CFG-GNSS
                onCFG_GNSS(*((CFG::GNSS*)buf));
                break;
            case 0x3B: // Message CFG-PM2
                onCFG_PM2(*((CFG::PM2*)buf));
                break;
            case 0x86: // Message CFG-PMS
                onCFG_PMS(*((CFG::PMS*)buf));
                break;
            case 0x00: // Message CFG-PRT
                onCFG_PRT(*((CFG::PRT*)buf));
                break;
            case 0x08: // Message CFG-RATE
                onCFG_RATE(*((CFG::RATE*)buf));
                break;
            case 0x11: // Message CFG-RXM
                onCFG_RXM(*((CFG::RXM*)buf));
                break;
            default:
                onUBXerr(cls, id, len, NotImplemented);
            }
            break;
        case 0x0A: // Message class MON
            switch(id) {
            case 0x04: // Message MON-VER
                onMON_VER(*((MON::VER*)buf));
                break;
            default:
                onUBXerr(cls, id, len, NotImplemented);
            }
            break;
        case 0xFF: // Message class TEST
            switch(id) {
            case 0xFF: // Message TEST-TEST_
                onTEST_TEST_(*((TEST::TEST_*)buf));
                break;
            default:
                onUBXerr(cls, id, len, NotImplemented);
            }
            break;
        default:
            onUBXerr(cls, id, len, NotImplemented);
        }
    }

    /* callback for ACK::ACK_ messages */
    virtual void onACK_ACK_(ACK::ACK_& msg) {}
    
    /* callback for ACK::NAK messages */
    virtual void onACK_NAK(ACK::NAK& msg) {}
    
    /* callback for CFG::GNSS messages */
    virtual void onCFG_GNSS(CFG::GNSS& msg) {}
    
    /* callback for CFG::PM2 messages */
    virtual void onCFG_PM2(CFG::PM2& msg) {}
    
    /* callback for CFG::PMS messages */
    virtual void onCFG_PMS(CFG::PMS& msg) {}
    
    /* callback for CFG::PRT messages */
    virtual void onCFG_PRT(CFG::PRT& msg) {}
    
    /* callback for CFG::RATE messages */
    virtual void onCFG_RATE(CFG::RATE& msg) {}
    
    /* callback for CFG::RXM messages */
    virtual void onCFG_RXM(CFG::RXM& msg) {}
    
    /* callback for MON::VER messages */
    virtual void onMON_VER(MON::VER& msg) {}
    
    /* callback for TEST::TEST_ messages */
    virtual void onTEST_TEST_(TEST::TEST_& msg) {}
    
};

#endif // #define __DESERIALIZER_H__

