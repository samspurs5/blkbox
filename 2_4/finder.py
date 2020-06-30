
from z3 import *
import re



checksum_1_byte = BitVec('checksum_1_byte',64)
checksum_2_byte = BitVec('checksum_2_byte',64)
checksum_3_byte = BitVec('checksum_3_byte',64)

target = "I'm winn1ng - We_rE@cH3D_7hE_Fu3L :~)"

s = Solver()

directions = [BitVec("directions[%i]"%(i),64) for i in range(100)]
constraint = []
checksumConstraint = [Or(*[checksum_1_byte == value for value in [0x2,0x16,0x3A]]),
Or(*[checksum_2_byte == value for value in [0x22,0xD,0x9]]),
Or(*[checksum_3_byte == value for value in [0x4,0x1F,0x29]])]
s.add(checksumConstraint)


for i in range(1,4):

    s.add(directions[((26*i)%27)] != directions[ ( (269*i)  %  104) ])
    s.add(directions[ ( ( 90*i) % 19) ] != directions[ ( ( 81*i)  %  87 ) ])
    s.add(directions[ ( ( 21*i) % 35) ] != directions[ ( (196*i)  %  73 ) ])
    s.add(directions[ ( ( 60*i) % 70) ] != directions[ ( (192*i)  %  76 ) ])
    s.add(directions[ ( (164*i) % 96) ] != directions[ ( ( 50*i)  %  88 ) ]) 

    #check 1 = 22
    #check 2 = 13
    #check 3 = 31



for i in range(len(directions)):
    directionValue = [directions[i] == ord(value) for value in "NSWE"]
    constraint.append(Or(*directionValue))
    

s.add(constraint)


f = open("directions.txt", "r")
for count,i in enumerate(f.readlines()):
    i = re.sub(" ","",i)
    i = re.sub("=", "==", i)
    i = re.sub(";","",i)
    i = re.sub(r"hash\[\d?\d\]", str(ord(target[count])),i)
    s.add(eval(i))
checksum_1 = BitVec("checksum_1",64)
checksum_2 = BitVec("checksum_2",64)
checksum_3 = BitVec("checksum_3",64)
s.add(checksum_1 == ((3*directions[18] + 4*directions[32] + 2*directions[33] + 0x4) % 52))
s.add(checksum_2 == ((directions[31] - 3*directions[20] + directions[19] - 0x8) % 16))
s.add(checksum_3 == ((2*directions[24] - 7*directions[46] + 3*directions[32] - 4*directions[27] ) % 62))
s.add( checksum_1 < 35)
s.add( checksum_1 > 27)
s.add( 13 == checksum_2)
s.add(checksum_3 > 20 )
s.add(checksum_3 < 26)



result = s.check()
print(result)
res = [None for i in range(100)]
if result != "unsat":
    m = s.model()
    for d in m.decls():
        print("%s = %s" % (d.name(), m[d]))
        if(d.name()[0] == "d"):
            res[int(d.name()[-3:].strip("[]"))] = int(m[d].as_long())
    
print("python -c 'print(\"",1,end =  "\\n")
for i in res:
    print(chr(int(i)),end = "\\n")
print("')|")

