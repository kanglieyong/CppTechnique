#include "PacketBuffer.h"
#include "IPPacket.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

int main(void)
{
  PacketBuffer<IPPacket> ipPackets(3);
  for (int i = 1; i <= 4; i++) {
    if (!ipPackets.bufferPacket(IPPacket(i))) {
      cout << "Packet " << i << " dropped (queue is full)." << endl;
    }
  }
  while (true) {
    try {
      IPPacket packet = ipPackets.getNextPacket();
      cout << "Processing packet " << packet.getID() << endl;
    } catch (const out_of_range&) {
      cout << "Queue is empty." << endl;
      break;
    }
  }

  return 0;
}
