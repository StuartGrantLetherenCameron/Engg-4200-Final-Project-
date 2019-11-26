#include <Printers.h>
#include <XBee.h>

XBee host = XBee();

uint8_t payload[] = {'H', 'i'};
XBeeAddress64 addr64 = XBeeAddress64(0x0013A200, 0x4155B96F);

void setup() {
  Serial.begin(9600);
  host.setSerial(Serial);
}

void loop() {
  ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
  host.send(zbTx);
}
