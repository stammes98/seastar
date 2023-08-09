import datetime
import sys
import DataFileSystem
from labjack import ljm

class ham:
    
    def __init__(self):
        self.__handle= ljm.openS("ANY", "ANY", "ANY")
        info= ljm.getHandleInfo(self.__handle)
        print("Opened a LabJack with Device type: %i, Connection type: %i,\n"
          "Serial number: %i, IP address: %s, Port: %i,\nMax bytes per MB: %i" %
          (info[0], info[1], info[2], ljm.numberToIP(info[3]), info[4], info[5]))
      
        self.__deviceType=info[0]

    def setupAnalog(self, SEorDIF, Range, SetTime, ResIndex):
        aNames = ["AIN_ALL_NEGATIVE_CH", "AIN_ALL_RANGE","AIN_ALL_RESOLUTION_INDEX","AIN_ALL_SETTLING_US"] #Register names for setting up AIN_ALL_NEGATIVE_CH
        aValues = [SEorDIF, Range, ResIndex, SetTime]
        numFrames = len(aNames)
        ljm.eWriteNames(self.__handle, numFrames, aNames, aValues)
        
    def getAnalog(self, addrArray):
        numFrames = len(addrArray)
        results = ljm.eReadNames(self.__handle, numFrames, addrArray)
        return results