#include <CP210x.h>
#include <usbhub.h>
#include "pgmstrings.h"

#include <SPI.h>

#include "Trace.h"
#include "Terminal.h"

//#define SERIAL_PORT Serial
#define SERIAL_PORT Serial1

class CP210xAsync : public CP210xAsyncOper
{
  public:
    uint8_t OnInit(CP210x *pftdi);
};

uint8_t CP210xAsync::OnInit(CP210x *cp210x)
{
  uint8_t rcode = 0;
  rcode = cp210x->IFCEnable();

  if (rcode)
  {
    return rcode;
  }

  rcode = cp210x->SetBaudRate(115200);

  if (rcode)
  {
    return rcode;
  }

  rcode = cp210x->SetDataBits(8);
  if (rcode)
  {
    return rcode;
  }

  rcode = cp210x->SetStopBits(CP210X_STOP_BITS_1);
  if (rcode)
  {
    return rcode;
  }

  rcode = cp210x->SetParity(CP210X_PARITY_NONE);
  if (rcode)
  {
    return rcode;
  }

  rcode = cp210x->SetFlowControl(CP210X_FLOW_CONTROL_OFF);
  if (rcode)
  {
    return rcode;
  }


  return rcode;
}

USBHost UsbH;
//USBHub Hub(&UsbH);
CP210xAsync cp210xAsync;
CP210x cp210x(&UsbH, &cp210xAsync);

void setupGlosdex()
{
  trace("setupGlosdex;\r\n");

  if (UsbH.Init() == -1)
    trace("OSC did not start\r\n");

  delay( 200 );
}

void updateGlosdex()
{
  UsbH.Task();

  if ( UsbH.getUsbTaskState() == USB_STATE_RUNNING )
  {
    uint8_t  rcode;
    char strbuf[] = "DEADBEEF";
    //char strbuf[] = "The quick brown fox jumps over the lazy dog";
    //char strbuf[] = "This string contains 61 character to demonstrate FTDI buffers"; //add one symbol to it to see some garbage
    //Serial.print(".");

    //rcode = cp210x.SndData(strlen(strbuf), (uint8_t*)strbuf);
	//TODO: send ErrorMessage, etc. from USBHost lib to correct serial port
    //if (rcode)
      //ErrorMessage<uint8_t>(PSTR("SndData"), rcode);

    uint8_t  buf[64];

    for (uint8_t i = 0; i < 64; i++)
      buf[i] = 0;

    uint16_t rcvd = 64;
    rcode = cp210x.RcvData(&rcvd, buf);

    if (rcode && rcode != USB_ERRORFLOW)
      ErrorMessage<uint8_t>(PSTR("Ret"), rcode);

    // // The device reserves the first two bytes of data
    // //   to contain the current values of the modem and line status registers.
    for (int i = 0; i < rcvd; i++)
		processSerialChar(buf[i]);
  }
}
