import socket
import struct
import binascii

class Udphdr:
    def __init__(self, srcport, dstport, length, checksum):
        
        self.srceport = srcport
        self.destport = dstport
        self.length = length
        self.checksum = checksum


    def pack_udphdr(self):
        packed = b''
        packed += struct.pack('!HHHH', self.srceport,  self.destport, self.length, self.checksum)
        return packed

def unpack_udphdr(buffer):
    unpacked = struct.unpack('!HHHH', buffer[:20])
    return unpacked


def getSrcPort(unpacked_udpheader):
    return unpacked_udpheader[0]

def getDstPort(unpacked_udpheader):
    return unpacked_udpheader[1]

def getLength(unpacked_udpheader):
    return unpacked_udpheader[2]


def getChecksum(unpacked_udpheader):
    return unpacked_udpheader[3]


udp = Udphdr(5555, 80, 1000, 0xFFFF)

packed_udphdr = udp.pack_udphdr()
print(binascii.b2a_hex(packed_udphdr))

unpacked_udphdr = unpack_udphdr(packed_udphdr)
print(unpacked_udphdr)

print('Source Port:{} Destination Port:{} Length:{} Checksum:{}'.format(getSrcPort(unpacked_udphdr), getDstPort(unpacked_udphdr), getLength(unpacked_udphdr), getChecksum(unpacked_udphdr)))
