int alien_hash(char directions[]) {

    if (strlen(directions) != 100) 
        return -1;

    int checksum_1_byte, checksum_2_byte, checksum_3_byte;
    char* desired_hash = "I'm winn1ng - We_rE@cH3D_7hE_Fu3L :~)";
    char hash[38] = "";

    for (int i=1; i<=3; i++) {
        if (directions[ ( ( 26*i) % 27) ] == directions[ ( (269*i)  %  104) ] || 
            directions[ ( ( 90*i) % 19) ] == directions[ ( ( 81*i)  %  87 ) ] || 
            directions[ ( ( 21*i) % 35) ] == directions[ ( (196*i)  %  73 ) ] ||
            directions[ ( ( 60*i) % 70) ] == directions[ ( (192*i)  %  76 ) ] ||
            directions[ ( (164*i) % 96) ] == directions[ ( ( 50*i)  %  88 ) ]) {
                return-1;
            }
    }

    int checksum_1 = ((3*directions[18] + 4*directions[32] + 2*directions[33] + 0x4) % 52);
    if (checksum_1 < 0)
        checksum_1 += 52; 

    if (checksum_1 <= 27)
        checksum_1_byte = 0x2;
    else if (checksum_1 < 35 && checksum_1 > 27)
        checksum_1_byte = 0x16;
    else
        checksum_1_byte = 0x3A;


    int checksum_2 = ((directions[31] - 3*directions[20] + directions[19] - 0x8) % 16);
    if (checksum_2 < 0)
        checksum_2 += 16;

    if (checksum_2 < 13)
        checksum_2_byte = 0x22;
    else if (checksum_2 == 13)
        checksum_2_byte = 0xD;
    else
        checksum_2_byte = 0x9;


    int checksum_3 = ((2*directions[24] - 7*directions[46] + 3*directions[32] - 4*directions[27] ) % 62);
    if (checksum_3 < 0)
        checksum_3 += 62;

    if (checksum_3 <= 20 && checksum_3 > 6)
        checksum_3_byte = 0x4;
    else if (checksum_3 < 26 && checksum_3 > 20)
        checksum_3_byte = 0x1F;
    else
        checksum_3_byte = 0x29;


    hash[0] = ((directions[6] ^ directions[10]) & 0xF)  +  ((directions[3] + directions[5] - 25 ) ^ (3*directions[99]));
    hash[1] = ( (   (directions[95] ^  directions[0]) | (directions[1] ^ directions[2])  )  +  (  (  (   (directions[9] ^ directions[99]) | directions[6] ) % 18 ) ^ (directions[10] & 0x1F) ) );
    hash[2] = 109;
    hash[3] = ((((directions[11] - directions[12]) * (( (directions[6] & directions[12]) & 0x2F) + (directions[0] / directions[1]) )) * 2  ));
    hash[4] = ((((   (~(  (directions[14] >> 2)) & 0x36) * (directions[15])  ) + 12 ) / (((~(directions[15] ^ directions[95]))  ^ ((directions[14] << 5)))  & 0xFF)) + 0x9);
    hash[5] = 105;
    hash[6] = (((((directions[14] - directions[6] + directions[10] - directions[15] + directions[99]) << 1) + ((directions[0] + directions[2] - directions[3] + directions[8]) << 1)) / 4)   |  ((directions[13]) & 0xBF)); 
    hash[7] = hash[6];
    hash[8] = (( ((directions[0] ^ directions[1]) * directions[5]) + (directions[8] / directions[0]) ) * ((directions[2] - directions[1]) + 40));
    hash[9] = (   (( directions[12] ^ (directions[11] - directions[10]) ^ (directions[6] & directions[95]) ^ (directions[13] )  ) >> ((directions[0] - directions[5]) & (directions[9] - directions[8]) )) ^ 0x40);
    hash[10] = 5*(directions[97] ^ (directions[43] + directions[86] - directions[78])) + 21*(directions[43] - directions[97]) - 1;
    hash[11] = 0x20;
    hash[12] = 0x2D;
    hash[13] = hash[11];
    hash[14] = ( (checksum_2_byte >> (directions[16] & 0x33)) * (directions[17] ^ 0x58));
    hash[15] = (( ((directions[22] + 10) % checksum_2_byte ) + 2*directions[21] - 1*directions[26] ) | 0x25 );
    hash[16] = (directions[24] + directions[73] - directions[23] - directions[27]) * (directions[28] & 0x3) - (directions[29] - directions[30] + 1);
    hash[17] = ( checksum_1_byte + 5*((directions[34] + 1) % directions[35]) + (3*directions[36] | directions[37]) ) % 128;
    hash[18] = directions[38] + ((directions[39] ^ directions[98]) | (directions[41] ^ directions[42]));
    hash[19] =  ( (directions[43] + directions[46] + 0x2) % directions[44]) << ((directions[45] & 0x85) ^ (directions[44] & 0x24));
    hash[20] = ((directions[47] ^ directions[48]) ^ (directions[49] ^ directions[50]) ^ directions[51]) ^ (2*checksum_2_byte + checksum_3_byte + (directions[52] & (directions[52] << 1)));
    hash[21] =  ( directions[53] ^ checksum_2_byte ) + ( directions[54]  ^ checksum_1_byte) - ( directions[55] ^ checksum_3_byte) - ( directions[56] & 0x2E );
    hash[22] =  ( (checksum_3_byte >> (directions[57] & 0x33)) + (directions[58] & 0xE9) / ((directions[60] ^ 0x56) + (directions[59] & 0xAD)));
    hash[23] =  ( directions[61] ^ directions[94]) + (6*directions[63] - 7*directions[64]);
    hash[24] = ((directions[65] - directions[66]) >> 1) +  (directions[68] - directions[67]) + (((directions[67] & directions[68]) & (0x2 + directions[69] + directions[70])) * checksum_3_byte);
    hash[25] = ((directions[71] * checksum_3_byte) - (directions[72] * checksum_1_byte) - (directions[25] * checksum_2_byte) + (2*directions[74]) - 0x14 ) + 0x200;
    hash[26] = (directions[75] >> (checksum_1_byte + checksum_2_byte - checksum_3_byte)) * (directions[76] - directions[77]) + (directions[78] ^ 0x5D);
    hash[27] = (directions[53] | directions[48] | directions[51]);
    hash[28] = (directions[79] + 5*directions[80] - 4*directions[92]) - 0x85;
    hash[29] = ((((2*directions[82] ^ directions[83]) - 0x21) % (directions[84] - 4) ) + directions[85]) - (directions[86] ^ directions[87]);
    hash[30] = (directions[88] * directions[88]) - (directions[89] * directions[89]) - (directions[90] * 8) - (directions[91] - directions[90]) - (checksum_1_byte / (checksum_2_byte - 2));
    hash[31] = (~directions[29] & 0x7F) + (~directions[37] & 0x7F) - (~directions[39] & 0x7F) + 3;
    hash[32] = ((directions[81] & 0x54) ^ (directions[26] & 0x4E) ^ (directions[81] & directions[81])) - 1;
    hash[33] = ((directions[93] + checksum_2_byte) & (directions[62] - checksum_3_byte)) * (16*directions[47] - 17*directions[49]);
    hash[34] = (directions[7] - (directions[69] ^ (directions[86] & directions[7]))) * ( (checksum_2_byte + checksum_1_byte) / (checksum_3_byte + 4));
    hash[35] = (directions[68] + directions[28] + directions[34] + directions[35] + directions[41] + directions[65] + directions[82]  - 7*directions[96]);
    hash[36] =  directions[20] + directions[29] - 0x7D;

    if (strncmp(hash, desired_hash, 37) == 0) {
        create_flag(directions);
        return 1;
    } else {
        return -1;
    }
}