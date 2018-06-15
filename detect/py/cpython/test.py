import os
from ctypes import *
libs = cdll.LoadLibrary(os.getcwd()+'/syscall.so')
libs.main()
