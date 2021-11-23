extern "C" {
#include "crc32.h"
#include "wire.h"
}

#include "gtest/gtest.h"

namespace {

    TEST(TestCrc32, testCrcComplex) {
        /*
        80 00 00 00 ff ff ff
        ff ff ff 02 5f 5a 1a e3 01 50 6f 9a 01 7f 01 d0
        23 97 3e 4c 06 00 00 00 00 64 00 20 04 dd 22 50
        6f 9a 13 00 02 00 01 bc 01 0d 00 02 5f 5a 1a e3
        01 bc 01 00 00 00 00 00 28 06 00 44 77 4d b1 01
        60 [57 e1 48 ff] <- fcs we want to verify
        */

        u_char testBuf[] = {
                0x80, 0x00, 0x00, 0x00,
                0xff, 0xff, 0xff, 0xff,
                0xff, 0xff, 0x02, 0x5f,
                0x5a, 0x1a, 0xe3, 0x01,
                0x50, 0x6f, 0x9a, 0x01,
                0x7f, 0x01, 0xd0, 0x23,
                0x97, 0x3e, 0x4c, 0x06,
                0x00, 0x00, 0x00, 0x00,
                0x64, 0x00, 0x20, 0x04,
                0xdd, 0x22, 0x50, 0x6f,
                0x9a, 0x13, 0x00, 0x02,
                0x00, 0x01, 0xbc, 0x01,
                0x0d, 0x00, 0x02, 0x5f,
                0x5a, 0x1a, 0xe3, 0x01,
                0xbc, 0x01, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x28,
                0x06, 0x00, 0x44, 0x77,
                0x4d, 0xb1, 0x01, 0x60
        };
        uint32_t result = crc32(testBuf, 72);
        EXPECT_EQ(htobe32(0x57e148ff), result);
    }
}