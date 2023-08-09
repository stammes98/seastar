import datetime

class DataFile:

    def __init__(self, name):
        self.name = name
        
        #Public Variables
        self.Title = 0
        self.Author = 0
        self.Description = 0
        self.Notes = 0
        
        #Private Variables
        self.__FilePointer = 0
        
        
    def create(self):
        self.__FilePointer = open("/home/seastar/steve_summer_seastar_ws/hamburger_logs/" + self.name+"_"+datetime.datetime.now().strftime("%Y_%m_%d_%H_%M_%S")+".txt", "w")
        self.__FilePointer.write(self.name+"_"+datetime.datetime.now().strftime("%Y_%m_%d_%H_%M_%S")+".txt"+"\n\n")
        
        if self.Title:
            self.__FilePointer.write("Title:"+self.Title+"\n")
        if self.Author:
            self.__FilePointer.write("Author:"+self.Author+"\n")
        if self.Description:
            self.__FilePointer.write("Description:"+self.Description+"\n")
        if self.Notes:
            self.__FilePointer.write("Additional Notes:"+self.Notes+"\n")
            
        self.__FilePointer.write("\n")
        
    def end(self):
        self.__FilePointer.close()
        
    def addData(self, line):
        self.__FilePointer.write(line+"\n")
