import os
import hashlib

def getHash(f):
  line=f.readline()
  hash=hashlib.md5()
  while(line):
    hash.update(line)
    line=f.readline()
  return hash.hexdigest() 

def IsHashEqual(f1,f2):
  str1=getHash(f1)
  str2=getHash(f2)
  return str1==str2

if __name__ == '__main__':
    cmds = []
    ans = []
    cmd = "./bin/splc"
    for i in range(1,10):
        file_name = cmd+ " ../test/test_1_r0"+str(i)+".spl > rst"
        a = "../test/test_1_r0" + str(i) +".out"
        cmds.append(file_name)
        ans.append(a)

    for i in range(10,13):
        file_name =cmd+ " ../test/test_1_r"+str(i)+".spl > rst"
        cmds.append(file_name)
        a = "../test/test_1_r" + str(i) +".out"
        ans.append(a)


    for i in range(len(cmds)):
        print("========"+ str(i+1) +"=======")
        os.system(cmds[i])
        f1=open("./rst","rb")
        f2=open(ans[i],"rb")
        print(IsHashEqual(f1,f2))